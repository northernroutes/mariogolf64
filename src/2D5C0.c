#include "common.h"

extern s32 D_801B60AC;

s32 func_800521C0(void) {
    return -((D_801B60AC & 2) != 0) & 9;
}

extern s32 D_801B60AC;
s32 func_800299F4(u32 n);

s32 func_800521DC(void) {
    if (func_800299F4(0x3D)) {
        return 2;
    }
    if (D_801B60AC & 6) {
        return 9;
    }
    return 18;
}

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

/* Defined as (void) in 2D290.c; func_80052264 passes it an argument anyway. */
s32 func_80051FCC();
extern s8 D_800C1434[][20][10];

s32 func_80052264(s32 arg0, s32 arg1, s32 arg2) {
    s32 q = -arg2 / 18;

    arg2 %= 18;
    return q - (arg2 >= D_800C1434[func_80051FCC(arg0)][arg1][1]);
}

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

void func_8005B150(s32 *vals, s32 *order, s32 n);

/* For each of the 8 tables, ranks the 18 [h][1] values (via func_8005B150's
 * ordering) and writes the ranks 18..1 back into [h][1]. */
void func_80052384(void) {
    s32 vals[18];
    s32 order[18];
    s32 k;
    s32 h;

    for (k = 0; k < 8; k++) {
        for (h = 0; h < 18; h++) {
            vals[h] = D_800C1434[k][h][1];
        }
        func_8005B150(vals, order, 18);
        for (h = 0; h < 18; h++) {
            D_800C1434[k][order[h]][1] = 18 - h;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_8005244C);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_800525C4);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052834);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052A68);

INCLUDE_ASM("asm/nonmatchings/2D5C0", func_80052CF0);
