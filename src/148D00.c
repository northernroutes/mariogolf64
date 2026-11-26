#include "common.h"

s32 func_800542A0(s32);
void func_80055AF4(s32, s32, s32);
void func_800560FC(s32, s32);
void func_800562F4(s32, f32);
void func_80054240(s32);

s32 func_ovl7_80206680(s32 arg0, s32 arg1) {
    s32 ret;

    if (func_800542A0(arg0) == 0) {
        func_80055AF4(arg0, arg1, 4);
        func_800560FC(arg0, 13);
        func_800562F4(arg0, 1.0f);
        ret = 1;
    } else {
        func_80054240(arg0);
        ret = 0;
    }
    return ret;
}

/* 0x1C-byte entries of D_ovl7_8020B564. Placeholder. */
typedef struct UnkOvl7_8020B564 {
    /* 0x00 */ u8 pad0[0x1C];
} UnkOvl7_8020B564;

extern UnkOvl7_8020B564 D_ovl7_8020B564[27];

/* Entry n, or entry 0 if n is out of range. */
UnkOvl7_8020B564 *func_ovl7_802066F0(u32 n) {
    n = (n < 27) ? n : 0;
    return &D_ovl7_8020B564[n];
}

/* 0xB8-byte entries at D_800B7868 (same code as func_80032E88 in E260.c). Placeholder. */
typedef struct Unk800B7868 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x58];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x40];
} Unk800B7868; /* size = 0xB8 */

s32 rand(void);
extern Unk800B7868 D_800B7868[1];

void func_ovl7_80206718(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_800B7868[i].unk0 = 0x800;
        D_800B7868[i].unk4 = -1000;
        rand();
        D_800B7868[i].unk8 = 0x1000;
        D_800B7868[i].unkC = rand() & 0x3FF;
        D_800B7868[i].unk10 = -100;
        D_800B7868[i].unk14 = rand() & 0x3FF;
        D_800B7868[i].unk18 = 0;
        D_800B7868[i].unk74 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206800);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_802068B4);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_802068EC);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206910);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206968);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206A50);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_80206AA4);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_8020A474);

INCLUDE_ASM("asm/nonmatchings/148D00", func_ovl7_8020A488);
