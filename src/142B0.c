#include "common.h"

INCLUDE_ASM("asm/nonmatchings/142B0", func_80038EB0);

INCLUDE_ASM("asm/nonmatchings/142B0", func_80039748);

INCLUDE_ASM("asm/nonmatchings/142B0", func_80039F7C);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003A078);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003A3DC);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003A4EC);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003ABA0);

/* Collision triangle: vertex coordinates stored per axis. */
typedef struct CollTri {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s16 x[3];
    /* 0x0A */ s16 y[3];
    /* 0x10 */ s16 z[3];
} CollTri;
extern char D_800CA724[];
void func_8004DA24(char *, s32, s32);

/* Computes the plane (a, b, c, d) of a collision triangle, normal facing +y, with
 * plane[4] = 1. Returns -1 (and a flat plane) for a degenerate triangle. */
s32 func_8003AC80(CollTri *tri, f32 *plane) {
    s32 e1x, e1y, e1z, e2x, e2y, e2z;
    f32 nx, ny, nz, d, len, inv;

    e1y = tri->y[1];
    e2z = tri->z[2];
    e1y -= tri->y[0];
    e2z -= tri->z[0];
    e2y = tri->y[2] - tri->y[0];
    e1z = tri->z[1] - tri->z[0];
    e1x = tri->x[1] - tri->x[0];
    e2x = tri->x[2] - tri->x[0];
    nx = e1y * e2z - e2y * e1z;
    ny = -e1x * e2z + e2x * e1z;
    nz = -e1y * e2x + e2y * e1x;
    len = sqrtf(nx * nx + ny * ny + nz * nz);
    d = -(nx * tri->x[0] + ny * tri->y[0] + nz * tri->z[0]);
    if (len == 0.0f) {
        func_8004DA24(D_800CA724, 3, 15);
        plane[0] = 0.0f;
        plane[2] = 0.0f;
        plane[3] = 0.0f;
        plane[1] = 1.0f;
        plane[4] = 1.0f;
        return -1;
    }
    if (ny < 0.0f) {
        len = -len;
    }
    inv = 1.0f / len;
    plane[4] = 1.0f;
    plane[0] = nx * inv;
    plane[1] = ny * inv;
    plane[2] = nz * inv;
    plane[3] = d * inv;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003AE50);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003B584);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003D1A8);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003D8EC);

INCLUDE_ASM("asm/nonmatchings/142B0", func_8003DE80);
