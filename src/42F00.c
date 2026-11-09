#include "common.h"

INCLUDE_ASM("asm/nonmatchings/42F00", func_80067B00);

INCLUDE_ASM("asm/nonmatchings/42F00", func_80067C0C);

INCLUDE_ASM("asm/nonmatchings/42F00", func_80067CB4);

s32 func_80067B00(s32 *, s32);
s32 func_80067CB4(s32 *);

void func_80067D04(s32 arg0) {
    s32 sp10[16];

    func_80067CB4(sp10);
    func_80067B00(sp10, arg0);
}
