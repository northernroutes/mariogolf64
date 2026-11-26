#include "common.h"

extern s8 D_800C3100;

void func_800660A0(void) {
    D_800C3100 = 1;
}

INCLUDE_ASM("asm/nonmatchings/414A0", func_800660B0);

INCLUDE_ASM("asm/nonmatchings/414A0", func_80066B50);

INCLUDE_ASM("asm/nonmatchings/414A0", func_800674B8);

void func_800679DC(void);
extern s32 D_8018D220;
extern s16 D_8018D228;
extern s16 D_8018D22A;
extern s16 D_8018D22C;
extern s16 D_8018D238;
extern s16 D_8018D23A;
extern s16 D_8018D23C;
extern s16 D_8018D248;
extern s16 D_8018D24A;
extern s16 D_8018D24C;

void func_800676B0(void) {
    D_8018D220 = 1;
    D_8018D228 = 0x800;
    D_8018D22A = -0x100;
    D_8018D22C = 0x1000;
    D_8018D238 = 0x800;
    D_8018D23A = -0x100;
    D_8018D23C = 0xF00;
    D_8018D248 = 0x700;
    D_8018D24A = -0x100;
    D_8018D24C = 0xF00;
    func_800679DC();
}

INCLUDE_ASM("asm/nonmatchings/414A0", func_80067730);

/* 0xB8-byte per-player entries (8 bytes below D_801B7250 in BBD00.c). Placeholder. */
typedef struct Unk801B7248 {
    /* 0x00 */ s8 unk0[3];
    /* 0x03 */ u8 pad3[0xB5];
} Unk801B7248; /* size = 0xB8 */

void func_800674B8(void);
s32 func_80067730(void);
extern s8 D_801B60B8;
extern Unk801B7248 D_801B7248[4];

void func_800679DC(void) {
    s32 n;
    s32 i;
    s32 j;

    func_800674B8();
    n = func_80067730();
    if (n >= 3) {
        n = 3;
    }
    if (D_801B60B8 != 2) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                D_801B7248[i].unk0[j] = j < n;
            }
        }
    }
}

s32 func_80050DA0(s32, s32, s32, s32, s32);
extern s16 D_800C3130[][34];

void func_80067A60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 v = (arg0 != 3) ? 0x14 : 0;

    if (arg3 == -1) {
        func_80050DA0(D_800C3130[arg0][arg2], arg1 + 4, D_800C3130[arg0][arg2 + 1], v, arg4);
    } else {
        func_80050DA0(D_800C3130[arg0][arg2], arg1 + 4, arg3, v, arg4);
    }
}
