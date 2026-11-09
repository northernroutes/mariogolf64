#include "common.h"

extern s32 D_80105148;
extern s8 D_80105165;

void func_80077BF0(void) {
    D_80105148 = 0x96;
    D_80105165 = 1;
}

extern s8 D_80105165;

void func_80077C0C(void) {
    D_80105165 = 0;
}

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80077C18);

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80077DEC);

extern s32 D_800C4664;

s32 func_80077E6C(void) {
    s32 temp_v0;

    if (D_800C4664 > 0) {
        return 0;
    }
    temp_v0 = D_800C4664 - 1;
    D_800C4664 = temp_v0;
    return temp_v0 < -2;
}

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80077E94);

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80078128);
