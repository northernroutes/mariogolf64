#include "common.h"

s32 func_8005B0A0(s32);

s32 func_ovl0_801F4A40(s32 arg0) {
    s32 sum = 0;
    s32 i;

    for (i = 1; i < arg0 + 1; i++) {
        sum += func_8005B0A0(i);
    }
    return sum;
}

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

void func_8004E47C(void *);
extern s32 D_ovl0_8022573C;
extern u8 D_ovl0_802256C8[];
extern u8 D_ovl0_802256CC[];
extern u8 D_ovl0_802256D0[];
extern u8 D_ovl0_8022570C[];
extern u8 D_ovl0_80225710[];
extern u8 D_ovl0_80225714[];

void func_ovl0_801F5E9C(void) {
    func_8004E47C(D_ovl0_80225710);
    func_8004E47C(D_ovl0_80225714);
    if (D_ovl0_8022573C == 1) {
        func_8004E47C(D_ovl0_802256C8);
    }
    if (D_ovl0_8022573C == 2) {
        func_8004E47C(D_ovl0_8022570C);
        func_8004E47C(D_ovl0_802256CC);
        func_8004E47C(D_ovl0_802256D0);
    }
    D_ovl0_8022573C = 0;
}

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

void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A548(Gfx **, s32);
void func_8006A84C(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_ovl0_802256D8[];
extern s32 D_ovl0_802256E8[];

void func_ovl0_801F7418(Gfx **gdl, s32 x, s32 y, s32 idx, s32 arg4) {
    Gfx *gfx = *gdl;

    func_8006A548(&gfx, D_ovl0_802256E8[idx]);
    func_8006A84C(&gfx, D_ovl0_802256D8[idx], 2, 1, 0x20, 0x20, 0, 1, 0, 5, 0, 0, 0);
    func_8006A2C0(&gfx, x * 4, y * 4, (x + 0x20) * 4, (y + 0x20) * 4, 0, arg4 << 10, 0, 0x400, 0x400);
    *gdl = gfx;
}

extern s32 D_ovl0_80225748;
extern s32 D_ovl0_8022574C;
extern s32 D_ovl0_80225750;
extern s32 D_ovl0_80225754;
extern f32 D_ovl0_80225758;
extern s32 D_ovl0_8022575C;
extern s32 D_ovl0_80225760;
extern s32 D_ovl0_80225764;
extern s32 D_ovl0_80225768;
extern s32 D_ovl0_8022576C;

void func_ovl0_801F7518(s32 arg0) {
    D_ovl0_8022573C = arg0;
    switch (arg0) {
        case 0:
            break;
        case 1:
            D_ovl0_80225748 = 0;
            D_ovl0_8022574C = 0;
            D_ovl0_80225750 = 320;
            D_ovl0_80225754 = 0;
            D_ovl0_80225758 = -1.57f;
            break;
        case 2:
            D_ovl0_8022575C = 0;
            D_ovl0_80225760 = 0;
            D_ovl0_80225764 = 0;
            D_ovl0_80225768 = 0;
            D_ovl0_8022576C = 0;
            break;
    }
}

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

void func_ovl0_801F7740(Gfx **);
void func_ovl0_801F8094(Gfx **);

void func_ovl0_801FD578(Gfx **gdl) {
    Gfx *gfx = *gdl;

    switch (D_ovl0_8022573C) {
        case 0:
            break;
        case 1:
            func_ovl0_801F7740(&gfx);
            break;
        case 2:
            func_ovl0_801F8094(&gfx);
            break;
    }
    *gdl = gfx;
}
