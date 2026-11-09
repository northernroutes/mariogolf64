#include "common.h"

INCLUDE_ASM("asm/nonmatchings/43810", func_80068410);

INCLUDE_ASM("asm/nonmatchings/43810", func_800685E8);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068A50);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068CA0);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068F00);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068F18);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068F4C);

INCLUDE_ASM("asm/nonmatchings/43810", func_80068F98);

s32 func_80051FCC();
s32 func_80052070();
s32 func_80068F98();
s32 func_802504E8(s32, s32);
extern s8 D_800D1380;
extern s32 D_801B6094;
extern s32 D_801B6098;
extern s8 D_801B60C2;

void func_800690C0(void) {
    s32 temp_s0;

    osSyncPrintf(&D_800D1380, D_801B60C2, D_801B6094, D_801B6098);
    temp_s0 = func_80051FCC();
    func_802504E8(temp_s0, func_80052070());
    func_80068F98();
}

INCLUDE_ASM("asm/nonmatchings/43810", func_80069124);

INCLUDE_ASM("asm/nonmatchings/43810", func_8006955C);

INCLUDE_ASM("asm/nonmatchings/43810", func_800695F8);

INCLUDE_ASM("asm/nonmatchings/43810", func_80069BCC);

s32 func_800695F8();
s32 func_80069BCC();

void func_80069CE4(void) {
    func_800695F8();
    func_80069BCC();
}

INCLUDE_ASM("asm/nonmatchings/43810", func_80069D08);

extern s32 D_800C3FA8;

void func_80069F28(void) {
    D_800C3FA8 = 1;
}

s32 func_80025D78(s32);
s32 func_800260C4(s32);
s32 func_80026230(s32);
s32 func_8004D148();
void func_80069D08(void *);
extern s32 D_800C3FA8;
extern OSThread D_800E1A50;
extern s32 D_8025D350;

void func_80069F38(void) {
    func_80026230(func_80025D78(8));
    func_800260C4(func_80025D78(6));
    osCreateThread(&D_800E1A50, 0xA, func_80069D08, NULL, &D_8025D350, 0x14);
    osStartThread(&D_800E1A50);
    D_800C3FA8 = 0;
    func_8004D148();
}

extern s32 D_800C3FA8;
extern OSThread D_800E1A50;

void func_80069FBC(void) {
    if (D_800C3FA8 == 0) {
        osDestroyThread(&D_800E1A50);
        D_800C3FA8 = 1;
    }
}
