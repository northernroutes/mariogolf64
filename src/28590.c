#include "common.h"

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D190);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D4B8);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D580);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D5F0);

extern s8 D_800DB40F;

void func_8004D794(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x4AF;
    var_v0 = &D_800DB40F;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D7B8);

extern s8 D_800BFEE4;

void func_8004D99C(s32 arg0) {
    if (arg0 != 0) {
        D_800BFEE4 = -0x80;
        return;
    }
    D_800BFEE4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D9C0);

s32 func_8004D9C0();
extern s8 D_800B67C0;

void func_8004DA24(char *arg0, s32 arg1, s32 arg2) {
    if (D_800B67C0 != 0) {
        func_8004D9C0(arg0, arg1, arg2);
    }
}

void func_8004DA4C(u32 n, s32 width, s32 arg2) {
    char buf[9];
    char *p;
    s32 d;
    s32 c;

    p = &buf[8];
    width += 8;
    buf[8] = 0;
    do {
        d = n & 0xF;
        c = d + '0';
        if (c > '9') {
            c = d + 'A' - 10;
        }
        *--p = c;
        n >>= 4;
        width--;
    } while (n != 0);
    func_8004DA24(p, width, arg2);
}

void func_8004DA9C(u32 n, s32 width, s32 arg2) {
    char buf[9];
    char *p;
    s32 d;
    s32 c;

    p = &buf[8];
    width += 8;
    buf[8] = 0;
    do {
        d = n & 0xF;
        c = d + '0';
        if (c > '9') {
            c = d + 'A' - 10;
        }
        *--p = c;
        width--;
        n >>= 4;
    } while (p != buf);
    func_8004DA24(p, width, arg2);
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DAF4);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DC44);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DD70);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DDE4);

/* 0x18-byte entries of D_800DC6F0. Placeholder. */
typedef struct Unk800DC6F0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0x10];
} Unk800DC6F0; /* size = 0x18 */

extern Unk800DC6F0 D_800DC6F0[];

s32 func_8004DE44(s32 arg0) {
    return D_800DC6F0[arg0].unk0;
}

s32 func_8004DE60(s32 arg0) {
    return D_800DC6F0[arg0].unk4;
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004DE7C);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E058);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E184);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E1E0);

extern s32 D_800DC738;

s32 func_8004E27C(void) {
    return D_800DC738;
}

/* Free-list node; the list head is a sentinel whose next field is D_800DC730. */
typedef struct Unk800DC728 {
    /* 0x0 */ u32 size;
    /* 0x4 */ s32 inUse;
    /* 0x8 */ struct Unk800DC728 *next;
} Unk800DC728;

extern Unk800DC728 *D_800DC730;
extern u32 D_800DC73C;

u32 func_8004E288(void) {
    Unk800DC728 **head;
    Unk800DC728 *p;
    Unk800DC728 *end;
    u32 max;

    head = &D_800DC730;
    p = *head;
    head -= 2;
    max = 0;
    if (p != (Unk800DC728 *)head) {
        end = (Unk800DC728 *)head;
        do {
            if (p->inUse == 0) {
                if (max < p->size) {
                    max = p->size;
                }
            }
            p = p->next;
        } while (p != end);
    }
    D_800DC73C = max;
    return max;
}

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E2DC);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004E47C);
