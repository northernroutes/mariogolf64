/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

extern s16 D_800C2900[4];
extern s32 D_ovl3_8022FF1C;
extern s32 D_ovl3_8022FF20;
extern s32 D_ovl3_8022FF24;
extern s32 D_ovl3_8022FF28;

void func_ovl3_80209500(void) {
    s32 a = D_800C2900[0];
    s32 b = D_800C2900[1];
    s32 c = D_800C2900[2];
    s32 d = D_800C2900[3];

    D_800C2900[0] = -1;
    D_800C2900[1] = -1;
    D_800C2900[2] = -1;
    D_800C2900[3] = -1;
    D_ovl3_8022FF1C = a;
    D_ovl3_8022FF20 = b;
    D_ovl3_8022FF24 = c;
    D_ovl3_8022FF28 = d;
}

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_80209568);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_80209894);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_80209BE0);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_80209D50);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020B2C4);

extern s16 D_800C28E4[][7];
s8 *func_8005AF74(void);

void func_ovl3_8020B3CC(void) {
    s8 *p = func_8005AF74();
    s32 i;
    s32 j;

    for (i = 0; i != 2; i++) {
        for (j = 0; j != 7; j++) {
            if (D_800C28E4[i][j] < -10) {
                p[4] = j;
                p[8] = i;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020B438);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020B590);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020BA08);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020C2D8);

extern u8 *D_ovl3_8023A568;
u8 *func_ovl3_801F4A40(void);
void func_8006A4A0(Gfx **, s32, void *);
void func_8006A5E4(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Draws the 288x176 CI4 picture of D_ovl3_8023A568 as sixteen 11-line bands,
 * then a small 80x8 label from the func_ovl3_801F4A40 buffer. */
void func_ovl3_8020C3B8(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 i;
    u8 *p;

    func_ovl3_801F4A40();
    gDPLoadTLUT_pal16(gfx++, 0, (u32)(D_ovl3_8023A568 + 8) & ~7);
    for (i = 0; i != 16; i++) {
        gDPLoadTextureBlock_4b(gfx++, (u32)(D_ovl3_8023A568 + (i * 0x630 + 0x28)) & ~7, G_IM_FMT_CI, 288, 11, 0, 0, 0,
                               0, 0, 0, 0);
        gDPPipeSync(gfx++);
        gSPScisTextureRectangle(gfx++, 0x40, i * 0x2C + 0xC0, 0x4C0, i * 0x2C + 0xEC, G_TX_RENDERTILE, 0, 0, 0x400,
                                0x400);
        gDPPipeSync(gfx++);
    }
    p = func_ovl3_801F4A40();
    p = p + 0x628;
    func_8006A4A0(&gfx, 0, p + 8);
    func_8006A5E4(&gfx, p + 0x28, G_IM_FMT_CI, 0x50, 8, 0, 0, 0, 0, 0, 0, 0);
    func_8006A2C0(&gfx, 0x320, 0x320, 0x3C0, 0x340, 0, 0x500, 0, 0x400, 0x400);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020C6D8);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020CD20);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020D338);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020D734);

INCLUDE_ASM("asm/nonmatchings/F3480", func_ovl3_8020DB30);
