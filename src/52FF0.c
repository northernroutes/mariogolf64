#include "common.h"

extern s32 D_80105148;
extern s8 D_80105165;

void func_80077BF0(void) {
    D_80105148 = 0x96;
    D_80105165 = 1;
}

extern s8 D_80105165;

void func_80077C0C(void) {
    D_80105165 = 0;
}

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80077C18);

/* 0x2C-byte entries of D_80105140. Placeholder. */
typedef struct Unk80105140 {
    /* 0x00 */ u8 pad0[0x2C];
} Unk80105140;

extern s32 D_800C4660;
extern s32 D_800C4664;
extern s32 D_800FE338;
extern Unk80105140 D_80105140[];
void func_8004E47C(void *);

void func_80077DEC(void) {
    s32 i;

    if (D_800C4664 == 1) {
        func_8004E47C(&D_800FE338);
        for (i = 0; i != D_800C4660; i++) {
            func_8004E47C(&D_80105140[i]);
        }
    }
    D_800C4664 = 0;
}

extern s32 D_800C4664;

s32 func_80077E6C(void) {
    s32 temp_v0;

    if (D_800C4664 > 0) {
        return 0;
    }
    temp_v0 = D_800C4664 - 1;
    D_800C4664 = temp_v0;
    return temp_v0 < -2;
}

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80077E94);

INCLUDE_ASM("asm/nonmatchings/52FF0", func_80078128);
