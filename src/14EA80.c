#include "common.h"

s32 func_ovl8_801F55A0();

void func_ovl8_801F4A40(void) {
    func_ovl8_801F55A0();
}

extern s8 D_800B67C0;

void func_ovl8_801F4A5C(void) {
    D_800B67C0 = 1;
}

s32 func_80029A30(s32);

void func_ovl8_801F4A6C(void) {
    func_80029A30(0x44);
    func_80029A30(0x65);
}

/* 0xC-byte entries of D_ovl8_801F592C. Placeholder. */
typedef struct UnkOvl8_801F592C {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u8 pad4[0x8];
} UnkOvl8_801F592C;

extern UnkOvl8_801F592C D_ovl8_801F592C[4];

void func_ovl8_801F4A90(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        D_ovl8_801F592C[i].unk0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/14EA80", func_ovl8_801F4ABC);

INCLUDE_ASM("asm/nonmatchings/14EA80", func_ovl8_801F4C84);

s32 func_800329D8(s32, s32, s32);
s32 func_8006F50C();

void func_ovl8_801F4D48(void) {
    func_8006F50C();
    func_800329D8(0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/14EA80", func_ovl8_801F4D74);

INCLUDE_ASM("asm/nonmatchings/14EA80", func_ovl8_801F4F80);
