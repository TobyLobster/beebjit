#ifndef ASM_OPCODES_H
#define ASM_OPCODES_H

#include <stdint.h>

struct asm_uop {
  int32_t uopcode;
  int32_t value1;
  int32_t value2;
  int is_eliminated;
};

/* NOTE: many of the opcodes < 0x100 are implied to be opcodes that are similar
 * to the behavior of the equivalent 6502 opcode.
 * This is neither particularly explicit, nor clean, and may be changed.
 */
enum {
  k_opcode_countdown = 0x100,
  k_opcode_debug,
  k_opcode_interp,
  k_opcode_inturbo,
  k_opcode_jump_raw,
  k_opcode_for_testing,
  k_opcode_ADD_CYCLES,
  k_opcode_ADD_ABS,
  k_opcode_ADD_ABX,
  k_opcode_ADD_ABY,
  k_opcode_ADD_IMM,
  k_opcode_ADD_SCRATCH,
  k_opcode_ADD_SCRATCH_Y,
  k_opcode_ADDR_CHECK,
  k_opcode_ASL_ACC_n,
  k_opcode_CHECK_BCD,
  k_opcode_CHECK_PAGE_CROSSING_SCRATCH_n,
  k_opcode_CHECK_PAGE_CROSSING_SCRATCH_X,
  k_opcode_CHECK_PAGE_CROSSING_SCRATCH_Y,
  k_opcode_CHECK_PAGE_CROSSING_X_n,
  k_opcode_CHECK_PAGE_CROSSING_Y_n,
  k_opcode_CHECK_PENDING_IRQ,
  k_opcode_CLEAR_CARRY,
  k_opcode_EOR_SCRATCH_n,
  k_opcode_FLAGA,
  k_opcode_FLAGX,
  k_opcode_FLAGY,
  k_opcode_FLAG_MEM,
  k_opcode_INVERT_CARRY,
  k_opcode_JMP_SCRATCH_n,
  k_opcode_LDA_SCRATCH_n,
  k_opcode_LDA_SCRATCH_X,
  k_opcode_LDA_Z,
  k_opcode_LDX_Z,
  k_opcode_LDY_Z,
  k_opcode_LOAD_CARRY_FOR_BRANCH,
  k_opcode_LOAD_CARRY_FOR_CALC,
  k_opcode_LOAD_CARRY_INV_FOR_CALC,
  k_opcode_LOAD_OVERFLOW,
  k_opcode_LOAD_SCRATCH_8,
  k_opcode_LOAD_SCRATCH_16,
  k_opcode_LSR_ACC_n,
  k_opcode_MODE_ABX,
  k_opcode_MODE_ABY,
  k_opcode_MODE_IND_8,
  k_opcode_MODE_IND_16,
  k_opcode_MODE_IND_SCRATCH_8,
  k_opcode_MODE_IND_SCRATCH_16,
  k_opcode_MODE_ZPX,
  k_opcode_MODE_ZPY,
  k_opcode_PULL_16,
  k_opcode_PUSH_16,
  k_opcode_ROL_ACC_n,
  k_opcode_ROR_ACC_n,
  k_opcode_SAVE_CARRY,
  k_opcode_SAVE_CARRY_INV,
  k_opcode_SAVE_OVERFLOW,
  k_opcode_SET_CARRY,
  k_opcode_STA_SCRATCH_n,
  k_opcode_STOA_IMM,
  k_opcode_SUB_ABS,
  k_opcode_SUB_IMM,
  k_opcode_WRITE_INV_ABS,
  k_opcode_WRITE_INV_SCRATCH,
  k_opcode_WRITE_INV_SCRATCH_n,
  k_opcode_WRITE_INV_SCRATCH_Y,
};

#endif /* ASM_OPCODES_H */
