#include "common.h"

/* Per-(a, b) value lookup with 200 as the default (30 for a = 6/7). */
s32 func_80051E90(s32 a, s32 b) {
    switch (a) {
        case 0:
            if (b == 10) {
                return 400;
            }
            if (b == 16) {
                return 400;
            }
            break;
        case 1:
            if (b == 1) {
                return 400;
            }
            if (b == 5) {
                return 600;
            }
            if (b == 7) {
                return 150;
            }
            if (b == 16) {
                return 300;
            }
            break;
        case 2:
            if (b == 2) {
                return 300;
            }
            if (b == 12) {
                return 600;
            }
            if (b == 16) {
                return 550;
            }
            break;
        case 3:
            if (b == 2) {
                return 300;
            }
            if (b == 4) {
                return 1000;
            }
            if (b == 9) {
                return 700;
            }
            if (b == 10) {
                return 400;
            }
            if (b == 11) {
                return 450;
            }
            if (b == 12) {
                return 400;
            }
            if (b == 13) {
                return 600;
            }
            if (b == 16) {
                return 900;
            }
            break;
        case 4:
            if (b == 10) {
                return 400;
            }
            if (b == 15) {
                return 300;
            }
            break;
        case 5:
            if (b == 15) {
                return 400;
            }
            if (b == 16) {
                return 700;
            }
            if (b == 17) {
                return 400;
            }
            break;
        case 6:
        case 7:
            return 30;
    }
    return 200;
}

INCLUDE_ASM("asm/nonmatchings/2D290", func_80051FCC);

INCLUDE_ASM("asm/nonmatchings/2D290", func_80052070);

INCLUDE_ASM("asm/nonmatchings/2D290", func_800520DC);

extern s8 D_800B67C0;
extern s8 D_801B60C2;
extern u8 D_800C143C[][20][10];

s32 func_80052100(s32 a, s32 b) {
    if (D_801B60C2 != 0) {
        return 0;
    }
    if ((D_800B67C0 != 0) & (b == 0)) {
        return 1;
    }
    return D_800C143C[a][b][0] & 1;
}

extern s8 D_801B60C2;
extern u8 D_800C143C[][20][10];

s32 func_80052168(s32 a, s32 b) {
    if (D_801B60C2 != 0) {
        return 0;
    }
    return D_800C143C[a][b][0] & 2;
}
