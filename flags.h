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
 * File: flags.h
 ********************************************************************/

#ifndef __FLAGS_H__         // If called multiple times, doesn't produce
#define __FLAGS_H__         // warnings about duplicate definitions

// Flags for flags register
#define FLAG_C      0x01    // Carry
#define FLAG_Z      0x02    // Zero result
#define FLAG_I      0x04    // Interrupt disable
#define FLAG_D      0x08    // Decimal mode
#define FLAG_B      0x10    // Break
#define FLAG_U      0x20    // Unassigned (flag ignored)
#define FLAG_V      0x40    // oVerflow
#define FLAG_N      0x80    // Negative result

#endif
