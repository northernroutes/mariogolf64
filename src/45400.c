#include "common.h"

double sqrt(double);

/* Integer 3D length: halves x, y and z until each fits in +-2^29, then rescales. */
u32 func_8006A000(s32 x, s32 y, s32 z) {
    s32 shift = 0;

    while (1) {
        if (!((u32) (x - 0x20000000) <= 0xBFFFFFFF || (u32) (y - 0x20000000) <= 0xBFFFFFFF ||
              (u32) (z - 0x20000000) <= 0xBFFFFFFF)) {
            break;
        }
        shift++;
        x >>= 1;
        y >>= 1;
        z >>= 1;
    }
    return (u32) sqrt((f64) x * x + (f64) y * y + (f64) z * z) << shift;
}

/* Integer 2D length (hypot) of (x, z), scaled the same way. */
u32 func_8006A0CC(s32 x, s32 z) {
    s32 shift = 0;

    while (1) {
        if (!((u32) (x - 0x20000000) <= 0xBFFFFFFF || (u32) (z - 0x20000000) <= 0xBFFFFFFF)) {
            break;
        }
        shift++;
        x >>= 1;
        z >>= 1;
    }
    return (u32) sqrt((f64) x * x + (f64) z * z) << shift;
}

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
    osSyncPrintf("CRC = %x\n", crc);
    return crc;
}

INCLUDE_ASM("asm/nonmatchings/45400", func_8006A274);
