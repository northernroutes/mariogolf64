#include "common.h"

/* Placeholder for the 0x10-byte object this segment works on: the second
 * argument of func_80050428/80050710/80050914, the D_800DE8A0 array (0x10
 * stride), and the func_80050588/80050598 accessors. Real type unknown;
 * rename once identified. */
typedef struct Unk2B800 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
} Unk2B800; /* size = 0x10 */

extern Unk2B800 D_800DE8A0[];

void func_80050428(s32 arg0, Unk2B800 *arg1, s32 arg2);
void func_80050710(s32 arg0, Unk2B800 *arg1, s32 arg2);
void func_80050914(s32 arg0, Unk2B800 *arg1, s32 arg2);

void func_80050400(void) {
    Unk2B800 *p;
    s32 i;

    /* `!=`, not `<`: with `<`, GCC 2.7 reverses the loop into a count-down. */
    for (i = 0, p = D_800DE8A0; i != 2; i++, p++) {
        p->unk0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/2B800", func_80050428);

void func_800504E8(s32 arg0, Unk2B800 *arg1, s32 arg2) {
    func_80050428(arg0, arg1, arg2);
}

extern char D_800CCB70[];
extern char D_800CCB7C[];

/* Claims a free D_800DE8A0 slot; arg1 is unused and arg2 is passed through. */
Unk2B800 *func_80050504(s32 arg0, s32 arg1, s32 arg2) {
    Unk2B800 *p;
    s32 i;

    for (i = 0, p = D_800DE8A0; i != 2; i++, p++) {
        if (p->unk0 == 0) {
            func_80050428(arg0, p, arg2);
            return p;
        }
    }
    osSyncPrintf(D_800CCB70, arg0);
    osSyncPrintf(D_800CCB7C, arg0);
    return NULL;
}

void func_80050588(Unk2B800 *arg0) {
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk0 = 0;
}

s32 func_80050598(Unk2B800 *arg0) {
    return arg0->unk4;
}

extern char D_800CCB9C[];
extern s32 D_8012D3A8;

/* Reads the next `size` bytes of the stream described by src (cursor unk0, end unkC). */
void func_800505A0(void *dst, u32 size, Unk2B800 *src) {
    if (src->unk0 + size > (u32)src->unkC) {
        size = src->unkC - src->unk0;
        osSyncPrintf(D_800CCB9C, D_8012D3A8);
    }
    nuPiReadRom(src->unk0, dst, (size + 1) & ~1);
    src->unk0 += size;
}

INCLUDE_ASM("asm/nonmatchings/2B800", func_8005062C);

void func_800506D4(s32 arg0, Unk2B800 *arg1, s32 arg2) {
    if (arg1->unk8 == 1) {
        func_80050710(arg0, arg1, arg2);
    } else {
        func_80050914(arg0, arg1, arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/2B800", func_80050710);

INCLUDE_ASM("asm/nonmatchings/2B800", func_80050914);
