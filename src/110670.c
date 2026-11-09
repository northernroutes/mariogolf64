/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

extern s32 D_ovl3_80230E88;
extern f32 D_ovl3_80230E8C;
extern f32 D_ovl3_80230E90;
extern s32 D_ovl3_80230E9C;
extern s32 D_ovl3_80230EA0;
extern u8 D_ovl3_80230F40;
/* splat labels the byte at 0x80105DC0 as D_80105DBC + 4. */
extern s8 D_80105DBC[];

void *func_8005AF50(void);
void *func_8005AF74(void);

void func_ovl3_802266F0(void) {
    D_ovl3_80230E88 = 0;
    D_ovl3_80230E8C = 0.0f;
    D_ovl3_80230E90 = 0.0f;
    D_ovl3_80230E9C = 0;
    D_ovl3_80230EA0 = 0;
}

void func_ovl3_8022671C(void) {
    D_ovl3_80230E9C = 0;
    D_ovl3_80230EA0 = 0;
    D_ovl3_80230E88 = 1;
    D_ovl3_80230E8C = 1.0f;
    D_ovl3_80230E90 = 1.0f;
}

void func_ovl3_80226754(void) {
    D_ovl3_80230E88 = 2;
}

s32 func_ovl3_80226764(void) {
    if (D_ovl3_80230E88 != 0) {
        return D_ovl3_80230E88 == 1;
    }
    return -1;
}

s32 func_ovl3_80226788(void) {
    if (D_ovl3_80230E88 != 2) {
        return D_ovl3_80230E88 == 3;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_802267B0);

/* Look up a 16-bit id in a table, fill a 0x20-byte buffer for it via
 * func_8005062C and pass both to func_800506D4 (cf. func_8006ACD8 in 456C0). */
s32 func_8005062C(s32 id, void *buf);
void func_800506D4(s32 handle, void *buf);

extern u16 D_800C2074[];
extern s32 D_ovl3_80230E7C;
extern s32 D_ovl3_80230E80;
extern u16 D_ovl3_80230EA4[];

void func_ovl3_80226904(s32 arg0) {
    s32 sp10[8];

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 >= 10) {
        arg0 = 9;
    }
    func_8005062C(D_800C2074[arg0], sp10);
    func_800506D4(D_ovl3_80230E7C, sp10);
}

void func_ovl3_80226958(s32 arg0) {
    s32 sp10[8];

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 >= 15) {
        arg0 = 14;
    }
    func_8005062C(D_ovl3_80230EA4[arg0], sp10);
    func_800506D4(D_ovl3_80230E80, sp10);
}

/* func_800504E8 / 80050598 / 800505A0 (2B800) work on a 0x10-byte object. */
s32 func_800504E8(s32 id, void *obj);
s16 func_80050598(void *obj);
s32 func_800505A0(s32 handle, s16 arg1, void *obj);

extern s32 D_ovl3_80230E84;
extern s16 D_ovl3_80230EC4[15][4];

void func_ovl3_802269AC(s32 arg0, s32 arg1) {
    s32 sp10[4];

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 >= 15) {
        arg0 = 14;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 >= 4) {
        arg1 = 3;
    }
    func_800504E8(D_ovl3_80230EC4[arg0][arg1], sp10);
    func_800505A0(D_ovl3_80230E84, func_80050598(sp10), sp10);
}

void func_ovl3_80226A34(void) {
    func_8005AF50();
    func_8005AF74();
}

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_80226A58);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022747C);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_802287EC);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_80228A80);

extern s32 D_ovl3_80230F5C;
extern s32 D_ovl3_80230F60;
extern s32 D_ovl3_80230F64;
extern s32 D_ovl3_80230F68;
extern s32 D_ovl3_80230F6C;
extern s32 D_ovl3_80230F70;
extern s32 D_ovl3_80230F74;
extern s32 D_ovl3_80230F78;
extern s32 D_ovl3_80230F7C;
extern u8 D_ovl3_80230F80;
extern u8 D_ovl3_80230FD4[8];

void func_ovl3_80228B60(void) {
    u8 *p = func_8005AF74(); /* layout unknown; bytes 0x47/0x48 are cleared */
    s32 i;

    p[0x47] = 0;
    p[0x48] = 0;
    D_ovl3_80230F74 = 0;
    for (i = 0; i != 8; i++) {
        D_ovl3_80230FD4[i] = 0xFF;
    }
    D_ovl3_80230F68 = 0;
    D_ovl3_80230F6C = 0;
    D_ovl3_80230F5C = 0;
    D_ovl3_80230F60 = 0;
    D_ovl3_80230F64 = 0;
    D_ovl3_80230F78 = 0;
    D_ovl3_80230F70 = 0;
    D_ovl3_80230F80 = 0;
    D_ovl3_80230F40 = 1;
    D_ovl3_80230F7C = 0;
}

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_80228C00);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_80229278);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_802296C4);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_80229CB0);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022A090);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022A43C);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022A8F4);

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022ADE8);

extern char D_80105118[];
extern char D_ovl3_80231AA8[];
void func_80074CA8(Gfx **, s32, s32, s32);
void func_8007624C(Gfx **, s32, s32, char *, s32, s32, s32);

/* Draws the eight entered code characters (0xFF = empty slot). */
void func_ovl3_8022B360(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 i;

    gDPPipeSync(gfx++);
    func_80071608(&gfx);
    func_80074CA8(&gfx, 0xFF, 0xFF, 0xFF);
    for (i = 0; i != 8; i++) {
        if (D_ovl3_80230FD4[i] != 0xFF) {
            sprintf(D_80105118, D_ovl3_80231AA8, D_ovl3_80230FD4[i]);
            func_8007624C(&gfx, i * 0x18 + 0x61, 0x96, D_80105118, -1, -1, 0);
        }
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022B46C);

extern s32 D_ovl3_80230F68;
extern u8 D_ovl3_80230FD4[8];

/* Deletes the last entered character; returns 1 if there was nothing to delete. */
s32 func_ovl3_8022B5E0(void) {
    s32 ret = 1;

    if (D_ovl3_80230F68 > 0) {
        if (D_ovl3_80230F68 == 8) {
            D_ovl3_80230F68 = 7;
        }
        D_ovl3_80230FD4[D_ovl3_80230F68] = 0xFF;
        D_ovl3_80230F68--;
        ret = 0;
    } else if (D_ovl3_80230FD4[0] != 0xFF) {
        D_ovl3_80230FD4[0] = 0xFF;
        ret = 0;
    }
    return ret;
}

s32 func_ovl3_80226764(void);
void func_80071608(Gfx **);
void func_800719A0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80071CE4(Gfx **, s32);

void func_ovl3_8022B668(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 x = 0;
    s32 dy;
    s32 flags;

    switch (D_ovl3_80230F6C) {
        case 0:
            dy = 0;
            x = 0x38;
            flags = (func_ovl3_80226764() == 0) ? 0x21 : 0x20;
            break;
        case 1:
            dy = 1;
            x = 0x18;
            flags = 0x21;
            break;
        default:
            dy = -1;
            flags = 0x21;
            break;
    }
    if (dy >= 0) {
        gDPPipeSync(gfx++);
        func_80071608(&gfx);
        func_800719A0(x, 0xB4, dy + 0x165, 1, 0, flags, 0xFF, 0xFF, 0xFF, 0xFF);
        func_80071CE4(&gfx, 0);
    }
    *gdl = gfx;
}

extern s32 D_ovl3_80230F6C;
extern u8 D_ovl3_80230FDC[36][8];

/* Returns the index of the D_ovl3_80230FDC entry equal to the entered code, or -1. */
s32 func_ovl3_8022B75C(void) {
    s32 found = -1;
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i != 36; i++) {
        n = 0;
        for (j = 0; j != 8; j++) {
            if (D_ovl3_80230FD4[j] != D_ovl3_80230FDC[i][j]) {
                break;
            }
            n++;
        }
        if (n == 8) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        D_ovl3_80230F6C = 1;
    }
    return found;
}

INCLUDE_ASM("asm/nonmatchings/110670", func_ovl3_8022B7E0);

s32 func_ovl3_8022BDB0(void) {
    return D_80105DBC[4] == -1;
}

s32 func_ovl3_8022BDC4(void) {
    return D_80105DBC[4];
}

s32 func_ovl3_8022BDD0(void) {
    if (D_ovl3_80230F40 != 0) {
        D_ovl3_80230F40 = 0;
        return 1;
    }
    return 0;
}

void func_ovl3_8022BDF8(void) {
}
