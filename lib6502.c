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

// Local definitions
#include "proc6502.h"
#include "opcodes.h"
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

// Resolve the opcode and do stuff according to the associated instruction
static int __execute_instruction(unsigned char opcode, char* mem) {
    int retcode = 0;
    
    switch(opcode) {
        case ADC_IM:
            // TODO: ADC immediate
            break;
        case ADC_ZP:
            // TODO: ADC zero page
            break;
        case ADC_ZPX:
            // TODO: ADC zero page +X
            break;
        case ADC_AB:
            // TODO: ADC absolute
            break;
        case ADC_ABX:
            // TODO: ADC absolute +X
            break;
        case ADC_ABY:
            // TODO: ADC absolute +Y
            break;
        case ADC_INX:
            // TODO: ADC indirect X
            break;
        case ADC_INY:
            // TODO: ADC indirect Y
            break;
        // TODO: rest of instructions
        default:
            retcode = ERR_OPCODE;
    }

    return retcode;
}

// TODO

// Global definitions
// ------------------

// TODO
