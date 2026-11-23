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

/* One course lighting entry (debug-editable): T/B/C/BG colour columns, fog alpha. */
typedef struct LightEntry {
    /* 0x00 */ s32 cc;
    /* 0x04 */ u8 t[3];
    /* 0x07 */ u8 b[3];
    /* 0x0A */ u8 c[3];
    /* 0x0D */ u8 bg[4];
    /* 0x11 */ u8 pad11[0xF];
} LightEntry; /* size 0x20 */

typedef struct PalHeader {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ u16 pal[256];
} PalHeader;

int sprintf(char *, const char *, ...);
s32 func_800299F4(s32);
void func_8002A97C(s32, s32);
void func_8004DA24(char *, s32, s32);
s32 func_80051FCC(void);
extern s32 D_800C5EF0;
extern LightEntry D_800C6014[][8];
extern u8 D_800C69CC[4][2][5][16];
extern u16 D_800C6C52[][2];
extern s32 D_800C6CD0[5];
extern s32 D_800C6CE4;
extern s32 D_800C6CE8;
extern LightEntry *D_800E3980;
extern u16 D_800FBDCE;
extern u16 D_800FBDD2;
extern char D_80105118[];
extern PalHeader *D_801EFFA4;

s32 func_8008E82C(void) {
    s32 buf[8];
    s32 dirty;
    s32 i;
    s32 j;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 f;
    u16 c;
    s32 t;
    s32 m;

    dirty = 0;
    if (func_800299F4(0x2D) != 0) {
        func_8004DA24(" ", D_800C6CE4 * 4 + 14, D_800C6CE8 + 5);
        D_800E3980 = &D_800C6014[func_80051FCC()][D_800BA9F8 * 4 + D_800C5EF0];
        if ((D_800FBDD2 & 0x202) && D_800C6CE4 > 0) {
            D_800C6CE4--;
        }
        if ((D_800FBDD2 & 0x101) && D_800C6CE4 < 4) {
            D_800C6CE4++;
        }
        if (D_800FBDD2 & 0x808) {
            D_800C6CE8--;
        }
        if (D_800FBDD2 & 0x404) {
            D_800C6CE8++;
        }
        if (D_800C6CE8 < 0) {
            D_800C6CE8 = 0;
        }
        if (D_800C6CE4 == 3) {
            if (D_800C6CE8 >= 4) {
                D_800C6CE8 = D_800C6CE4;
            }
        } else if (D_800C6CE4 == 4) {
            if (D_800C6CE8 >= 5) {
                D_800C6CE8 = D_800C6CE4;
            }
        } else if (D_800C6CE8 >= 3) {
            D_800C6CE8 = 2;
        }
        if (D_800FBDCE & 0x8000) {
            switch (D_800C6CE4) {
                case 0:
                    D_800E3980->t[D_800C6CE8] += 4;
                    D_800E3980->t[D_800C6CE8] %= 256;
                    break;
                case 1:
                    D_800E3980->b[D_800C6CE8] += 4;
                    D_800E3980->b[D_800C6CE8] %= 256;
                    break;
                case 2:
                    D_800E3980->c[D_800C6CE8] += 4;
                    D_800E3980->c[D_800C6CE8] %= 256;
                    break;
                case 3:
                    D_800E3980->bg[D_800C6CE8] += 1;
                    dirty = 1;
                    if (D_800C6CE8 == 3) {
                        if (D_800E3980->bg[3] == 101) {
                            D_800E3980->bg[3] = 0;
                        }
                        if (D_800E3980->bg[D_800C6CE8] > 101) {
                            D_800E3980->bg[D_800C6CE8] = 100;
                        }
                    } else {
                        D_800E3980->bg[D_800C6CE8] &= 0x1F;
                    }
                    break;
                case 4:
                    D_800C6CD0[D_800C6CE8] += 4;
                    break;
            }
        } else if (D_800FBDCE & 0x4000) {
            switch (D_800C6CE4) {
                case 0:
                    D_800E3980->t[D_800C6CE8] -= 4;
                    D_800E3980->t[D_800C6CE8] %= 256;
                    break;
                case 1:
                    D_800E3980->b[D_800C6CE8] -= 4;
                    D_800E3980->b[D_800C6CE8] %= 256;
                    break;
                case 2:
                    D_800E3980->c[D_800C6CE8] -= 4;
                    D_800E3980->c[D_800C6CE8] %= 256;
                    break;
                case 3:
                    D_800E3980->bg[D_800C6CE8] -= 1;
                    dirty = 1;
                    if (D_800C6CE8 == 3) {
                        if (D_800E3980->bg[3] == 101) {
                            D_800E3980->bg[3] = 0;
                        }
                        if (D_800E3980->bg[D_800C6CE8] > 101) {
                            D_800E3980->bg[D_800C6CE8] = 100;
                        }
                    } else {
                        D_800E3980->bg[D_800C6CE8] &= 0x1F;
                    }
                    break;
                case 4:
                    D_800C6CD0[D_800C6CE8] -= 4;
                    break;
            }
        }
        if (D_800C6CD0[0] > 255) {
            D_800C6CD0[0] = 255;
        }
        if (D_800C6CD0[1] > 255) {
            D_800C6CD0[1] = 255;
        }
        if (D_800C6CD0[2] > 255) {
            D_800C6CD0[2] = 255;
        }
        if (D_800C6CD0[3] > 1200) {
            D_800C6CD0[3] = 1200;
        }
        if (D_800C6CD0[4] > 1200) {
            D_800C6CD0[4] = 1200;
        }
        if (D_800C6CD0[0] < 0) {
            D_800C6CD0[0] = 0;
        }
        if (D_800C6CD0[1] < 0) {
            D_800C6CD0[1] = 0;
        }
        if (D_800C6CD0[2] < 0) {
            D_800C6CD0[2] = 0;
        }
        if (D_800C6CD0[3] < 0) {
            D_800C6CD0[3] = 0;
        }
        if (D_800C6CD0[4] < 0) {
            D_800C6CD0[4] = 0;
        }
        for (i = 0; i != 4; i++) {
            for (j = 0; j != 3; j++) {
                D_800C69CC[i][0][0][j] = D_800E3980->t[j];
                D_800C69CC[i][0][1][j] = D_800E3980->b[j];
                D_800C69CC[i][0][2][j] = D_800E3980->b[j];
                D_800C69CC[i][0][3][j] = D_800E3980->t[j];
                D_800C69CC[i][0][4][j] = D_800E3980->t[j];
                t = (D_800E3980->t[j] + 0x3F) * 0.5f;
                m = (D_800E3980->b[j] + D_800E3980->t[j]) * 0.5f;
                m = (m + 0x3F) * 0.5f;
                D_800C69CC[i][1][0][j] = t;
                D_800C69CC[i][1][1][j] = m;
                D_800C69CC[i][1][2][j] = m;
                D_800C69CC[i][1][3][j] = t;
                D_800C69CC[i][1][4][j] = t;
            }
        }
        if (dirty != 0) {
            func_8005062C(D_800C6C52[func_80051FCC()][0], buf);
            func_800506D4(D_801EFFA4, buf);
            i = 0;
            for (; i != 256; i++) {
                c = D_801EFFA4->pal[i];
                r = c >> 11;
                g = (c >> 6) & 0x1F;
                b = (c >> 1) & 0x1F;
                a = c & 1;
                if (a == 0) {
                    r = (D_800E3980->b[0] * 5 + D_800E3980->t[0]) / 48;
                    g = (D_800E3980->b[1] * 5 + D_800E3980->t[1]) / 48;
                    b = (D_800E3980->b[2] * 5 + D_800E3980->t[2]) / 48;
                } else {
                    f = D_800E3980->bg[3];
                    r = (r * (100 - f) + D_800E3980->bg[0] * f) / 100;
                    g = (g * (100 - f) + D_800E3980->bg[1] * f) / 100;
                    b = (b * (100 - f) + D_800E3980->bg[2] * f) / 100;
                }
                if (r < 0) {
                    r = 0;
                }
                if (g < 0) {
                    g = 0;
                }
                if (b < 0) {
                    b = 0;
                }
                if (r > 31) {
                    r = 31;
                }
                if (g > 31) {
                    g = 31;
                }
                if (b > 31) {
                    b = 31;
                }
                D_801EFFA4->pal[i] = (r << 11) | (g << 6) | (b << 1) | a;
            }
        }
        func_8004DA24("   T   B   C   BG  FOG", 13, 11);
        sprintf(D_80105118, "R: %3d %3d %3d %3d %4d  ", D_800E3980->t[0], D_800E3980->b[0], D_800E3980->c[0], D_800E3980->bg[0], D_800C6CD0[0]);
        func_8004DA24(D_80105118, 13, 12);
        sprintf(D_80105118, "G: %3d %3d %3d %3d %4d  ", D_800E3980->t[1], D_800E3980->b[1], D_800E3980->c[1], D_800E3980->bg[1], D_800C6CD0[1]);
        func_8004DA24(D_80105118, 13, 13);
        sprintf(D_80105118, "B: %3d %3d %3d %3d %4d  ", D_800E3980->t[2], D_800E3980->b[2], D_800E3980->c[2], D_800E3980->bg[2], D_800C6CD0[2]);
        func_8004DA24(D_80105118, 13, 14);
        sprintf(D_80105118, "A:             %3d %4d  ", D_800E3980->bg[3], D_800C6CD0[3]);
        func_8004DA24(D_80105118, 13, 15);
        sprintf(D_80105118, "CC:%d               %4d  ", D_800E3980->cc, D_800C6CD0[4]);
        func_8004DA24(D_80105118, 13, 16);
        func_8004DA24(">", D_800C6CE4 * 4 + 15, D_800C6CE8 + 12);
        func_800292FC(3);
        func_8002A97C(4, 0);
        return 1;
    }
    return 0;
}

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
