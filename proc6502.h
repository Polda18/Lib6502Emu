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
 * File: proc6502.h
 ********************************************************************/

#ifndef __PROC6502_H__                          // If called multiple times, doesn't produce
#define __PROC6502_H__                          // warnings about duplicate definitions

// 6502 CPU structure declaration: make sure to include this header in order to
// import external definition in the dynamic link library itself (DLL on Windows, SO on Linux)
typedef struct {
    unsigned short PC;                          // Program Counter
    unsigned short SP;                          // Stack Pointer
    unsigned char flags;                        // Flags register
    unsigned char X;                            // Register X
    unsigned char Y;                            // Register Y
    unsigned char A;                            // Accumulator
} _proc6502_t;

// Import the external definition by using
// extern _proc6502_t proc6502;

// Memory map has to be used separately. By default, CPU does not have any internal memory
// apart from registers and pointers. Make new memory map by first importing <limits.h>
// and then allocating a memory space eighter using malloc or with static array pointer
// definition. It is recommended to allocate memory with USHRT_MAX constant from <limits.h>.

#endif
