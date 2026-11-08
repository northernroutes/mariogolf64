#include "common.h"

f32 func_80095A10(f32 arg0, f32 arg1, f32 arg2) {
    f32 var_ft0;

    var_ft0 = arg2;
    if (var_ft0 < 0.0f) {
        var_ft0 = 0.0f;
    }
    if (var_ft0 > 1.0f) {
        var_ft0 = 1.0f;
    }
    return (arg0 * (1.0f - var_ft0)) + (arg1 * var_ft0);
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095A68);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095C10);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095D10);

extern s32 D_800E4C5C;

void func_80095D64(void) {
    D_800E4C5C = 0;
}

s32 func_80050BF0(s32, s32, s32);
extern s32 D_800C73A0;
extern s32 D_800C73E0;

void func_80095D70(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if ((arg1 != -1) && ((D_800C73A0 - 1) == arg0)) {
        func_80050BF0(arg1, D_800C73E0, 0x7F);
        temp_v0 = D_800C73E0 + 1;
        D_800C73E0 = temp_v0;
        if (temp_v0 >= 8) {
            D_800C73E0 = 4;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095DE0);

INCLUDE_ASM("asm/nonmatchings/70E10", func_8009676C);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800967F4);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80096C04);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80096F44);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097218);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800974D8);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800977E0);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097A08);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097C18);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097E30);

INCLUDE_ASM("asm/nonmatchings/70E10", func_8009806C);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098310);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800985B4);

extern s8 D_800E4CC8;

void func_8009874C(void) {
    D_800E4CC8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098758);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800989C4);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800989EC);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098C6C);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098CA0);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098CD8);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098D70);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098E48);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800990D0);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80099454);
