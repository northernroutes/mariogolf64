#include "common.h"

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080220);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800802E0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080564);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008060C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080688);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008085C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080C4C);

s32 func_80026400(s32, s32);
s32 func_8004E2DC(s32);
extern s32 D_800C5470;
extern s32 D_800C59E0;

void func_80080DCC(void) {
    u8 pad_unused[0x20]; /* unused; sizes the stack frame */
    s32 temp_v0;

    if (D_800C59E0 == 0) {
        temp_v0 = func_8004E2DC(0x7118);
        D_800C5470 = temp_v0;
        func_80026400(temp_v0, 0x7118);
        D_800C59E0 = 1;
    }
}

s32 func_800263B0();
s32 func_8004E47C(s32 *);
s32 func_8007E2B0();
s32 func_80080C4C();
s32 func_80216B74(s32);
s32 memset(s32 *, s32, s32);
extern s32 D_801061B8;

void func_80080E14(void) {
    if (D_800C59E0 != 0) {
        func_800263B0();
        func_8004E47C(&D_800C5470);
        func_8007E2B0();
        func_80216B74(1);
        func_80080C4C();
        D_800C59E0 = 0;
        memset(&D_801061B8, 0, 0x8C);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80080E7C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081284);

s32 func_8003E4B4();

void func_80081550(void) {
    func_8003E4B4();
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008156C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081C90);

s32 func_800326FC(s32, s32, s32, s32);
u32 *func_80032E60(s8);
s32 func_8004C510(s32);
s32 func_8007515C(s32, s32, s32, s32, s32, s32);
s32 func_8020FFEC(s32);
extern s32 D_800C5A10;
extern s32 D_800C5A14;
extern s8 D_800D1AD0;
extern s8 D_80104B6B;
extern s32 D_801B7F70;
extern s32 D_801B7F78;
extern s32 D_801B7F7C;

void func_80081D4C(s32 arg0) {
    s32 temp_s0;
    u32 temp_v1;

    D_800C5A14 = 0;
    if (arg0 == -1) {
        D_800C5A10 = arg0;
        func_8007515C(0, -1, 0, 0, 0, 0);
        func_8007515C(1, -1, 0, 0, 0, 0);
        func_8020FFEC(-1);
        return;
    }
    temp_s0 = D_800C5A10;
    if (temp_s0 == -1) {
        D_800C5A10 = arg0;
        temp_v1 = *func_80032E60(D_80104B6B);
        switch (temp_v1) {
        case 13:
            D_801B7F70 = 1;
            D_801B7F78 = 0x4D;
            D_800C5A10 = temp_s0;
            D_801B7F7C = 0x65;
            func_800326FC(0xA0, 0x80, 0x80, 0x80);
            func_8004C510(0x3C);
            func_8020FFEC(0);
            osSyncPrintf(&D_800D1AD0);
            return;
        case 21:
        case 10:
            D_800C5A10 = 2;
            func_8004C510(0x3C);
            return;
        case 11:
            func_8004C510(0x28);
            return;
        default:
            D_801B7F70 = 1;
            D_801B7F78 = 0x4D;
            D_801B7F7C = 0x4D;
            func_8004C510(0x28);
            func_800326FC(0xA0, 0xA0, 0x40, 0x38);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80081EF8);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800824E4);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80082534);

typedef struct Unk800E3370 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Unk800E3370; /* size = 0xC */

typedef struct Unk80104AE0 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
} Unk80104AE0; /* size = 0xC */

extern s32 D_800C5AA8;
extern Unk800E3370 D_800E3370[0x80];
extern Unk80104AE0 D_80104AE0;

void func_80083A48(void) {
    s32 i;

    D_800C5AA8 = 0;
    for (i = 0; i != 0x80; i++) {
        D_800E3370[i].x = D_80104AE0.x * (1.0f / 1024);
        D_800E3370[i].y = D_80104AE0.y * (1.0f / 1024);
        D_800E3370[i].z = D_80104AE0.z * (1.0f / 1024);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80083AC8);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800842C0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80084468);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80084EBC);

extern u16 D_800FBDD2;
extern s32 D_800C5AD0;
extern char D_80105118[];
extern char D_800D1B70[];
s32 func_800299F4(u32 n);
void func_8004DA24(char *, s32, s32);

void func_800852A8(void) {
    if (func_800299F4(0x6E) != 0) {
        if (D_800FBDD2 & 8) {
            D_800C5AD0--;
        }
        if (D_800FBDD2 & 4) {
            D_800C5AD0++;
        }
        sprintf(D_80105118, D_800D1B70, D_800C5AD0);
        func_8004DA24(D_80105118, 0x14, 6);
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008534C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80085F98);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008658C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008679C);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80086864);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800874D8);

extern s32 D_800E2190[5];
extern s32 D_800E21A8[5];

void func_80087BAC(void) {
    s32 i;

    for (i = 0; i != 5; i++) {
        D_800E2190[i] = 0;
        D_800E21A8[i] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_80087BE4);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80087CB0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_800880A0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80088890);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80088A90);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80088BDC);

INCLUDE_ASM("asm/nonmatchings/5B620", func_80089094);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008C520);

extern s32 D_800C5ED8;
extern s32 D_800E3970;
extern s32 D_800E3974;

void func_8008C658(void) {
    if (D_800C5ED8 & 1) {
        func_8004E47C(&D_800E3970);
    }
    if (D_800C5ED8 & 2) {
        func_8004E47C(&D_800E3974);
    }
    D_800C5ED8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008C6B0);

INCLUDE_ASM("asm/nonmatchings/5B620", func_8008CD30);

extern s32 D_800C54E0;

void func_8008D0DC(void) {
    D_800C54E0 ^= 1;
}
