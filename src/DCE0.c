#include "common.h"

INCLUDE_ASM("asm/nonmatchings/DCE0", func_800328E0);

INCLUDE_ASM("asm/nonmatchings/DCE0", func_800329B8);

extern s32 D_800B7840;
extern s32 D_800B7844;
extern s32 D_800B7848;

void func_800329D8(s32 arg0, s32 arg1, s32 arg2) {
    D_800B7840 = arg0;
    D_800B7844 = arg1;
    D_800B7848 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/DCE0", func_800329F4);

INCLUDE_ASM("asm/nonmatchings/DCE0", func_80032B78);

INCLUDE_ASM("asm/nonmatchings/DCE0", func_80032E34);
