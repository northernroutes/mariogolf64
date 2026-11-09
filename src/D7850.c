#include "common.h"

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E550);

INCLUDE_ASM("asm/nonmatchings/D7850", func_ovl0_8021E5F4);

extern s32 D_ovl0_80224B2C;
extern s32 D_ovl0_8022D690;
extern s32 D_ovl0_8022D694;
extern s32 D_801B5CD0[];
void func_8004E47C(void *);

void func_ovl0_8021E6B8(void) {
    s32 *p;

    D_ovl0_80224B2C = -1;
    func_8004E47C(&D_ovl0_8022D690);
    func_8004E47C(&D_ovl0_8022D694);
    p = &D_801B5CD0[12];
    func_8004E47C(p);
    func_8004E47C(p + 1);
}

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
