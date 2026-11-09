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

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_800542A0);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_80054310);

/* 0x18C-byte slots at D_801F43F0 (see Unk801F4424 in 2FD00). Placeholder. */
typedef struct Unk801F43F0 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ s32 unk8;
    /* 0x00C */ u8 padC[0x180];
} Unk801F43F0; /* size = 0x18C */

extern Unk801F43F0 D_801F43F0[4];

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

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_800544B4);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_80054550);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_8005470C);

INCLUDE_ASM("asm/nonmatchings/2E3E0", func_8005483C);

void func_80054550(s32, s32, s32);

void func_800548DC(s32 arg0, s32 arg1) {
    func_80054550(arg0, 2, arg1);
}
