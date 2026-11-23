#include "common.h"

extern s32 D_800B67A0;
extern u8 D_800B67A4;
extern u8 D_800B67A5;
extern u8 D_800B67A6;
extern u8 D_800B67A7;
extern s32 D_800B67B0;
extern u16 **nuGfxCfb;
extern u32 nuGfxCfbCounter;
extern u16 *nuGfxCfb_ptr;

/* Like NuSystem nuGfxSetCfb: sets the frame buffer array and count. */
void func_80029250(u16 **cfb, s32 n) {
    nuGfxCfb = cfb;
    D_800B67B0 = n;
    nuGfxCfbCounter = 0;
    nuGfxCfb_ptr = cfb[0];
    if (n == 3) {
        D_800B67A0 = 0x802EA000;
        D_800B67A4 = 1;
        D_800B67A5 = 2;
        D_800B67A6 = 0;
        D_800B67A7 = 0xFF;
    } else {
        D_800B67A0 = (s32) cfb[2];
        D_800B67A4 = 1;
        D_800B67A5 = 0;
        D_800B67A6 = 0xFF;
        D_800B67A7 = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/4650", func_800292FC);
