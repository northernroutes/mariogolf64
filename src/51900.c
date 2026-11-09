#include "common.h"

extern f32 D_80105B6C[3];
extern f32 D_80105F30[3];

void func_80076500(f32 *a, f32 *b) {
    a[0] = D_80105B6C[0];
    a[1] = D_80105B6C[1];
    a[2] = D_80105B6C[2];
    b[0] = D_80105F30[0];
    b[1] = D_80105F30[1];
    b[2] = D_80105F30[2];
}

extern s32 D_800E1CD0;

void func_8007654C(void) {
    D_800E1CD0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/51900", func_80076558);

INCLUDE_ASM("asm/nonmatchings/51900", func_80076640);

/* out = v transformed by the row-vector matrix m (translation in row 3). */
void func_80076778(f32 m[4][4], f32 *v, f32 *out) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];

    out[0] = m[0][0] * x + m[1][0] * y + m[2][0] * z + m[3][0];
    out[1] = m[0][1] * x + m[1][1] * y + m[2][1] * z + m[3][1];
    out[2] = m[0][2] * x + m[1][2] * y + m[2][2] * z + m[3][2];
}

INCLUDE_ASM("asm/nonmatchings/51900", func_8007680C);
