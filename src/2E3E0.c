#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_80052FE0);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_800530FC);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_8005342C);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_80053604);

extern s8 D_800D0488;
extern s32 D_801F43F8;

s32 func_80054240(u32 arg0) {
    osSyncPrintf(&D_800D0488, arg0);
    if (arg0 < 4U) {
        *((__typeof__(D_801F43F8) *)((u8 *)&D_801F43F8 + (arg0 * 0x18C))) = -1;
    }
}

/* 0x18C-byte slots at D_801F43F0 (see Unk801F4424 in 2FD00). Placeholder. */
typedef struct Unk801F43F0 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s32 unk8;
    /* 0x00C */ u8 padC[0x28];
    /* 0x034 */ s32 unk34;
    /* 0x038 */ u8 pad38[0x154];
} Unk801F43F0; /* size = 0x18C */

extern Unk801F43F0 D_801F43F0[4];
extern s32 D_800B67F0;

/* 1 for an invalid index, a slot in use (unk8 != -1), or unk34 equal to
 * D_800B67F0 or D_800B67F0 - 1. */
s32 func_800542A0(s32 i) {
    s32 r;

    if ((u32) i >= 4) {
        return 1;
    }
    r = 0;
    if (D_801F43F0[i].unk8 != -1 || (u32) (D_800B67F0 - D_801F43F0[i].unk34) < 2) {
        r = 1;
    }
    return r;
}

s32 func_80054310(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_800542A0(i)) {
            return 1;
        }
    }
    return 0;
}

/* Slot i if it is in use (unk8 != -1), else NULL. */
Unk801F43F0 *func_80054354(u32 i) {
    if (i < 4) {
        if (D_801F43F0[i].unk8 != -1) {
            return &D_801F43F0[i];
        }
    }
    return NULL;
}


void func_800543A4(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_80054240(var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
}

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_800543DC);

/* Entry returned by func_800448E0 (Unk800BB258 in 1EEF0.c). Placeholder. */
typedef struct Unk800448E0_2E3E0 {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s16 unk24;
} Unk800448E0_2E3E0;

Unk800448E0_2E3E0 *func_800448E0(s32);
extern s32 D_800C1DEC;

s32 func_800544B4(u32 i, s32 arg1) {
    s32 r = -1;
    Unk801F43F0 *slot = func_80054354(i);

    if (slot != NULL) {
        D_800C1DEC = slot->unk8;
        switch (func_800448E0(arg1)->unk24) {
            case 0:
                r = 0;
                break;
            case 1:
                r = 1;
                break;
            case 2:
                r = 2;
                break;
            case 3:
                r = 3;
                break;
            default:
                r = -1;
                break;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_80054550);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_8005470C);

s32 func_80054550(s32, s32, f32 *);
void func_8005470C(Unk801F43F0 *, f32 (*)[4]);

/* Transforms point arg1 of slot i by the slot's matrix into out; zeroes out
 * (and returns the negative result) if func_80054550 fails. */
s32 func_8005483C(s32 i, s32 arg1, f32 *out) {
    f32 mtx[4][4];
    f32 v[3];
    s32 r = func_80054550(i, arg1, v);

    if (r < 0) {
        out[0] = out[1] = out[2] = 0.0f;
    } else {
        func_8005470C(func_80054354(i), mtx);
        guMtxXFMF(mtx, v[0], v[1], v[2], &out[0], &out[1], &out[2]);
    }
    return r;
}

void func_800548DC(s32 arg0, f32 *arg1) {
    func_80054550(arg0, 2, arg1);
}
