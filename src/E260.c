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

INCLUDE_ASM("asm/nonmatchings/E260", func_80032E88);

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
