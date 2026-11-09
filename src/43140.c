#include "common.h"

extern s32 D_800C3600;

void func_80067D40(s32 arg0) {
    D_800C3600 = arg0;
}

extern s32 D_800C3600;

void func_80067D4C(void) {
    D_800C3600 = (D_800C3600 * 0x5D588B65) + 1;
}

INCLUDE_ASM("asm/nonmatchings/43140", func_80067D74);

INCLUDE_ASM("asm/nonmatchings/43140", func_800680FC);

INCLUDE_ASM("asm/nonmatchings/43140", func_80068308);
