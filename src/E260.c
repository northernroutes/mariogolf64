#include "common.h"

/* 0x1C-byte entries of D_800B790C. Placeholder. */
typedef struct Unk800B790C {
    /* 0x00 */ u8 pad0[0x1C];
} Unk800B790C;

extern Unk800B790C D_800B790C[27];

/* Entry n, or entry 0 if n is out of range. */
Unk800B790C *func_80032E60(u32 n) {
    n = (n < 27) ? n : 0;
    return &D_800B790C[n];
}

/* 0xB8-byte entries at D_800B7868. Placeholder. */
typedef struct Unk800B7868 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x58];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x40];
} Unk800B7868; /* size = 0xB8 */

s32 rand(void);
extern Unk800B7868 D_800B7868[1];

void func_80032E88(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_800B7868[i].unk0 = 0x800;
        D_800B7868[i].unk4 = -1000;
        rand();
        D_800B7868[i].unk8 = 0x1000;
        D_800B7868[i].unkC = rand() & 0x3FF;
        D_800B7868[i].unk10 = -100;
        D_800B7868[i].unk14 = rand() & 0x3FF;
        D_800B7868[i].unk18 = 0;
        D_800B7868[i].unk74 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/E260", func_80032F70);

INCLUDE_ASM("asm/nonmatchings/E260", func_80032FE8);

INCLUDE_ASM("asm/nonmatchings/E260", func_800330D0);

INCLUDE_ASM("asm/nonmatchings/E260", func_80033134);

INCLUDE_ASM("asm/nonmatchings/E260", func_80033228);

INCLUDE_ASM("asm/nonmatchings/E260", func_8003327C);

/* 6-byte entries; contents unknown. Placeholder. */
typedef struct Unk800B7C2E {
    /* 0x0 */ u8 unk0[6];
} Unk800B7C2E;

s32 func_80044AC8(s32 arg0, s32 arg1, s32 arg2);
extern Unk800B7C2E D_800B7C00;
extern Unk800B7C2E D_800B7C08;
/* Six rows of 11 entries for n = -5..5; D_800B7C2E is row 0, n = 0. */
extern Unk800B7C2E D_800B7C2E[][11];

/* Entry for row func_80044AC8(...) - 1 (clamped to 0..5) and column n;
 * D_800B7C00 / D_800B7C08 when n is below / above the table. */
Unk800B7C2E *func_80037E50(s32 arg0, s32 arg1, s32 arg2, s32 n) {
    Unk800B7C2E *p;
    Unk800B7C2E *r;
    s32 row = func_80044AC8(arg0, arg1, arg2) - 1;

    if (row < 0) {
        row = 0;
    }
    if (row >= 6) {
        row = 5;
    }
    if (n < -5) {
        p = &D_800B7C00;
    } else if (n >= 6) {
        p = &D_800B7C08;
    } else {
        r = D_800B7C2E[row];
        p = r + n;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/E260", func_80037EE0);

INCLUDE_ASM("asm/nonmatchings/E260", func_80037F94);
