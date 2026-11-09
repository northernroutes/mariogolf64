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

/* 0xB8-byte player records at D_801B71D0. Placeholder. */
typedef struct Unk801B71D0_2D5C0 {
    /* 0x00 */ u8 pad0[0x23];
    /* 0x23 */ s8 unk23;
    /* 0x24 */ u8 pad24[0x5];
    /* 0x29 */ s8 unk29;
    /* 0x2A */ u8 pad2A[0x8E];
} Unk801B71D0_2D5C0; /* size = 0xB8 */

extern Unk801B71D0_2D5C0 D_801B71D0[];
extern s32 D_801B6094;
extern s32 D_801B6098;
s32 func_80052264(s32, s32, s32);

s32 func_80052324(s32 i) {
    return D_801B71D0[i].unk23 + func_80052264(D_801B6094, D_801B6098, D_801B71D0[i].unk29);
}

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052384);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_8005244C);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_800525C4);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052834);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052A68);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052CF0);
