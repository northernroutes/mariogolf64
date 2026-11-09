#include "common.h"

INCLUDE_ASM("asm/nonmatchings/15F250", func_ovl13_80241800);

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
