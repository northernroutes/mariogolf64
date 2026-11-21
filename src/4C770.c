/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

/* Placeholder types; real types unknown. Rename once identified. */

/* 0x2C-byte entries of D_8012F510. splat labels the fields separately
 * (D_8012F51C = unkC, D_8012F524 = unk14, D_8012F52C = unk1C). */
typedef struct Unk8012F510 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0x4];
    /* 0x1C */ s32 unk1C[4];
} Unk8012F510; /* size = 0x2C */

/* 3-byte entries of D_8010CFA8 (see func_800718F4). */
typedef struct Unk8010CFA8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
} Unk8010CFA8; /* size = 0x3 */

/* 0x48-byte entries of D_800FF570 (see func_8007512C). */
typedef struct Unk800FF570 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ s8 unk3;
    /* 0x04 */ u8 pad4[0x44];
} Unk800FF570; /* size = 0x48 */

/* 0x48-byte glyph slots: one positioned character of an on-screen message.
 * D_800FF570 (Unk800FF570) is the same array seen from +0x40. */
typedef struct MsgGlyph {
    /* 0x00 */ Mtx mtx;
    /* 0x40 */ u16 code;
    /* 0x42 */ s8 size;
    /* 0x43 */ s8 owner;
    /* 0x44 */ u8 pad44[4];
} MsgGlyph; /* size = 0x48 */

/* 4-byte entries of the array D_800E1C48 points to (see func_80071C9C). */
typedef struct Unk800E1C48 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} Unk800E1C48; /* size = 0x4 */

extern Unk8012F510 D_8012F510[];
extern Unk8010CFA8 D_8010CFA8[];
extern Unk800FF570 D_800FF570[];
extern Unk800E1C48 *D_800E1C48;
extern u8 D_801321B0[];

INCLUDE_ASM("asm/nonmatchings/4C770", func_80071370);

s32 func_8004E47C(Unk800E1C48 **);
extern Unk800E1C48 *D_800E1C30;
extern Unk800E1C48 *D_800E1C34;
extern Unk800E1C48 *D_800E1C38;
extern Unk800E1C48 *D_800E1C44;
extern Unk800E1C48 *D_800E1C4C;
extern Unk800E1C48 *D_8012F4E0;

void func_800715A0(void) {
    func_8004E47C(&D_8012F4E0);
    func_8004E47C(&D_800E1C30);
    func_8004E47C(&D_800E1C34);
    func_8004E47C(&D_800E1C38);
    func_8004E47C(&D_800E1C4C);
    func_8004E47C(&D_800E1C44);
    func_8004E47C(&D_800E1C48);
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_80071608);

void func_800718C4(void) {
    s32 i;

    for (i = 0; i != 12; i++) {
        D_8012F510[i].unk14 = -1;
    }
}

void func_800718F4(u8 arg0, u8 arg1, u8 arg2, s32 arg3) {
    D_8010CFA8[arg3].unk0 = arg0;
    D_8010CFA8[arg3].unk1 = arg1;
    D_8010CFA8[arg3].unk2 = arg2;
}

void func_80071924(s32 arg0, s32 arg1, s32 arg2) {
    D_8012F510[arg1].unk1C[arg2] = arg0;
}

void func_80071954(u8 *src) {
    u8 *dst = D_801321B0;
    u8 *end = src + 0x13;
    u8 c;

    do {
        c = *src;
        *dst = c;
        if (c >= 'a' && c <= 'z') {
            *dst = c + 0x80;
        }
        if (*src == 0) {
            break;
        }
        src++;
        dst++;
    } while (src != end);
    D_801321B0[0x13] = 0;
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_800719A0);

/* 0x2C-byte drawable objects at D_8012F518. Placeholder. */
typedef struct Unk8012F518 {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 flags;
    /* 0x0C */ s32 id;
    /* 0x10 */ u8 r;
    /* 0x11 */ u8 g;
    /* 0x12 */ u8 b;
    /* 0x13 */ u8 a;
    /* 0x14 */ u8 pad14[0x18];
} Unk8012F518; /* size = 0x2C */

extern Unk8012F518 D_8012F518[12];
void func_80071608(Gfx **);
void func_80071CE4(Gfx **, s32);
void func_80072A08(Gfx **, s32);

void func_80071B34(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 i;

    func_80071608(&gfx);
    for (i = 0; i != 12; i++) {
        if (D_8012F518[i].id == -1) {
            continue;
        }
        if (D_8012F518[i].flags & 0x20) {
            continue;
        }
        gDPSetPrimColor(gfx++, 0, 0, D_8012F518[i].r, D_8012F518[i].g, D_8012F518[i].b, D_8012F518[i].a);
        if (D_8012F518[i].type == 10) {
            func_80072A08(&gfx, i);
        } else {
            func_80071CE4(&gfx, i);
        }
    }
    *gdl = gfx;
}

void func_80071C74(s32 arg0) {
    D_8012F510[arg0].unkC = 0xFF;
}

s32 func_80071C9C(s32 arg0) {
    Unk8012F510 *p = &D_8012F510[arg0];

    /* Indexed as [unk14 + 1]: a field-at-0x4 struct picks different registers. */
    return p->unkC >= D_800E1C48[p->unk14 + 1].unk2;
}

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D1588);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D158C);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D1590);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D1598);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D15A0);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D15A8);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D15AC);

INCLUDE_RODATA("asm/nonmatchings/4C770", D_800D15B0);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80071CE4);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80072A08);

INCLUDE_ASM("asm/nonmatchings/4C770", func_800734F0);

INCLUDE_ASM("asm/nonmatchings/4C770", func_800738BC);

extern char D_800D1588[];
extern char D_800D158C[];
extern s32 D_80104FD0;
extern u8 D_800C4390[];
extern char D_80105118[];
int sprintf(char *, const char *, ...);
u32 func_800738BC(s32, s32, s32);
s32 func_80073BF0(u8 *);

/* Measures message `msg` at glyph size `size`: the widest of up to three lines
 * goes to *width and the extra height of the line breaks to *height. Code
 * 0x8019 is a line break, 0x800F a name, 0x8014-0x8017 a player's number. */
void func_8007399C(s32 msg, s32 size, s32 *width, s32 *height, s32 player) {
    s32 w[3] = { 0, 0, 0 };
    s32 n;
    Unk800E1C48 *e;
    s32 h, i, max;
    s32 count, start, code;

    n = 0;
    h = 0;
    count = D_800E1C48[msg + 1].unk2;
    start = D_800E1C48[msg + 1].unk0;
    for (i = 0; i != count; i++) {
        code = ((u16 *)D_800E1C48)[D_80104FD0 + start + i];
        if (code < 0x100) {
            if (code != 0xDE && code != 0xDF) {
                if (size == 12) {
                    w[n] += D_800C4390[code];
                } else {
                    w[n] += size;
                }
            }
        } else if (code > 0x7FFF) {
            switch (code) {
                case 0x8019:
                    n++;
                    h = h + (6 + size);
                    break;
                case 0x800F:
                    sprintf(D_80105118, D_800D1588, D_801321B0);
                    w[n] += func_800738BC((s32)D_80105118, size, 2);
                    break;
                case 0x8014:
                case 0x8015:
                case 0x8016:
                case 0x8017:
                    sprintf(D_80105118, D_800D158C, D_8012F510[player].unk1C[code - 0x8014]);
                    w[n] += func_80073BF0((u8 *)D_80105118) * size;
                    break;
                case 0x8000:
                case 0x8001:
                case 0x8002:
                case 0x8003:
                case 0x8004:
                case 0x8005:
                case 0x8006:
                case 0x8007:
                case 0x8008:
                case 0x8009:
                case 0x800A:
                case 0x800C:
                case 0x800D:
                case 0x800E:
                    w[n] += 12;
                    break;
                case 0x800B:
                case 0x8010:
                case 0x8011:
                case 0x8012:
                case 0x8013:
                case 0x8018:
                    break;
            }
        }
    }
    max = w[0];
    if (max < w[1]) {
        max = w[1];
    }
    *width = max;
    if (max < w[2]) {
        max = w[2];
    }
    *width = max;
    *height = h;
}

s32 func_80073BF0(u8 *str) {
    s32 len = 0;

    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_80073C14);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80073F24);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80074230);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80074500);

u32 func_800738BC(s32, s32, s32);
s32 func_80073F24(s32 *, s16, s16, s32);

void func_800747B0(s32 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 sp10;
    u32 temp_v0;

    sp10 = *arg0;
    temp_v0 = func_800738BC(arg3, 0xC, 2);
    func_80073F24(&sp10, (s16) (arg1 - ((s32) ((temp_v0 >> 0x1F) + temp_v0) >> 1)), arg2, arg3);
    *arg0 = sp10;
}

s32 func_80074230(s32 *, s16, s16, s32);

void func_80074840(s32 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 sp10;
    u32 temp_v0;

    sp10 = *arg0;
    temp_v0 = func_800738BC(arg3, 0xA, 2);
    func_80074230(&sp10, (s16) (arg1 - ((s32) ((temp_v0 >> 0x1F) + temp_v0) >> 1)), arg2, arg3);
    *arg0 = sp10;
}

s32 func_80074500(s32 *, s16, s16, s32);

void func_800748D0(s32 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 sp10;
    u32 temp_v0;

    sp10 = *arg0;
    temp_v0 = func_800738BC(arg3, 8, 2);
    func_80074500(&sp10, (s16) (arg1 - ((s32) ((temp_v0 >> 0x1F) + temp_v0) >> 1)), arg2, arg3);
    *arg0 = sp10;
}

void func_80074960(void) {
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_80074968);

void func_80074CA8(Gfx **gdl, s32 r, s32 g, s32 b) {
    Gfx *gfx = *gdl;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, r, g, b, 255);
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

/* As func_80075010, but '.' is drawn narrow (3 px pulled in, 5 px advance). */
void func_80074D0C(Gfx **gdl, s16 x, s16 y, u8 *str) {
    Gfx *gfx = *gdl;
    u8 c;
    s32 i;
    s32 s;

    gDPPipeSync(gfx++);
    for (c = *str; c != 0; c = *++str) {
        if (c == '.') {
            x -= 3;
        }
        i = c - 0x20;
        s = (i % 31) << 8;
        gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE, s,
                            ((i / 31) << 8) & 0xFF00, 1 << 10, 1 << 10);
        if (*str == '.') {
            x += 5;
        } else {
            x += 8;
        }
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_80074E5C);

/* Draws str centred on x using the 6-pixel font tiles (character c is at s = c - 0x27). */
void func_80074EFC(Gfx **gdl, s16 x, s16 y, u8 *str) {
    Gfx *gfx = *gdl;
    s32 n;
    s32 c;

    gDPPipeSync(gfx++);
    for (n = 0; str[n] != 0; n++) {
    }
    x -= n * 3;
    for (c = *str; c != 0; c = *++str, x += 6) {
        gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 7) << 2, (y + 8) << 2, G_TX_RENDERTILE, (c - 0x27) << 8,
                            3 << 8, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

/* Draws str at (x, y) with the 8x8 font (31 glyphs per row, starting at ' '). */
void func_80075010(Gfx **gdl, s16 x, s16 y, u8 *str) {
    Gfx *gfx = *gdl;
    s32 c;
    s32 i;
    s32 s;

    gDPPipeSync(gfx++);
    for (c = *str; c != 0; c = *++str, x += 7) {
        i = c - 0x20;
        s = (i % 31) << 8;
        gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE, s,
                            ((i / 31) << 8) & 0xFF00, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

void func_8007512C(void) {
    s32 i;

    for (i = 0; i != 300; i++) {
        D_800FF570[i].unk3 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_8007515C);

extern MsgGlyph D_800FF530[];
extern u8 D_800FBE18[];

/* Lays out message `msg` for owner `id`, centred on (x0, y0), claiming free
 * glyph slots. size == -1 frees the owner's slots instead.
 * Returns (width / 2) << 16 | (height / 2). */
s32 func_800754BC(s32 id, s32 size, s32 x0, s32 y0, s32 msg) {
    s32 w, h;
    s32 i, n, x;
    s32 start, count, code;

    if (size == -1) {
        for (i = 0; i != 300; i++) {
            if (D_800FF530[i].owner == id) {
                D_800FF530[i].owner = -1;
            }
        }
        return;
    }
    start = D_800E1C48[msg + 1].unk0;
    count = D_800E1C48[msg + 1].unk2;
    func_8007399C(msg, size, &w, &h, 0);
    w /= 2;
    h /= 2;
    y0 += h;
    D_800FBE18[id] = count;
    for (i = 0; i != 300; i++) {
        if (D_800FF530[i].owner == id) {
            D_800FF530[i].owner = -1;
        }
    }
    n = 0;
    x = 0;
    for (i = 0; n != count; i++) {
        if (D_800FF530[i].owner == -1) {
            code = ((u16 *)D_800E1C48)[D_80104FD0 + start + n];
            if (code < 0x100) {
                if (code == 0xDE || code == 0xDF) {
                    guTranslate(&D_800FF530[i].mtx, (f32)(x - w + x0) - 6.0f, (f32)y0 + 4.0f, 0.0f);
                } else {
                    guTranslate(&D_800FF530[i].mtx, (f32)(x - w + x0), (f32)y0, 0.0f);
                    x += D_800C4390[code];
                }
                D_800FF530[i].code = code;
                D_800FF530[i].size = size;
                D_800FF530[i].owner = id;
            } else if (code > 0x7FFF) {
                switch (code) {
                    case 0x8019:
                        x = 0;
                        y0 += -6 - size;
                        break;
                    case 0x8000:
                    case 0x8001:
                    case 0x8002:
                    case 0x8003:
                    case 0x8004:
                    case 0x8005:
                    case 0x8006:
                    case 0x8007:
                    case 0x8008:
                    case 0x8009:
                    case 0x800A:
                    case 0x800C:
                    case 0x800D:
                    case 0x800E:
                        guTranslate(&D_800FF530[i].mtx, (f32)(x - w + x0), (f32)y0, 0.0f);
                        x += size;
                        D_800FF530[i].code = code;
                        D_800FF530[i].size = size;
                        D_800FF530[i].owner = id;
                        break;
                }
            }
            n++;
        }
    }
    return (w << 16) | h;
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_8007580C);

INCLUDE_ASM("asm/nonmatchings/4C770", func_80075E48);

/* Glyph offset for a font character: digits map to (c - '/') * 16, and a
 * few punctuation marks have their own cells. */
s32 func_800760CC(s32 c) {
    switch ((u8)c) {
        case ':':
            return 0xB0;
        case '*':
            return 0;
        case '+':
            return 0xC0;
        case '-':
            return 0xD0;
        case '#':
            return 0xE0;
        case '!':
            return 0xF0;
        default:
            return ((u8)c - '/') << 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/4C770", func_80076138);

INCLUDE_ASM("asm/nonmatchings/4C770", func_8007624C);
