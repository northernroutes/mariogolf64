/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

/* The 6x6 table at 0x1320 of the object returned by func_8005AF50
 * (Unk8012F720.unk1320 in 34FA0.c). Placeholder. */
typedef struct Unk8005AF50_15F250 {
    /* 0x0000 */ u8 pad0[0x1320];
    /* 0x1320 */ s8 unk1320[6][6];
} Unk8005AF50_15F250;

Unk8005AF50_15F250 *func_8005AF50(void);
s32 func_800299F4(s32);

/* 1..6 from how many of the 36 entries are positive (6 if flag 0x5E is set). */
s32 func_ovl13_80241800(void) {
    Unk8005AF50_15F250 *obj = func_8005AF50();
    s32 n = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            n += obj->unk1320[i][j] > 0;
        }
    }
    if (func_800299F4(0x5E)) {
        return 6;
    }
    if (n >= 20) {
        return 6;
    }
    if (n >= 16) {
        return 5;
    }
    if (n >= 12) {
        return 4;
    }
    if (n >= 8) {
        return 3;
    }
    if (n >= 4) {
        return 2;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_802418B8);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80241BD8);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80241CE8);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80241DF0);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80241FF0);

extern s32 D_ovl13_80243EE0;

s32 func_ovl13_80242374(void) {
    return D_ovl13_80243EE0 == 0;
}

extern s32 D_ovl13_80243EE4;

void func_ovl13_80242384(s32 arg0) {
    if (D_ovl13_80243EE4 != arg0) {
        D_ovl13_80243EE4 = arg0;
    }
}

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_802423A4);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_802427E8);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80242D40);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80243610);

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80243784);
