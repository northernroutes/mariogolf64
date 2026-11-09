#include "common.h"

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_80213390);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_ovl3_8023AA44;

void func_ovl3_8021342C(s32 arg0) {
    s32 sp10[8];

    D_ovl3_8023AA44 = arg0;
    func_8005062C(0x8E9, sp10);
    func_800506D4(D_ovl3_8023AA44, sp10);
}

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_80213464);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_80213558);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_80213748);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_802144E4);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_802149A8);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_8021508C);

INCLUDE_ASM("asm/nonmatchings/FD310", func_ovl3_8021585C);
