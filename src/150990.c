#include "common.h"

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80241800);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80242074);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80242334);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80242B74);

/* Fields of D_80104FD0 used by overlay 11's text layout. Placeholder. */
typedef struct UnkOvl11_80104FD0 {
    /* 0x00 */ u8 pad0[0xC8];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ u8 padD0[0x4];
    /* 0xD4 */ s32 unkD4;
} UnkOvl11_80104FD0;

extern UnkOvl11_80104FD0 D_80104FD0;
extern s32 D_800C0E60;
extern s32 D_800C4140;
void func_80050DA0(s32, s32, s32, s32, s32);

void func_ovl11_80242FC0(s32 mode) {
    if (mode == 0) {
        func_80050DA0(0x47, D_800C0E60, 0x64, 0x14, 0xDF);
    } else if (mode == 1) {
        func_80050DA0(0x48, D_800C0E60, 0x64, 0x14, 0x20);
    }
    if (mode == 0) {
        D_80104FD0.unkC8 = 0x140;
        D_80104FD0.unkCC = 0;
    }
    D_800C4140 = mode;
    D_80104FD0.unkD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80243050);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_802433B4);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_802434A0);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80243634);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_802436C8);

void func_8006A548(Gfx **, void *);
void func_8006A84C(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Draws an 8-bit CI image with a header (big-endian width at 2, height at 4,
 * TLUT at +8, pixels at +0x208), in two horizontal bands if wider than 96. */
void func_ovl11_8024373C(Gfx **gdl, u8 *img, s32 x, s32 y) {
    Gfx *gfx = *gdl;
    s32 w;
    s32 h;
    s32 n;
    s32 i;

    w = (img[2] << 8) | img[3];
    h = (img[4] << 8) | img[5];
    n = 1;
    if (w > 96) {
        n = 2;
    }
    func_8006A548(&gfx, img + 8);
    h /= n;
    for (i = 0; i != n; i++) {
        func_8006A84C(&gfx, img + (i * w * h + 0x208), 2, 1, w, h, 0, 0, 0, 0, 0, 0, 0);
        func_8006A2C0(&gfx, x * 4, y * 4, (x + w) * 4, (y + h) * 4, 0, 0, 0, 0x400, 0x400);
        y += h;
    }
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_802438D0);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80243C48);

s32 func_80054240(s32);
extern s32 D_ovl11_8024C4A4;

void func_ovl11_8024407C(void) {
    func_80054240(0);
    func_80054240(1);
    D_ovl11_8024C4A4 = -1;
}

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_802440AC);

INCLUDE_ASM("asm/nonmatchings/150990", func_ovl11_80244244);
