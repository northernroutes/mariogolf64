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

extern u8 D_E473F0[]; /* ROM: table of {offset, size} pairs, offsets relative to the table */
extern s32 D_8012D3A8;

/* Points stream `s` at entry `id` of the ROM table D_E473F0. */
void func_80050428(s32 id, Unk2B800 *s, s32 arg2) {
    u8 offBuf[0x40];
    u8 sizeBuf[0x40];
    u32 *off = (u32 *)(((u32)offBuf + 0xF) & ~0xF);
    u32 *size = (u32 *)(((u32)sizeBuf + 0xF) & ~0xF);

    nuPiReadRom((u32)&D_E473F0[id * 8], size, 4);
    nuPiReadRom((u32)&D_E473F0[4] + id * 8, off, 4);
    s->unk0 = s->unk8 = *off + (u32)D_E473F0;
    s->unkC = s->unk8 + *size;
    s->unk4 = *size;
    D_8012D3A8 = id;
}

void func_800504E8(s32 arg0, Unk2B800 *arg1, s32 arg2) {
    func_80050428(arg0, arg1, arg2);
}


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
    osSyncPrintf("ropen %d\n", arg0);
    osSyncPrintf("%d\224\324\202\314\203t\203@\203C\203\213\203I\201[\203v\203\223\216\270\224s\201B\n", arg0);
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

extern s32 D_8012D3A8;

/* Reads the next `size` bytes of the stream described by src (cursor unk0, end unkC). */
void func_800505A0(void *dst, u32 size, Unk2B800 *src) {
    if (src->unk0 + size > (u32)src->unkC) {
        size = src->unkC - src->unk0;
        osSyncPrintf("size error %d \n", D_8012D3A8);
    }
    nuPiReadRom(src->unk0, dst, (size + 1) & ~1);
    src->unk0 += size;
}

s32 func_800299F4(s32);

/* Opens stream `id` into p[1] and reads its 4-byte header: the top byte is
 * the format (p->unk8), the low 24 bits stay in the header word. */
void func_8005062C(u16 id, Unk2B800 *p) {
    u8 buf[0x80];
    u32 *hdr = (u32 *)(((u32)buf + 0xF) & ~0xF);

    if (func_800299F4(0x49) != 0) {
        osSyncPrintf("OP:%d\n", id);
    }
    /* Called with two arguments in the original; the third (a2) is garbage. */
    ((void (*)(s32, Unk2B800 *))func_800504E8)(id, p + 1);
    p->unkC = func_80050598(p + 1);
    func_800505A0(hdr, 4, p + 1);
    p->unk8 = *(u8 *)hdr;
    *hdr &= 0xFFFFFF;
}

void func_800506D4(s32 arg0, Unk2B800 *arg1, s32 arg2) {
    if (arg1->unk8 == 1) {
        func_80050710(arg0, arg1, arg2);
    } else {
        func_80050914(arg0, arg1, arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/2B800", func_80050710);

INCLUDE_ASM("asm/nonmatchings/2B800", func_80050914);
