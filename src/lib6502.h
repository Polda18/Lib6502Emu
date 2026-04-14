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
 * File: lib6502.h
 ********************************************************************/

#ifndef __LIB6502_H__                           // If called multiple times, doesn't produce
#define __LIB6502_H__                           // warnings about duplicate definitions

// =========================================================================
// Global functions declarations to use for the CPU declaration.
// All declarations use memory pointer which is defined by your application.
// =========================================================================

// Getter functions for the internal registers

/*****************************************************
 * Get the current value of the Program Counter (PC) register
 * @return The current value of the PC register
 *****************************************************/
unsigned short lib6502_get_pc();

/*****************************************************
 * Get the current value of the Stack Pointer (SP) register
 * @return The current value of the SP register
 *****************************************************/
unsigned short lib6502_get_sp();

/*****************************************************
 * Get the current value of the flags register
 * @return The current value of the flags register
 *****************************************************/
char lib6502_get_flags();

/*****************************************************
 * Get the current value of the X register
 * @return The current value of the X register
 *****************************************************/
char lib6502_get_x();

/*****************************************************
 * Get the current value of the Y register
 * @return The current value of the Y register
 *****************************************************/
char lib6502_get_y();

/*****************************************************
 * Get the current value of the Accumulator (A) register
 * @return The current value of the A register
 *****************************************************/
char lib6502_get_a();

// Setter functions for the internal registers

/*****************************************************
 * Set the value of the Program Counter (PC) register
 * @param pc The value to set the PC register to
 *****************************************************/
void lib6502_set_pc(unsigned short pc);

/*****************************************************
 * Set the value of the Stack Pointer (SP) register
 * @param sp The value to set the SP register to
 *****************************************************/
void lib6502_set_sp(unsigned short sp);

/*****************************************************
 * Set the value of the flags register
 * @param flags The value to set the flags register to
 *****************************************************/
void lib6502_set_flags(char flags);

/*****************************************************
 * Set the value of the X register
 * @param x The value to set the X register to
 *****************************************************/
void lib6502_set_x(char x);

/*****************************************************
 * Set the value of the Y register
 * @param y The value to set the Y register to
 *****************************************************/
void lib6502_set_y(char y);

/*****************************************************
 * Set the value of the Accumulator (A) register
 * @param a The value to set the A register to
 *****************************************************/
void lib6502_set_a(char a);

// TODO: rest of the CPU state manipulations and executing instructions

#endif
