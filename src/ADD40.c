#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F4A40);

s32 func_ovl0_801F4AEC();
s32 func_ovl0_801F618C();
extern s32 D_ovl0_8021FC74;
extern s32 D_ovl0_8021FC80;

void func_ovl0_801F4AA4(s32 arg0) {
    if (arg0 == -1) {
        func_ovl0_801F618C();
        return;
    }
    func_ovl0_801F4AEC();
    D_ovl0_8021FC80 = 0x140;
    D_ovl0_8021FC74 = 0;
}

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F4AEC);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F5C24);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F5E9C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F5F2C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F618C);

extern s32 D_ovl0_802257D8[4];
extern s32 D_ovl0_802257E8[4];
extern s32 D_ovl0_802257F8[4];

void func_ovl0_801F63CC(s32 arg0, s32 arg1) {
    D_ovl0_802257D8[arg1] = arg0;
    D_ovl0_802257E8[arg1] = 0;
    D_ovl0_802257F8[arg1] = 0;
}

s32 func_80050BF0(s32, s32, s32);
extern s32 D_800C0E60;
extern s32 D_ovl0_8021FC88;
extern s32 D_ovl0_8021FDB8;

void func_ovl0_801F63F8(void) {
    s32 temp_a0;

    temp_a0 = D_ovl0_8021FDB8 + 1;
    D_ovl0_8021FDB8 = temp_a0;
    if ((D_ovl0_8021FC88 != 1) || !(temp_a0 & 3)) {
        func_80050BF0(0x20, D_800C0E60, 0x7F);
    }
}

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F6450);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F6718);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F6D0C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F6DFC);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F7294);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F7418);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F7518);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F75B0);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F7740);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F7F7C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F8094);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F8A30);

extern s32 D_ovl0_8021FD94;

s32 func_ovl0_801F8B7C(void) {
    return D_ovl0_8021FD94;
}

extern s32 D_ovl0_8021FD98;
extern s32 D_ovl0_8021FD9C;
extern s32 D_ovl0_8021FDA0;

void func_ovl0_801F8B88(s32 arg0, s32 arg1) {
    D_ovl0_8021FD94 = arg0;
    D_ovl0_8021FD98 = arg1;
    if (arg0 == 0) {
        D_ovl0_8021FD9C = 0x140;
        D_ovl0_8021FDA0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F8BB8);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801F9AD0);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FA098);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FA248);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FA684);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FAD2C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FB02C);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FB500);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FBBBC);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FC3D4);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FCC48);

INCLUDE_ASM("asm/nonmatchings/ADD40", func_ovl0_801FD578);
