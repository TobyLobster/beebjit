#ifndef BEEBJIT_ASM_X64_JIT_DEFS_H
#define BEEBJIT_ASM_X64_JIT_DEFS_H

#include "asm_x64_defs.h"

#define K_BBC_JIT_ADDR                     0x20000000
#define K_JIT_CONTEXT_OFFSET_JIT_CALLBACK  (K_CONTEXT_OFFSET_DRIVER_END + 0)
#define K_JIT_CONTEXT_OFFSET_JIT_PTRS      (K_CONTEXT_OFFSET_DRIVER_END + 8)

#endif /* BEEBJIT_ASM_X64_JIT_DEFS_H */

