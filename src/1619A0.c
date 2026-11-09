/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80241800);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_8024186C);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80241E54);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80242050);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80242294);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80243698);

extern s32 D_ovl14_802457E8;
extern s32 D_ovl14_802457EC;

void func_ovl14_80243880(void) {
    D_ovl14_802457E8 = 0;
    D_ovl14_802457EC = 5;
}

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80243898);

extern s32 D_ovl14_802457E8;
extern s32 D_ovl14_802457EC;

void func_ovl14_802439B0(void) {
    D_ovl14_802457E8 = 0;
    D_ovl14_802457EC = 5;
}

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_802439C8);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80243E28);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80244134);

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80245260);

s32 func_8004E47C(s32 *);
s32 func_80051C08(s32, s32);
extern s32 D_ovl14_802457E0;
extern s32 D_ovl14_80245860;
extern s32 D_ovl14_80245AB0;

void func_ovl14_802452E4(void) {
    func_8004E47C(&D_ovl14_80245AB0);
    D_ovl14_802457E0 = 0;
    func_80051C08(D_ovl14_80245860, 0x11);
}

extern s32 D_ovl14_80245A20;
void func_8006A548(Gfx **, void *);
void func_8006A84C(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Draws the 32 288x7 strips of the D_ovl14_80245AB0 image scrolled up by D_ovl14_80245A20. */
void func_ovl14_80245320(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 i;
    s32 top;
    s32 bottom;

    if (D_ovl14_802457E0 == 1) {
        gDPPipeSync(gfx++);
        gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gfx++);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPPipeSync(gfx++);
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        gDPPipeSync(gfx++);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPPipeSync(gfx++);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gDPPipeSync(gfx++);
        gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x0F0A7008);
        gDPSetCombine(gfx++, 0x119623, 0xFF2FFFFF);
        func_8006A548(&gfx, (u8 *)D_ovl14_80245AB0 + 8);
        for (i = 0; i != 32; i++) {
            func_8006A84C(&gfx, (u8 *)D_ovl14_80245AB0 + (i * 0x7E0 + 0x208), 2, 1, 0x120, 7, 0, 1, 1, 0, 0, 0, 0);
            top = D_ovl14_80245A20 - 8;
            bottom = D_ovl14_80245A20 - 15;
            func_8006A2C0(&gfx, 0x40, (i * 7 - top) * 4, 0x4C0, (i * 7 - bottom) * 4, 0, 0, 0, 0x400, 0x400);
        }
        *gdl = gfx;
    }
}

INCLUDE_ASM("asm/nonmatchings/1619A0", func_ovl14_80245598);
