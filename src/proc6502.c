/********************************************************************
 * 6502 CPU Emulator Library
 * ------------------------------------------------------------------
 * This project is put together to offer dynamic link library
 * for various computer emulators utilizing a 6502 CPU emu layer.
 * 
 * This library is based on the real hardware, it offers functions
 * for cycles computation, for op codes resolvent, and contains
 * static definitions for the registers, flags and declarations
 * for memory assignment. For development purposes, a separate
 * download for header files is available for download, including
 * op codes definitions in "opcodes.h" file. Choose whichever
 * version you're going to go with (Windows or Unix: Linux/MacOS)
 * ------------------------------------------------------------------
 * File: proc6502.c
 ********************************************************************/

#include <limits.h>

#include "proc6502.h"

// External definition of the 6502 CPU structure
_proc6502_t proc6502 = {
    0,              // PC       -> Program Counter
    0,              // SP       -> Stack Pointer
    0,              // flags    -> Flags register
    0,              // X        -> Register X
    0,              // Y        -> Register Y
    0               // A        -> Accumulator
};
