#include "common.h"

/* 0x8C-byte entries of D_800FF1E8. Placeholder. */
typedef struct Unk800FF1E8 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x26];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x60];
} Unk800FF1E8; /* size = 0x8C */

extern Unk800FF1E8 D_800FF1E8[];

void func_8006F1A0(s32 arg0, s32 arg1) {
    D_800FF1E8[arg0].unk28 += arg1;
    if (D_800FF1E8[arg0].unk28 >= 10000) {
        D_800FF1E8[arg0].unk28 = 9999;
    }
}

extern s32 D_800FE4A8;

s32 func_8006F1F0(void) {
    return D_800FE4A8;
}

s32 func_8006F1FC(s32 arg0) {
    return D_800FF1E8[arg0].unk0 == 1;
}

u8 *func_8006F228(s32 arg0) {
    return &D_800FF1E8[arg0].unk1;
}

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006F24C);

extern s32 D_800C42D4;

void func_8006F2E8(void) {
    D_800C42D4 = 0;
}

s32 func_8006F2F4(void) {
    return D_800C42D4;
}

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006F300);

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006F404);

s32 nuContRmbForceStop();

void func_8006F4F0(void) {
    nuContRmbForceStop();
}

extern s8 D_800D1540;

void func_8006F50C(void) {
    nuContRmbForceStop();
    osSyncPrintf(&D_800D1540);
}

s32 nuContGBPakCheckConnector(s32, s32);
s32 nuContGBPakFread(s32, s32, s32, s32);
s32 nuContGBPakFwrite(s32, s32, s32, s32);
s32 nuContGBPakGetStatus(s32, s32);
s32 nuContGBPakMgrInit();
s32 nuContGBPakPower(s32, s32);
s32 nuContGBPakReadID(s32, s32, s32);
s32 nuContGBPakReadWrite(s32, s32, s32, s32, s32);

void func_8006F534(void) {
    nuContGBPakMgrInit();
    nuContGBPakGetStatus(0, 0);
    nuContGBPakPower(0, 1);
    nuContGBPakReadWrite(0, 1, 0, 0, 0x20);
    nuContGBPakCheckConnector(0, 0);
    nuContGBPakReadID(0, 0, 0);
    nuContGBPakReadWrite(0, 0, 0, 0, 0);
    nuContGBPakFread(0, 0, 0, 0);
    nuContGBPakFwrite(0, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006F5E0);

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006F734);

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_8006FE88);

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_800708B4);

INCLUDE_ASM("asm/nonmatchings/4A5A0", func_80070BCC);
