#include "common.h"

/* 0x1C-byte entries of D_800B790C. Placeholder. */
typedef struct Unk800B790C {
    /* 0x00 */ u8 pad0[0x1C];
} Unk800B790C;

extern Unk800B790C D_800B790C[27];

/* Entry n, or entry 0 if n is out of range. */
Unk800B790C *func_80032E60(u32 n) {
    n = (n < 27) ? n : 0;
    return &D_800B790C[n];
}

INCLUDE_ASM("asm/nonmatchings/E260", func_80032E88);

INCLUDE_ASM("asm/nonmatchings/E260", func_80032F70);

INCLUDE_ASM("asm/nonmatchings/E260", func_80032FE8);

INCLUDE_ASM("asm/nonmatchings/E260", func_800330D0);

INCLUDE_ASM("asm/nonmatchings/E260", func_80033134);

INCLUDE_ASM("asm/nonmatchings/E260", func_80033228);

INCLUDE_ASM("asm/nonmatchings/E260", func_8003327C);

INCLUDE_ASM("asm/nonmatchings/E260", func_80037E50);

INCLUDE_ASM("asm/nonmatchings/E260", func_80037EE0);

INCLUDE_ASM("asm/nonmatchings/E260", func_80037F94);
