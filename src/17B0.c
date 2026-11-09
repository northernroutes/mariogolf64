#include "common.h"

INCLUDE_ASM("asm/nonmatchings/17B0", func_800263B0);

s32 func_800263B0();
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

s32 func_800263B0();
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
