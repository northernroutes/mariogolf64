#include "common.h"

INCLUDE_ASM("asm/nonmatchings/40180", func_80064D80);

INCLUDE_ASM("asm/nonmatchings/40180", func_80065070);

INCLUDE_ASM("asm/nonmatchings/40180", func_800653CC);

extern f32 D_800E16F8;
extern f32 D_800E1708;
extern f32 D_800E1718;
extern f32 D_800E1728;

s32 func_80065600(f32 arg0, f32 arg1, f32 arg2) {
    return (s32) ((D_800E16F8 * arg0) + (D_800E1708 * arg1) + (D_800E1718 * arg2) + D_800E1728);
}

INCLUDE_ASM("asm/nonmatchings/40180", func_80065650);

INCLUDE_ASM("asm/nonmatchings/40180", func_80065898);

INCLUDE_ASM("asm/nonmatchings/40180", func_80065A1C);

INCLUDE_ASM("asm/nonmatchings/40180", func_80065B98);

/* out = a * b for 4x4 float matrices. */
void func_80065D5C(f32 a[4][4], f32 b[4][4], f32 out[4][4]) {
    s32 i;
    s32 j;

    for (i = 0; i != 4; i++) {
        for (j = 0; j != 4; j++) {
            out[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/40180", func_80065DD8);

INCLUDE_ASM("asm/nonmatchings/40180", func_80065E6C);
