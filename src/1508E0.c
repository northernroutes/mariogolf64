#include "common.h"

s32 func_80050BF0(s32, s32, s32);
s32 func_800719A0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8009226C(s32);
extern s32 D_800BB020;
extern s32 D_800BB024;
extern s32 D_800BB02C;
extern s32 D_800BB030;
extern u16 D_800FBDC4;

void func_ovl10_801F4A40(void) {
    if (D_800FBDC4 & 0x9000) {
        func_8009226C(8);
        D_800BB020 = 0x19;
        D_800BB024 = 0x1B;
        D_800BB02C = 0xD;
        D_800BB030 = 0xC;
        func_80050BF0(0x5D, 0xF, 0x7F);
        func_800719A0(0xA0, 0x72, -1, 1, 0, 0, 0, 0, 0, 0);
    }
}

void func_ovl10_801F4AD8(s32 *arg0) {
    *arg0 = *arg0;
}
