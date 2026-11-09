#include "common.h"

INCLUDE_ASM("asm/nonmatchings/193D0", func_8003DFD0);

INCLUDE_ASM("asm/nonmatchings/193D0", func_8003E004);

INCLUDE_ASM("asm/nonmatchings/193D0", func_8003E314);

s32 func_8004E2DC(s32);
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_800DAD00;
extern s32 D_800DAD04;
extern s32 D_800DAD08;
extern s32 D_800DAD0C;

void func_8003E400(void) {
    s32 sp10[8];
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;

    temp_v0 = func_8004E2DC(func_8005062C(0x4CA, sp10));
    D_800DAD04 = temp_v0;
    func_800506D4(temp_v0, sp10);
    temp_v0_2 = func_8004E2DC(func_8005062C(0x4C9, sp10));
    D_800DAD00 = temp_v0_2;
    func_800506D4(temp_v0_2, sp10);
    temp_v0_3 = func_8004E2DC(func_8005062C(0x703, sp10));
    D_800DAD08 = temp_v0_3;
    func_800506D4(temp_v0_3, sp10);
    temp_v0_4 = func_8004E2DC(func_8005062C(0x704, sp10));
    D_800DAD0C = temp_v0_4;
    func_800506D4(temp_v0_4, sp10);
}

s32 func_8004E47C(s32 *);
extern s32 D_800DAD00;
extern s32 D_800DAD04;
extern s32 D_800DAD08;
extern s32 D_800DAD0C;

void func_8003E4B4(void) {
    func_8004E47C(&D_800DAD00);
    func_8004E47C(&D_800DAD04);
    func_8004E47C(&D_800DAD08);
    func_8004E47C(&D_800DAD0C);
}

INCLUDE_ASM("asm/nonmatchings/193D0", func_8003E4F8);

extern s8 D_800BA9A8;

void func_8003E628(void) {
    D_800BA9A8 = 1;
}

extern s8 D_800BA9A9;

void func_8003E638(void) {
    D_800BA9A9 = 1;
}

s32 *func_80032E60(s32);
extern s8 D_800BA9A8;
extern s8 D_800BA9A9;
extern s32 D_800FBE70;
extern s32 D_801B6088;
extern s8 D_801B60C2;

s32 func_8003E648(void) {
    s32 var_v0;

    if ((D_800BA9A8 != 0) || (D_800BA9A9 != 0)) {
        return 0;
    }
    var_v0 = 1;
    if ((u32) (D_801B6088 - 6) < 2U) {
        if (D_801B60C2 != 0) {
            return 1;
        }
        var_v0 = *func_80032E60(D_800FBE70) != 0xB;
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/193D0", func_8003E6C0);
