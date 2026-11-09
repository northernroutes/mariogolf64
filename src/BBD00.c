#include "common.h"

/* Placeholder types; real types unknown. Rename once identified. */

/* 0xA8-byte entries of D_ovl0_8022B5D0 (10 of them). */
typedef struct UnkOvl0_8022B5D0 {
    /* 0x00 */ u8 pad0[0xA7];
    /* 0xA7 */ u8 unkA7;
} UnkOvl0_8022B5D0; /* size = 0xA8 */

/* Object passed to func_ovl0_80207014 / 80207048 / 802078C4: three s8
 * flags at 0x78. */
typedef struct UnkOvl0_80207014 {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ s8 unk78[3];
} UnkOvl0_80207014;

/* 0x10 bytes at D_800FBE78; only unk4 and unkC are written here. */
typedef struct Unk800FBE78 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk800FBE78; /* size = 0x10 */

extern UnkOvl0_8022B5D0 D_ovl0_8022B5D0[10];
extern Unk800FBE78 D_800FBE78;
extern s32 D_ovl0_80227198;
extern s32 D_ovl0_80227C90[2];
extern s32 D_ovl0_80227C98;
extern s32 D_800C3070;
extern s32 D_800C3080;
extern u16 D_800C307A;
extern u16 D_801B55CC;
extern s8 D_801B60B9;
extern s32 D_801B608C;

void func_80054240(s32 arg0);
void func_800560FC(s32 arg0, s32 arg1);
void func_8004E47C(s32 *arg0);
void func_80095D64(void);
void func_ovl0_80203B4C(void);
s32 func_ovl0_80207250(s32 arg0);
s32 func_ovl0_802072AC();

void func_ovl0_80202A00(void) {
    nuSiSendMesg(0x305, NULL);
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80202A20);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80202D04);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802038D0);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80203B4C);

s32 func_800292FC(s32);
s32 func_8002A97C(s32, s32);
s32 func_80050F68(s32);
s32 func_800934CC(s32);
extern s32 D_800B680C;
extern s32 D_800C306C;
extern s32 D_800C308C;
extern s32 D_800C3090;
extern u16 D_800FBE48;
extern s8 D_801061BD;
extern s8 D_801061C4;
extern s8 D_80106240;

void func_ovl0_80203DAC(void) {
    D_800FBE78.unk4 = -0x12C00;
    D_800C308C = 1;
    D_800C3070 = 0;
    D_800C3090 = 0;
    D_80106240 = 0x47;
    D_800C307A = D_800FBE48;
    func_800934CC(3);
    D_800C306C = 4;
    D_801061BD = 0;
    D_801061C4 = 0;
    if (D_800B680C == 3) {
        func_800292FC(3);
        func_8002A97C(4, 0);
    }
    func_80050F68(8);
}

s32 func_80050DA0(s32, s32, s32, s32, s32);
extern s32 D_800C3084;
extern s32 D_ovl0_80227194;

void func_ovl0_80203E58(void) {
    if ((D_801B55CC & 0x2020) && !(D_800C3084 & 2)) {
        if ((D_800C3090 == 0) && (D_ovl0_80227194 == 0)) {
            func_80050DA0(0x26, 8, 0x3C, 0x14, 0xE6);
        }
        D_800C3090 = 1;
        return;
    }
    func_80050F68(8);
    D_800C3090 = 0;
}

void func_ovl0_80203EEC(void) {
    s32 sp10[4]; /* unused; only sizes the stack frame (0x28) to match */

    D_800FBE78.unk4 = 0xFFFF1000;
    D_800FBE78.unkC = -0x4E00;
    D_800C3070 = 0;
    D_800C3080 = 0;
    func_ovl0_80203B4C();
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80203F30);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80204104);

void func_ovl0_802041C8(void) {
    if (D_801B55CC & 2) {
        D_800C307A -= 200;
    } else if (D_801B55CC & 1) {
        D_800C307A += 200;
    }
}

extern s32 D_800C3084;
extern s32 D_800FBE54;
extern u16 D_801B55CC;
extern f64 D_ovl0_80224F18;
extern f64 D_ovl0_80224F20;
extern f64 D_ovl0_80224F28;
extern f64 D_ovl0_80224F30;

void func_ovl0_80204210(void) {
    s32 speed;

    if (D_800C3084 & 2) {
        if (D_800FBE54 == 2) {
            speed = 10;
        } else {
            speed = (D_800FBE54 != 1) ? 15 : 13;
        }
        if (D_801B55CC & 2) {
            D_800FBE78.unkC = D_800FBE78.unkC + speed * D_ovl0_80224F18;
        } else if (D_801B55CC & 1) {
            D_800FBE78.unkC = D_800FBE78.unkC - speed * D_ovl0_80224F20;
        }
    } else if (D_801B55CC & 2) {
        D_800FBE78.unkC = D_800FBE78.unkC + D_ovl0_80224F28;
        if (D_800FBE78.unkC < -0x5A00) {
            D_800FBE78.unk4 = D_800FBE78.unk4 + D_ovl0_80224F28;
        }
    } else if (D_801B55CC & 1) {
        D_800FBE78.unkC = D_800FBE78.unkC - D_ovl0_80224F30;
        if (D_800FBE78.unkC > -0x96000) {
            D_800FBE78.unk4 = D_800FBE78.unk4 - D_ovl0_80224F30;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020439C);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80204460);

extern s8 D_801B55D9;

void func_ovl0_80204568(void) {
    s32 v = D_801B55D9;
    s32 *p;
    s32 a;

    a = v;
    if (v < 0) {
        a = -v;
    }
    if (a >= 9) {
        p = &D_800FBE78.unkC;
        *p -= (v / 16) * 0x600;
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802045BC);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020466C);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80204910);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802054CC);

void func_ovl0_802055F8(void) {
    D_ovl0_80227198 = osGetCount();
}

s32 func_ovl0_8020561C(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80205624);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802059C0);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80205AE4);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80205BB8);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80205C78);

extern s32 D_801B6090;
extern char D_ovl0_80225020[];
s32 func_ovl0_80205BB8(s32, s32);
void func_8004DA24(char *, s32, s32);

/* Debug: prints the per-player total of func_ovl0_80205BB8 over 12 entries. */
void func_ovl0_80205D44(void) {
    char buf[0x80];
    s32 i;
    s32 j;
    s32 sum;

    for (i = 0; i < D_801B6090; i++) {
        sum = 0;
        for (j = 0; j < 12; j++) {
            sum += func_ovl0_80205BB8(i, j);
        }
        sprintf(buf, D_ovl0_80225020, i, sum);
        func_8004DA24(buf, 2, i + 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80205DE8);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80206354);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80206BD0);

s32 func_ovl0_80206CC8(void) {
    if (D_801B60B9 == 0) {
        return D_801B608C == 9;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80206CF0);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80206E88);

s32 func_ovl0_80207014(UnkOvl0_80207014 *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0->unk78[i] != 0) {
            return 0;
        }
    }
    return 1;
}

s32 func_ovl0_80207048(UnkOvl0_80207014 *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0->unk78[i] == 1) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207080);

/* 0xB8-byte entries starting at D_801B71D0. Placeholder. */
typedef struct Unk801B71D0 {
    /* 0x00 */ u8 pad0[0x1E];
    /* 0x1E */ s8 unk1E;
    /* 0x1F */ u8 pad1F[0x4];
    /* 0x23 */ s8 unk23;
    /* 0x24 */ u8 pad24[0x94];
} Unk801B71D0; /* size = 0xB8 */

extern Unk801B71D0 D_801B71D0[];
extern s8 D_800BAA04;
void func_ovl0_80207080(s32);

void func_ovl0_802071B8(s32 i) {
    if (D_801B608C == 9 && D_801B71D0[i].unk23 <= D_800BAA04 && D_801B71D0[i].unk1E == 0 &&
        func_ovl0_80207014((UnkOvl0_80207014 *)&D_801B71D0[i])) {
        func_ovl0_80207080(i);
    }
}

s32 func_800544B4(void);

/* The explicit case 0 is needed: it changes GCC's compare tree. */
s32 func_ovl0_80207250(s32 arg0) {
    switch (func_800544B4()) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 9;
        default:
            return 0;
    }
}

/* K&R definition: the only caller passes just arg0, but arg2 is read. */
s32 func_ovl0_802072AC(arg0, arg1, arg2)
    s32 arg0;
    s32 arg1;
    s32 arg2;
{
    s32 base;

    switch (func_800544B4()) {
        case 0:
            base = 1;
            break;
        case 1:
            base = 4;
            break;
        case 2:
            base = 7;
            break;
        case 3:
            base = 10;
            break;
        default:
            base = 0;
            break;
    }
    return base + (arg2 == 2);
}

void func_ovl0_80207328(s32 arg0) {
    func_800560FC(arg0, func_ovl0_80207250(arg0));
}

void func_ovl0_80207358(s32 arg0) {
    func_800560FC(arg0, func_ovl0_802072AC(arg0));
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207388);

void func_ovl0_80207660(void) {
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207668);

void func_ovl0_802078C4(UnkOvl0_80207014 *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0->unk78[i] >= 2) {
            arg0->unk78[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802078F4);

void func_ovl0_80207A10(void) {
    func_80054240(0);
    func_80095D64();
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207A34);

/* 0xB8-byte entries starting at D_801B7250. Placeholder. */
typedef struct Unk801B7250 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0xB0];
} Unk801B7250; /* size = 0xB8 */

extern Unk801B7250 D_801B7250[];

void func_ovl0_80207B8C(s32 i) {
    if (D_801B7250[i].unk0 == -2) {
        D_801B7250[i].unk0 = -1;
    }
    if (D_801B7250[i].unk4 == -2) {
        D_801B7250[i].unk4 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207BEC);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207CAC);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207E88);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80207F70);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802080B4);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802080D4);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80208120);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020816C);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802081F8);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80208354);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020845C);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802087D0);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80208810);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_80208850);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_802088B0);

extern s32 D_ovl0_80224034;
s32 func_8005062C(s32 arg0, void *arg1);
s32 func_8004E2DC(s32);
void func_800506D4(s32 arg0, void *arg1);

void func_ovl0_8020D6F0(void) {
    s32 sp10[8];
    s32 handle;

    handle = func_8004E2DC(func_8005062C(0x6E0, sp10));
    D_ovl0_80227C90[0] = handle;
    func_800506D4(handle, sp10);
    handle = func_8004E2DC(func_8005062C(0x6E5, sp10));
    D_ovl0_80227C90[1] = handle;
    func_800506D4(handle, sp10);
    handle = func_8004E2DC(func_8005062C(0x6F0, sp10));
    D_ovl0_80227C98 = handle;
    func_800506D4(handle, sp10);
    D_ovl0_80224034 = 0;
}

void func_ovl0_8020D784(void) {
    func_8004E47C(&D_ovl0_80227C90[0]);
    func_8004E47C(&D_ovl0_80227C90[1]);
    func_8004E47C(&D_ovl0_80227C98);
}

f32 func_80059FAC(f32, f32);
extern f32 D_801B54EC;
extern f32 D_801B54F4;
extern f32 D_801B54F8;
extern f32 D_801B5500;

f32 func_ovl0_8020D7C4(void) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 var_ft1;

    temp_fa0 = D_801B54F8 - D_801B54EC;
    var_ft1 = 0.0f;
    temp_fa1 = D_801B5500 - D_801B54F4;
    if (((s32) temp_fa0 != 0) || ((s32) temp_fa1 != 0)) {
        var_ft1 = func_80059FAC(temp_fa0, temp_fa1);
    }
    return var_ft1;
}

s32 func_ovl0_8020D838(void) {
    UnkOvl0_8022B5D0 *p;
    s32 i;

    for (i = 0; i != 10; i++) {
        p = &D_ovl0_8022B5D0[i];
        if (p->unkA7 == 2) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020D874);

void func_ovl0_8020D9F0(void) {
    UnkOvl0_8022B5D0 *p;
    s32 i;

    for (i = 0; i != 10; i++) {
        p = &D_ovl0_8022B5D0[i];
        p->unkA7 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020DA18);

INCLUDE_ASM("asm/nonmatchings/BBD00", func_ovl0_8020DCA4);
