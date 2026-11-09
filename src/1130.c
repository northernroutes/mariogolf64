#include "common.h"

s32 func_80080DCC();
s32 func_801FD624();

void func_80025D30(void) {
    func_80080DCC();
    func_801FD624();
}

s32 func_801F5018();
s32 func_802033B0();

void func_80025D54(void) {
    func_802033B0();
    func_801F5018();
}

INCLUDE_ASM("asm/nonmatchings/1130", func_80025D78);

INCLUDE_ASM("asm/nonmatchings/1130", func_80025D8C);

s32 func_800299F4(s32);
extern s8 D_800C9F70;

s32 func_80025EC8(s32 arg0) {
    s32 var_v0;

    if (((arg0 < 0x100) | ((u32) arg0 >= 0x111U)) != 0) {
        var_v0 = 0;
        if (func_800299F4(0x4D) == 0) {
            osSyncPrintf(&D_800C9F70);
            return 0;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = arg0 & 0xFF;
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/1130", func_80025F18);

INCLUDE_ASM("asm/nonmatchings/1130", func_800260C4);

INCLUDE_ASM("asm/nonmatchings/1130", func_80026230);

s32 func_800299F4(s32);
extern s8 D_800CA09C;

s32 func_80026358(void) {
    if (func_800299F4(0x4D) == 0) {
        osSyncPrintf(&D_800CA09C);
    }
    if (func_800299F4(0x4D) == 0) {
        osSyncPrintf(&D_800CA09C);
    }
    return 0;
}
