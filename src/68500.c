#define F3DEX_GBI_2
#include "common.h"

extern s32 D_800C5EE4;
extern s32 D_800C5EFC;
extern s32 D_800C7304;
extern s32 D_800C730C;

s32 func_800292FC(s32);
s32 func_80029A30(s32);
s32 func_80069F38();
s32 func_80069FBC();
s32 memset(s32 *, s32, s32);
s16 rand();
extern s32 D_800BA9F0;
extern s16 D_800BA9F4;
extern s32 D_800BA9F8;
extern s32 D_800BA9FC;
extern s16 D_800BAA00;
extern s16 D_800BAA02;
extern s32 D_801B6088;
extern s32 D_801B608C;
extern s32 D_801B6090;
extern s32 D_801B6094;
extern s32 D_801B6098;
extern s32 D_801B609C;

void func_8008D100(void) {
    memset(&D_801B6088, 0, 0x44);
    D_801B6098 = 9;
    D_801B6094 = 0;
    D_801B609C = 0;
    D_801B608C = 0xC;
    D_800BA9F8 = 0;
    D_800BA9F0 = (rand() & 0x3F) * 0x1770;
    D_800BA9F4 = rand();
    D_800BA9FC = 6;
    D_800BAA02 = 0x1000;
    D_800BAA00 = 0x6000;
    func_80029A30(7);
    D_801B6090 = 1;
    func_80069FBC();
    func_80069F38();
    func_800292FC(2);
}

INCLUDE_ASM("asm/nonmatchings/68500", func_8008D1DC);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008D3F4);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008DDDC);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008E164);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008E1B4);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008E82C);

INCLUDE_ASM("asm/nonmatchings/68500", func_8008F30C);

void func_8008FF14(s32 arg0) {
    D_800C5EFC = arg0;
}

INCLUDE_ASM("asm/nonmatchings/68500", func_8008FF20);

INCLUDE_ASM("asm/nonmatchings/68500", func_80091110);

extern s32 D_800C72F8;
extern s32 D_800C72FC;
extern s32 D_800C7300;
extern s32 D_800C5EE8;

/* Sets mode D_800C5EE8 and its per-mode value D_800C5EE4; -1 turns it off. */
void func_8009226C(s32 mode) {
    if (mode == -1) {
        D_800C72F8 = 0;
        D_800C5EE4 = 0;
        return;
    }
    if (mode != 4 && mode != 5) {
        D_800C7300 = 0;
    }
    switch (mode) {
        case 0:
            D_800C5EE4 = 0x160;
            break;
        case 1:
        case 9:
            D_800C5EE4 = 0xFF;
            break;
        case 2:
            D_800C5EE4 = 0xFF;
            break;
        case 8:
            D_800C5EE4 = 0xA0;
            break;
        case 10:
            D_800C5EE4 = 0x48;
            break;
        case 3:
            D_800C5EE4 = 0xFF;
            break;
        case 5:
            D_800C5EE4 = 0x40;
            break;
        case 6:
        case 7:
            D_800C5EE4 = 0x20;
            break;
    }
    D_800C5EE8 = mode;
    D_800C72F8 = 1;
    D_800C72FC = 0;
}

void func_80092324(void) {
}

INCLUDE_ASM("asm/nonmatchings/68500", func_8009232C);

INCLUDE_ASM("asm/nonmatchings/68500", func_80092E10);

INCLUDE_ASM("asm/nonmatchings/68500", func_80092F18);

void func_800934CC(s32 arg0) {
    if (arg0 == -1) {
        D_800C7304 = 0;
    } else if (arg0 == 3) {
        D_800C730C = arg0;
        D_800C7304 = 2;
    } else {
        D_800C7304 = 1;
        D_800C730C = arg0;
    }
}

INCLUDE_ASM("asm/nonmatchings/68500", func_8009351C);

INCLUDE_ASM("asm/nonmatchings/68500", func_800939E8);

INCLUDE_ASM("asm/nonmatchings/68500", func_80094228);

INCLUDE_ASM("asm/nonmatchings/68500", func_800947A8);

INCLUDE_ASM("asm/nonmatchings/68500", func_80095150);

INCLUDE_ASM("asm/nonmatchings/68500", func_8009548C);

extern Gfx *D_801B93DC;
extern s32 D_800C5EE8;
extern u16 *D_800FED10;
extern u16 *nuGfxCfb_ptr;
void func_80095150(void);
void func_8009232C(Gfx **);
void func_800947A8(void);
void func_80094228(void);
void func_8009548C(void);
void func_80092F18(Gfx **);

/* Per-frame draw for mode D_800C5EE8: sets up, then calls the mode's drawer;
 * remembers the frame buffer it drew to. */
void func_800957F0(void) {
    func_80095150();
    gDPPipeSync(D_801B93DC++);
    gDPSetColorDither(D_801B93DC++, G_CD_DISABLE);
    switch (D_800C5EE8) {
        case 1:
        case 6:
        case 7:
        case 8:
        case 9:
            func_8009232C(&D_801B93DC);
            break;
        case 2:
            func_800947A8();
            break;
        case 3:
            func_80094228();
            break;
        case 5:
            func_8009548C();
            break;
        case 10:
            func_80092F18(&D_801B93DC);
            break;
    }
    D_800FED10 = nuGfxCfb_ptr;
}

extern Gfx *D_801B93DC;
typedef struct Unk801B7F30 {
    /* 0x0 */ s16 ulx;
    /* 0x2 */ s16 uly;
    /* 0x4 */ s16 lrx;
    /* 0x6 */ s16 lry;
} Unk801B7F30;

extern Unk801B7F30 D_801B7F30;

void func_800958D8(void) {

    D_801B7F30.ulx = 0;
    D_801B7F30.lrx = 320;
    D_801B7F30.lry = 240;
    D_801B7F30.uly = 0;
    gDPPipeSync(D_801B93DC++);
    gDPSetScissor(D_801B93DC++, G_SC_NON_INTERLACE, D_801B7F30.ulx, D_801B7F30.uly, D_801B7F30.lrx, D_801B7F30.lry);
}

s32 func_800959F8(void) {
    return D_800C5EE4 < 1;
}
