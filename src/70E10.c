/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

f32 func_80095A10(f32 arg0, f32 arg1, f32 arg2) {
    f32 var_ft0;

    var_ft0 = arg2;
    if (var_ft0 < 0.0f) {
        var_ft0 = 0.0f;
    }
    if (var_ft0 > 1.0f) {
        var_ft0 = 1.0f;
    }
    return (arg0 * (1.0f - var_ft0)) + (arg1 * var_ft0);
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095A68);

extern s32 D_800E4C5C;
extern Light D_800C73B0[3];

/* gSPSetLights3 on the Lights3 whose diffuse lights are D_800C73B0; its
 * ambient light (the tail of D_800C73A0) sits 8 bytes before. */
s32 func_80095C10(Gfx **gdl, Lights3 *src) {
    Gfx *gfx = *gdl;

    if (D_800E4C5C != 0) {
        D_800C73B0[0] = src->l[0];
        D_800C73B0[1] = src->l[1];
        gSPNumLights(gfx++, NUMLIGHTS_3);
        gSPLight(gfx++, &D_800C73B0[0], 1);
        gSPLight(gfx++, &D_800C73B0[1], 2);
        gSPLight(gfx++, &D_800C73B0[2], 3);
        gSPLight(gfx++, (u8 *)D_800C73B0 - 8, 4);
        *gdl = gfx;
        return 1;
    }
    *gdl = gfx;
    return 0;
}

s32 func_80056494(s32 arg0, s32 arg1);
extern s32 D_800E4C50;
extern s32 D_800E4C5C;
extern s32 D_800E4C54;
extern s32 D_800E4C58;
extern s8 D_800E4C90;
extern s8 D_800E4C91;
extern s32 D_800C73A0;

/* arg0 passes straight through to func_80056494. */
void func_80095D10(s32 arg0, s32 arg1, s32 arg2) {
    D_800E4C50 = arg1;
    D_800E4C5C = 0;
    D_800C73A0 = 0;
    D_800E4C90 = 0;
    D_800E4C91 = 0;
    D_800E4C54 = arg2;
    D_800E4C58 = func_80056494(arg0, arg2);
}

extern s32 D_800E4C5C;

void func_80095D64(void) {
    D_800E4C5C = 0;
}

s32 func_80050BF0(s32, s32, s32);
extern s32 D_800C73A0;
extern s32 D_800C73E0;

void func_80095D70(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if ((arg1 != -1) && ((D_800C73A0 - 1) == arg0)) {
        func_80050BF0(arg1, D_800C73E0, 0x7F);
        temp_v0 = D_800C73E0 + 1;
        D_800C73E0 = temp_v0;
        if (temp_v0 >= 8) {
            D_800C73E0 = 4;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095DE0);

s32 func_80043A04(s32 x, s32 z);

/* pos is an x/y/z float vector; y is clamped to a height looked up from x
 * and z (in 1/1024 units, offset by 0x1E00). */
void func_8009676C(f32 *pos) {
    f32 height = (f32)(func_80043A04((s32)(pos[0] * 1024.0f), (s32)(pos[2] * 1024.0f)) - 0x1E00) * 0.0009765625f;

    if (height < pos[1]) {
        pos[1] = height;
    }
}

void *func_80054354(void);
void func_8005483C(s32, s32, f32 *);
void func_80079358(s32, s32);
void func_800563A8(s32, s32);
void func_80095A68(f32 *, f32 *, f32, s32);
s32 func_800299F4(s32);
extern s32 D_800BB020;
extern s32 D_801B60A0;

/* Places the camera (cam[0..2] = eye, cam[3..5] = at) behind the player,
 * looking at their ground-clamped position. In mode 12 it also points light 2
 * of the scene's Lights3 along a direction taken from func_8005483C. */
void func_800967F4(s32 player, f32 *cam) {
    f32 pos[3];
    f32 unused[4][4]; /* never touched; keeps the frame layout */
    f32 a[3];
    f32 b[3];
    u8 *obj;
    f32 dist, len, scale, height;

    obj = func_80054354();
    if (D_800E4C54 == 14) {
        dist = func_80095A10(107520.0f, 30720.0f, D_800C73A0 * 0.025f);
    } else {
        dist = func_80095A10(107520.0f, 38400.0f, D_800C73A0 * 0.025f);
    }
    if (D_800E4C54 == 12 && D_800C73A0 >= 10) {
        func_80079358(player, 3);
        func_8005483C(0, 3, a);
        func_8005483C(0, 1, b);
        a[0] -= b[0];
        a[1] -= b[1];
        a[2] -= b[2];
        len = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
        if (len > 1.0f) {
            scale = 127.0f / len;
            D_800E4C5C = 1;
            a[0] *= scale;
            a[1] *= scale;
            a[2] *= scale;
            func_800563A8(player, 2);
            D_800C73B0[2].l.col[0] = 0xFF;
            D_800C73B0[2].l.col[1] = 0xFF;
            D_800C73B0[2].l.col[2] = 0x7F;
            D_800C73B0[2].l.colc[0] = 0xFF;
            D_800C73B0[2].l.colc[1] = 0xFF;
            D_800C73B0[2].l.colc[2] = 0x7F;
            D_800C73B0[2].l.dir[0] = a[0];
            D_800C73B0[2].l.dir[1] = a[1];
            D_800C73B0[2].l.dir[2] = a[2];
        }
    }
    func_8005483C(player, 1, pos);
    height = (f32)(func_80043A04((s32)(pos[0] * 1024.0f), (s32)(pos[2] * 1024.0f)) - 0x1E00) * 0.0009765625f;
    if (height < pos[1]) {
        pos[1] = height;
    }
    if (D_800E4C54 == 12) {
        pos[1] -= 4.5f;
    }
    cam[3] = pos[0];
    cam[4] = pos[1];
    cam[5] = pos[2];
    cam[0] = pos[0] + cosf(-*(f32 *)(obj + 0x48) - 1.5707964f) * dist * 0.0009765625f;
    cam[1] = pos[1] + -1.5f;
    if (D_800E4C54 == 14) {
        cam[1] = pos[1] + -7.5f;
    }
    cam[2] = pos[2] + sinf(-*(f32 *)(obj + 0x48) - 1.5707964f) * dist * 0.0009765625f;
    func_8009676C(cam);
    func_80095A68(cam, cam + 3, 0.1f, 3);
    if (func_800299F4(0x7F) || (D_800BB020 != 30 && D_801B60A0 == 1)) {
        cam[4] -= 4.5f;
        cam[1] += 4.5f;
    }
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80096C04);

f32 func_80059FAC(f32, f32);
void func_80078FA8(s32, s32, f32);

/* Follow camera for a closer mode (cf. func_800967F4). In mode 15, after
 * frame 44 it spawns an effect to the side of the view every frame,
 * alternating left and right. */
void func_80096F44(s32 player, f32 *cam) {
    f32 pos[3];
    f32 unused[4][4]; /* never touched; keeps the frame layout */
    u8 *obj;
    f32 dist, height, dx, dz, angle;

    obj = func_80054354();
    dist = func_80095A10(61440.0f, 30720.0f, D_800C73A0 * 0.0125f);
    func_8005483C(player, 1, pos);
    height = (f32)(func_80043A04((s32)(pos[0] * 1024.0f), (s32)(pos[2] * 1024.0f)) - 0x2400) * 0.0009765625f;
    if (height < pos[1]) {
        pos[1] = height;
    }
    cam[3] = pos[0];
    cam[4] = pos[1];
    cam[5] = pos[2];
    cam[0] = pos[0] + cosf(-*(f32 *)(obj + 0x48) - 1.5707964f) * dist * 0.0009765625f;
    cam[1] = pos[1];
    cam[2] = pos[2] + sinf(-*(f32 *)(obj + 0x48) - 1.5707964f) * dist * 0.0009765625f;
    func_8009676C(cam);
    func_80095A68(cam, cam + 3, 0.1f, 3);
    if (D_800E4C54 == 15 && D_800C73A0 >= 44) {
        dx = cam[3] - cam[0];
        dz = cam[5] - cam[2];
        if ((s32)dx != 0 || (s32)dz != 0) {
            angle = func_80059FAC(dz, dx);
        } else {
            angle = 0.0f;
        }
        if (!(D_800C73A0 & 1)) {
            func_80078FA8(player, 3, angle + 1.5707963267948966);
        } else {
            func_80078FA8(player, 4, angle - 1.5707963267948966);
        }
    }
    if (func_800299F4(0x7F) || (D_800BB020 != 30 && D_801B60A0 == 1)) {
        cam[4] -= 4.5f;
        cam[1] += 4.5f;
    }
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097218);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800974D8);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800977E0);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097A08);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097C18);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80097E30);

INCLUDE_ASM("asm/nonmatchings/70E10", func_8009806C);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098310);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800985B4);

extern s8 D_800E4CC8;

void func_8009874C(void) {
    D_800E4CC8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098758);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800989C4);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800989EC);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098C6C);

u8 func_80098CA0(u8 n) {
    u8 r = 0;
    s32 i;

    for (i = 0; i < 8; i++) {
        r = r * 2;
        if (n & 1) {
            r |= 1;
        }
        n >>= 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098CD8);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098D70);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80098E48);

INCLUDE_ASM("asm/nonmatchings/70E10", func_800990D0);

/* 3-byte records; ids >= 0xC0 fall back to the first one. Placeholder. */
typedef struct Unk800C7464 {
    /* 0x0 */ u8 unk0[3];
} Unk800C7464;

extern Unk800C7464 D_800C7464[];

Unk800C7464 *func_80099454(u8 n) {
    if (n >= 0xC0) {
        return D_800C7464;
    }
    return &D_800C7464[n];
}

/* Unreferenced string; the tail of this file's .rodata. */
INCLUDE_RODATA("asm/nonmatchings/70E10", D_800D1F2C);
