#include "common.h"

extern s32 D_801B60AC;

s32 func_800521C0(void) {
    return -((D_801B60AC & 2) != 0) & 9;
}

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_800521DC);

s32 func_800521C0();
s32 func_800521DC();

s32 func_80052220(void) {
    s32 temp_s0;

    temp_s0 = func_800521C0();
    return (temp_s0 + func_800521DC()) - 1;
}

extern s32 D_801B6094;

s32 func_80052250(void) {
    return D_801B6094 == 0xC;
}

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052264);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052324);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052384);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_8005244C);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_800525C4);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052834);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052A68);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052CF0);
