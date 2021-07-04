#ifndef BEEBJIT_ASM_INTURBO_H
#define BEEBJIT_ASM_INTURBO_H

#include <stdint.h>

struct util_buffer;

int asm_inturbo_is_enabled(void);
void asm_emit_inturbo_save_countdown(struct util_buffer* p_buf);
void asm_emit_inturbo_epilog(struct util_buffer* p_buf);
void asm_emit_inturbo_check_special_address(struct util_buffer* p_buf,
                                            uint16_t special_mode_above);
void asm_emit_inturbo_check_countdown(struct util_buffer* p_buf,
                                      uint8_t opcycles);
void asm_emit_inturbo_commit_branch(struct util_buffer* p_buf);
void asm_emit_inturbo_check_decimal(struct util_buffer* p_buf);
void asm_emit_inturbo_check_interrupt(struct util_buffer* p_buf);
void asm_emit_inturbo_advance_pc_and_next(struct util_buffer* p_buf,
                                          uint8_t advance);
void asm_emit_inturbo_advance_pc_and_ret(struct util_buffer* p_buf,
                                         uint8_t advance);
void asm_emit_inturbo_enter_debug(struct util_buffer* p_buf);
void asm_emit_inturbo_call_interp(struct util_buffer* p_buf);
void asm_emit_inturbo_do_write_invalidation(struct util_buffer* p_buf);

void asm_emit_inturbo_mode_rel(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_zpg(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_abs(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_abx(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_abx_check_page_crossing(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_aby(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_aby_check_page_crossing(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_zpx(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_zpy(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_idx(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_idy(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_idy_check_page_crossing(struct util_buffer* p_buf);
void asm_emit_inturbo_mode_ind(struct util_buffer* p_buf);

void asm_emit_instruction_ADC_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ADC_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ALR_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_AND_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_AND_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ASL_acc_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ASL_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BCC_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BCC_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BCS_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BCS_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BEQ_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BEQ_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BIT_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BMI_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BMI_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BNE_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BNE_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BPL_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BPL_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BRK_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BVC_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BVC_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_BVS_interp(struct util_buffer* p_buf);
void asm_emit_instruction_BVS_interp_accurate(struct util_buffer* p_buf);
void asm_emit_instruction_CMP_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_CMP_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_CPX_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_CPX_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_CPY_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_CPY_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_DEC_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_EOR_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_EOR_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_INC_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_JMP_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_JSR_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDA_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDA_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDX_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDX_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDY_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LDY_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LSR_acc_interp(struct util_buffer* p_buf);
void asm_emit_instruction_LSR_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ORA_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ORA_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ROL_acc_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ROL_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ROR_acc_interp(struct util_buffer* p_buf);
void asm_emit_instruction_ROR_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_RTI_interp(struct util_buffer* p_buf);
void asm_emit_instruction_RTS_interp(struct util_buffer* p_buf);
void asm_emit_instruction_SAX_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_SBC_imm_interp(struct util_buffer* p_buf);
void asm_emit_instruction_SBC_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_SLO_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_STA_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_STX_scratch_interp(struct util_buffer* p_buf);
void asm_emit_instruction_STY_scratch_interp(struct util_buffer* p_buf);

/* Symbols pointing directly to ASM bytes. */
void asm_inturbo_check_special_address();
void asm_inturbo_check_special_address_END();
void asm_inturbo_check_special_address_lea_patch();
void asm_inturbo_check_special_address_jb_patch();
void asm_inturbo_check_countdown();
void asm_inturbo_check_countdown_END();
void asm_inturbo_check_countdown_lea_patch();
void asm_inturbo_check_countdown_jb_patch();
void asm_inturbo_check_countdown_with_page_crossing();
void asm_inturbo_check_countdown_with_page_crossing_END();
void asm_inturbo_check_countdown_with_page_crossing_lea_patch();
void asm_inturbo_check_countdown_with_page_crossing_jb_patch();
void asm_inturbo_check_decimal();
void asm_inturbo_check_decimal_END();
void asm_inturbo_check_decimal_jb_patch();
void asm_inturbo_load_opcode();
void asm_inturbo_load_opcode_END();
void asm_inturbo_load_opcode_mov_patch();
void asm_inturbo_advance_pc();
void asm_inturbo_advance_pc_END();
void asm_inturbo_advance_pc_lea_patch();
void asm_inturbo_jump_opcode();
void asm_inturbo_jump_opcode_END();

void asm_inturbo_JMP_scratch_plus_1_interp();
void asm_inturbo_JMP_scratch_plus_1_interp_END();
void asm_inturbo_load_pc_from_pc();
void asm_inturbo_load_pc_from_pc_END();
void asm_inturbo_call_interp();
void asm_inturbo_call_interp_countdown();
void asm_inturbo_check_interrupt();
void asm_inturbo_check_interrupt_END();
void asm_inturbo_check_interrupt_jae_patch();
void asm_inturbo_jump_call_interp();
void asm_inturbo_jump_call_interp_END();
void asm_inturbo_jump_call_interp_jmp_patch();
void asm_inturbo_pc_plus_2_to_scratch();
void asm_inturbo_pc_plus_2_to_scratch_END();
void asm_inturbo_interrupt_vector();
void asm_inturbo_interrupt_vector_END();
void asm_inturbo_do_special_addr();

void asm_inturbo_mode_nil();
void asm_inturbo_mode_nil_END();
void asm_inturbo_mode_imm();
void asm_inturbo_mode_imm_END();
void asm_inturbo_mode_zpg();
void asm_inturbo_mode_zpg_END();
void asm_inturbo_mode_abs();
void asm_inturbo_mode_abs_END();
void asm_inturbo_mode_abs_lea_patch();
void asm_inturbo_mode_abs_jb_patch();
void asm_inturbo_mode_abx();
void asm_inturbo_mode_abx_END();
void asm_inturbo_mode_abx_check_page_crossing();
void asm_inturbo_mode_abx_check_page_crossing_END();
void asm_inturbo_mode_aby();
void asm_inturbo_mode_aby_END();
void asm_inturbo_mode_aby_check_page_crossing();
void asm_inturbo_mode_aby_check_page_crossing_END();
void asm_inturbo_mode_zpx();
void asm_inturbo_mode_zpx_END();
void asm_inturbo_mode_zpy();
void asm_inturbo_mode_zpy_END();
void asm_inturbo_mode_idx();
void asm_inturbo_mode_idx_jump_patch();
void asm_inturbo_mode_idx_END();
void asm_inturbo_mode_idy();
void asm_inturbo_mode_idy_jump_patch();
void asm_inturbo_mode_idy_END();
void asm_inturbo_mode_idy_check_page_crossing();
void asm_inturbo_mode_idy_check_page_crossing_END();
void asm_inturbo_mode_ind();
void asm_inturbo_mode_ind_END();

void asm_instruction_Bxx_interp_accurate();
void asm_instruction_Bxx_interp_accurate_END();
void asm_instruction_Bxx_interp_accurate_not_taken_target();
void asm_instruction_Bxx_interp_accurate_jb_patch();

void asm_instruction_ADC_imm_interp();
void asm_instruction_ADC_imm_interp_END();
void asm_instruction_ADC_scratch_interp();
void asm_instruction_ADC_scratch_interp_END();
void asm_instruction_ALR_imm_interp();
void asm_instruction_ALR_imm_interp_END();
void asm_instruction_AND_imm_interp();
void asm_instruction_AND_imm_interp_END();
void asm_instruction_AND_scratch_interp();
void asm_instruction_AND_scratch_interp_END();
void asm_instruction_ASL_acc_interp();
void asm_instruction_ASL_acc_interp_END();
void asm_instruction_ASL_scratch_interp();
void asm_instruction_ASL_scratch_interp_END();
void asm_instruction_BCC_interp();
void asm_instruction_BCC_interp_END();
void asm_instruction_BCC_interp_accurate();
void asm_instruction_BCC_interp_accurate_END();
void asm_instruction_BCC_interp_accurate_jump_patch();
void asm_instruction_BCS_interp();
void asm_instruction_BCS_interp_END();
void asm_instruction_BCS_interp_accurate();
void asm_instruction_BCS_interp_accurate_END();
void asm_instruction_BCS_interp_accurate_jump_patch();
void asm_instruction_BEQ_interp();
void asm_instruction_BEQ_interp_END();
void asm_instruction_BEQ_interp_accurate();
void asm_instruction_BEQ_interp_accurate_END();
void asm_instruction_BEQ_interp_accurate_jump_patch();
void asm_instruction_BIT_interp();
void asm_instruction_BIT_interp_END();
void asm_instruction_BMI_interp();
void asm_instruction_BMI_interp_END();
void asm_instruction_BMI_interp_accurate();
void asm_instruction_BMI_interp_accurate_END();
void asm_instruction_BMI_interp_accurate_jump_patch();
void asm_instruction_BNE_interp();
void asm_instruction_BNE_interp_END();
void asm_instruction_BNE_interp_accurate();
void asm_instruction_BNE_interp_accurate_END();
void asm_instruction_BNE_interp_accurate_jump_patch();
void asm_instruction_BPL_interp();
void asm_instruction_BPL_interp_END();
void asm_instruction_BPL_interp_accurate();
void asm_instruction_BPL_interp_accurate_END();
void asm_instruction_BPL_interp_accurate_jump_patch();
void asm_instruction_BVC_interp();
void asm_instruction_BVC_interp_END();
void asm_instruction_BVC_interp_accurate();
void asm_instruction_BVC_interp_accurate_END();
void asm_instruction_BVC_interp_accurate_jump_patch();
void asm_instruction_BVS_interp();
void asm_instruction_BVS_interp_END();
void asm_instruction_BVS_interp_accurate();
void asm_instruction_BVS_interp_accurate_END();
void asm_instruction_BVS_interp_accurate_jump_patch();
void asm_instruction_CMP_imm_interp();
void asm_instruction_CMP_imm_interp_END();
void asm_instruction_CMP_scratch_interp();
void asm_instruction_CMP_scratch_interp_END();
void asm_instruction_CPX_imm_interp();
void asm_instruction_CPX_imm_interp_END();
void asm_instruction_CPX_scratch_interp();
void asm_instruction_CPX_scratch_interp_END();
void asm_instruction_CPY_imm_interp();
void asm_instruction_CPY_imm_interp_END();
void asm_instruction_CPY_scratch_interp();
void asm_instruction_CPY_scratch_interp_END();
void asm_instruction_DEC_scratch_interp();
void asm_instruction_DEC_scratch_interp_END();
void asm_instruction_EOR_imm_interp();
void asm_instruction_EOR_imm_interp_END();
void asm_instruction_EOR_scratch_interp();
void asm_instruction_EOR_scratch_interp_END();
void asm_instruction_INC_scratch_interp();
void asm_instruction_INC_scratch_interp_END();
void asm_instruction_JMP_scratch_interp();
void asm_instruction_JMP_scratch_interp_END();
void asm_instruction_JSR_scratch_interp();
void asm_instruction_JSR_scratch_interp_END();
void asm_instruction_LDA_imm_interp();
void asm_instruction_LDA_imm_interp_END();
void asm_instruction_LDA_scratch_interp();
void asm_instruction_LDA_scratch_interp_END();
void asm_instruction_LDX_imm_interp();
void asm_instruction_LDX_imm_interp_END();
void asm_instruction_LDX_scratch_interp();
void asm_instruction_LDX_scratch_interp_END();
void asm_instruction_LDY_imm_interp();
void asm_instruction_LDY_imm_interp_END();
void asm_instruction_LDY_scratch_interp();
void asm_instruction_LDY_scratch_interp_END();
void asm_instruction_LSR_acc_interp();
void asm_instruction_LSR_acc_interp_END();
void asm_instruction_LSR_scratch_interp();
void asm_instruction_LSR_scratch_interp_END();
void asm_instruction_ORA_imm_interp();
void asm_instruction_ORA_imm_interp_END();
void asm_instruction_ORA_scratch_interp();
void asm_instruction_ORA_scratch_interp_END();
void asm_instruction_ROL_acc_interp();
void asm_instruction_ROL_acc_interp_END();
void asm_instruction_ROL_scratch_interp();
void asm_instruction_ROL_scratch_interp_END();
void asm_instruction_ROR_acc_interp();
void asm_instruction_ROR_acc_interp_END();
void asm_instruction_ROR_scratch_interp();
void asm_instruction_ROR_scratch_interp_END();
void asm_instruction_SAX_scratch_interp();
void asm_instruction_SAX_scratch_interp_END();
void asm_instruction_SBC_imm_interp();
void asm_instruction_SBC_imm_interp_END();
void asm_instruction_SBC_scratch_interp();
void asm_instruction_SBC_scratch_interp_END();
void asm_instruction_SLO_scratch_interp();
void asm_instruction_SLO_scratch_interp_END();
void asm_instruction_STA_scratch_interp();
void asm_instruction_STA_scratch_interp_END();
void asm_instruction_STX_scratch_interp();
void asm_instruction_STX_scratch_interp_END();
void asm_instruction_STY_scratch_interp();
void asm_instruction_STY_scratch_interp_END();

#endif /* BEEBJIT_ASM_INTURBO_H */
