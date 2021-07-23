#ifndef BEEBJIT_ASM_JIT_H
#define BEEBJIT_ASM_JIT_H

#include <stdint.h>

struct util_buffer;

struct asm_jit_struct;

int asm_jit_is_enabled(void);
void asm_jit_test_preconditions(void);
int asm_jit_supports_optimizer(void);
int asm_jit_supports_uopcode(int32_t uopcode);
uint32_t asm_jit_enter(void* p_context,
                       uint32_t jump_addr_x64,
                       int64_t countdown,
                       void* p_mem_base);

struct asm_jit_struct* asm_jit_init(void* p_jit_base);
void asm_jit_destroy(struct asm_jit_struct* p_asm);
void asm_jit_start_code_updates(struct asm_jit_struct* p_asm);
void asm_jit_finish_code_updates(struct asm_jit_struct* p_asm);
int asm_jit_handle_fault(struct asm_jit_struct* p_asm,
                         uintptr_t* p_pc,
                         uint16_t addr_6502,
                         void* p_fault_addr,
                         int is_write);

void asm_jit_invalidate_code_at(void* p);

void asm_emit_jit_invalidated(struct util_buffer* p_buf);
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
void asm_emit_jit_CHECK_BCD(struct util_buffer* p_buf,
                            struct util_buffer* p_epilog_buf,
                            uint16_t addr);
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

#endif /* BEEBJIT_ASM_JIT_H */
