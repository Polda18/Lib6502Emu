# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project status

Early, in-progress C library that will compile to a shared library (DLL on Windows, SO on Unix) emulating a MOS 6502 CPU. There is **no build system in the tree yet** — no Makefile, CMakeLists, or VS solution. Empty `build/x86_64/{win,unix}/`, `test/`, and `zip/` directories exist as placeholders for the eventual multi-platform output, test suite, and packaging.

When working here, expect to be filling in stubs (most opcode handlers are `// TODO`), not refactoring a finished system.

## Architecture

All source files share the `lib6502_` prefix: `src/lib6502_lib.{c,h}` (public API + dispatch), `src/lib6502_proc.{c,h}` (CPU state), `src/lib6502_opcodes.h`, `src/lib6502_flags.h`, `src/lib6502_errors.h`. Keep that convention when adding new files.

The CPU is a single global `_proc6502_t` (PC, SP, flags, X, Y, A) defined in `src/lib6502_proc.c` and accessed from `src/lib6502_lib.c` via `extern _proc6502_t proc6502;`. Treat the CPU as a singleton; do not introduce per-instance state.

Public API surface lives in `src/lib6502_lib.h` and uses the `lib6502_` prefix. Currently only register getters/setters are exposed — instruction execution and CPU manipulation are still TODO. The host application owns memory: it passes a `char* mem` into execution functions (the library never allocates the address space). The recommended host allocation is `USHRT_MAX` bytes (16-bit address space).

Inside `lib6502_lib.c`, the opcode dispatch pattern is:

- `__resolve_opcode_exec(opcode)` returns a `__exec_instr_t` function pointer (one `__exec_*` per opcode+addressing-mode combo).
- `__resolve_opcode_min_max_cycles(opcode)` returns `{min, max}` cycles; `max > min` means "+1 if page boundary crossed".
- Unknown opcodes fall through to `__exec_illegal_opcode`, which returns `ERR_OPCODE` from `lib6502_errors.h`.

When adding a new instruction, update **both** resolver switches plus add an `__exec_*` static function. Opcode constants follow `MNEMONIC_MODE` naming (e.g. `ADC_ZPX` for ADC zero-page,X) — see `src/lib6502_opcodes.h` (sourced from [6502.org](http://6502.org/tutorials/6502opcodes.html)).

Flag bits in `src/lib6502_flags.h` (`FLAG_C/Z/I/D/B/U/V/N`) map to the standard 6502 status register layout. Decimal mode is detected via `__decmode_enabled()` checking `FLAG_D`.

## CPU variant and illegal opcodes

**Default target is the original NMOS 6502**, not the 65C02. This is deliberate — software written for C64/NES/Apple II commonly relies on NMOS quirks (JMP indirect page-wrap bug, undefined decimal flags after ADC/SBC, etc.) and on undocumented ("illegal") opcodes. A 65C02 build that fixes those quirks would fail to run that software faithfully, which conflicts with the "behave almost exactly like the real hardware" goal and the planned C64 profile.

Illegal opcodes are split into three tiers, and the resolver should treat them differently:

1. **Stable illegals** — implement these as documented community behavior: `LAX`, `SAX`, `SLO`, `RLA`, `SRE`, `RRA`, `DCP`, `ISC` (a.k.a. `ISB`), `ANC`, `ALR` (a.k.a. `ASR`), `ARR`. Real software uses them.
2. **Unstable illegals** — `ANE` (a.k.a. `XAA`), `LXA` (a.k.a. `LAX#`), `SHA`/`SHX`/`SHY`/`TAS`. Behavior depends on chip batch, temperature, and bus capacitance. Implement a best-effort common case (e.g. `ANE` with magic constant `0xEE` or `0xFF`) and document the chosen constant in the `__exec_*` function — do not pretend it is canonical.
3. **KIL/JAM/HLT** (`0x02`, `0x12`, `0x22`, …) — halt the CPU on real hardware. Return `ERR_OPCODE` and stop execution; do not silently NOP.

Note that this means `__exec_illegal_opcode` (the current fallback) should eventually only be hit for genuinely unmapped bytes — most "illegal" opcodes will have real `__exec_*` entries.

### Future 65C02 variant

Do **not** preemptively add a variant flag, parallel dispatch tables, or `#ifdef MODE_65C02` blocks. The current single-resolver pattern is fine for now; when 65C02 support is actually scheduled, the natural extension is a second resolver (`__resolve_opcode_exec_65c02`) selected by a runtime field on `_proc6502_t` or a build-time `-DLIB6502_VARIANT=...`. Decisions to defer until then: whether the variant is per-CPU-instance (irrelevant while the CPU is a singleton) and how the new 65C02-only opcodes (`BRA`, `PHX/PHY/PLX/PLY`, `STZ`, `TRB/TSB`, the Rockwell bit ops) coexist with NMOS illegals in `opcodes.h` (likely a separate header section, since several opcode bytes are reused).

## Conventions

- Header guards use `__NAME_H__` form.
- Public symbols: `lib6502_*`. File-local helpers: `static` with `__` prefix.
- Every source file repeats the same banner comment block — keep it when adding new files.
- The README's "Development" section is an append-only changelog of additions; when making notable changes, add a new dated entry there following the existing `TYPE FILENAME COMMENT` table format (`ADD`/`MOD`/`MOV`).

## Building

No build scripts exist yet. To compile manually for testing during development on an x86_64 host:

```sh
# Linux shared object
gcc -shared -fPIC -o build/x86_64/linux/lib6502.so src/*.c

# MacOS dylib — must be built on a Mac (see target matrix below)
clang -shared -fPIC -o build/x86_64/macos/lib6502.dylib src/*.c

# Windows DLL (MinGW)
gcc -shared -o build/x86_64/win/lib6502.dll src/*.c
```

A developer kit of header files (the `src/*.h` set) ships alongside the binaries so consumers can link against the shared library.

There are no tests, no linter config, and no CI.

### Planned target matrix

Three architectures × three OSes, but **not all nine cells are real targets**:

|              | x86_64           | ARM64                 | MIPS64                  |
|--------------|------------------|-----------------------|-------------------------|
| **Windows**  | yes              | yes (Windows on ARM)  | no (dropped in NT4 era) |
| **Linux**    | yes              | yes                   | yes                     |
| **MacOS**    | yes (Intel Macs) | yes (Apple Silicon)   | no                      |

Practical implications for builds:

- **Linux and MacOS are not binary-compatible** despite both being POSIX. A `.so` built on Linux will not load on MacOS, and a `.dylib` built on MacOS will not load on Linux. They need separate build pipelines and separate output directories (suggested: `build/<arch>/{win,linux,macos}/`, replacing the current `build/x86_64/{win,unix}/` placeholder).
- **MacOS builds must run on Mac hardware** (or a licensed MacOS VM). Cross-compiling MacOS binaries from Linux/Windows requires the macOS SDK and a toolchain like osxcross, which is brittle and not officially supported by Apple. Expect to defer MacOS until a real Mac (Apple Silicon) is available.
- **Apple Silicon is ARM64** (specifically ARMv8-A and later — Apple's M-series chips). Confirmed correct. Note that Intel Macs (pre-2020) are x86_64, so the MacOS column has both rows until those machines fully age out.
- **Host = Intel x86/64** means non-x86_64 Linux targets (ARM64, MIPS64) are reachable via a cross-compiler (`aarch64-linux-gnu-gcc`, `mips64-linux-gnuabi64-gcc`) or via virtualization/QEMU. ARM64 Windows similarly needs MSVC's ARM64 toolchain or a Windows-on-ARM VM.

A developer kit (headers only) is architecture- and OS-independent and can be packaged once per release.

### Planned tooling (not yet in tree)

- **Makefile** — will drive the per-target builds above. Do not create it preemptively; wait until the build matrix and output layout are finalized.
- **`.gitignore` refresh** — the current file is the stock Visual Studio template. When the Makefile lands, it will need entries for the new `build/<arch>/<os>/` outputs and for common editor/IDE droppings (VS Code's `.vscode/`, Sublime Text's `*.sublime-workspace` / `*.sublime-project`, etc.). Refactor at the same time as the Makefile, not before.
- **CI** — will likely be GitHub Actions when introduced. The workflow will need a Linux runner for the Linux/MIPS64/ARM64-cross builds, a Windows runner for the DLL, and a `macos-latest` (Apple Silicon) runner for the dylib.
