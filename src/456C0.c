/* This file builds F3DEX2 display lists (G_RDPHALF_1 = 0xE1 etc.). */
#define F3DEX_GBI_2
#include "common.h"

extern s32 D_800C4010;
extern s32 D_800C4014;
extern s32 D_800C4018;
extern s32 D_800C4020;
extern s32 D_800C4060;
extern s32 D_800C4064;
extern s32 D_800C4068;
extern s32 D_800C4124;
extern s32 D_800C4144;
extern s32 D_800E1C00;
extern s32 D_800E1C04;
extern s32 D_800E1C08;
extern s32 D_800E1C0C;
extern s32 D_800FF4B0;
extern s32 D_800FF4B4;
extern s32 D_800FF4B8;

s32 func_8004E2DC(s32 arg0);
void func_8004E47C(s32 *arg0);
s32 func_8005062C(s32 arg0, void *arg1);
void func_800506D4(s32 arg0, void *arg1);
void func_8006B54C(void);

void func_8006A2C0(Gfx **gdl, s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tile, s32 s, s32 t, s32 dsdx, s32 dtdy) {
    Gfx *gfx = *gdl;

    gDPPipeSync(gfx++);
    gSPScisTextureRectangle(gfx++, ulx, uly, lrx, lry, tile, s, t, dsdx, dtdy);
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

void func_8006A4A0(Gfx **gdl, s32 pal, void *tlut) {
    Gfx *gfx = *gdl;

    gDPLoadTLUT_pal16(gfx++, pal, (u32)tlut & ~7);
    *gdl = gfx;
}

void func_8006A548(Gfx **gdl, void *tlut) {
    Gfx *gfx = *gdl;

    gDPLoadTLUT_pal256(gfx++, (u32)tlut & ~7);
    *gdl = gfx;
}

void func_8006A5E4(Gfx **gdl, void *timg, s32 fmt, s32 width, s32 height, s32 pal, s32 cms, s32 cmt, s32 masks,
                   s32 maskt, s32 shifts, s32 shiftt) {
    Gfx *gfx = *gdl;

    gDPLoadTextureBlock_4b(gfx++, (u32)timg & ~7, fmt, width, height, pal, cms, cmt, masks, maskt, shifts,
                        shiftt);
    *gdl = gfx;
}

/* gDPLoadTextureBlock with the render tile's size taken from a runtime value
 * (`rsiz`) while the load uses the compile-time size `siz`. */
#define gDPLoadTextureBlockRS(pkt, timg, fmt, siz, rsiz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt) \
    {                                                                                                              \
        gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg);                                                   \
        gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);    \
        gDPLoadSync(pkt);                                                                                          \
        gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1,             \
                     CALC_DXT(width, siz##_BYTES));                                                                \
        gDPPipeSync(pkt);                                                                                          \
        gDPSetTile(pkt, fmt, rsiz, (((width) * siz##_LINE_BYTES) + 7) >> 3, 0, G_TX_RENDERTILE, pal, cmt, maskt,   \
                   shiftt, cms, masks, shifts);                                                                    \
        gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width) - 1) << G_TEXTURE_IMAGE_FRAC,                          \
                       ((height) - 1) << G_TEXTURE_IMAGE_FRAC)                                                     \
    }

void func_8006A84C(Gfx **gdl, void *timg, s32 fmt, s32 siz, s32 width, s32 height, s32 pal, s32 cms, s32 cmt,
                   s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx *gfx = *gdl;

    if (siz == G_IM_SIZ_8b) {
        gDPLoadTextureBlockRS(gfx++, (u32)timg & ~7, fmt, G_IM_SIZ_8b, siz, width, height, pal, cms, cmt, masks,
                              maskt, shifts, shiftt);
    } else {
        gDPLoadTextureBlockRS(gfx++, (u32)timg & ~7, fmt, G_IM_SIZ_16b, siz, width, height, pal, cms, cmt, masks,
                              maskt, shifts, shiftt);
    }
    *gdl = gfx;
}

void func_8006ACD8(void) {
    s32 sp10[8];
    s32 handle;

    handle = func_8004E2DC(func_8005062C(0x63F, sp10));
    D_800E1C04 = handle;
    func_800506D4(handle, sp10);
    func_8006B54C();
}

extern u16 D_800C4026[][2];

void func_8006AD1C(s32 i) {
    s32 sp10[8];

    func_8005062C(D_800C4026[i % 14][0], sp10);
    func_800506D4(D_800E1C04, sp10);
}

void func_8006AD88(void) {
    D_800C4020 = 0;
}

s32 func_8006AD94(void) {
    return D_800C4020;
}

extern f32 D_800C401C;

s32 func_8006ADA0(void) {
    if (D_800C4010 == 0) {
        return (s32) D_800C401C;
    }
    switch (D_800C4014) {
    case 1:
    default:
        return 0;
    case 3:
        D_800C4010 = 0;
        return 0x14;
    }
}

s32 func_80050DA0(s32, s32, s32, s32, s32);

void func_8006ADF8(s32 arg0) {
    if (D_800C4010 == 1) {
        if (arg0 == 2 || arg0 == 3) {
            D_800C4014 = 2;
            D_800C4018 = -1;
        }
    } else {
        D_800C4020 = arg0;
        switch (arg0) {
            case 1:
                D_800C401C = 12.0f;
                func_80050DA0(0x64, 2, 0x28, 0x14, 0x7F);
                break;
            case 2:
            case 3:
                D_800C401C = -2.0f;
                func_80050DA0(0x65, 2, 0x28, 0x14, 0x7F);
                break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006AEA4);

void func_8006B54C(void) {
    D_800C4068 = -1;
}

s32 func_8006B55C(void) {
    return D_800C4064 < 2;
}

void func_8006B56C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800C4068 = 0;
    D_800C4060 = arg3;
    D_800C4064 = arg3;
    D_800FF4B0 = arg0;
    D_800FF4B4 = arg1;
    D_800FF4B8 = arg2;
}

void func_8006B5A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800C4068 = 1;
    D_800C4060 = arg3;
    D_800C4064 = arg3;
    D_800FF4B0 = arg0;
    D_800FF4B4 = arg1;
    D_800FF4B8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006B5D8);

void func_8006B980(void) {
    s32 sp10[8];
    s32 handle;
    s32 handle2;

    handle = func_8004E2DC(func_8005062C(0x70B, sp10));
    D_800E1C08 = handle;
    func_800506D4(handle, sp10);
    handle2 = func_8004E2DC(func_8005062C(0x70C, sp10));
    D_800E1C0C = handle2;
    func_800506D4(handle2, sp10);
}

void func_8006B9E4(void) {
    func_8004E47C(&D_800E1C08);
    func_8004E47C(&D_800E1C0C);
}

s32 func_8006BA10(void) {
    return D_800C4124 == -1;
}

/* 0x10-byte entries of D_800C406C. Placeholder. */
typedef struct Unk800C406C {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ u8 pad8[0x8];
} Unk800C406C;

void func_80050BF0(s32 arg0, s32 arg1, s32 arg2);

extern Unk800C406C D_800C406C[];
extern s32 D_800C0E60;
extern s32 D_800C411C;
extern s32 D_800C4120;
extern s32 D_800C4128;

void func_8006BA24(s32 arg0) {
    Unk800C406C *entry;

    if (arg0 != -1) {
        entry = &D_800C406C[arg0];
        D_800C4120 = 0;
        D_800C411C = arg0;
        func_8006B980();
        D_800C4124 = 0;
        D_800C4128 = entry->unk4;
        func_80050BF0(0x64, D_800C0E60, 0x64);
    }
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006BA94);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006BC80);

void func_8006C3E8(void) {
    s32 sp10[8];
    s32 handle;

    if (D_800C4010 == 0) {
        handle = func_8004E2DC(func_8005062C(0x955, sp10));
        D_800E1C00 = handle;
        func_800506D4(handle, sp10);
    }
    D_800C4010 = 1;
    D_800C4014 = 0;
    D_800C4018 = 0x90;
}

void func_8006C450(void) {
    if (D_800C4010 != 0) {
        func_8004E47C(&D_800E1C00);
    }
    D_800C4010 = 0;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006C484);

s32 func_8006C8CC(u16 *arg0) {
    if (D_800C4010 == 0 || D_800C4014 != 0 || (D_800C4018 < 0 && (arg0[2] & 0x8000))) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006C918);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006CD50);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006CE88);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006D058);

extern s16 D_801B725E[][0x5C];
extern s16 D_8012D3C8[4][7];
extern s16 D_801B60C6;
extern s16 D_801B60C8;
extern s16 D_801B60CA;
extern s32 D_800C4130;
extern s32 D_800C4134;
extern s32 D_800C4138;
extern s32 D_800C413C;

void func_8006D164(void) {
    s32 i;
    s32 j;

    for (i = 0; i != 4; i++) {
        for (j = 0; j != 7; j++) {
            D_8012D3C8[i][j] = D_801B725E[i][j];
        }
    }
    D_800C413C = 0;
    D_800C4144 = -1;
    D_800C4130 = D_801B60C6;
    D_800C4134 = D_801B60C8;
    D_800C4138 = D_801B60CA;
}

s32 func_8006D1FC(void) {
    return D_800C4144;
}

void func_8006D208(s32 arg0) {
    D_800C4144 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006D214);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006D38C);

void func_8006D4DC(void) {
    D_800C4144 = -1;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006D4EC);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006D6D0);

/* Placeholder: 0x74-byte entries at 0xEA4 in the object returned by func_8005AF50. */
typedef struct Unk8005AF50_Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x70];
} Unk8005AF50_Entry; /* size = 0x74 */

typedef struct Unk8005AF50_456C0 {
    /* 0x000 */ u8 pad0[0xEA4];
    /* 0xEA4 */ Unk8005AF50_Entry unkEA4[1];
} Unk8005AF50_456C0;

/* Same layout as SaveBlob1C in 34FA0.c. */
typedef struct SaveBlob1C {
    s32 w[7];
} SaveBlob1C;

Unk8005AF50_456C0 *func_8005AF50(void);
extern SaveBlob1C D_800FF4D0;
extern s32 D_801B6094;

void func_8006DDCC(void) {
    Unk8005AF50_456C0 *obj = func_8005AF50();

    D_800FF4D0.w[0] = 0;
    D_800FF4D0.w[1] = 0;
    D_800FF4D0.w[2] = 0;
    D_800FF4D0.w[5] = 0;
    D_800FF4D0.w[3] = (obj->unkEA4 + D_801B6094)->unk0;
    D_800FF4D0.w[4] = 0;
    D_800FF4D0.w[6] = 0;
}

void func_8006DE44(void) {
    Unk8005AF50_456C0 *obj = func_8005AF50();

    D_800FF4D0.w[0] = 0;
    D_800FF4D0.w[1] = 0;
    D_800FF4D0.w[2] = 0;
    D_800FF4D0.w[5] = 0;
    D_800FF4D0.w[3] = (obj->unkEA4 + D_801B6094)->unk0;
    D_800FF4D0.w[6] = 0;
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006DEB4);

/* 0x34-byte entries of D_800BB258 (see Unk800BB258 in 1EEF0.c). Placeholder. */
typedef struct Unk800BB258 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0xA];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 pad18[0x1C];
} Unk800BB258; /* size = 0x34 */

/* 0xB8-byte entries starting at D_801B7250 (see BBD00.c). Placeholder. */
typedef struct Unk801B7250 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0x18];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x94];
} Unk801B7250; /* size = 0xB8 */

Unk800BB258 *func_8004491C(void);
extern Unk801B7250 D_801B7250[];

s32 func_8006DF84(void) {
    SaveBlob1C *p = &D_800FF4D0;
    Unk800BB258 *e = func_8004491C();

    D_801B7250[0].unk20 = D_801B7250[0].unk0;
    if (e->unk16 == 0 && D_801B7250[0].unk0 > 0) {
        p->w[6] = 1;
    } else {
        p->w[6] = 0;
    }
    return D_801B7250[0].unk20 > p->w[3];
}

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006DFF0);

INCLUDE_ASM("asm/nonmatchings/456C0", func_8006E210);
