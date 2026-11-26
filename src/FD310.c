#include "common.h"

extern u16 D_800C2064[];
extern s32 *D_ovl3_8023AA40;

/* Loads resources D_800C2064[0..5] into the handles in out. */
void func_ovl3_80213390(s32 *out) {
    s32 sp10[8];
    s16 i;

    D_ovl3_8023AA40 = out;
    for (i = 0; i != 6; i++) {
        func_8005062C(D_800C2064[i], sp10);
        func_800506D4(D_ovl3_8023AA40[i], sp10);
    }
}

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
