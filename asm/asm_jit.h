#ifndef BEEBJIT_ASM_JIT_H
#define BEEBJIT_ASM_JIT_H

#include <stdint.h>

struct util_buffer;

int asm_jit_is_enabled(void);
void asm_jit_test_preconditions(void);
int asm_jit_supports_optimizer(void);
int asm_jit_supports_uopcode(int32_t uopcode);
uint32_t asm_jit_enter(void* p_context,
                       uint32_t jump_addr_x64,
                       int64_t countdown,
                       void* p_mem_base);
void asm_jit_invalidate_code_at(void* p);

void asm_emit_jit_invalidated(struct util_buffer* p_buf);
void asm_emit_jit_call_compile_trampoline(struct util_buffer* p_buf);
void asm_emit_jit_jump_interp_trampoline(struct util_buffer* p_buf,
                                         uint16_t addr);
void asm_emit_jit_check_countdown(struct util_buffer* p_buf,
                                  struct util_buffer* p_buf_epilog,
                                  uint32_t count,
                                  uint16_t addr,
                                  void* p_trampoline);
void asm_emit_jit_check_countdown_no_save_nz_flags(struct util_buffer* p_buf,
                                                   uint32_t count,
                                                   void* p_trampoline);
void asm_emit_jit_call_debug(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_jump_interp(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_call_inturbo(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_for_testing(struct util_buffer* p_buf);

void asm_emit_jit_ADD_CYCLES(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ADD_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADD_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADD_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADD_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ADD_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_ADD_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_CHECK_BCD(struct util_buffer* p_buf);
void asm_emit_jit_CHECK_PAGE_CROSSING_SCRATCH_n(struct util_buffer* p_buf,
                                                uint8_t offset);
void asm_emit_jit_CHECK_PAGE_CROSSING_SCRATCH_X(struct util_buffer* p_buf);
void asm_emit_jit_CHECK_PAGE_CROSSING_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_CHECK_PAGE_CROSSING_X_n(struct util_buffer* p_buf,
                                          uint16_t addr);
void asm_emit_jit_CHECK_PAGE_CROSSING_Y_n(struct util_buffer* p_buf,
                                          uint16_t addr);
void asm_emit_jit_CHECK_PENDING_IRQ(struct util_buffer* p_buf,
                                    void* p_trampoline);
void asm_emit_jit_CLEAR_CARRY(struct util_buffer* p_buf);
void asm_emit_jit_FLAG_MEM(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_INVERT_CARRY(struct util_buffer* p_buf);
void asm_emit_jit_JMP_SCRATCH_n(struct util_buffer* p_buf, uint16_t n);
void asm_emit_jit_LDA_Z(struct util_buffer* p_buf);
void asm_emit_jit_LDX_Z(struct util_buffer* p_buf);
void asm_emit_jit_LDY_Z(struct util_buffer* p_buf);
void asm_emit_jit_LOAD_CARRY_FOR_BRANCH(struct util_buffer* p_buf);
void asm_emit_jit_LOAD_CARRY_FOR_CALC(struct util_buffer* p_buf);
void asm_emit_jit_LOAD_CARRY_INV_FOR_CALC(struct util_buffer* p_buf);
void asm_emit_jit_LOAD_OVERFLOW(struct util_buffer* p_buf);
void asm_emit_jit_LOAD_SCRATCH_8(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_LOAD_SCRATCH_16(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_MODE_ABX(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_MODE_ABY(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_MODE_IND_8(struct util_buffer* p_buf, uint8_t addr);
void asm_emit_jit_MODE_IND_16(struct util_buffer* p_buf,
                              uint16_t addr,
                              uint32_t segment);
void asm_emit_jit_MODE_IND_SCRATCH_8(struct util_buffer* p_buf);
void asm_emit_jit_MODE_IND_SCRATCH_16(struct util_buffer* p_buf);
void asm_emit_jit_MODE_ZPX(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_MODE_ZPY(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_PULL_16(struct util_buffer* p_buf);
void asm_emit_jit_PUSH_16(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_SAVE_CARRY(struct util_buffer* p_buf);
void asm_emit_jit_SAVE_CARRY_INV(struct util_buffer* p_buf);
void asm_emit_jit_SAVE_OVERFLOW(struct util_buffer* p_buf);
void asm_emit_jit_SET_CARRY(struct util_buffer* p_buf);
void asm_emit_jit_STOA_IMM(struct util_buffer* p_buf,
                           uint16_t addr,
                           uint8_t value);
void asm_emit_jit_SUB_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_SUB_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_WRITE_INV_ABS(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_WRITE_INV_SCRATCH(struct util_buffer* p_buf);
void asm_emit_jit_WRITE_INV_SCRATCH_n(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_WRITE_INV_SCRATCH_Y(struct util_buffer* p_buf);

void asm_emit_jit_ADC_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADC_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADC_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ADC_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ADC_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_ADC_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_ALR_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_AND_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_AND_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_AND_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_AND_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_AND_SCRATCH(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_AND_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_ASL_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ASL_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ASL_ABX(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ASL_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ASL_ACC(struct util_buffer* p_buf);
void asm_emit_jit_ASL_ACC_n(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ASL_scratch(struct util_buffer* p_buf);
void asm_emit_jit_BCC(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BCS(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BEQ(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BIT(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_BMI(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BNE(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BPL(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BVC(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_BVS(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_CMP_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_CMP_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_CMP_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_CMP_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_CMP_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_CMP_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_CPX_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_CPX_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_CPY_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_CPY_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_DEC_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_DEC_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_DEC_ABX(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_DEC_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_DEC_scratch(struct util_buffer* p_buf);
void asm_emit_jit_EOR_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_EOR_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_EOR_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_EOR_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_EOR_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_EOR_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_INC_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_INC_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_INC_ABX(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_INC_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_INC_scratch(struct util_buffer* p_buf);
void asm_emit_jit_JMP(struct util_buffer* p_buf, void* p_target);
void asm_emit_jit_LDA_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDA_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDA_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDA_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_LDA_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_LDA_SCRATCH_X(struct util_buffer* p_buf);
void asm_emit_jit_LDA_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_LDX_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDX_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDX_scratch(struct util_buffer* p_buf);
void asm_emit_jit_LDX_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_LDY_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDY_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_LDY_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_LDY_scratch(struct util_buffer* p_buf);
void asm_emit_jit_LSR_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_LSR_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_LSR_ABX(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_LSR_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_LSR_ACC(struct util_buffer* p_buf);
void asm_emit_jit_LSR_ACC_n(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_LSR_scratch(struct util_buffer* p_buf);
void asm_emit_jit_ORA_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ORA_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ORA_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_ORA_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ORA_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_ORA_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_ROL_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROL_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROL_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROL_ACC(struct util_buffer* p_buf);
void asm_emit_jit_ROL_ACC_n(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ROL_scratch(struct util_buffer* p_buf);
void asm_emit_jit_ROR_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROR_ABS_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROR_ABX_RMW(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_ROR_ACC(struct util_buffer* p_buf);
void asm_emit_jit_ROR_ACC_n(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_ROR_scratch(struct util_buffer* p_buf);
void asm_emit_jit_SAX_ABS(struct util_buffer* p_buf, uint16_t value);
void asm_emit_jit_SBC_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_SBC_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_SBC_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_SBC_IMM(struct util_buffer* p_buf, uint8_t value);
void asm_emit_jit_SBC_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_SBC_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_SHY_ABX(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_SLO_ABS(struct util_buffer* p_buf, uint16_t addr);
void asm_emit_jit_STA_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_STA_ABX(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_STA_ABY(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_STA_SCRATCH(struct util_buffer* p_buf, uint8_t offset);
void asm_emit_jit_STA_SCRATCH_Y(struct util_buffer* p_buf);
void asm_emit_jit_STX_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_STX_scratch(struct util_buffer* p_buf);
void asm_emit_jit_STY_ABS(struct util_buffer* p_buf,
                          uint16_t addr,
                          uint32_t segment);
void asm_emit_jit_STY_scratch(struct util_buffer* p_buf);

/* Symbols pointing directly to ASM bytes. */
void asm_jit_compile_trampoline();
void asm_jit_interp();

void asm_jit_call_compile_trampoline();
void asm_jit_call_compile_trampoline_END();
void asm_jit_jump_interp_trampoline();
void asm_jit_jump_interp_trampoline_pc_patch();
void asm_jit_jump_interp_trampoline_jump_patch();
void asm_jit_jump_interp_trampoline_END();
void asm_jit_check_countdown();
void asm_jit_check_countdown_count_patch();
void asm_jit_check_countdown_jump_patch();
void asm_jit_check_countdown_END();
void asm_jit_check_countdown_8bit();
void asm_jit_check_countdown_8bit_count_patch();
void asm_jit_check_countdown_8bit_jump_patch();
void asm_jit_check_countdown_8bit_END();
void asm_jit_call_debug();
void asm_jit_call_debug_pc_patch();
void asm_jit_call_debug_call_patch();
void asm_jit_call_debug_END();
void asm_jit_jump_interp();
void asm_jit_jump_interp_pc_patch();
void asm_jit_jump_interp_jump_patch();
void asm_jit_jump_interp_END();
void asm_jit_for_testing();
void asm_jit_for_testing_END();

void asm_jit_ADD_ABS();
void asm_jit_ADD_ABS_END();
void asm_jit_ADD_ABX();
void asm_jit_ADD_ABX_END();
void asm_jit_ADD_ABY();
void asm_jit_ADD_ABY_END();
void asm_jit_ADD_CYCLES();
void asm_jit_ADD_CYCLES_END();
void asm_jit_ADD_IMM();
void asm_jit_ADD_IMM_END();
void asm_jit_ADD_SCRATCH();
void asm_jit_ADD_SCRATCH_END();
void asm_jit_ADD_SCRATCH_Y();
void asm_jit_ADD_SCRATCH_Y_END();
void asm_jit_ADD_ZPG();
void asm_jit_ADD_ZPG_END();
void asm_jit_CHECK_BCD();
void asm_jit_CHECK_BCD_END();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_n();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_n_mov_patch();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_n_END();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_X();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_X_END();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_Y();
void asm_jit_CHECK_PAGE_CROSSING_SCRATCH_Y_END();
void asm_jit_CHECK_PAGE_CROSSING_X_n();
void asm_jit_CHECK_PAGE_CROSSING_X_n_mov_patch();
void asm_jit_CHECK_PAGE_CROSSING_X_n_END();
void asm_jit_CHECK_PAGE_CROSSING_Y_n();
void asm_jit_CHECK_PAGE_CROSSING_Y_n_mov_patch();
void asm_jit_CHECK_PAGE_CROSSING_Y_n_END();
void asm_jit_CHECK_PENDING_IRQ();
void asm_jit_CHECK_PENDING_IRQ_jump_patch();
void asm_jit_CHECK_PENDING_IRQ_END();
void asm_jit_CLEAR_CARRY();
void asm_jit_CLEAR_CARRY_END();
void asm_jit_FLAGA();
void asm_jit_FLAGA_END();
void asm_jit_FLAGX();
void asm_jit_FLAGX_END();
void asm_jit_FLAGY();
void asm_jit_FLAGY_END();
void asm_jit_FLAG_MEM();
void asm_jit_FLAG_MEM_END();
void asm_jit_INVERT_CARRY();
void asm_jit_INVERT_CARRY_END();
void asm_jit_LDA_Z();
void asm_jit_LDA_Z_END();
void asm_jit_LDX_Z();
void asm_jit_LDX_Z_END();
void asm_jit_LDY_Z();
void asm_jit_LDY_Z_END();
void asm_jit_LOAD_CARRY_FOR_BRANCH();
void asm_jit_LOAD_CARRY_FOR_BRANCH_END();
void asm_jit_LOAD_CARRY_FOR_CALC();
void asm_jit_LOAD_CARRY_FOR_CALC_END();
void asm_jit_LOAD_CARRY_INV_FOR_CALC();
void asm_jit_LOAD_CARRY_INV_FOR_CALC_END();
void asm_jit_LOAD_OVERFLOW();
void asm_jit_LOAD_OVERFLOW_END();
void asm_jit_LOAD_SCRATCH_8();
void asm_jit_LOAD_SCRATCH_8_END();
void asm_jit_MODE_ABX();
void asm_jit_MODE_ABX_END();
void asm_jit_MODE_ABY();
void asm_jit_MODE_ABY_END();
void asm_jit_MODE_IND_8();
void asm_jit_MODE_IND_8_mov1_patch();
void asm_jit_MODE_IND_8_mov2_patch();
void asm_jit_MODE_IND_8_END();
void asm_jit_MODE_IND_16();
void asm_jit_MODE_IND_16_mov1_patch();
void asm_jit_MODE_IND_16_mov2_patch();
void asm_jit_MODE_IND_16_END();
void asm_jit_MODE_IND_SCRATCH_8();
void asm_jit_MODE_IND_SCRATCH_8_END();
void asm_jit_MODE_IND_SCRATCH_16();
void asm_jit_MODE_IND_SCRATCH_16_END();
void asm_jit_MODE_ZPX();
void asm_jit_MODE_ZPX_lea_patch();
void asm_jit_MODE_ZPX_END();
void asm_jit_MODE_ZPX_8bit();
void asm_jit_MODE_ZPX_8bit_lea_patch();
void asm_jit_MODE_ZPX_8bit_END();
void asm_jit_MODE_ZPY();
void asm_jit_MODE_ZPY_lea_patch();
void asm_jit_MODE_ZPY_END();
void asm_jit_MODE_ZPY_8bit();
void asm_jit_MODE_ZPY_8bit_lea_patch();
void asm_jit_MODE_ZPY_8bit_END();
void asm_jit_LOAD_OVERFLOW_END();
void asm_jit_PULL_16();
void asm_jit_PULL_16_END();
void asm_jit_PUSH_16();
void asm_jit_PUSH_16_word_patch();
void asm_jit_PUSH_16_END();
void asm_jit_SAVE_CARRY();
void asm_jit_SAVE_CARRY_END();
void asm_jit_SAVE_CARRY_INV();
void asm_jit_SAVE_CARRY_INV_END();
void asm_jit_SAVE_OVERFLOW();
void asm_jit_SAVE_OVERFLOW_END();
void asm_jit_SET_CARRY();
void asm_jit_SET_CARRY_END();
void asm_jit_SUB_ABS();
void asm_jit_SUB_ABS_END();
void asm_jit_SUB_IMM();
void asm_jit_SUB_IMM_END();
void asm_jit_SUB_ZPG();
void asm_jit_SUB_ZPG_END();
void asm_jit_WRITE_INV_ABS();
void asm_jit_WRITE_INV_ABS_offset_patch();
void asm_jit_WRITE_INV_ABS_END();
void asm_jit_WRITE_INV_SCRATCH();
void asm_jit_WRITE_INV_SCRATCH_END();
void asm_jit_WRITE_INV_SCRATCH_Y();
void asm_jit_WRITE_INV_SCRATCH_Y_END();

void asm_jit_ADC_ABS();
void asm_jit_ADC_ABS_END();
void asm_jit_ADC_ABX();
void asm_jit_ADC_ABX_END();
void asm_jit_ADC_ABY();
void asm_jit_ADC_ABY_END();
void asm_jit_ADC_IMM();
void asm_jit_ADC_IMM_END();
void asm_jit_ADC_SCRATCH();
void asm_jit_ADC_SCRATCH_END();
void asm_jit_ADC_SCRATCH_Y();
void asm_jit_ADC_SCRATCH_Y_END();
void asm_jit_ADC_ZPG();
void asm_jit_ADC_ZPG_END();
void asm_jit_ALR_IMM();
void asm_jit_ALR_IMM_patch_byte();
void asm_jit_ALR_IMM_END();
void asm_jit_AND_ABS();
void asm_jit_AND_ABS_END();
void asm_jit_AND_ABX();
void asm_jit_AND_ABX_END();
void asm_jit_AND_ABY();
void asm_jit_AND_ABY_END();
void asm_jit_AND_IMM();
void asm_jit_AND_IMM_END();
void asm_jit_AND_SCRATCH();
void asm_jit_AND_SCRATCH_END();
void asm_jit_AND_SCRATCH_Y();
void asm_jit_AND_SCRATCH_Y_END();
void asm_jit_AND_ZPG();
void asm_jit_AND_ZPG_END();
void asm_jit_ASL_ABS();
void asm_jit_ASL_ABS_END();
void asm_jit_ASL_ABS_RMW();
void asm_jit_ASL_ABS_RMW_mov1_patch();
void asm_jit_ASL_ABS_RMW_mov2_patch();
void asm_jit_ASL_ABS_RMW_END();
void asm_jit_ASL_ABX();
void asm_jit_ASL_ABX_END();
void asm_jit_ASL_ABX_RMW();
void asm_jit_ASL_ABX_RMW_mov1_patch();
void asm_jit_ASL_ABX_RMW_mov2_patch();
void asm_jit_ASL_ABX_RMW_END();
void asm_jit_ASL_ACC();
void asm_jit_ASL_ACC_END();
void asm_jit_ASL_ACC_n();
void asm_jit_ASL_ACC_n_END();
void asm_jit_ASL_scratch();
void asm_jit_ASL_scratch_END();
void asm_jit_ASL_ZPG();
void asm_jit_ASL_ZPG_END();
void asm_jit_BCC();
void asm_jit_BCC_END();
void asm_jit_BCC_8bit();
void asm_jit_BCC_8bit_END();
void asm_jit_BCS();
void asm_jit_BCS_END();
void asm_jit_BCS_8bit();
void asm_jit_BCS_8bit_END();
void asm_jit_BEQ();
void asm_jit_BEQ_END();
void asm_jit_BEQ_8bit();
void asm_jit_BEQ_8bit_END();
void asm_jit_BIT_ABS();
void asm_jit_BIT_ABS_END();
void asm_jit_BIT_ZPG();
void asm_jit_BIT_ZPG_END();
void asm_jit_BMI();
void asm_jit_BMI_END();
void asm_jit_BMI_8bit();
void asm_jit_BMI_8bit_END();
void asm_jit_BNE();
void asm_jit_BNE_END();
void asm_jit_BNE_8bit();
void asm_jit_BNE_8bit_END();
void asm_jit_BPL();
void asm_jit_BPL_END();
void asm_jit_BPL_8bit();
void asm_jit_BPL_8bit_END();
void asm_jit_BVC();
void asm_jit_BVC_END();
void asm_jit_BVC_8bit();
void asm_jit_BVC_8bit_END();
void asm_jit_BVS();
void asm_jit_BVS_END();
void asm_jit_BVS_8bit();
void asm_jit_BVS_8bit_END();
void asm_jit_CMP_ABS();
void asm_jit_CMP_ABS_END();
void asm_jit_CMP_ABX();
void asm_jit_CMP_ABX_END();
void asm_jit_CMP_ABY();
void asm_jit_CMP_ABY_END();
void asm_jit_CMP_IMM();
void asm_jit_CMP_IMM_END();
void asm_jit_CMP_SCRATCH();
void asm_jit_CMP_SCRATCH_END();
void asm_jit_CMP_SCRATCH_Y();
void asm_jit_CMP_SCRATCH_Y_END();
void asm_jit_CMP_ZPG();
void asm_jit_CMP_ZPG_END();
void asm_jit_CPX_ABS();
void asm_jit_CPX_ABS_END();
void asm_jit_CPX_IMM();
void asm_jit_CPX_IMM_END();
void asm_jit_CPX_ZPG();
void asm_jit_CPX_ZPG_END();
void asm_jit_CPY_ABS();
void asm_jit_CPY_ABS_END();
void asm_jit_CPY_IMM();
void asm_jit_CPY_IMM_END();
void asm_jit_CPY_ZPG();
void asm_jit_CPY_ZPG_END();
void asm_jit_DEC_ABS();
void asm_jit_DEC_ABS_END();
void asm_jit_DEC_ABS_RMW();
void asm_jit_DEC_ABS_RMW_mov1_patch();
void asm_jit_DEC_ABS_RMW_mov2_patch();
void asm_jit_DEC_ABS_RMW_END();
void asm_jit_DEC_ABX();
void asm_jit_DEC_ABX_END();
void asm_jit_DEC_ABX_RMW();
void asm_jit_DEC_ABX_RMW_mov1_patch();
void asm_jit_DEC_ABX_RMW_mov2_patch();
void asm_jit_DEC_ABX_RMW_END();
void asm_jit_DEC_scratch();
void asm_jit_DEC_scratch_END();
void asm_jit_DEC_ZPG();
void asm_jit_DEC_ZPG_END();
void asm_jit_EOR_ABS();
void asm_jit_EOR_ABS_END();
void asm_jit_EOR_ABX();
void asm_jit_EOR_ABX_END();
void asm_jit_EOR_ABY();
void asm_jit_EOR_ABY_END();
void asm_jit_EOR_IMM();
void asm_jit_EOR_IMM_END();
void asm_jit_EOR_SCRATCH();
void asm_jit_EOR_SCRATCH_END();
void asm_jit_EOR_SCRATCH_Y();
void asm_jit_EOR_SCRATCH_Y_END();
void asm_jit_EOR_ZPG();
void asm_jit_EOR_ZPG_END();
void asm_jit_INC_ABS();
void asm_jit_INC_ABS_END();
void asm_jit_INC_ABS_RMW();
void asm_jit_INC_ABS_RMW_mov1_patch();
void asm_jit_INC_ABS_RMW_mov2_patch();
void asm_jit_INC_ABS_RMW_END();
void asm_jit_INC_ABX();
void asm_jit_INC_ABX_END();
void asm_jit_INC_ABX_RMW();
void asm_jit_INC_ABX_RMW_mov1_patch();
void asm_jit_INC_ABX_RMW_mov2_patch();
void asm_jit_INC_ABX_RMW_END();
void asm_jit_INC_scratch();
void asm_jit_INC_scratch_END();
void asm_jit_INC_ZPG();
void asm_jit_INC_ZPG_END();
void asm_jit_JMP();
void asm_jit_JMP_END();
void asm_jit_JMP_8bit();
void asm_jit_JMP_8bit_END();
void asm_jit_LDA_IMM();
void asm_jit_LDA_IMM_END();
void asm_jit_LDA_ABS();
void asm_jit_LDA_ABS_END();
void asm_jit_LDA_ABX();
void asm_jit_LDA_ABX_END();
void asm_jit_LDA_ABY();
void asm_jit_LDA_ABY_END();
void asm_jit_LDA_SCRATCH();
void asm_jit_LDA_SCRATCH_END();
void asm_jit_LDA_SCRATCH_X();
void asm_jit_LDA_SCRATCH_X_END();
void asm_jit_LDA_SCRATCH_Y();
void asm_jit_LDA_SCRATCH_Y_END();
void asm_jit_LDA_ZPG();
void asm_jit_LDA_ZPG_END();
void asm_jit_LDX_ABS();
void asm_jit_LDX_ABS_END();
void asm_jit_LDX_ABY();
void asm_jit_LDX_ABY_END();
void asm_jit_LDX_IMM();
void asm_jit_LDX_IMM_END();
void asm_jit_LDX_scratch();
void asm_jit_LDX_scratch_END();
void asm_jit_LDX_ZPG();
void asm_jit_LDX_ZPG_END();
void asm_jit_LDY_ABS();
void asm_jit_LDY_ABS_END();
void asm_jit_LDY_ABX();
void asm_jit_LDY_ABX_END();
void asm_jit_LDY_IMM();
void asm_jit_LDY_IMM_END();
void asm_jit_LDY_scratch();
void asm_jit_LDY_scratch_END();
void asm_jit_LDY_ZPG();
void asm_jit_LDY_ZPG_END();
void asm_jit_LSR_ABS();
void asm_jit_LSR_ABS_END();
void asm_jit_LSR_ABS_RMW();
void asm_jit_LSR_ABS_RMW_mov1_patch();
void asm_jit_LSR_ABS_RMW_mov2_patch();
void asm_jit_LSR_ABS_RMW_END();
void asm_jit_LSR_ABX();
void asm_jit_LSR_ABX_END();
void asm_jit_LSR_ABX_RMW();
void asm_jit_LSR_ABX_RMW_mov1_patch();
void asm_jit_LSR_ABX_RMW_mov2_patch();
void asm_jit_LSR_ABX_RMW_END();
void asm_jit_LSR_ACC();
void asm_jit_LSR_ACC_END();
void asm_jit_LSR_ACC_n();
void asm_jit_LSR_ACC_n_END();
void asm_jit_LSR_scratch();
void asm_jit_LSR_scratch_END();
void asm_jit_LSR_ZPG();
void asm_jit_LSR_ZPG_END();
void asm_jit_ORA_ABS();
void asm_jit_ORA_ABS_END();
void asm_jit_ORA_ABX();
void asm_jit_ORA_ABX_END();
void asm_jit_ORA_ABY();
void asm_jit_ORA_ABY_END();
void asm_jit_ORA_IMM();
void asm_jit_ORA_IMM_END();
void asm_jit_ORA_SCRATCH();
void asm_jit_ORA_SCRATCH_END();
void asm_jit_ORA_SCRATCH_Y();
void asm_jit_ORA_SCRATCH_Y_END();
void asm_jit_ORA_ZPG();
void asm_jit_ORA_ZPG_END();
void asm_jit_ROL_ABS();
void asm_jit_ROL_ABS_END();
void asm_jit_ROL_ABS_RMW();
void asm_jit_ROL_ABS_RMW_mov1_patch();
void asm_jit_ROL_ABS_RMW_mov2_patch();
void asm_jit_ROL_ABS_RMW_END();
void asm_jit_ROL_ABX_RMW();
void asm_jit_ROL_ABX_RMW_mov1_patch();
void asm_jit_ROL_ABX_RMW_mov2_patch();
void asm_jit_ROL_ABX_RMW_END();
void asm_jit_ROL_ACC();
void asm_jit_ROL_ACC_END();
void asm_jit_ROL_ACC_n();
void asm_jit_ROL_ACC_n_END();
void asm_jit_ROL_scratch();
void asm_jit_ROL_scratch_END();
void asm_jit_ROL_ZPG();
void asm_jit_ROL_ZPG_END();
void asm_jit_ROR_ABS();
void asm_jit_ROR_ABS_END();
void asm_jit_ROR_ABS_RMW();
void asm_jit_ROR_ABS_RMW_mov1_patch();
void asm_jit_ROR_ABS_RMW_mov2_patch();
void asm_jit_ROR_ABS_RMW_END();
void asm_jit_ROR_ABX_RMW();
void asm_jit_ROR_ABX_RMW_mov1_patch();
void asm_jit_ROR_ABX_RMW_mov2_patch();
void asm_jit_ROR_ABX_RMW_END();
void asm_jit_ROR_ACC();
void asm_jit_ROR_ACC_END();
void asm_jit_ROR_ACC_n();
void asm_jit_ROR_ACC_n_END();
void asm_jit_ROR_scratch();
void asm_jit_ROR_scratch_END();
void asm_jit_ROR_ZPG();
void asm_jit_ROR_ZPG_END();
void asm_jit_SAX_ABS();
void asm_jit_SAX_ABS_END();
void asm_jit_SBC_ABS();
void asm_jit_SBC_ABS_END();
void asm_jit_SBC_ABX();
void asm_jit_SBC_ABX_END();
void asm_jit_SBC_ABY();
void asm_jit_SBC_ABY_END();
void asm_jit_SBC_IMM();
void asm_jit_SBC_IMM_END();
void asm_jit_SBC_SCRATCH();
void asm_jit_SBC_SCRATCH_END();
void asm_jit_SBC_SCRATCH_Y();
void asm_jit_SBC_SCRATCH_Y_END();
void asm_jit_SBC_ZPG();
void asm_jit_SBC_ZPG_END();
void asm_jit_SHY_ABX();
void asm_jit_SHY_ABX_byte_patch();
void asm_jit_SHY_ABX_mov_patch();
void asm_jit_SHY_ABX_END();
void asm_jit_SLO_ABS();
void asm_jit_SLO_ABS_mov1_patch();
void asm_jit_SLO_ABS_mov2_patch();
void asm_jit_SLO_ABS_END();
void asm_jit_STA_ABS();
void asm_jit_STA_ABS_END();
void asm_jit_STA_ABX();
void asm_jit_STA_ABX_END();
void asm_jit_STA_ABY();
void asm_jit_STA_ABY_END();
void asm_jit_STA_SCRATCH();
void asm_jit_STA_SCRATCH_END();
void asm_jit_STA_SCRATCH_Y();
void asm_jit_STA_SCRATCH_Y_END();
void asm_jit_STA_ZPG();
void asm_jit_STA_ZPG_END();
void asm_jit_STX_ABS();
void asm_jit_STX_ABS_END();
void asm_jit_STX_scratch();
void asm_jit_STX_scratch_END();
void asm_jit_STX_ZPG();
void asm_jit_STX_ZPG_END();
void asm_jit_STY_ABS();
void asm_jit_STY_ABS_END();
void asm_jit_STY_scratch();
void asm_jit_STY_scratch_END();
void asm_jit_STY_ZPG();
void asm_jit_STY_ZPG_END();

#endif /* BEEBJIT_ASM_JIT_H */
