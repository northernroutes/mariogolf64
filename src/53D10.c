#include "common.h"

s32 func_8004E47C(s32 *);
extern s32 D_800C53B8;
extern s32 D_800E1DA0;
extern s32 D_800E1DA4;
extern s32 D_800E1DA8;
extern s32 D_800E1DAC;
extern s32 D_800E1DB0;
extern s32 D_800E1DB4;
extern s32 D_800E1DB8;
extern s32 D_800E1DBC;
extern s32 D_800E1DC0;
extern s32 D_800E1DC4;
extern s32 D_800E1DC8;
extern s32 D_800E1DCC;

void func_80078910(void) {
    if (D_800C53B8 != 0) {
        func_8004E47C(&D_800E1DA0);
        func_8004E47C(&D_800E1DA4);
        func_8004E47C(&D_800E1DA8);
        func_8004E47C(&D_800E1DAC);
        func_8004E47C(&D_800E1DB0);
        func_8004E47C(&D_800E1DB4);
        func_8004E47C(&D_800E1DB8);
        func_8004E47C(&D_800E1DBC);
        func_8004E47C(&D_800E1DC0);
        func_8004E47C(&D_800E1DC4);
        func_8004E47C(&D_800E1DC8);
        func_8004E47C(&D_800E1DCC);
        D_800C53B8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_800789C8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078BDC);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078D94);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078DC0);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078FA8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079358);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007955C);

INCLUDE_ASM("asm/nonmatchings/53D10", func_800796F8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079940);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079A08);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079ADC);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079EBC);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007A10C);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007A40C);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007A6C8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007B054);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007B994);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007C5D8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007CF10);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007D19C);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007D4E8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007DB08);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007DE9C);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007DFD0);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E104);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E19C);

s32 func_8004E2DC(s32);
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
s32 func_8007E7B8();
extern s32 D_800C5448;
extern s32 D_800FF4CC;
extern s32 D_801B8BB8;
extern s32 D_801EFFA8;

void func_8007E234(s32 arg0) {
    s32 sp10[8];
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8004E2DC(func_8005062C(0x6BC, sp10));
        D_800FF4CC = temp_v0;
        func_800506D4(temp_v0, sp10);
        D_801EFFA8 = func_8004E2DC(0x900);
        D_801B8BB8 = func_8004E2DC(0x380);
        func_8007E7B8();
    }
    D_800C5448 = arg0;
}

s32 func_8004E47C(s32 *);
s32 func_80050F68(s32);
extern s32 D_800C5448;
extern s32 D_800FF4CC;
extern s32 D_801B8BB8;
extern s32 D_801EFFA8;

void func_8007E2B0(void) {
    if (D_800C5448 == 2) {
        func_8004E47C(&D_800FF4CC);
        func_8004E47C(&D_801EFFA8);
        func_8004E47C(&D_801B8BB8);
    }
    func_80050F68(9);
    D_800C5448 = -1;
}

extern f32 D_801B54EC;
extern f32 D_801B54F4;
extern f32 D_801B54F8;
extern f32 D_801B5500;
typedef struct Vec2i {
    s32 x;
    s32 z;
} Vec2i;
extern Vec2i D_800FF418;
extern char D_800D1A78[];

/* Sets D_800FF418 to the point 150 units from (D_801B54EC, D_801B54F4)
 * towards (D_801B54F8, D_801B5500), in XZ. */
void func_8007E30C(void) {
    s32 dx = D_801B54F8 - D_801B54EC;
    s32 dz = D_801B5500 - D_801B54F4;
    f32 len = sqrtf(dx * dx + dz * dz);

    D_800FF418.x = dx;
    D_800FF418.z = dz;
    if ((s32)len != 0.0f) {
        len = 150.0f / len;
    } else {
        osSyncPrintf(D_800D1A78);
        len = 0.0f;
    }
    D_800FF418.x = D_800FF418.x * len + D_801B54EC;
    D_800FF418.z = D_800FF418.z * len + D_801B54F4;
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E438);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E664);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E7B8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E980);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007EF0C);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_800C5458;
extern s32 D_800C545C;
extern s32 D_800C5460;
extern s32 D_800E1DB4;
extern s32 D_800E1DB8;

void func_8007FE44(s32 arg0) {
    s32 sp10[8];

    D_800C5458 = arg0;
    D_800C545C = 1;
    D_800C5460 = 0;
    func_8005062C(0x663, sp10);
    func_800506D4(D_800E1DB4, sp10);
    func_8005062C(0x689, sp10);
    func_800506D4(D_800E1DB8, sp10);
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007FEAC);
