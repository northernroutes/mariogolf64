#include "common.h"

extern s32 D_ovl3_80230A90;
extern s32 D_ovl3_80230A94;
extern s32 D_ovl3_80230A98;
extern s32 D_ovl3_8023B670;
extern s32 D_ovl3_8023B674;
extern s32 D_ovl3_8023B678;
extern s32 D_ovl3_8023B67C;

void func_ovl3_8021F5F0(s32 arg0, s16 arg1) {
    s32 sp10[8];

    switch (arg1) {
        case 1:
            D_ovl3_8023B670 = arg0;
            break;
        case 2:
            D_ovl3_8023B674 = arg0;
            func_8005062C(0x5F7, sp10);
            func_800506D4(D_ovl3_8023B674, sp10);
            break;
        case 3:
            D_ovl3_8023B678 = arg0;
            func_8005062C(0x70E, sp10);
            func_800506D4(D_ovl3_8023B678, sp10);
            break;
        case 4:
            D_ovl3_8023B67C = arg0;
            func_8005062C(0x720, sp10);
            func_800506D4(D_ovl3_8023B67C, sp10);
            D_ovl3_80230A90 = 0;
            D_ovl3_80230A94 = 0;
            D_ovl3_80230A98 = 0;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8021F6E0);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8021F79C);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8021FC5C);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80220A30);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80220BB0);

extern s16 D_ovl3_8023B684[5];

/* Next used slot (!= -1) after arg0, forward or backward with wraparound; -1 if none. */
s16 func_ovl3_80220D68(s8 arg0, u8 forward) {
    s32 cur = arg0;
    s32 dir;
    s32 i;

    if (cur < 0) {
        return -1;
    }
    if (cur >= 5) {
        return -1;
    }
    dir = (forward == 0) ? -1 : 1;
    cur += dir;
    for (i = 0; i != 4; i++) {
        if (cur >= 5) {
            cur = 0;
        }
        if (cur < 0) {
            cur = 4;
        }
        if (D_ovl3_8023B684[cur] != -1) {
            break;
        }
        cur += dir;
    }
    if (i == 4) {
        return -1;
    }
    return cur;
}

u8 *func_8005AF74(void);
extern s16 D_ovl3_8023B684[];

s16 func_ovl3_80220DF8(void) {
    return D_ovl3_8023B684[(s8)func_8005AF74()[0x42]];
}

u32 func_ovl3_80220E28(u8 *arg0) {
    return arg0[0x36] >> 7;
}

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80220E34);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_802213C8);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8022181C);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_802218C0);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80221B20);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80221CC0);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80221EBC);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_ovl3_8023BD78;
extern s32 D_ovl3_8023BD7C;

void func_ovl3_80222038(s32 arg0, s32 arg1) {
    s32 sp10[8];
    s32 temp_a1;

    temp_a1 = arg1 & 0xFF;
    switch (temp_a1) {
    case 1:
        D_ovl3_8023BD78 = arg0;
        return;
    case 2:
        D_ovl3_8023BD7C = arg0;
        func_8005062C(0x528, sp10);
        func_800506D4(D_ovl3_8023BD7C, sp10);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8022209C);

/* 0xA0-byte entries at 0x1FF8 in the object returned by func_8005AF50. Placeholder. */
typedef struct UnkOvl3_8005AF50_Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x9C];
} UnkOvl3_8005AF50_Entry; /* size = 0xA0 */

typedef struct UnkOvl3_8005AF50 {
    /* 0x0000 */ u8 pad0[0x1FF8];
    /* 0x1FF8 */ UnkOvl3_8005AF50_Entry unk1FF8[1]; /* length unknown */
} UnkOvl3_8005AF50;

UnkOvl3_8005AF50 *func_8005AF50(void);
u8 *func_8005AF74(void);

/* -1 if the current player's entry has unk0 == 0, else 0. */
s32 func_ovl3_80222C94(void) {
    UnkOvl3_8005AF50 *obj = func_8005AF50();

    return -(((UnkOvl3_8005AF50_Entry *)((s8)func_8005AF74()[0x43] * 0xA0 + (u8 *)obj->unk1FF8))->unk0 == 0);
}

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80222CDC);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80222F2C);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_802230C0);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80224AFC);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80225358);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80225960);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_80226190);

INCLUDE_ASM("asm/nonmatchings/109570", func_ovl3_8022644C);
