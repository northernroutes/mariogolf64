#include "common.h"

/* 0x10-byte entries of D_800B6290. Placeholder. */
typedef struct Unk800B6290 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u8 pad4[0xC];
} Unk800B6290;

extern Unk800B6290 D_800B6290[46];
extern char D_800CA0D0[];
extern s8 D_800B6564;
void func_8004DDE4(s32);

void func_800263B0(void) {
    u32 i;

    osSyncPrintf(D_800CA0D0);
    for (i = 0; i < 46; i++) {
        D_800B6290[i].unk0 = 0;
    }
    func_8004DDE4(1);
    D_800B6564 = 0;
}

void func_800263B0(void);
s32 func_8004DD70(s32, s32, s32);
extern s8 D_800B6564;
extern s32 D_800B6568;
extern s32 D_800B656C;
extern s8 D_800CA0E0;

void func_80026400(s32 arg0, s32 arg1) {
    s32 temp_s0;

    osSyncPrintf(&D_800CA0E0);
    temp_s0 = arg0 + arg1;
    func_800263B0();
    D_800B6568 = arg0;
    D_800B656C = temp_s0;
    func_8004DD70(1, arg0, temp_s0);
    D_800B6564 = 1;
}

void func_800263B0(void);
s32 func_8004DD70(s32, s32, s32);
extern s8 D_800B6564;
extern s32 D_800B6568;
extern s32 D_800B656C;
extern s8 D_800CA0F0;

void func_8002646C(void) {
    osSyncPrintf(&D_800CA0F0);
    func_800263B0();
    func_8004DD70(1, D_800B6568, D_800B656C);
    D_800B6564 = 1;
}

INCLUDE_ASM("asm/nonmatchings/17B0", func_800264BC);

INCLUDE_ASM("asm/nonmatchings/17B0", func_8002671C);

INCLUDE_ASM("asm/nonmatchings/17B0", func_8002687C);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80026CC4);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80027ACC);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80028110);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80028204);
