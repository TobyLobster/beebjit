#ifndef JIT_OPCODE_H
#define JIT_OPCODE_H

#include "asm/asm_opcodes.h"

#include <stdint.h>

enum {
  k_max_uops_per_opcode = 16,
};

struct jit_opcode_details {
  /* Static details. */
  int32_t addr_6502;
  uint8_t opcode_6502;
  uint16_t operand_6502;
  uint8_t num_bytes_6502;
  uint8_t max_cycles;
  int branches;
  uint16_t branch_addr_6502;
  int32_t min_6502_addr;
  int32_t max_6502_addr;

  /* Partially dynamic details that may be changed by optimization. */
  uint8_t num_uops;
  struct asm_uop uops[k_max_uops_per_opcode];
  int has_prefix_uop;
  int has_postfix_uop;

  /* Dynamic details that are calculated as compilation proceeds. */
  int ends_block;
  void* p_host_address_prefix_end;
  void* p_host_address_start;
  int32_t cycles_run_start;
  int32_t reg_a;
  int32_t reg_x;
  int32_t reg_y;
  int32_t flag_carry;
  int32_t flag_decimal;
  uint8_t num_fixup_uops;
  struct asm_uop* fixup_uops[k_max_uops_per_opcode];
  int self_modify_invalidated;
  int is_dynamic_opcode;
  int is_dynamic_operand;
  int is_branch_landing_addr;
  int is_post_branch_addr;
};

void jit_opcode_find_replace1(struct jit_opcode_details* p_opcode,
                              int32_t find_uop,
                              int32_t uop1,
                              int32_t value1);
void jit_opcode_find_replace2(struct jit_opcode_details* p_opcode,
                              int32_t find_uop,
                              int32_t uop1,
                              int32_t value1,
                              int32_t uop2,
                              int32_t value2);

void jit_opcode_make_uop1(struct asm_uop* p_uop,
                          int32_t uopcode,
                          int32_t value1);

struct asm_uop* jit_opcode_find_uop(struct jit_opcode_details* p_opcode,
                                    int32_t uopcode);

void jit_opcode_erase_uop(struct jit_opcode_details* p_opcode, int32_t uopcode);

struct asm_uop* jit_opcode_insert_uop(struct jit_opcode_details* p_opcode,
                                      uint32_t index,
                                      int32_t uopcode,
                                      int32_t value);

void jit_opcode_eliminate(struct jit_opcode_details* p_opcode);

#endif /* JIT_OPCODE_H */
