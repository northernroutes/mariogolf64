#include "common.h"

s32 func_80050BF0(s32, s32, s32);
s32 func_8005AF50();
s32 func_8005DF54(s32, s32);
s32 func_80099490();
s32 func_ovl8_801F5604();
s32 func_ovl8_801F56E4();

void func_ovl8_801F55A0(void) {
    s32 temp_s0;

    temp_s0 = func_8005AF50();
    func_80050BF0(0x69, 0xD, 0x50);
    func_80099490();
    func_8005DF54(temp_s0, 0);
    func_ovl8_801F5604();
    func_ovl8_801F56E4();
    func_8005DF54(temp_s0, 1);
}

INCLUDE_ASM("asm/nonmatchings/14F5E0", func_ovl8_801F5604);

INCLUDE_ASM("asm/nonmatchings/14F5E0", func_ovl8_801F56E4);

void func_ovl8_801F5780(void) {
    s32 obj = func_8005AF50();
    s32 i;
    s32 j;

    func_80099490();
    func_8005DF54(obj, 0);
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 3; j++) {
            /* 0x74-byte entries from 0xEA4; s32[3] at 0x24 within each */
            ((s32 *)(obj + i * 0x74 + 0xEC8))[j] = 1;
        }
    }
    func_8005DF54(obj, 1);
}

INCLUDE_ASM("asm/nonmatchings/14F5E0", func_ovl8_801F57F8);
