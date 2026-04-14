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

// Global definitions
#include <limits.h>
#include <stdbool.h>

// Local definitions
#include "proc6502.h"
#include "opcodes.h"
#include "flags.h"
#include "errors.h"

// Defined functions are here
#include "lib6502.h"

// External definition of proc6502, declared within this scope
extern _proc6502_t proc6502;

// =========================================================================
// Global functions declarations to use for the CPU declaration.
// All declarations use memory pointer which is defined by your application.
// =========================================================================

// Local definitions
// -----------------

// Illegal opcode handler
static int __exec_illegal_opcode(size_t cycle, char* mem) {
    return ERR_OPCODE;
}

// ADC IMmediate
static int __exec_adc_im(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC Zero Page
static int __exec_adc_zp(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC Zero Page +X
static int __exec_adc_zpx(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC ABsolute
static int __exec_adc_ab(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC ABsolute +X
static int __exec_adc_abx(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC ABsolute +Y
static int __exec_adc_aby(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC INdirect X
static int __exec_adc_inx(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// ADC INdirect Y
static int __exec_adc_iny(size_t cycle, char* mem) {
    // TODO
    return 0;
}

// TODO: rest of instructions

// Type definition for the function pointer to execute an instruction
typedef int (*__exec_instr_t)(size_t, char*);       // __exec_instr(cycle, mem)

// Resolve the opcode and return the minimum and maximum cycles counts for the instruction
static size_t* __resolve_opcode_min_max_cycles(unsigned char opcode) {
    size_t min_cycles = 0;
    size_t max_cycles = 0;

    switch(opcode) {
        // TODO: Fix ADC cycles min and max counts (placeholder values for now)
        case ADC_IM:
            min_cycles = 2;
            max_cycles = 2;
            break;
        case ADC_ZP:
            min_cycles = 3;
            max_cycles = 3;
            break;
        case ADC_ZPX:
            min_cycles = 4;
            max_cycles = 4;
            break;
        case ADC_AB:
            min_cycles = 4;
            max_cycles = 4;
            break;
        case ADC_ABX:
            min_cycles = 4;
            max_cycles = 5;      // +1 if page boundary is crossed
            break;
        case ADC_ABY:
            min_cycles = 4;
            max_cycles = 5;      // +1 if page boundary is crossed
            break;
        case ADC_INX:
            min_cycles = 6;
            max_cycles = 6;
            break;
        case ADC_INY:
            min_cycles = 5;
            max_cycles = 6;      // +1 if page boundary is crossed
            break;
        // TODO: rest of instructions
        default:
            min_cycles = 0;
            max_cycles = 0;
    }

    return (size_t[2]){min_cycles, max_cycles};
}

// Resolve decimal mode
static bool __decmode_enabled() {
    return (bool)(proc6502.flags & FLAG_D);
}

// Resolve the opcode and do stuff according to the associated instruction
static __exec_instr_t __resolve_opcode_exec(unsigned char opcode) {
    __exec_instr_t exec_instr = NULL;

    switch(opcode) {
        case ADC_IM:
            // ADC IMmediate
            exec_instr = __exec_adc_im;
            break;
        case ADC_ZP:
            // ADC Zero Page
            exec_instr = __exec_adc_zp;
            break;
        case ADC_ZPX:
            // ADC Zero Page +X
            exec_instr = __exec_adc_zpx;
            break;
        case ADC_AB:
            // ADC ABsolute
            exec_instr = __exec_adc_ab;
            break;
        case ADC_ABX:
            // ADC ABsolute +X
            exec_instr = __exec_adc_abx;
            break;
        case ADC_ABY:
            // ADC ABsolute +Y
            exec_instr = __exec_adc_aby;
            break;
        case ADC_INX:
            // ADC INdirect X
            exec_instr = __exec_adc_inx;
            break;
        case ADC_INY:
            // ADC INdirect Y
            exec_instr = __exec_adc_iny;
            break;
        // TODO: rest of instructions
        default:
            // Illegal opcode
            exec_instr = __exec_illegal_opcode;
    }

    return exec_instr;
}

// TODO

// Global definitions
// ------------------

// Get the current values of the internal registers

/*****************************************************
 * Get the current value of the Program Counter (PC) register
 * @return The current value of the PC register
 *****************************************************/
unsigned short lib6502_get_pc() {
    return proc6502.PC;
}

/*****************************************************
 * Get the current value of the Stack Pointer (SP) register
 * @return The current value of the SP register
 *****************************************************/
unsigned short lib6502_get_sp() {
    return proc6502.SP;
}

/*****************************************************
 * Get the current value of the flags register
 * @return The current value of the flags register
 *****************************************************/
char lib6502_get_flags() {
    return proc6502.flags;
}

/*****************************************************
 * Get the current value of the X register
 * @return The current value of the X register
 *****************************************************/
char lib6502_get_x() {
    return proc6502.X;
}

/*****************************************************
 * Get the current value of the Y register
 * @return The current value of the Y register
 *****************************************************/
char lib6502_get_y() {
    return proc6502.Y;
}

/*****************************************************
 * Get the current value of the Accumulator (A) register
 * @return The current value of the A register
 *****************************************************/
char lib6502_get_a() {
    return proc6502.A;
}

// Set the values of the internal registers

/*****************************************************
 * Set the value of the Program Counter (PC) register
 * @param pc The value to set the PC register to
 *****************************************************/
void lib6502_set_pc(unsigned short pc) {
    proc6502.PC = pc;
}

/*****************************************************
 * Set the value of the Stack Pointer (SP) register
 * @param sp The value to set the SP register to
 *****************************************************/
void lib6502_set_sp(unsigned short sp) {
    proc6502.SP = sp;
}

/*****************************************************
 * Set the value of the flags register
 * @param flags The value to set the flags register to
 *****************************************************/
void lib6502_set_flags(char flags) {
    proc6502.flags = flags;
}

/*****************************************************
 * Set the value of the X register
 * @param x The value to set the X register to
 *****************************************************/
void lib6502_set_x(char x) {
    proc6502.X = x;
}

/*****************************************************
 * Set the value of the Y register
 * @param y The value to set the Y register to
 *****************************************************/
void lib6502_set_y(char y) {
    proc6502.Y = y;
}

/*****************************************************
 * Set the value of the Accumulator (A) register
 * @param a The value to set the A register to
 *****************************************************/
void lib6502_set_a(char a) {
    proc6502.A = a;
}

// TODO: Global functions for the rest of manipulating the CPU state, executing instructions, etc.
