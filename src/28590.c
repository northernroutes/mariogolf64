#include "common.h"

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D190);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D4B8);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D580);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D5F0);

extern s8 D_800DB40F;

void func_8004D794(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x4AF;
    var_v0 = &D_800DB40F;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D7B8);

extern s8 D_800BFEE4;

void func_8004D99C(s32 arg0) {
    if (arg0 != 0) {
        D_800BFEE4 = -0x80;
        return;
    }
    D_800BFEE4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D9C0);

s32 func_8004D9C0();
extern s8 D_800B67C0;

void func_8004DA24(void) {
    if (D_800B67C0 != 0) {
        func_8004D9C0();
    }
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DA4C);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DA9C);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DAF4);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DC44);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DD70);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DDE4);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DE44);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DE60);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DE7C);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E058);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E184);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E1E0);

extern s32 D_800DC738;

s32 func_8004E27C(void) {
    return D_800DC738;
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E288);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E2DC);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E47C);
