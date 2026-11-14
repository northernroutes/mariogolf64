#include "common.h"
#include "ovl7_camera.h"

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

s32 rand(void);
extern s32 D_ovl7_8020AC64;
extern s32 D_ovl7_8020AC68;
extern s32 D_ovl7_8020AC6C;
extern s32 D_ovl7_8020AC70;
extern s32 D_ovl7_8020AC74;
extern s32 D_ovl7_8020AC78;
extern s32 D_ovl7_8020AC7C;
extern s32 D_ovl7_8020AC80;
extern s32 D_ovl7_8020AC84;
extern s32 D_ovl7_8020AC88;
extern s32 D_ovl7_8020AC8C;

/* Ambient sounds: while the camera is within 254 units, randomly starts three
 * kinds of sound timers, then plays each sound (quieter with distance) on the
 * frame its timer starts. */
void func_ovl7_801F4AEC(void) {
    if (D_ovl7_8020AC64 == 1) {
        if ((u32)(D_ovl7_8022BE30.dist * 0.5f) < 127) {
            if (D_ovl7_8020AC68 == 0 && (rand() & 100) < 80) {
                if (D_ovl7_8020AC74 == 2) {
                    D_ovl7_8020AC74 = 1;
                    D_ovl7_8020AC68 = D_ovl7_8020AC7C;
                } else {
                    D_ovl7_8020AC74 = 2;
                    D_ovl7_8020AC68 = D_ovl7_8020AC80;
                }
            }
            if (D_ovl7_8020AC6C == 0 && (rand() & 100) < 80) {
                D_ovl7_8020AC6C = D_ovl7_8020AC84;
            }
            if (D_ovl7_8020AC70 == 0 && (rand() & 100) < 80) {
                switch (rand() & 3) {
                    case 0:
                        D_ovl7_8020AC78 = 1;
                        D_ovl7_8020AC70 = D_ovl7_8020AC88;
                        break;
                    case 1:
                        D_ovl7_8020AC78 = 2;
                        D_ovl7_8020AC70 = D_ovl7_8020AC8C;
                        break;
                }
            }
        }
        if (D_ovl7_8020AC68 != 0) {
            if (D_ovl7_8020AC74 == 1 && D_ovl7_8020AC68 == D_ovl7_8020AC7C) {
                func_80050DA0(0x184, 13, 127 - (u32)(D_ovl7_8022BE30.dist * 0.5f), 0, 0x9D);
            }
            if (D_ovl7_8020AC74 == 2 && D_ovl7_8020AC68 == D_ovl7_8020AC80) {
                func_80050DA0(0x185, 13, 127 - (u32)(D_ovl7_8022BE30.dist * 0.5f), 0, 0x9D);
            }
            D_ovl7_8020AC68--;
        }
        if (D_ovl7_8020AC6C != 0) {
            if (D_ovl7_8020AC6C == D_ovl7_8020AC84) {
                func_80050DA0(0x18B, 14, 127 - (u32)(D_ovl7_8022BE30.dist * 0.5f), 0, 0x75);
            }
            D_ovl7_8020AC6C--;
        }
        if (D_ovl7_8020AC70 != 0) {
            if (D_ovl7_8020AC78 == 1 && D_ovl7_8020AC70 == D_ovl7_8020AC88) {
                func_80050DA0(0x1A3, 15, 127 - (u32)(D_ovl7_8022BE30.dist * 0.5f), 0, 0x61);
            }
            if (D_ovl7_8020AC78 == 2 && D_ovl7_8020AC70 == D_ovl7_8020AC8C) {
                func_80050DA0(0x1BA, 15, 127 - (u32)(D_ovl7_8022BE30.dist * 0.5f), 0, 0x61);
            }
            if (--D_ovl7_8020AC70 == 0) {
                D_ovl7_8020AC78 = 0;
            }
        }
    }
}

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

extern s32 D_ovl7_8020AD68;
extern s32 D_ovl7_8022BF08;
extern s32 D_ovl7_8022BF0C;
extern s32 D_ovl7_8022BF10;
extern f32 D_ovl7_8021706C;
extern f32 D_ovl7_80217070;
extern f32 D_ovl7_80217074;
extern f32 D_ovl7_8020B260;

/* Eases the camera's look-at point towards a target, by camera mode
 * D_ovl7_8020AD68: 1 and 2 track D_ovl7_8022BF08 (1/1024 units) at 10% / 1%
 * per frame, 3 tracks D_ovl7_8021706C with a rate ramping up to 10%. */
void func_ovl7_802008D8(void) {
    switch (D_ovl7_8020AD68) {
        case 1:
            D_ovl7_8022BE30.pos[1][0] += (D_ovl7_8022BF08 * 0.0009765625f - D_ovl7_8022BE30.pos[1][0]) * 0.1f;
            D_ovl7_8022BE30.pos[1][1] += (D_ovl7_8022BF0C * 0.0009765625f - D_ovl7_8022BE30.pos[1][1]) * 0.1f;
            D_ovl7_8022BE30.pos[1][2] += (D_ovl7_8022BF10 * 0.0009765625f - D_ovl7_8022BE30.pos[1][2]) * 0.1f;
            func_ovl7_80203620();
            break;
        case 2:
            D_ovl7_8022BE30.pos[1][0] += (D_ovl7_8022BF08 * 0.0009765625f - D_ovl7_8022BE30.pos[1][0]) * 0.01f;
            D_ovl7_8022BE30.pos[1][1] += (D_ovl7_8022BF0C * 0.0009765625f - D_ovl7_8022BE30.pos[1][1]) * 0.01f;
            D_ovl7_8022BE30.pos[1][2] += (D_ovl7_8022BF10 * 0.0009765625f - D_ovl7_8022BE30.pos[1][2]) * 0.01f;
            func_ovl7_80203620();
            break;
        case 3:
            D_ovl7_8022BE30.pos[1][0] += ((D_ovl7_8021706C + 38.1f) - D_ovl7_8022BE30.pos[1][0]) * D_ovl7_8020B260;
            D_ovl7_8022BE30.pos[1][1] += ((D_ovl7_80217070 - 4.5f) - D_ovl7_8022BE30.pos[1][1]) * D_ovl7_8020B260;
            D_ovl7_8022BE30.pos[1][2] += ((D_ovl7_80217074 - 4.795f) - D_ovl7_8022BE30.pos[1][2]) * D_ovl7_8020B260;
            func_ovl7_80203620();
            D_ovl7_8020B260 += 0.002f;
            if (D_ovl7_8020B260 > 0.1f) {
                D_ovl7_8020B260 = 0.1f;
            }
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80200B18);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80200CBC);

INCLUDE_ASM("asm/nonmatchings/1370C0", func_ovl7_80202D34);
