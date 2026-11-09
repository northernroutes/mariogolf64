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

/* Rotation (X, Y, Z radians) and translation to a 4x4 float matrix. */
void func_80065A1C(f32 m[4][4], f32 *rot, f32 *pos) {
    f32 sx = sinf(rot[0]);
    f32 cx = cosf(rot[0]);
    f32 sy = sinf(rot[1]);
    f32 cy = cosf(rot[1]);
    f32 sz = sinf(rot[2]);
    f32 cz = cosf(rot[2]);

    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[0][3] = 0.0f;
    m[1][0] = sx * sy * cz - cx * sz;
    m[1][1] = sx * sy * sz + cx * cz;
    m[1][2] = sx * cy;
    m[1][3] = 0.0f;
    m[2][0] = cx * sy * cz + sx * sz;
    m[2][1] = cx * sy * sz - sx * cz;
    m[2][2] = cx * cy;
    m[2][3] = 0.0f;
    m[3][0] = pos[0];
    m[3][1] = pos[1];
    m[3][2] = pos[2];
    m[3][3] = 1.0f;
}

/* Rotation (X, Y, Z radians), per-row scale and translation to a 4x4 float matrix. */
void func_80065B98(f32 m[4][4], f32 *rot, f32 *pos, f32 *scale) {
    f32 sx = sinf(rot[0]);
    f32 cx = cosf(rot[0]);
    f32 sy = sinf(rot[1]);
    f32 cy = cosf(rot[1]);
    f32 sz = sinf(rot[2]);
    f32 cz = cosf(rot[2]);

    m[0][0] = cy * cz * scale[0];
    m[0][1] = cy * sz * scale[0];
    m[0][2] = -sy * scale[0];
    m[0][3] = 0.0f;
    m[1][0] = (sx * sy * cz - cx * sz) * scale[1];
    m[1][1] = (sx * sy * sz + cx * cz) * scale[1];
    m[1][2] = sx * cy * scale[1];
    m[1][3] = 0.0f;
    m[2][0] = (cx * sy * cz + sx * sz) * scale[2];
    m[2][1] = (cx * sy * sz - sx * cz) * scale[2];
    m[2][2] = cx * cy * scale[2];
    m[2][3] = 0.0f;
    m[3][0] = pos[0];
    m[3][1] = pos[1];
    m[3][2] = pos[2];
    m[3][3] = 1.0f;
}

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

/* guMtxF2L: float matrix to fixed-point Mtx. */
void func_80065DD8(f32 mf[4][4], Mtx *m) {
    s32 i;
    s32 j;
    s32 e1;
    s32 e2;
    s32 *ai = (s32 *)&m->m[0][0];
    s32 *af = (s32 *)&m->m[2][0];

    for (i = 0; i != 4; i++) {
        for (j = 0; j != 2; j++) {
            e1 = mf[i][j * 2] * 65536.0f;
            e2 = mf[i][j * 2 + 1] * 65536.0f;
            *(ai++) = (e1 & 0xFFFF0000) | ((u32)e2 >> 16);
            *(af++) = (e1 << 16) | (e2 & 0xFFFF);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/40180", func_80065E6C);
