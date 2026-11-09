#include "common.h"

extern s32 D_ovl7_8020AC4C;

void func_ovl7_801F4A40(void) {
    s32 temp_v0;

    temp_v0 = D_ovl7_8020AC4C + 1;
    D_ovl7_8020AC4C = temp_v0;
    if (temp_v0 == 0xB) {
        D_ovl7_8020AC4C = 0;
    }
}

s32 func_80050DA0(s32, s32, s32, s32, s32);
extern s32 D_ovl7_8020AC50;
extern f32 D_ovl7_8020AC5C;
extern s32 D_ovl7_8020AC60;

void func_ovl7_801F4A6C(void) {
    if (D_ovl7_8020AC60 != 0) {
        func_80050DA0(0x51, 0xC, 0x30 - (s32) (D_ovl7_8020AC5C * 0.2f), 0, 0x7F - ((s32) (D_ovl7_8020AC50 - 0xA0) / 2));
    }
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F4AEC);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F5018);

extern s32 D_801B7EE0;
extern s32 D_ovl7_802259F8[2];
extern s32 D_ovl7_80225A04;
void func_8004E47C(void *);
void func_80029B58(void);
void func_800329D8(s32, s32, s32);
void func_80078910(void);

void func_ovl7_801F5100(void) {
    s32 *p;
    s32 i;

    func_8004E47C(&D_801B7EE0);
    for (i = 0, p = D_ovl7_802259F8; i < 2; i++, p++) {
        func_8004E47C(p);
    }
    func_80029B58();
    func_8004E47C(&D_ovl7_80225A04);
    func_800329D8(0xFF, 0xFF, 0xFF);
    func_80078910();
}

s32 func_80058D04(s32, s32, s32);
extern s32 D_801B93DC;

void func_ovl7_801F5180(s32 arg0, s32 *arg1) {
    s32 var_s0;

    var_s0 = 0;
    D_801B93DC = *arg1;
    do {
        func_80058D04(arg0, 2, var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
    *arg1 = D_801B93DC;
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F51F0);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F5454);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F58EC);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801F6788);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FA4EC);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FA83C);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FA8D8);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FB864);

/* 0x1208-byte sound slots at D_ovl7_80214C50. Placeholder. */
typedef struct UnkOvl7_80214C50 {
    /* 0x0000 */ u8 pad0[0x1208];
} UnkOvl7_80214C50;

extern u16 D_ovl7_8020AD8A[][2];
extern UnkOvl7_80214C50 D_ovl7_80214C50[];
extern s32 D_ovl7_8020AD70[];
extern f32 D_ovl7_8020AD80[];
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32 *, s32 *);

void func_ovl7_801FBB10(s32 idx, s32 slot) {
    s32 sp10[8];

    func_8005062C(D_ovl7_8020AD8A[idx][0], sp10);
    func_800506D4((s32 *)&D_ovl7_80214C50[slot], sp10);
    D_ovl7_8020AD70[slot] = 0;
    D_ovl7_8020AD80[slot] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FBB94);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32 *, s32 *);
extern s32 D_ovl7_80212830;

void func_ovl7_801FE270(void) {
    s32 sp10[8];

    func_8005062C(0x908, sp10);
    func_800506D4(&D_ovl7_80212830, sp10);
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FE2A0);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FE7B4);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FE8F8);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FF5E8);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32 *, s32 *);
extern s32 D_ovl7_80212830;

void func_ovl7_801FF6DC(void) {
    s32 sp10[8];

    func_8005062C(0x93D, sp10);
    func_800506D4(&D_ovl7_80212830, sp10);
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FF70C);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32 *, s32 *);
extern s32 D_ovl7_80213A40;

void func_ovl7_801FFC10(void) {
    s32 sp10[8];

    func_8005062C(0x939, sp10);
    func_800506D4(&D_ovl7_80213A40, sp10);
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_801FFC40);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_802008D8);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80200B18);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80200CBC);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80202D34);
