#include "common.h"

/* Texture tables at D_80104FD0 + 0x9C. Placeholder. */
typedef struct Unk80104FD0 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u8 *unk20; /* CI4 atlas: palette at +8, 80x18 images from +0x28 */
    /* 0x24 */ u8 pad24[0x14];
    /* 0x38 */ u8 *unk38; /* image atlas: TLUT at +8 */
    /* 0x3C */ u8 pad3C[0x60];
    /* 0x9C */ void *tex[4];
    /* 0xAC */ void *tlut[4];
} Unk80104FD0;

extern Unk80104FD0 D_80104FD0;
void func_8006A548(Gfx **, void *);
void func_8006A84C(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8006A2C0(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_ovl11_802443D0(Gfx **gdl, s32 x, s32 y, s32 idx) {
    Gfx *gfx = *gdl;

    func_8006A548(&gfx, D_80104FD0.tlut[idx]);
    func_8006A84C(&gfx, D_80104FD0.tex[idx], 2, 1, 0x20, 0x20, 0, 0, 0, 0, 0, 0, 0);
    func_8006A2C0(&gfx, x * 4, y * 4, (x + 0x20) * 4, (y + 0x20) * 4, 0, 0, 0, 0x400, 0x400);
    *gdl = gfx;
}

extern void *D_801321C8[];
extern void *D_801B55E0[];

void func_ovl11_802444B8(Gfx **gdl, s32 x, s32 y, s32 idx, s32 mask) {
    Gfx *gfx = *gdl;

    func_8006A548(&gfx, D_801321C8[idx]);
    func_8006A84C(&gfx, D_801B55E0[idx], 2, 1, 0x20, 0x18, 0, 1, 1, mask * 5, 0, 0, 0);
    func_8006A2C0(&gfx, x * 4, y * 4, (x + 0x20) * 4, (y + 0x18) * 4, 0, mask << 10, 0, 0x400, 0x400);
    *gdl = gfx;
}

/* Draws image idx of the D_80104FD0.unk38 atlas twice: the 0x1208 bank at
 * x + 24 and the 0x208 bank at x. */
void func_ovl11_802445C0(Gfx **gdl, s32 x, s32 y, s32 idx) {
    Gfx *gfx = *gdl;

    func_8006A548(&gfx, D_80104FD0.unk38 + 8);
    func_8006A84C(&gfx, D_80104FD0.unk38 + ((idx << 10) + 0x1208), 2, 1, 0x20, 0x20, 0, 0, 0, 0, 0, 0, 0);
    func_8006A2C0(&gfx, (x + 24) * 4, y * 4, (x + 56) * 4, (y + 32) * 4, 0, 0, 0, 0x400, 0x400);
    func_8006A84C(&gfx, D_80104FD0.unk38 + ((idx << 10) + 0x208), 2, 1, 0x20, 0x20, 0, 0, 0, 0, 0, 0, 0);
    func_8006A2C0(&gfx, x * 4, y * 4, (x + 32) * 4, (y + 32) * 4, 0, 0, 0, 0x400, 0x400);
    *gdl = gfx;
}

void func_8006A4A0(Gfx **, s32, void *);

/* Draws 80x18 CI4 image idx of the D_80104FD0.unk20 atlas (rectangle 54 wide). */
void func_ovl11_80244748(Gfx **gdl, s32 x, s32 y, s32 idx) {
    Gfx *gfx = *gdl;

    func_8006A4A0(&gfx, 0, D_80104FD0.unk20 + 8);
    gDPLoadTextureTile_4b(gfx++, (u32)(D_80104FD0.unk20 + (idx * 0x2D0 + 0x28)) & ~7, G_IM_FMT_CI, 80, 18, 0, 0, 79,
                          17, 0, 0, 0, 0, 0, 0, 0);
    func_8006A2C0(&gfx, x * 4, y * 4, (x + 54) * 4, (y + 18) * 4, 0, 0, 0, 0x400, 0x400);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_802448D4);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_80244CA0);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_80245184);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_802460F8);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_80246804);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_802478B0);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_80247D80);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_80247E3C);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_802493DC);

INCLUDE_ASM("asm/nonmatchings/153560", func_ovl11_8024C1D8);
