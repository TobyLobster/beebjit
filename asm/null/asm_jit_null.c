#include "../asm_jit.h"

int
asm_jit_is_enabled(void) {
  return 0;
}

void
asm_jit_test_preconditions(void) {
}

int
asm_jit_supports_optimizer(void) {
  return 0;
}

int
asm_jit_supports_uopcode(int32_t uopcode) {
  (void) uopcode;
  return 0;
}

struct asm_jit_struct*
asm_jit_create(void* p_jit_base,
               int (*is_memory_always_ram)(void* p, uint16_t addr),
               void* p_memory_object) {
  (void) p_jit_base;
  (void) is_memory_always_ram;
  (void) p_memory_object;
  return NULL;
}

void
asm_jit_destroy(struct asm_jit_struct* p_asm) {
  (void) p_asm;
}

void*
asm_jit_get_private(struct asm_jit_struct* p_asm) {
  (void) p_asm;
  return NULL;
}

void
asm_jit_start_code_updates(struct asm_jit_struct* p_asm) {
  (void) p_asm;
}

void
asm_jit_finish_code_updates(struct asm_jit_struct* p_asm) {
  (void) p_asm;
}

int
asm_jit_handle_fault(struct asm_jit_struct* p_asm,
                     uintptr_t* p_pc,
                     uint16_t addr_6502,
                     void* p_fault_addr,
                     int is_write) {
  (void) p_asm;
  (void) p_pc;
  (void) addr_6502;
  (void) p_fault_addr;
  (void) is_write;
  return 0;
}

void
asm_jit_invalidate_code_at(void* p) {
  (void) p;
}

int
asm_jit_is_invalidated_code_at(void* p) {
  (void) p;
  return 0;
}

void
asm_emit_jit(struct asm_jit_struct* p_asm,
             struct util_buffer* p_buf,
             struct util_buffer* p_buf_epilog,
             int32_t uopcode,
             uint32_t arg1,
             uint32_t arg2) {
  (void) p_asm;
  (void) p_buf;
  (void) p_buf_epilog;
  (void) uopcode;
  (void) arg1;
  (void) arg2;
}
