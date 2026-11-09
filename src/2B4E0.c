#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2B4E0", func_800500E0);

extern s32 D_800C0E50;
extern s32 D_80132370[];

void func_80050274(s32 arg0) {
    s32 i = D_800C0E50;

    D_80132370[i] = arg0;
    D_800C0E50 = i + 1;
}

INCLUDE_ASM("asm/nonmatchings/2B4E0", func_8005029C);
