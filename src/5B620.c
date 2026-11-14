/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080220);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800802E0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080564);

extern s32 D_801B608C;
extern s32 D_800C59E0;
extern s32 D_800C59E4;
void func_80241CE8(void);
void func_8008C658(void);
void func_8008085C(void);

void func_8008060C(void) {
    if (D_801B608C == 9) {
        if (D_800C59E4 == 1) {
            D_800C59E4 = 0;
            func_80241CE8();
        }
    } else if (D_801B608C == 3) {
        if (D_800C59E4 == 1) {
            D_800C59E4 = 0;
            func_80241CE8();
        }
    } else {
        func_8008C658();
    }
    if (D_800C59E0 == 1) {
        func_8008085C();
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080688);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008085C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080C4C);

s32 func_80026400(s32, s32);
s32 func_8004E2DC(s32);
extern s32 D_800C5470;
extern s32 D_800C59E0;

void func_80080DCC(void) {
    u8 pad_unused[0x20]; /* unused; sizes the stack frame */
    s32 temp_v0;

    if (D_800C59E0 == 0) {
        temp_v0 = func_8004E2DC(0x7118);
        D_800C5470 = temp_v0;
        func_80026400(temp_v0, 0x7118);
        D_800C59E0 = 1;
    }
}

s32 func_800263B0();
s32 func_8004E47C(s32 *);
s32 func_8007E2B0();
s32 func_80080C4C();
s32 func_80216B74(s32);
s32 memset(s32 *, s32, s32);
extern s32 D_801061B8;

void func_80080E14(void) {
    if (D_800C59E0 != 0) {
        func_800263B0();
        func_8004E47C(&D_800C5470);
        func_8007E2B0();
        func_80216B74(1);
        func_80080C4C();
        D_800C59E0 = 0;
        memset(&D_801061B8, 0, 0x8C);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080E7C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081284);

s32 func_8003E4B4();

void func_80081550(void) {
    func_8003E4B4();
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008156C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081C90);

s32 func_800326FC(s32, s32, s32, s32);
u32 *func_80032E60(s8);
s32 func_8004C510(s32);
s32 func_8007515C(s32, s32, s32, s32, s32, s32);
s32 func_8020FFEC(s32);
extern s32 D_800C5A10;
extern s32 D_800C5A14;
extern s8 D_80104B6B;
extern s32 D_801B7F70;
extern s32 D_801B7F78;
extern s32 D_801B7F7C;

void func_80081D4C(s32 arg0) {
    s32 temp_s0;
    u32 temp_v1;

    D_800C5A14 = 0;
    if (arg0 == -1) {
        D_800C5A10 = arg0;
        func_8007515C(0, -1, 0, 0, 0, 0);
        func_8007515C(1, -1, 0, 0, 0, 0);
        func_8020FFEC(-1);
        return;
    }
    temp_s0 = D_800C5A10;
    if (temp_s0 == -1) {
        D_800C5A10 = arg0;
        temp_v1 = *func_80032E60(D_80104B6B);
        switch (temp_v1) {
        case 13:
            D_801B7F70 = 1;
            D_801B7F78 = 0x4D;
            D_800C5A10 = temp_s0;
            D_801B7F7C = 0x65;
            func_800326FC(0xA0, 0x80, 0x80, 0x80);
            func_8004C510(0x3C);
            func_8020FFEC(0);
            osSyncPrintf("MOVIE KINOP \n");
            return;
        case 21:
        case 10:
            D_800C5A10 = 2;
            func_8004C510(0x3C);
            return;
        case 11:
            func_8004C510(0x28);
            return;
        default:
            D_801B7F70 = 1;
            D_801B7F78 = 0x4D;
            D_801B7F7C = 0x4D;
            func_8004C510(0x28);
            func_800326FC(0xA0, 0xA0, 0x40, 0x38);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081EF8);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800824E4);

INCLUDE_RODATA("asm/nonmatchings/5B620", D_800D1B10);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80082534);

typedef struct Unk800E3370 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Unk800E3370; /* size = 0xC */

typedef struct Unk80104AE0 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
} Unk80104AE0; /* size = 0xC */

extern s32 D_800C5AA8;
extern Unk800E3370 D_800E3370[0x80];
extern Unk80104AE0 D_80104AE0;

void func_80083A48(void) {
    s32 i;

    D_800C5AA8 = 0;
    for (i = 0; i != 0x80; i++) {
        D_800E3370[i].x = D_80104AE0.x * (1.0f / 1024);
        D_800E3370[i].y = D_80104AE0.y * (1.0f / 1024);
        D_800E3370[i].z = D_80104AE0.z * (1.0f / 1024);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80083AC8);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800842C0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80084468);

extern f32 D_801B54EC; /* eye x */
extern f32 D_801B54F0; /* eye y */
extern f32 D_801B54F4; /* eye z */
extern f32 D_801B54F8; /* at x */
extern f32 D_801B54FC; /* at y */
extern f32 D_801B5500; /* at z */
extern f32 D_801B7F68[];
extern s32 D_800C54E0;
extern Mtx D_800E1ED0[];
extern Lights1 D_800C5AB8;
/* D_800FC861 and D_8012CFE4 are declared as arrays: the scheduler must treat
 * them as possibly aliasing the Gfx stores, as in the original. */
extern s8 D_800FC861[];
extern s32 D_8012CFE4[];
extern s32 D_800B67F0;
extern Gfx D_80222400[];
f64 atan2(f64, f64);
void func_80065A1C(f32 (*)[4], f32 *, f32 *);
void func_80067B00(f32 (*)[4], Mtx *);
void func_80084468(Gfx **gfxp, f32 x, f32 y);

/* Draws a lit model at (x, y, -300), pitched to face the camera and turned by
 * D_801B7F68 (0..1 of a full turn). func_80084468 is drawn before it when the
 * angle is outside (pi/2, 3pi/2) and after it when inside. */
void func_80084EBC(Gfx **gfxp, f32 x, f32 y) {
    f32 d[3];
    f32 rot[3];
    f32 pos[3];
    f32 unused[4]; /* never touched; keeps the frame layout */
    f32 mf[4][4];
    f32 tmp[4][4];
    Gfx *gfx = *gfxp;
    f32 horiz;

    d[0] = D_801B54F8 - D_801B54EC;
    d[2] = D_801B5500 - D_801B54F4;
    horiz = sqrtf(d[0] * d[0] + d[2] * d[2]);
    d[1] = D_801B54FC - D_801B54F0;
    rot[0] = atan2(d[1], horiz) + 3.141592653589793 + 0.3f;
    rot[1] = 0.0f;
    rot[2] = 0.0f;
    pos[0] = x;
    pos[1] = y;
    pos[2] = -300.0f;
    func_80065A1C(mf, rot, pos);
    guRotateRPYF(tmp, 0.0f, 180.0 - D_801B7F68[0] * 360.0f * 0.15915494309189535, 0.0f);
    guMtxCatF(tmp, mf, mf);
    guScaleF(tmp, -0.07f, -0.07f, -0.07f);
    guMtxCatF(tmp, mf, mf);
    func_80067B00(mf, &D_800E1ED0[D_800C54E0]);
    if (!(1.5707963267948966 < D_801B7F68[0] && D_801B7F68[0] < 4.71238898038469)) {
        func_80084468(&gfx, x, y);
    }
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, 0x552048, 0);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPPipeSync(gfx++);
    gSPMatrix(gfx++, (u8 *)&D_800E1ED0[D_800C54E0] - 0x80000000, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPSetLights1(gfx++, D_800C5AB8);
    if (D_800FC861[0]) {
        D_8012CFE4[0] = D_800B67F0;
        gSPDisplayList(gfx++, D_80222400);
    }
    if (1.5707963267948966 < D_801B7F68[0] && D_801B7F68[0] < 4.71238898038469) {
        func_80084468(&gfx, x, y);
    }
    *gfxp = gfx;
}

extern u16 D_800FBDD2;
extern s32 D_800C5AD0;
extern char D_80105118[];
s32 func_800299F4(u32 n);
void func_8004DA24(char *, s32, s32);

void func_800852A8(void) {
    if (func_800299F4(0x6E) != 0) {
        if (D_800FBDD2 & 8) {
            D_800C5AD0--;
        }
        if (D_800FBDD2 & 4) {
            D_800C5AD0++;
        }
        sprintf(D_80105118, "%3d", D_800C5AD0);
        func_8004DA24(D_80105118, 0x14, 6);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008534C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80085F98);

extern Gfx *D_801B93DC;
extern u16 D_801B7EE4;
extern Mtx D_800E2050;
extern Mtx D_800FE2F0;
void func_80065B98(f32 (*)[4], f32 *, f32 *, f32 *);
void func_80065DD8(f32 (*)[4], Mtx *);
void func_80085F98(s32);

void func_8008658C(void) {
    f32 pos[3];
    f32 scale[3];
    f32 rot[3];
    f32 mf[4][4];

    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    pos[0] = -240.0f;
    pos[1] = 180.0f;
    pos[2] = -500.0f;
    scale[0] = 0.1f;
    scale[1] = 0.1f;
    scale[2] = 0.1f;
    func_80065B98(mf, rot, pos, scale);
    func_80065DD8(mf, &D_800E2050);
    gDPPipeSync(D_801B93DC++);
    gDPPipeSync(D_801B93DC++);
    gDPSetCycleType(D_801B93DC++, G_CYC_1CYCLE);
    gSPClearGeometryMode(D_801B93DC++, 0xFFFFFFFF);
    gSPSetGeometryMode(D_801B93DC++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPPipeSync(D_801B93DC++);
    gSPSetOtherMode(D_801B93DC++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552048);
    gSPPerspNormalize(D_801B93DC++, D_801B7EE4);
    gDPPipeSync(D_801B93DC++);
    gDPSetTexturePersp(D_801B93DC++, G_TP_PERSP);
    gSPMatrix(D_801B93DC++, (u8 *)&D_800FE2F0 - 0x80000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(D_801B93DC++, (u8 *)&D_800E2050 - 0x80000000, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    func_80085F98(0);
    gDPPipeSync(D_801B93DC++);
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008679C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80086864);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800874D8);

extern s32 D_800E2190[5];
extern s32 D_800E21A8[5];

void func_80087BAC(void) {
    s32 i;

    for (i = 0; i != 5; i++) {
        D_800E2190[i] = 0;
        D_800E21A8[i] = 0;
    }
}

/* Scales a stick vector down to length 56 and stores it as quarter steps.
 * (As decompiled, the length is only taken when both components are zero.) */
void func_80087BE4(s32 x, s32 y) {
    f32 scale;
    f32 len;

    if ((x == 0) & (y == 0)) {
        len = sqrtf((f32)(x * x + y * y));
    } else {
        len = 0.0f;
    }
    if (len > 56.0f) {
        scale = 56.0f / len;
        x = (f32)x * scale;
        y = (f32)y * scale;
    }
    if (x < 0) {
        x += 3;
    }
    *D_800E2190 = x >> 2;
    *D_800E21A8 = -y / 4;
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80087CB0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800880A0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80088890);

/* Draws a string with the digit font: 0-9 plus 'f', 'm', 'y', '.' and ' ' (a gap). */
void func_80088A90(Gfx **gdl, s32 x, s32 y, u8 *str) {
    Gfx *gfx = *gdl;
    u8 c;
    s32 w;
    s32 s;

    for (c = *str; c != 0; c = *++str) {
        switch (c) {
            case ' ':
                continue;
            case '.':
                w = 4;
                s = 0x70;
                break;
            case 'm':
                w = 8;
                s = 0x50;
                break;
            case 'y':
                w = 8;
                s = 0x58;
                break;
            case 'f':
                w = 16;
                s = 0x60;
                break;
            default:
                w = 8;
                s = (*str - '0') * 8;
                break;
        }
        gSPTextureRectangle(gfx++, x << 2, y << 2, (x + w) << 2, (y + 12) << 2, G_TX_RENDERTILE, s << 5, 0, 1 << 10,
                            1 << 10);
        x += w;
    }
    *gdl = gfx;
}

INCLUDE_RODATA("asm/nonmatchings/5B620", D_800D1BB8);

INCLUDE_RODATA("asm/nonmatchings/5B620", D_800D1BC8);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80088BDC);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80089094);

INCLUDE_RODATA("asm/nonmatchings/5B620", D_800D1C84);

INCLUDE_RODATA("asm/nonmatchings/5B620", D_800D1C98);

INCLUDE_RODATA("asm/nonmatchings/5B620", jtbl_800D1CA0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008C520);

extern s32 D_800C5ED8;
extern s32 D_800E3970;
extern s32 D_800E3974;

void func_8008C658(void) {
    if (D_800C5ED8 & 1) {
        func_8004E47C(&D_800E3970);
    }
    if (D_800C5ED8 & 2) {
        func_8004E47C(&D_800E3974);
    }
    D_800C5ED8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008C6B0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008CD30);

extern s32 D_800C54E0;

void func_8008D0DC(void) {
    D_800C54E0 ^= 1;
}
