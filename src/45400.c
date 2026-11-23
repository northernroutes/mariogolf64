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

extern char D_800D1420[];
void osSyncPrintf(const char *, ...);

/* CRC-16/X.25 (reflected CCITT polynomial 0x8408). */
u16 func_8006A1EC(void *data, s32 len) {
    u8 *p = data;
    u32 crc = 0xFFFF;
    u32 i;
    u32 n;

    for (n = 0; n < len; n++) {
        crc ^= p[n];
        for (i = 0; i < 8; i++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0x8408;
            } else {
                crc >>= 1;
            }
        }
    }
    crc = ~crc;
    crc &= 0xFFFF;
    osSyncPrintf(D_800D1420, crc);
    return crc;
}

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A274);
