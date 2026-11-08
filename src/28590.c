#include "common.h"

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D190);

INCLUDE_ASM("asm/nonmatchings/28590", func_8004D4B8);

void func_8004D9C0();
void func_8004D5F0(s8 c, s32 x, s32 y);

void func_8004D580(char *str, s32 x, s32 y) {
    func_8004D9C0();
    while (*str != 0) {
        func_8004D5F0(*str, x, y);
        str++;
        x++;
    }
}

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

extern u8 D_800DAF60[0x4B0];

/* Writes a string into the 40x30 text buffer at (x, y), or'ing in the attribute bit. */
void func_8004D9C0(s8 *str, s32 x, s32 y) {
    u8 attr = D_800BFEE4;
    u8 *p = &D_800DAF60[y * 40 + x];
    s32 c;

    while (1) {
        c = *str++;
        if (c == 0) {
            break;
        }
        if (p >= D_800DAF60) {
            if (p < D_800DAF60 + 0x4B0) {
                *p = attr | c;
            }
        }
        p++;
    }
    D_800BFEE4 = 0;
}

void func_8004D9C0();
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

/* 0x18-byte entries of D_800DC6E0; each holds a list head pointing to itself. Placeholder. */
typedef struct Unk800DC6E0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ struct Unk800DC6E0 *unk8;
    /* 0x0C */ struct Unk800DC6E0 *unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Unk800DC6E0; /* size = 0x18 */

extern Unk800DC6E0 D_800DC6E0[];

/* Appends the block [blk, end) to the free list of entry i. */
void func_8004DD70(s32 i, Unk800DC6E0 *blk, u8 *end) {
    s32 size = end - (u8 *)blk;

    blk->unk0 = size;
    D_800DC6E0[i].unk10 += size;
    blk->unk4 = 0;
    blk->unk8 = &D_800DC6E0[i];
    blk->unkC = D_800DC6E0[i].unkC;
    D_800DC6E0[i].unkC->unk8 = blk;
    D_800DC6E0[i].unkC = blk;
}

void func_8004DDE4(s32 arg0) {
    Unk800DC6E0 *p = &D_800DC6E0[arg0];

    D_800DC6E0[arg0].unk10 = 0;
    D_800DC6E0[arg0].unk0 = 0;
    D_800DC6E0[arg0].unk4 = -1;
    p->unkC = p;
    D_800DC6E0[arg0].unk8 = p;
    D_800DC6E0[arg0].unk14 = -1;
}

s32 func_8004DE44(s32 arg0) {
    return D_800DC6E0[arg0].unk10;
}

s32 func_8004DE60(s32 arg0) {
    return D_800DC6E0[arg0].unk14;
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
