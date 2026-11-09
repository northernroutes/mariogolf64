#include "common.h"

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A000);

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A0CC);

extern s32 D_800C3FB0;

void func_8006A174(s32 arg0) {
    D_800C3FB0 = arg0;
}

extern s32 D_800C3FB0;

void func_8006A180(void) {
    D_800C3FB0 = (D_800C3FB0 * 0x5D588B65) + 1;
}

float sqrtf(float);
f32 func_8006A1A8(f32 x, f32 y) {
    return sqrtf(x * x + y * y);
}

float sqrtf(float);
f32 func_8006A1C0(f32 x, f32 y, f32 z) {
    return sqrtf(x * x + y * y + z * z);
}

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A1EC);

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A274);
