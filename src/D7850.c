#include "common.h"

s32 func_800299F4(s32);
void func_8004DA24(char *, s32, s32);
extern u16 D_800FBDD2;
extern char D_80105118[];
extern s32 D_ovl0_80224BD0;
extern char D_ovl0_80225690[];

void func_ovl0_8021E550(void) {
    if (func_800299F4(0x6E)) {
        if (D_800FBDD2 & 0x800) {
            D_ovl0_80224BD0--;
        }
        if (D_800FBDD2 & 0x400) {
            D_ovl0_80224BD0++;
        }
        sprintf(D_80105118, D_ovl0_80225690, D_ovl0_80224BD0);
        func_8004DA24(D_80105118, 0x14, 5);
    }
}

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

void func_ovl0_8021E550(void);
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
