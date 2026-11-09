#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2D290", func_80051E90);

INCLUDE_ASM("asm/nonmatchings/2D290", func_80051FCC);

INCLUDE_ASM("asm/nonmatchings/2D290", func_80052070);

INCLUDE_ASM("asm/nonmatchings/2D290", func_800520DC);

INCLUDE_ASM("asm/nonmatchings/2D290", func_80052100);

extern s8 D_801B60C2;
extern u8 D_800C143C[][20][10];

s32 func_80052168(s32 a, s32 b) {
    if (D_801B60C2 != 0) {
        return 0;
    }
    return D_800C143C[a][b][0] & 2;
}
