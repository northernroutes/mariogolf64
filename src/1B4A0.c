#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800400A0);

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_8004018C);

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

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80041344);

/* Object returned by func_80041344; only the s16 at 2 is known. */
typedef struct Unk80041344 {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 pad4[0x8];
    /* 0xC */ u8 unkC;
    /* 0xD */ u8 unkD;
    /* 0xE */ u8 unkE;
} Unk80041344;

Unk80041344 *func_80041344();

s16 func_800413A0(void) {
    return func_80041344()->unk2;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800413C0);

void func_80041464(s32 arg0, s32 arg1, s32 arg2) {
    func_80041344()->unk2 = arg2 & 0xFFFE;
}

void func_80041490(s32 arg0, s32 arg1, u8 arg2) {
    Unk80041344 *p = func_80041344();

    p->unkC = arg2;
    p->unkD = arg2;
    p->unkE = arg2;
}

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_800414C0);

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

INCLUDE_ASM("asm/nonmatchings/1B4A0", func_80043A20);
