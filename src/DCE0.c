#include "common.h"

INCLUDE_ASM("asm/nonmatchings/DCE0", func_800328E0);

extern Gfx *D_801B93DC;
void func_800328E0(s32, Gfx **);

void func_800329B8(s32 arg0) {
    func_800328E0(arg0, &D_801B93DC);
}

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

void func_80032B78(s32, Gfx **);

void func_80032E34(s32 arg0) {
    func_80032B78(arg0, &D_801B93DC);
}
