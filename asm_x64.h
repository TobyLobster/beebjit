#ifndef BEEBJIT_ASM_X64_H
#define BEEBJIT_ASM_X64_H

#include <stddef.h>
#include <stdint.h>

struct util_buffer;

size_t asm_x64_copy(struct util_buffer* p_buf, void* p_start, void* p_end);

void asm_x64_asm_enter(void* p_context, uint32_t jump_addr_x64);
void asm_x64_asm_debug();

void asm_x64_emit_instruction_CRASH(struct util_buffer* p_buf);
void asm_x64_emit_instruction_REAL_NOP(struct util_buffer* p_buf);
void asm_x64_emit_instruction_TRAP(struct util_buffer* p_buf);

void asm_x64_emit_instruction_CLD(struct util_buffer* p_buf);
void asm_x64_emit_instruction_PHP(struct util_buffer* p_buf);
void asm_x64_emit_instruction_PLP(struct util_buffer* p_buf);
void asm_x64_emit_instruction_TSX(struct util_buffer* p_buf);
void asm_x64_emit_instruction_TXS(struct util_buffer* p_buf);

void asm_x64_emit_instruction_BCS_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_BEQ_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_BMI_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_BNE_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_CMP_imm_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_CMP_scratch_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_CPX_imm_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_CPX_scratch_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_JMP_scratch_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_LDA_imm_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_LDA_scratch_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_LDX_imm_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_LDX_scratch_interp(struct util_buffer* p_buf);
void asm_x64_emit_instruction_STA_scratch_interp(struct util_buffer* p_buf);

void asm_x64_emit_instruction_A_NZ_flags(struct util_buffer* p_buf);
void asm_x64_emit_instruction_X_NZ_flags(struct util_buffer* p_buf);
void asm_x64_emit_instruction_Y_NZ_flags(struct util_buffer* p_buf);

void asm_x64_emit_inturbo_next_opcode(struct util_buffer* p_buf);

/* Symbols pointing directly to ASM bytes. */
void asm_x64_instruction_CRASH();
void asm_x64_instruction_CRASH_END();
void asm_x64_instruction_EXIT();
void asm_x64_instruction_EXIT_END();
void asm_x64_instruction_REAL_NOP();
void asm_x64_instruction_REAL_NOP_END();
void asm_x64_instruction_TRAP();
void asm_x64_instruction_TRAP_END();

void asm_x64_instruction_CLD();
void asm_x64_instruction_CLD_END();
void asm_x64_instruction_TAX();
void asm_x64_instruction_TAX_END();
void asm_x64_instruction_TAY();
void asm_x64_instruction_TAY_END();
void asm_x64_instruction_TSX();
void asm_x64_instruction_TSX_END();
void asm_x64_instruction_TXS();
void asm_x64_instruction_TXS_END();

void asm_x64_instruction_A_NZ_flags();
void asm_x64_instruction_A_NZ_flags_END();
void asm_x64_instruction_X_NZ_flags();
void asm_x64_instruction_X_NZ_flags_END();
void asm_x64_instruction_Y_NZ_flags();
void asm_x64_instruction_Y_NZ_flags_END();

void asm_x64_instruction_BCS_interp();
void asm_x64_instruction_BCS_interp_END();
void asm_x64_instruction_BEQ_interp();
void asm_x64_instruction_BEQ_interp_END();
void asm_x64_instruction_BMI_interp();
void asm_x64_instruction_BMI_interp_END();
void asm_x64_instruction_BNE_interp();
void asm_x64_instruction_BNE_interp_END();
void asm_x64_instruction_CMP_imm_interp();
void asm_x64_instruction_CMP_imm_interp_END();
void asm_x64_instruction_CMP_scratch_interp();
void asm_x64_instruction_CMP_scratch_interp_END();
void asm_x64_instruction_CPX_imm_interp();
void asm_x64_instruction_CPX_imm_interp_END();
void asm_x64_instruction_CPX_scratch_interp();
void asm_x64_instruction_CPX_scratch_interp_END();
void asm_x64_instruction_JMP_scratch_interp();
void asm_x64_instruction_JMP_scratch_interp_END();
void asm_x64_instruction_LDA_imm_interp();
void asm_x64_instruction_LDA_imm_interp_END();
void asm_x64_instruction_LDA_scratch_interp();
void asm_x64_instruction_LDA_scratch_interp_END();
void asm_x64_instruction_LDX_imm_interp();
void asm_x64_instruction_LDX_imm_interp_END();
void asm_x64_instruction_LDX_scratch_interp();
void asm_x64_instruction_LDX_scratch_interp_END();
void asm_x64_instruction_STA_scratch_interp();
void asm_x64_instruction_STA_scratch_interp_END();

void asm_x64_asm_emit_intel_flags_to_scratch();
void asm_x64_asm_emit_intel_flags_to_scratch_END();
void asm_x64_asm_set_intel_flags_from_scratch();
void asm_x64_asm_set_intel_flags_from_scratch_END();
void asm_x64_set_brk_flag_in_scratch();
void asm_x64_set_brk_flag_in_scratch_END();
void asm_x64_push_from_scratch();
void asm_x64_push_from_scratch_END();
void asm_x64_pull_to_scratch();
void asm_x64_pull_to_scratch_END();

void asm_x64_inturbo_next_opcode();
void asm_x64_inturbo_next_opcode_END();
void asm_x64_inturbo_enter_debug();
void asm_x64_inturbo_enter_debug_END();
void asm_x64_inturbo_mode_nil();
void asm_x64_inturbo_mode_nil_END();
void asm_x64_inturbo_mode_imm();
void asm_x64_inturbo_mode_imm_END();
void asm_x64_inturbo_mode_zpg();
void asm_x64_inturbo_mode_zpg_END();
void asm_x64_inturbo_mode_abs();
void asm_x64_inturbo_mode_abs_END();

#endif /* BEEBJIT_ASM_X64_H */
