#include "common.h"

extern s8 D_ovl5_8025C848;

void func_ovl5_8024D800(void) {
    D_ovl5_8025C848 = 0;
}

void func_ovl5_8024D870(void *);
extern s32 D_ovl5_80253C64;
extern OSThread D_ovl5_80254300;
extern s32 D_ovl5_8025A640;

void func_ovl5_8024D80C(void) {
    func_ovl5_8024D800();
    D_ovl5_80253C64 = 0;
    osCreateThread(&D_ovl5_80254300, 0xB, func_ovl5_8024D870, NULL, &D_ovl5_8025A640, 0x14);
    osStartThread(&D_ovl5_80254300);
}

s32 func_ovl5_8024DBF8(s32 *);
extern s32 D_ovl5_802544B0;

void func_ovl5_8024D870(void *arg0) {
    do {

    } while (func_ovl5_8024DBF8(&D_ovl5_802544B0) == -1);
    D_ovl5_80253C64 = 2;
loop_3:
    goto loop_3;
}

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024D8B4);

/* 0xB8-byte entries starting at D_801B71F3 (s8 at the start). Placeholder. */
/* An s32 x/y/z position. */
typedef struct Unk80251570 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
} Unk80251570;

typedef struct Unk801B71F3 {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ u8 pad1[0xB7];
} Unk801B71F3; /* size = 0xB8 */

extern Unk801B71F3 D_801B71ED[];
extern Unk801B71F3 D_801B71F3[];
extern s8 D_800BAA04;
extern s32 D_ovl5_8025C640;
extern s32 D_ovl5_8025C884;

extern s8 D_ovl5_80253B52[][0xE];

s8 func_ovl5_8024D958(void) {
    return D_ovl5_80253B52[D_801B71ED[D_ovl5_8025C884].unk0][0];
}

s32 func_ovl5_8024D99C(void) {
    return D_801B71F3[D_ovl5_8025C884].unk0 >= D_800BAA04 + D_ovl5_8025C640 - 1;
}

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024D9E8);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024DBF8);

s32 func_8006A0CC(s32, s32);
extern Unk80251570 D_800BA9D8;
extern Unk80251570 D_ovl5_8025C874;

void func_ovl5_8024F070(void) {
    func_8006A0CC(D_ovl5_8025C874.x - D_800BA9D8.x, D_ovl5_8025C874.z - D_800BA9D8.z);
}

extern s32 D_800BA9F0;
extern u16 D_800BA9F4;
extern char D_ovl5_80253ED0[];
extern char D_ovl5_80253EE0[];

/* Returns the heading from D_800BA9D8 to D_ovl5_8025C874, scaled by up to
 * +/-20% by how far the D_800BA9F4/D_800BA9F0 vector (wind?) points along
 * that heading when the two are at least 153600 apart, plus 0.1x the
 * height difference. */
s32 func_ovl5_8024F0B0(void) {
    s32 angle;
    f32 dx, dz, dist, inv, dir, c, s, k;

    angle = func_8006A0CC(D_ovl5_8025C874.x - D_800BA9D8.x, D_ovl5_8025C874.z - D_800BA9D8.z);
    dx = D_800BA9D8.x - D_ovl5_8025C874.x;
    dz = D_800BA9D8.z - D_ovl5_8025C874.z;
    dist = sqrtf(dx * dx + dz * dz);
    dir = D_800BA9F4 * 9.58738e-05f;
    if (dist >= 153600.0f) {
        inv = 1.0f / dist;
        dx *= inv;
        dz *= inv;
        c = cosf(dir) * D_800BA9F0 * (1.0f / 65536);
        s = sinf(dir) * D_800BA9F0 * (1.0f / 65536);
        k = dx * c + dz * s;
        osSyncPrintf(D_ovl5_80253ED0, k);
        k = -k * 0.01f + 1.0f;
        osSyncPrintf(D_ovl5_80253EE0, k);
        if (k < 0.8f) {
            k = 0.8f;
        }
        if (k >= 1.2f) {
            k = 1.2f;
        }
        angle = angle * k;
    }
    return angle + (D_ovl5_8025C874.y - D_800BA9D8.y) * 0.1f;
}

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024F320);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024F688);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024F790);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8024F844);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_802504A0);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80250768);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_802507D8);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_802510D0);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80251198);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80251378);

s32 func_ovl5_80251378(Unk80251570 *, Unk80251570 *, Unk80251570 *);

s32 func_ovl5_80251570(Unk80251570 *a, Unk80251570 *b) {
    Unk80251570 hit;

    if (func_ovl5_80251378(a, b, &hit) == 1) {
        return func_8006A0CC(hit.x - a->x, hit.z - a->z);
    }
    return func_8006A0CC(b->x - a->x, b->z - a->z);
}

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_802515DC);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_802517F0);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80251AC0);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80251B20);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80252EE4);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80252F70);

s32 func_ovl5_80253180(s32 arg0, s32 arg1) {
    arg0 = (s16)(arg0 - arg1);
    return (arg0 < 0) ? -arg0 : arg0;
}

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_8025319C);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80253574);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80253754);

INCLUDE_ASM("asm/nonmatchings/1300A0", func_ovl5_80253978);
