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
 * File: lib6502_errors.h
 ********************************************************************/

#ifndef __LIB6502_ERRORS_H__                    // If called multiple times, doesn't produce
#define __LIB6502_ERRORS_H__                    // warnings about duplicate definitions

// Error codes definition
#define ERR_OPCODE              1               // Op code couldn't be resolved
#define ERR_OUT_OF_BOUND        2               // Access out of bound
#define ERR_CYCLES              3               // Cycles error
#define ERR_OUT_OF_MEM          4               // Insufficient memory

#define ERR_DEC_OUT_OF_RANGE    99              // Decimal mode out of range

#endif
