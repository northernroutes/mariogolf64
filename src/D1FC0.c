/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

extern s8 D_801061BD;
extern s8 D_801061BF;
extern s8 D_801061C0;
extern s8 D_801061C1;
extern s8 D_801061C2;
extern s8 D_801061C3;
extern s8 D_801061C4;
extern s8 D_801061C5;
extern s8 D_80106241;
extern s8 D_80106242;
extern s8 D_80106243;

void func_ovl0_80218CC0(void) {
    D_801061BD = 0;
    D_801061C4 = 0;
    D_801061BF = 0;
    D_80106241 = 0;
    D_80106242 = 0;
    D_80106243 = 0;
    D_801061C0 = 0;
    D_801061C1 = 0;
    D_801061C2 = 0;
    D_801061C3 = 0;
    D_801061C5 = 0;
}

s32 func_800292FC(s32);
s32 func_8002A97C(s32, s32);
s32 func_800934CC(s32);
extern s32 D_800C306C;
extern s8 D_801061BD;
extern s8 D_801061BF;
extern s8 D_801061C0;
extern s8 D_801061C1;
extern s8 D_801061C2;
extern s8 D_801061C3;
extern s8 D_801061C4;
extern s8 D_801061C5;
extern s8 D_80106241;
extern s8 D_80106242;
extern s8 D_80106243;

void func_ovl0_80218D1C(void) {
    D_801061BD = 1;
    D_801061C4 = 1;
    D_801061BF = 1;
    D_80106241 = 0;
    D_80106242 = 0;
    D_80106243 = 0;
    D_801061C0 = 1;
    D_801061C1 = 1;
    D_801061C2 = 1;
    D_801061C3 = 1;
    D_801061C5 = 1;
    func_800934CC(-1);
    D_800C306C = 0;
    func_800292FC(3);
    func_8002A97C(4, 0);
}

extern s32 D_ovl0_80224A80;
extern s32 D_ovl0_8022D678;

void func_ovl0_80218DB0(s32 arg0, s32 arg1) {
    D_ovl0_80224A80 = (arg1 != 0) ? -1 : 1;
    D_ovl0_8022D678 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_80218DD0);

s32 func_8004E47C(s32 *);
s32 func_80051A88(s32);
extern s32 D_ovl0_80224A7C;
extern s32 D_ovl0_8022B530;
extern s32 D_ovl0_8022B534;
extern s32 D_ovl0_8022B538;

void func_ovl0_80218FDC(void) {
    if (D_ovl0_80224A7C == 1) {
        D_ovl0_80224A7C = 0;
        func_8004E47C(&D_ovl0_8022B530);
        func_8004E47C(&D_ovl0_8022B534);
        func_8004E47C(&D_ovl0_8022B538);
    }
    func_80051A88(0x7F);
}

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_80219034);

extern s32 D_ovl0_80224A84;
void func_8006A4A0(Gfx **, s32, void *);
void func_8006A5E4(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Animated arrows either side of a span of width w centred on (cx, y). */
void func_ovl0_802199EC(Gfx **gdl, s32 cx, s32 y, s32 w) {
    Gfx *gfx = *gdl;
    s32 half;

    D_ovl0_80224A84 = (D_ovl0_80224A84 + 1) % 8;
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPPipeSync(gfx++);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A7008);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    func_8006A4A0(&gfx, 0, (u8 *)D_ovl0_8022B538 + 8);
    func_8006A5E4(&gfx, (u8 *)D_ovl0_8022B538 + ((D_ovl0_80224A84 / 4 << 9) + 0x28), G_IM_FMT_CI, 0x10, 0x40, 0, 0, 0, 0,
                  0, 0, 0);
    half = w / 2;
    gDPPipeSync(gfx++);
    func_8006A2C0(&gfx, (cx - half - 8) * 4, (y - 8) * 4, (cx - half + 8) * 4, (y + 8) * 4, 0, 0, 0x600, 0x400,
                  0x400);
    func_8006A2C0(&gfx, (cx + half - 8) * 4, (y - 8) * 4, (cx + half + 8) * 4, (y + 8) * 4, 0, 0, 0x400, 0x400,
                  0x400);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_80219C74);

s32 func_8004E2DC(s32);
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_ovl0_8022B534;
extern s32 D_ovl0_8022B53C;

void func_ovl0_8021A62C(void) {
    s32 sp10[8];
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_8004E2DC(func_8005062C(0x70F, sp10));
    D_ovl0_8022B53C = temp_v0;
    func_800506D4(temp_v0, sp10);
    temp_v0_2 = func_8004E2DC(func_8005062C(0x71F, sp10));
    D_ovl0_8022B534 = temp_v0_2;
    func_800506D4(temp_v0_2, sp10);
}

s32 func_8004E47C(s32 *);
extern s32 D_ovl0_8022B534;
extern s32 D_ovl0_8022B53C;

void func_ovl0_8021A690(void) {
    func_8004E47C(&D_ovl0_8022B53C);
    func_8004E47C(&D_ovl0_8022B534);
}

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_8021A6BC);

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_8021A724);

INCLUDE_ASM("asm/nonmatchings/D1FC0", func_ovl0_8021A940);
