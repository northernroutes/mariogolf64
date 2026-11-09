#include "common.h"

s32 func_8004E2DC(s32);
extern s32 D_ovl0_80224114;
extern s32 D_ovl0_80224120;
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_8022D650;

void func_ovl0_8020E740(void) {
    u8 pad_unused[0x20]; /* unused; sizes the stack frame */
    D_ovl0_80224114 = -1;
    D_ovl0_80224124 = 1;
    D_ovl0_8022D650 = func_8004E2DC(0x6270);
    D_ovl0_80224120 = -1;
}

s32 func_8004E47C(s32 *);
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_8022D650;

void func_ovl0_8020E78C(void) {
    D_ovl0_80224124 = 0;
    func_8004E47C(&D_ovl0_8022D650);
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020E7B4);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020EBBC);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020ED54);

void func_ovl0_8020EEEC(s32 *arg0) {
    *arg0 = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020EEF8);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FAE8);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FC10);

extern s32 D_ovl0_80224410;

s32 func_ovl0_8020FFD8(void) {
    return ~D_ovl0_80224410 == 0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FFEC);

extern s32 D_ovl0_80224418;

s32 func_ovl0_8021035C(void) {
    return D_ovl0_80224418 >= 0xC;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80210370);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802104BC);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80210F40);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8021169C);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80211D60);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80212590);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802129C0);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80212CE0);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213038);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213634);

extern s32 D_ovl0_802246F8;

s32 func_ovl0_80213C64(void) {
    return ~D_ovl0_802246F8 != 0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213C78);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213D70);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8021419C);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80214250);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
s32 func_800772B0();
extern s32 D_ovl0_80224114;
extern s32 D_ovl0_80224120;
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_80224848;
extern s32 D_ovl0_8022484C;
extern s32 D_ovl0_8022D650;

void func_ovl0_80216130(s32 arg0) {
    s32 sp10[8];

    if (D_ovl0_80224124 == 1) {
        if (arg0 == -1) {
            D_ovl0_80224848 = -1;
            return;
        }
        D_ovl0_80224848 = 0;
        D_ovl0_8022484C = 0x6CF;
        func_8005062C(0x6CF, sp10);
        func_800506D4(D_ovl0_8022D650, sp10);
        func_8005062C(0x6AF, sp10);
        func_800506D4(D_ovl0_8022D650 + 0x808, sp10);
        D_ovl0_80224120 = -1;
        D_ovl0_80224114 = -1;
        func_800772B0();
    }
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802161D4);
