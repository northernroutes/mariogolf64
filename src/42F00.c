#include "common.h"

INCLUDE_ASM("asm/nonmatchings/42F00", func_80067B00);

INCLUDE_ASM("asm/nonmatchings/42F00", func_80067C0C);

void func_80067CB4(f32 m[4][4]) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                m[i][j] = 1.0f;
            } else {
                m[i][j] = 0.0f;
            }
        }
    }
}

s32 func_80067B00(s32 *, s32);
void func_80067CB4(f32 m[4][4]);

void func_80067D04(s32 arg0) {
    f32 m[4][4];

    func_80067CB4(m);
    func_80067B00((s32 *)m, arg0);
}
