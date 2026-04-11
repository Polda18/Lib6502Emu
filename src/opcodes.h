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
 * File: opcodes.h
 ********************************************************************/

#ifndef __OPCODES_H__                       // If called multiple times, doesn't produce
#define __OPCODES_H__                       // warnings about duplicate definitions

// Op codes definitions
// Reference guide: http://6502.org/tutorials/6502opcodes.html

// ---- INSTRUCTION ----------------------- OP CODE ------------------ COMMENT

// ADC: ADd with Carry
#define ADC_IM                              0x69                    // IMmediate addressing
#define ADC_ZP                              0x65                    // Zero Page addressing
#define ADC_ZPX                             0x75                    // Zero Page with X addition addressing
#define ADC_AB                              0x6d                    // ABsolute addressing
#define ADC_ABX                             0x7d                    // ABsolute with X addition addressing
#define ADC_ABY                             0x79                    // ABsolute with Y addition addressing
#define ADC_INX                             0x61                    // INdirect X addressing
#define ADC_INY                             0x71                    // INdirect Y addressing

// AND: bitwise AND with accumulator
#define AND_IM                              0x29                    // IMmediate addressing
#define AND_ZP                              0x25                    // Zero Page addressing
#define AND_ZPX                             0x35                    // Zero Page with X addition addressing
#define AND_AB                              0x2d                    // ABsolute addressing
#define AND_ABX                             0x3d                    // ABsolute with X addition addressing
#define AND_ABY                             0x39                    // ABsolute with Y addition addressing
#define AND_INX                             0x21                    // INdirect X addressing
#define AND_INY                             0x31                    // INdirect Y addressing´

// ASL: Arithmetic Shift Left
#define ASL_AC                              0x0a                    // ACcumulator
#define ASL_ZP                              0x06                    // Zero Page addressing
#define ASL_ZPX                             0x16                    // Zero Page with X addition addressing
#define ASL_AB                              0x0e                    // ABsolute addressing
#define ASL_ABX                             0x1e                    // ABsolute with X addition addressing

// BIT: test BITs
#define BIT_ZP                              0x24                    // Zero Page addressing
#define BIT_AB                              0x2c                    // ABsolute addressing

// CMP: CoMPare accumulator
#define CMP_IM                              0xc9                    // IMmediate addressing
#define CMP_ZP                              0xc5                    // Zero Page addressing
#define CMP_ZPX                             0xd5                    // Zero Page with X addition addressing
#define CMP_AB                              0xcd                    // ABsolute addressing
#define CMP_ABX                             0xdd                    // ABsolute with X addition addressing
#define CMP_ABY                             0xd9                    // ABsolute with Y addition addressing
#define CMP_INX                             0xc1                    // INdirect X addressing
#define CMP_INY                             0xd1                    // INdirect Y addressing

// CPX: ComPare X register
#define CPX_IM                              0xe0                    // IMmediate addressing
#define CPX_ZP                              0xe4                    // Zero Page addressing
#define CPX_AB                              0xec                    // ABsolute addressing

// CPY: ComPare Y register
#define CPY_IM                              0xc0                    // IMmediate addressing
#define CPY_ZP                              0xc4                    // Zero Page addressing
#define CPY_AB                              0xcc                    // ABsolute addressing

// DEC: DECrement memory
#define DEC_ZP                              0xc6                    // Zero Page addressing
#define DEC_ZPX                             0xd6                    // Zero Page with X addition addressing
#define DEC_AB                              0xce                    // ABsolute addressing
#define DEC_ABX                             0xde                    // ABsolute with X addition addressing

// EOR: bitwise Exclusive OR with accumulator
#define EOR_IM                              0x49                    // IMmediate addressing
#define EOR_ZP                              0x45                    // Zero Page addressing
#define EOR_ZPX                             0x55                    // Zero Page with X addition addressing
#define EOR_AB                              0x4d                    // ABsolute addressing
#define EOR_ABX                             0x5d                    // ABsolute with X addition addressing
#define EOR_ABY                             0x59                    // ABsolute with Y addition addressing
#define EOR_INX                             0x41                    // INdirect X addressing
#define EOR_INY                             0x51                    // INdirect Y addressing

// INC: INCrement memory
#define INC_ZP                              0xe6                    // Zero Page addressing
#define INC_ZPX                             0xf6                    // Zero Page with X addition addressing
#define INC_AB                              0xee                    // ABsolute addressing
#define INC_ABX                             0xfe                    // ABsolute with X addition addressing

// JMP: JuMP
#define JMP_AB                              0x4c                    // ABsolute addressing
#define JMP_IN                              0x6c                    // INdirect addressing

// JSR: Jump to SubRoutine
#define JSR                                 0x20                    // only absolute addressing

// LDA: LoaD Accumulator
#define LDA_IM                              0xa9                    // IMmediate addressing
#define LDA_ZP                              0xa5                    // Zero Page addressing
#define LDA_ZPX                             0xb5                    // Zero Page with X addition addressing
#define LDA_AB                              0xad                    // ABsolute addressing
#define LDA_ABX                             0xbd                    // ABsolute with X addition addressing
#define LDA_ABY                             0xb9                    // ABsolute with Y addition addressing
#define LDA_INX                             0xa1                    // INdirect X addressing
#define LDA_INY                             0xb1                    // INdirect Y addressing

// LDX: LoaD X register
#define LDX_IM                              0xa2                    // IMmediate addressing
#define LDX_ZP                              0xa6                    // Zero Page addressing
#define LDX_ZPY                             0xb6                    // Zero Page with Y addition addressing
#define LDX_AB                              0xae                    // ABsolute addressing
#define LDX_ABY                             0xbe                    // ABsolute with Y addition addressing

// LDY: LoaD Y register
#define LDY_IM                              0xa0                    // IMmediate addressing
#define LDY_ZP                              0xa4                    // Zero Page addressing
#define LDY_ZPX                             0xb4                    // Zero Page with X addition addressing
#define LDY_AB                              0xac                    // ABsolute addressing
#define LDY_ABX                             0xbc                    // ABsolute with X addition addressing

// LSR: Logical Shift Right
#define LSR_AC                              0x4a                    // Accumulator
#define LSR_ZP                              0x46                    // Zero Page addressing
#define LSR_ZPX                             0x56                    // Zero Page with X addition addressing
#define LSR_AB                              0x4e                    // ABsolute addressing
#define LSR_ABX                             0x5e                    // ABsolute with X addition addressing

// ORA: biwtise OR with Accumulator
#define ORA_IM                              0x09                    // IMmediate addressing
#define ORA_ZP                              0x05                    // Zero Page addressing
#define ORA_ZPX                             0x15                    // Zero Page with X addition addressing
#define ORA_AB                              0x0d                    // ABsolute addressing
#define ORA_ABX                             0x1d                    // ABsolute with X addition addressing
#define ORA_ABY                             0x19                    // ABsolute with Y addition addressing
#define ORA_INX                             0x01                    // INdirect X addressing
#define ORA_INY                             0x11                    // INdirect Y addressing

// ROL: ROtate Left
#define ROL_AC                              0x2a                    // Accumulator
#define ROL_ZP                              0x26                    // Zero Page addressing
#define ROL_ZPX                             0x36                    // Zero Page with X addition addressing
#define ROL_AB                              0x2e                    // ABsolute addressing
#define ROL_ABX                             0x3e                    // ABsolute with X addition addressing

// ROR: ROtate Right
#define ROR_AC                              0x6a                    // Accumulator
#define ROR_ZP                              0x66                    // Zero Page addressing
#define ROR_ZPX                             0x76                    // Zero Page with X addition addressing
#define ROR_AB                              0x6e                    // ABsolute addressing
#define ROR_ABX                             0x7e                    // ABsolute with X addition addressing

// SBC: SuBtract with Carry
#define SBC_IM                              0xe9                    // IMmediate addressing
#define SBC_ZP                              0xe5                    // Zero Page addressing
#define SBC_ZPX                             0xf5                    // Zero Page with X addition addressing
#define SBC_AB                              0xed                    // ABsolute addressing
#define SBC_ABX                             0xfd                    // ABsolute with X addition addressing
#define SBC_ABY                             0xf9                    // ABsolute with Y addition addressing
#define SBC_INX                             0xe1                    // INdirect X addressing
#define SBC_INY                             0xf1                    // INdirect Y addressing

// STA: STore Accumulator
#define STA_ZP                              0x85                    // Zero Page addressing
#define STA_ZPX                             0x95                    // Zero Page with X addition addressing
#define STA_AB                              0x8d                    // ABsolute addressing
#define STA_ABX                             0x9d                    // ABsolute with X addition addressing
#define STA_ABY                             0x99                    // ABsolute with Y addition addressing
#define STA_INX                             0x81                    // INdirect X addressing
#define STA_INY                             0x91                    // INdirect Y addressing

// STX: STore X register
#define STX_ZP                              0x86                    // Zero Page addressing
#define STX_ZPY                             0x96                    // Zero Page with Y addition addressing
#define STX_AB                              0x8e                    // ABsolute addressing

// STY: STore Y register
#define STY_ZP                              0x84                    // Zero Page addressing
#define STY_ZPX                             0x94                    // Zero Page with Y addition addressing
#define STY_AB                              0x8c                    // ABsolute addressing

// Branch instructions
#define BPL                                 0x10                    // Branch on PLus
#define BMI                                 0x30                    // Branch on MInus
#define BVC                                 0x50                    // Branch on oVerflow Clear
#define BVS                                 0x70                    // Branch on oVerflow Set
#define BCC                                 0x90                    // Branch on Carry Clear
#define BCS                                 0xb0                    // Branch on Carry Set
#define BNE                                 0xd0                    // Branch on Not Equal
#define BEQ                                 0xf0                    // Branch on EQual

// Flag (Processor Status) instructions
#define CLC                                 0x18                    // CLear Carry
#define SEC                                 0x38                    // SEt Carry
#define CLI                                 0x58                    // CLear Interrupt
#define SEI                                 0x78                    // SEt Interrupt
#define CLV                                 0xb8                    // CLear oVerflow
#define CLD                                 0xd8                    // CLear Decimal
#define SED                                 0xf8                    // SEt Decimal

// Register instructions
#define TAX                                 0xaa                    // Transfer A to X
#define TXA                                 0x8a                    // Transfer X to A
#define DEX                                 0xca                    // DEcrement X
#define INX                                 0xe8                    // INcrement X
#define TAY                                 0xa8                    // Trasfer A to Y
#define TYA                                 0x98                    // Transfer Y to A
#define DEY                                 0x88                    // DEcrement Y
#define INY                                 0xc8                    // INcrement Y

// Stack instructions
#define TXS                                 0x9a                    // Transfer X to Stack pointer
#define TSX                                 0xba                    // Transfer Stack pointer to X
#define PHA                                 0x48                    // PusH Accumulator
#define PLA                                 0x68                    // PuLl Accumulator
#define PHP                                 0x08                    // PusH Processor status
#define PLP                                 0x28                    // PuLl Processor status

// Miscelaneous instructions
#define BRK                                 0x00                    // BReaK
#define NOP                                 0xea                    // No OPeration
#define RTI                                 0x40                    // ReTurn from Interrupt
#define RTS                                 0x60                    // ReTurn from Subroutine

// End of instructions and their op codes definitions

#endif
