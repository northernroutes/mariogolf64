#include "common.h"

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E550);

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E5F4);

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E6B8);

extern u8 D_ovl0_80224B23;
extern s32 D_ovl0_80224B24;

void func_ovl0_8021E710(void) {
    D_ovl0_80224B24 = 0;
    D_ovl0_80224B23 = 0;
}

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E724);

s32 func_ovl0_8021EA48(void) {
    return D_ovl0_80224B23 == 0;
}

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021EA58);

s32 func_ovl0_8021E550();
s32 func_ovl0_8021EA58(s32 *);
extern s8 D_801061C4;

void func_ovl0_8021FC20(s32 *arg0) {
    s32 sp10;

    sp10 = *arg0;
    if (D_801061C4 != 0) {
        func_ovl0_8021E550();
        func_ovl0_8021EA58(&sp10);
        *arg0 = sp10;
    }
}
