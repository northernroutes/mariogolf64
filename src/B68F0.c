#include "common.h"

/* Placeholder for the 0xA0-byte entries of D_ovl0_80222600 (32 of them).
 * splat labels the fields separately (D_ovl0_80222604 = unk4,
 * D_ovl0_80222608 = unk8). Real type unknown; rename once identified. */
typedef struct UnkOvl0_80222600 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[0x3];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x94];
} UnkOvl0_80222600; /* size = 0xA0 */

extern UnkOvl0_80222600 D_ovl0_80222600[32];
extern s32 D_ovl0_80223E24;
extern s32 D_ovl0_80223E30;
extern s32 D_ovl0_80223E34;
extern u8 D_ovl0_80224E90[];
extern u8 D_ovl0_80227040[];
extern u8 D_ovl0_802270C0[];
extern s32 D_ovl0_80227100;

void func_8004D4B8(void *arg0, s32 arg1, void *arg2);
void func_80067CB4(void *arg0);
void func_ovl0_801FD8DC(void);
void func_ovl0_801FD9E4(void);

void func_ovl0_801FD5F0(void) {
}

void func_ovl0_801FD5F8(void) {
    func_8004D4B8(D_ovl0_80224E90, 4, D_ovl0_80227040);
}

INCLUDE_ASM("asm/nonmatchings/B68F0", func_ovl0_801FD624);

INCLUDE_ASM("asm/nonmatchings/B68F0", func_ovl0_801FD760);

INCLUDE_ASM("asm/nonmatchings/B68F0", func_ovl0_801FD798);

typedef struct UnkOvl0_Vec3f {
    f32 x;
    f32 y;
    f32 z;
} UnkOvl0_Vec3f;

/* 0x14-byte entries from D_ovl0_8022397C. Placeholder. */
typedef struct UnkOvl0_8022397C {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0xC];
} UnkOvl0_8022397C; /* size = 0x14 */

/* A vec3 at 0x94 in each 0xA0-byte entry, i.e. 0xC below D_ovl0_80222600[i]
 * (splat's D_ovl0_802225F4). Placeholder. */
typedef struct UnkOvl0_802225F4 {
    /* 0x00 */ UnkOvl0_Vec3f v;
    /* 0x0C */ u8 padC[0x94];
} UnkOvl0_802225F4; /* size = 0xA0 */

extern UnkOvl0_802225F4 D_ovl0_802225F4[];
extern s32 D_801B60A8;
extern UnkOvl0_Vec3f D_ovl0_80223970;
extern UnkOvl0_8022397C D_ovl0_8022397C[];
extern UnkOvl0_Vec3f D_ovl0_80223E0C;
extern s32 D_ovl0_80223E20;
extern s32 D_ovl0_80223E28;
extern s32 D_ovl0_80223E2C;

void func_ovl0_801FD8DC(void) {
    s32 i;

    for (i = 0; i != 60; i++) {
        D_ovl0_8022397C[i].unk0 = -1;
        D_ovl0_8022397C[i].unk4 = 0;
    }
    D_ovl0_80223970.x = D_ovl0_802225F4[D_801B60A8].v.x;
    D_ovl0_80223970.y = D_ovl0_802225F4[D_801B60A8].v.y;
    D_ovl0_80223970.z = D_ovl0_802225F4[D_801B60A8].v.z;
    D_ovl0_80223E0C.x = D_ovl0_802225F4[D_801B60A8].v.x;
    D_ovl0_80223E0C.y = D_ovl0_802225F4[D_801B60A8].v.y;
    D_ovl0_80223E0C.z = D_ovl0_802225F4[D_801B60A8].v.z;
    D_ovl0_80223E20 = 0;
    D_ovl0_80223E24 = 0;
    D_ovl0_80223E28 = 0;
    D_ovl0_80223E2C = 0;
}

void func_ovl0_801FD9C0(void) {
    D_ovl0_80223E24 = 1;
    D_ovl0_80223E30 = 1;
    D_ovl0_80223E34 = 10;
}

void func_ovl0_801FD9E4(void) {
    func_80067CB4(D_ovl0_802270C0);
}

void func_ovl0_801FDA04(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        D_ovl0_80222600[i].unk0 = -1;
        D_ovl0_80222600[i].unk8 = 0;
    }
    func_ovl0_801FD8DC();
    func_ovl0_801FD9E4();
    D_ovl0_80227100 = 0;
}

INCLUDE_ASM("asm/nonmatchings/B68F0", func_ovl0_801FDA64);

s32 func_ovl0_801FE31C(void) {
    s32 found = 0;
    s32 i;

    for (i = 0; i != 32; i++) {
        if (D_ovl0_80222600[i].unk4 == 1 && D_ovl0_80222600[i].unk0 != -1) {
            found = 1;
        }
    }
    return found;
}

INCLUDE_ASM("asm/nonmatchings/B68F0", func_ovl0_801FE370);
