#include "common.h"

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206680);

/* 0x1C-byte entries of D_ovl7_8020B564. Placeholder. */
typedef struct UnkOvl7_8020B564 {
    /* 0x00 */ u8 pad0[0x1C];
} UnkOvl7_8020B564;

extern UnkOvl7_8020B564 D_ovl7_8020B564[27];

/* Entry n, or entry 0 if n is out of range. */
UnkOvl7_8020B564 *func_ovl7_802066F0(u32 n) {
    n = (n < 27) ? n : 0;
    return &D_ovl7_8020B564[n];
}

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206718);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206800);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_802068B4);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_802068EC);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206910);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206968);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206A50);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206AA4);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_8020A474);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_8020A488);
