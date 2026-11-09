#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800400A0);

typedef struct Unk800BB040 {
    /* 0x0 */ s8 r;
    /* 0x1 */ s8 g;
    /* 0x2 */ s8 b;
    /* 0x3 */ s8 unk3;
} Unk800BB040; /* size = 0x4 */

extern Unk800BB040 D_800BB040[];

/* Index of the palette entry closest (Manhattan distance) to an RGBA5551 colour. */
s32 func_8004018C(s32 color) {
    s32 best = 1000000;
    s32 bestIdx = 0;
    s32 r = (color >> 11) & 0x1F;
    s32 g = (color >> 6) & 0x1F;
    s32 b = (color >> 1) & 0x1F;
    s32 dr;
    s32 dg;
    s32 db;
    s32 dist;
    s32 i;

    for (i = 0; i < 11; i++) {
        dr = r - D_800BB040[i].r;
        if (dr < 0) {
            dr = -dr;
        }
        dg = g - D_800BB040[i].g;
        if (dg < 0) {
            dg = -dg;
        }
        db = b - D_800BB040[i].b;
        dist = dr + dg;
        if (db < 0) {
            db = -db;
        }
        dist += db;
        if (dist < best) {
            best = dist;
            bestIdx = i;
        }
    }
    return bestIdx;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80040234);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800402F4);

/* Placeholder types for func_80040380; real types unknown. */
typedef struct Unk80040380 {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s8 unk8;
    /* 0x9 */ s8 unk9;
    /* 0xA */ s8 unkA;
} Unk80040380;

typedef struct Unk80040380Mask {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s32 unk8;
} Unk80040380Mask;

s32 func_800449D4(s32 arg0, Unk80040380 *arg1);

void func_80040380(Unk80040380 *arg0, Unk80040380Mask *arg1, s32 *out) {
    s32 v;

    if (arg1->unk8 & func_800449D4(1, arg0)) {
        out[0] = arg0->unk8;
        out[1] = arg0->unk9;
        return;
    }
    v = arg0->unk8 - arg0->unkA;
    out[0] = v;
    if (v < 5) {
        out[0] = 5;
    }
    v = arg0->unk9 - arg0->unkA;
    out[1] = v;
    if (v < 5) {
        out[1] = 5;
    }
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80040428);

f32 func_800407D8(s32 arg0) {
    return (f32) arg0;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800407E8);

s32 func_800407E8(s32 arg0, s32 arg1, s32 arg2);

/* Passes its first two arguments straight through. */
s32 func_80040E20(s32 arg0, s32 arg1) {
    return func_800407E8(arg0, arg1, 0);
}

s32 func_80032E60(s32);
s32 func_80040E20();

void func_80040E3C(s32 arg0, s32 arg1) {
    func_80032E60(func_80040E20(arg0, arg1));
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80040E60);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80040EF8);

s32 func_80041058(s32 arg0, s32 arg1, s32 arg2) {
    return func_80040E20(arg0, arg2) == 5;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_8004107C);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041160);

/* Object returned by func_80041344; only the s16 at 2 is known. */
typedef struct Unk80041344 {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ u8 unkC;
    /* 0xD */ u8 unkD;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 unkF;
} Unk80041344; /* size = 0x10 */

extern Unk80041344 D_80182D00[];

/* Out-of-range coordinates fall back to entry 0. */
Unk80041344 *func_80041344(u32 x, u32 y) {
    Unk80041344 *ret;

    if ((x >= 18) | (y >= 34)) {
        ret = &D_80182D00[0];
    } else {
        ret = &D_80182D00[y * 17 + (x >> 1) + (x & 1) * 9];
    }
    return ret;
}

s16 func_800413A0(s32 arg0, s32 arg1) {
    return func_80041344(arg0, arg1)->unk2;
}

/* Initialises slot (x, y): position, extent and a grey level. */
void func_800413C0(s32 x, s32 y, s32 arg2, u8 shade) {
    Unk80041344 *p = func_80041344(x, y);

    p->unk0 = x << 8;
    p->unk4 = y << 8;
    p->unk2 = arg2 & 0xFFFE;
    p->unk6 = 0;
    p->unk8 = (x << 10) + 0x20;
    p->unkA = (y << 10) + 0x20;
    if (y == 0x20) {
        p->unkA = 0x7FFF;
    }
    p->unkC = shade;
    p->unkD = shade;
    p->unkE = shade;
    p->unkF = 0xFF;
}

void func_80041464(s32 arg0, s32 arg1, s32 arg2) {
    func_80041344(arg0, arg1)->unk2 = arg2 & 0xFFFE;
}

void func_80041490(s32 arg0, s32 arg1, u8 arg2) {
    Unk80041344 *p = func_80041344(arg0, arg1);

    p->unkC = arg2;
    p->unkD = arg2;
    p->unkE = arg2;
}

typedef struct Unk800414C0 {
    /* 0x0 */ u8 data[0x10];
} Unk800414C0;

void func_800414C0(s32 arg0, s32 arg1, Unk800414C0 *src) {
    *(Unk800414C0 *)func_80041344(arg0, arg1) = *src;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041524);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800415C4);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041878);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041AA8);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041B98);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041D44);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041E8C);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041EC0);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80042228);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80042318);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800425C8);

extern s32 func_802504E8;

s32 func_80042720(void) {
    return (u32) &func_802504E8 > 0x803FFFFFU;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80042738);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800427E8);

Unk80041344 *func_80042DF4(Unk80041344 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk80041344 *ret;

    if (arg3 & 0x80) {
        ret = func_80041344(arg1 * 2 + ((arg3 >> 2) & 3), arg2 * 2 + (arg3 & 3));
    } else {
        ret = &arg0[arg3];
    }
    return ret;
}

s32 func_80042E40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return ((arg2 - arg0) * (arg5 - arg1)) - ((arg3 - arg1) * (arg4 - arg0));
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80042E78);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800432E4);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_8004333C);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80043620);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800437FC);

s32 func_800437FC();

void func_80043A04(void) {
    func_800437FC();
}

s32 func_800437FC(s32, s32);
s32 func_8003AE50(s32, s32, s32, s32, s32, s32, void *, f32 *);

/* Height at (x, z): func_800437FC, lowered to a vertical ray hit if there is one. */
s32 func_80043A20(s32 x, s32 z) {
    s32 sp20[6];
    f32 hit[0x22];
    s32 h = func_800437FC(x, z);
    s32 t;

    if (func_8003AE50(x, -0x2EE000, z, x, 0x2EE000, z, sp20, hit)) {
        t = hit[0] * 6144000.0f + -3072000.0f;
        if (t < h) {
            h = t;
        }
    }
    return h;
}
