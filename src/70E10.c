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

INCLUDE_ASM("asm/nonmatchings/70E10", func_80095C10);

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

INCLUDE_ASM("asm/nonmatchings/70E10", func_800967F4);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80096C04);

INCLUDE_ASM("asm/nonmatchings/70E10", func_80096F44);

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
