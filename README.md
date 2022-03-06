# 6502 CPU Emulator Library
_COMING SOON_

This repository holds source code for 6502 CPU emulator library. Emulator libary is going to be done
entirely in C, purely for practice purposes in low level programming. Emulator is going to behave
almost exactly like the real hardware, including all of the memory handling, registers and arithmetic
operations. Compiled DLL/SO binary will be available for both Windows and Unix-like operating systems.

A very simple emulator is going to be available on a separate repository as an example usage of this
library and debug tool for 6502 machine code. That repository is going to be called "6502 CPU Debug
Emulator". It's going to be a GUI construction written in C, for both Windows and Unix-like operating
systems. It will contain control panel with buttons that can halt the program counter, step with ticks,
set run speed, and also will contain display fields that will display values of different registers
and memory spaces with their respective values which can be (with exception of memory spaces) rotated
between binary, octal, decimal and hexadecimal representation. Memory space is going to be a static
8bit array with 16bit addressing. It's going to be represented with canonical HEX+ASCII display.
It will also have interrupt interface that will generate all sorts of interrupt signals possible with
6502.

## Word of note
This is going to be really long development process and I might call for your help. However, as I stated,
this is supposed to be challenge. It could be made more effectively with C++ and using OOP, but I like
to work with low level stuff. The debug tool will contain some example 6502 assembly codes and compiled
version will also contain the compiled 6502 machine code binaries to try out. The debug tool will ask
for starting point of the program and to program in some initial data into memory space before proceeding.
You may also choose one of profiles for debugging, like Commodore 64 (it will preload memory map of
Commodore 64 into the memory space, which has the BASIC ROM in it that contains BASIC operating system).
Depending on difficulty and whether it resembles an I/O device, the profile may or may not contain screen
pixel emulator, keyboard interface control, or anything else that would be useful for debugging. Those
interface controls will essentially be macros that will generate interrupts sequences. You may contribute
your own macros to be added into the project. Memory space programming may ask for direct manual programming,
selection of predefined profiles, or selection of custom memory map from a file.

## Development
This section is used to document the development of the emulator library. Please note that once this
project is finished, the entire README file is going to be rewritten to reflect what a developer of
a custom 6502 emulator will need to use this library. The following list is then more or less just
to keep track of additions to the project.

```
2022-03-04
----------

Made first piece and created one of the basic founding block of this project.

TYPE    FILENAME                        COMMENT
----    --------                        -------
ADD     opcodes.h                       List of all instructions and their op codes
MOD     README.md                       Update of informations about this project


2022-03-05
----------

Started making the CPU itself, with all the library functions to operate it

TYPE    FILENAME                        COMMENT
----    --------                        -------
ADD     proc6502.h                      Header file defining CPU structure type
ADD     proc6502.c                      Initialization of the CPU structure object
ADD     lib6502.h                       Header file that will declare all of the necessary functions
ADD     lib6502.c                       This will define the procedures of the necessary functions
MOD     README.md                       Addition of new context


2022-03-06
----------

Started code for opcode instruction executions

TYPE    FILENAME                        COMMENT
----    --------                        -------
ADD     errors.h                        Foundation of return error codes
MOD     lib6502.c                       Addition of opcode switch to execute given instructions
MOD     README.md                       Addition of new context
```
