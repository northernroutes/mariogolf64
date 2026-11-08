#include "common.h"

extern s8 D_800CA184;

void func_800298E0(void) {
    osSyncPrintf(&D_800CA184);
}

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029900);

s32 func_80029250(s32 *, s32);
extern s32 D_800B67D8;

void func_800299D0(void) {
    func_80029250(&D_800B67D8, 3);
}

INCLUDE_ASM("asm/nonmatchings/4CE0", func_800299F4);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029A30);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029A6C);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029AA8);

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

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029B08);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029B58);

s32 func_8006F4F0();
extern s8 g_mus_audio_paused;

void func_80029BD8(void) {
    func_8006F4F0();
    g_mus_audio_paused = 1;
}

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029C00);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029C34);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029EEC);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029F28);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_80029F6C);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A144);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A310);

INCLUDE_ASM("asm/nonmatchings/4CE0", func_8002A434);
