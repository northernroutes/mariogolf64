#include "common.h"

extern s8 D_800CA184;

void func_800298E0(void) {
    osSyncPrintf(&D_800CA184);
}

extern char D_800CA1A8[];

/* Normalises the vector (*x, *y, *z); falls back to (0, 1, 0) with a warning. */
void func_80029900(f32 *x, f32 *y, f32 *z) {
    f32 vx = *x;
    f32 vy = *y;
    f32 vz = *z;
    f32 len2 = vx * vx + vy * vy + vz * vz;

    if (len2 < 0.0f) {
        osSyncPrintf(D_800CA1A8);
        *x = 0.0f;
        *y = 1.0f;
        *z = 0.0f;
    } else {
        len2 = 1.0f / sqrtf(len2);
        *x = vx * len2;
        *y = vy * len2;
        *z = vz * len2;
    }
}

s32 func_80029250(s32 *, s32);
extern s32 D_800B67D8;

void func_800299D0(void) {
    func_80029250(&D_800B67D8, 3);
}

/* A 256-entry bit array of game flags: check / set / clear / toggle flag n.
 * func_800299F4 is the "is flag set" check used throughout the game. */
extern u8 D_801052F8[];

s32 func_800299F4(u32 n) {
    if (n >= 0x100) {
        return 0;
    }
    return (D_801052F8[n >> 3] & (0x80 >> (n & 7))) != 0;
}

void func_80029A30(u32 n) {
    u32 i = n >> 3;

    if (n < 0x100) {
        D_801052F8[i] |= 0x80 >> (n & 7);
    }
}

void func_80029A6C(u32 n) {
    u32 i = n >> 3;

    if (n < 0x100) {
        D_801052F8[i] &= 0xFF7F >> (n & 7);
    }
}

void func_80029AA8(u32 n) {
    u32 i = n >> 3;

    if (n < 0x100) {
        D_801052F8[i] ^= 0x80 >> (n & 7);
    }
}

extern s8 D_80105317;

void func_80029AE4(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x1F;
    var_v0 = &D_80105317;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}

extern char D_800CA1B8[];

void func_80029B08(void) {
    s32 i;

    while (1) {
        for (i = 0; i != 100000000; i++) {
        }
        osSyncPrintf(D_800CA1B8, 100000000);
    }
}

extern char D_800CA1C4[];
extern u8 D_80132D00[];
s32 func_800577D0(void);
void func_800577DC(s32, void *);

void func_80029B58(void) {
    s32 n;

    n = func_800577D0();
    func_800577DC(1, D_80132D00);
    func_800577DC(3, D_80132D00 + n);
    func_800577DC(2, D_80132D00 + n * 2);
    osSyncPrintf(D_800CA1C4, 0x827E0 - n * 3);
}

s32 func_8006F4F0();
extern s8 g_mus_audio_paused;

void func_80029BD8(void) {
    func_8006F4F0();
    g_mus_audio_paused = 1;
}

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029C00);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029C34);

s32 func_80029EEC(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
    u32 mag;

    mag = arg0;
    if (arg0 < 0) {
        mag = -arg0;
    }
    if (mag > arg3) {
        if (mag < arg2) {
            arg0 = arg1;
        }
    } else {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }
    return (arg0 < 0) ? -1 : 1;
}

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029F28);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029F6C);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A144);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A310);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A434);
