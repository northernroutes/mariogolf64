#include "common.h"

/* Placeholder types; real types unknown. Rename once identified. */

/* D_8012F720, returned by func_8005AF50. */
typedef struct Unk8012F720 {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ s8 unk28;
    /* 0x29 */ s8 unk29;
    /* 0x2A */ s8 unk2A;
    /* 0x2B */ s8 unk2B;
    /* 0x2C */ u8 pad2C[0xA58];
    /* 0xA84 */ s8 unkA84[6][18];
    /* 0xAF0 */ u8 padAF0[0x830];
    /* 0x1320 */ s8 unk1320[6][6];
} Unk8012F720;

/* D_801323A0, returned by func_8005AF74. */
typedef struct Unk801323A0 {
    /* 0x00 */ u8 pad0[0x2E];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
} Unk801323A0;

extern Unk8012F720 D_8012F720;
extern Unk801323A0 D_801323A0;
extern s32 D_800C2B28[6];
extern u32 D_8012F724;
extern u8 D_8012D400[3];
extern s8 D_80105DC1;
extern s8 D_80105DC2;
extern s32 D_80105DC4;
extern s32 D_80105DC8;
extern s32 D_80105DCC;
extern s32 D_801B6094;
extern s32 D_801B6098;
extern s32 D_800FE334;
extern u8 D_801052E8;
extern u8 D_801B9410;
extern u8 D_800C2BD4;
extern s32 D_801EFFA0;

void func_80099490(void);
void func_8005DF54(Unk8012F720 *arg0, u8 arg1);
Unk8012F720 *func_8005AF50(void);
Unk801323A0 *func_8005AF74(void);
s32 func_8005D23C(void);

/* fdlibm word access (math_private.h). */
typedef union {
    f32 value;
    s32 word;
} ieee_float_shape_type;

#define GET_FLOAT_WORD(i, d)           \
    do {                               \
        ieee_float_shape_type gf_u;    \
        gf_u.value = (d);              \
        (i) = gf_u.word;               \
    } while (0)

#define SET_FLOAT_WORD(d, i)           \
    do {                               \
        ieee_float_shape_type sf_u;    \
        sf_u.word = (i);               \
        (d) = sf_u.value;              \
    } while (0)

/* fdlibm fabsf (s_fabsf.c). */
f32 func_80059BA0(f32 x) {
    s32 ix;

    GET_FLOAT_WORD(ix, x);
    SET_FLOAT_WORD(x, ix & 0x7FFFFFFF);
    return x;
}

/* func_80059BC0 is fdlibm's __ieee754_acosf (e_acosf.c); the constants are
 * immediates in the original, hence the macros. */
#define AC_PI 3.1415925026e+00f
#define AC_PIO2_HI 1.5707962513e+00f
#define AC_PIO2_LO 7.5497894159e-08f
#define AC_PS0 1.6666667163e-01f
#define AC_PS1 -3.2556581497e-01f
#define AC_PS2 2.0121252537e-01f
#define AC_PS3 -4.0055535734e-02f
#define AC_PS4 7.9153501429e-04f
#define AC_PS5 3.4793309169e-05f
#define AC_QS1 -2.4033949375e+00f
#define AC_QS2 2.0209457874e+00f
#define AC_QS3 -6.8828397989e-01f
#define AC_QS4 7.7038154006e-02f

f32 func_80059BC0(f32 x) {
    f32 z, p, q, r, w, s, c, df;
    s32 hx, ix, idf;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7FFFFFFF;
    if (ix == 0x3F800000) {
        if (hx > 0) {
            return 0.0f;
        } else {
            return AC_PI + 2.0f * AC_PIO2_LO;
        }
    } else if (ix > 0x3F800000) {
        return (x - x) / (x - x);
    }
    if (ix < 0x3F000000) {
        if (ix <= 0x23000000) {
            return AC_PIO2_HI + AC_PIO2_LO;
        }
        z = x * x;
        p = z * (AC_PS0 + z * (AC_PS1 + z * (AC_PS2 + z * (AC_PS3 + z * (AC_PS4 + z * AC_PS5)))));
        q = 1.0f + z * (AC_QS1 + z * (AC_QS2 + z * (AC_QS3 + z * AC_QS4)));
        r = p / q;
        return AC_PIO2_HI - (x - (AC_PIO2_LO - x * r));
    } else if (hx < 0) {
        z = (1.0f + x) * 0.5f;
        p = z * (AC_PS0 + z * (AC_PS1 + z * (AC_PS2 + z * (AC_PS3 + z * (AC_PS4 + z * AC_PS5)))));
        q = 1.0f + z * (AC_QS1 + z * (AC_QS2 + z * (AC_QS3 + z * AC_QS4)));
        s = sqrtf(z);
        r = p / q;
        w = r * s - AC_PIO2_LO;
        return AC_PI - 2.0f * (s + w);
    } else {
        z = (1.0f - x) * 0.5f;
        s = sqrtf(z);
        df = s;
        GET_FLOAT_WORD(idf, df);
        SET_FLOAT_WORD(df, idf & 0xFFFFF000);
        c = (z - df * df) / (s + df);
        p = z * (AC_PS0 + z * (AC_PS1 + z * (AC_PS2 + z * (AC_PS3 + z * (AC_PS4 + z * AC_PS5)))));
        q = 1.0f + z * (AC_QS1 + z * (AC_QS2 + z * (AC_QS3 + z * AC_QS4)));
        r = p / q;
        w = r * s + c;
        return 2.0f * (df + w);
    }
}

#define AT2_TINY 1.0e-30f
#define AT2_PI_O_4 7.8539818525e-01f
#define AT2_PI_O_2 1.5707963705e+00f
#define AT2_PI 3.1415925026e+00f
#define AT2_PI_LO 1.5099578832e-07f
f32 func_80059BA0(f32 x);
f32 func_8005A2AC(f32 x);

/* fdlibm __ieee754_atan2f(y, x) (e_atan2f.c), the older version with
 * pi = 0x40490fda and pi_lo = 0x34222168. */
extern f32 D_800D089C;

f32 func_80059FAC(f32 y, f32 x) {
    f32 z;
    s32 k, m, hx, hy, ix, iy;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7FFFFFFF;
    GET_FLOAT_WORD(hy, y);
    iy = hy & 0x7FFFFFFF;
    if ((ix > 0x7F800000) || (iy > 0x7F800000)) {
        return x + y;
    }
    if (hx == 0x3F800000) {
        return func_8005A2AC(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if (iy == 0) {
        switch (m) {
            case 0:
            case 1:
                return y;
            case 2:
                return AT2_PI + AT2_TINY;
            case 3:
                return -AT2_PI - AT2_TINY;
        }
    }
    if (ix == 0) {
        return (hy < 0) ? -AT2_PI_O_2 - AT2_TINY : AT2_PI_O_2 + AT2_TINY;
    }
    if (ix == 0x7F800000) {
        if (iy == 0x7F800000) {
            switch (m) {
                case 0:
                    return AT2_PI_O_4 + AT2_TINY;
                case 1:
                    return -AT2_PI_O_4 - AT2_TINY;
                case 2:
                    return 3.0f * AT2_PI_O_4 + AT2_TINY;
                case 3:
                    return -3.0f * AT2_PI_O_4 - AT2_TINY;
            }
        } else {
            switch (m) {
                case 0:
                    return 0.0f;
                case 1:
                    return D_800D089C; /* -zero, kept in .rodata */
                case 2:
                    return AT2_PI + AT2_TINY;
                case 3:
                    return -AT2_PI - AT2_TINY;
            }
        }
    }
    if (iy == 0x7F800000) {
        return (hy < 0) ? -AT2_PI_O_2 - AT2_TINY : AT2_PI_O_2 + AT2_TINY;
    }

    k = (iy - ix) >> 23;
    if (k > 60) {
        z = AT2_PI_O_2 + 0.5f * AT2_PI_LO;
    } else if (hx < 0 && k < -60) {
        z = 0.0f;
    } else {
        z = func_8005A2AC(func_80059BA0(y / x));
    }
    switch (m) {
        case 0:
            return z;
        case 1: {
            s32 zh;
            GET_FLOAT_WORD(zh, z);
            SET_FLOAT_WORD(z, zh ^ 0x80000000);
        }
            return z;
        case 2:
            return AT2_PI - (z - AT2_PI_LO);
        default:
            return (z - AT2_PI_LO) - AT2_PI;
    }
}

extern f32 D_800D08A0[4];  /* atanhi */
extern f32 D_800D08B0[4];  /* atanlo */
extern f32 D_800D08C0[11]; /* aT */
f32 func_80059BA0(f32 x);

/* fdlibm atanf (s_atanf.c); the coefficient tables are in .rodata. */
f32 func_8005A2AC(f32 x) {
    f32 w, s1, s2, z;
    s32 ix, hx, id;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7FFFFFFF;
    if (ix >= 0x50800000) {
        if (ix > 0x7F800000) {
            return x + x;
        }
        if (hx > 0) {
            return D_800D08A0[3] + D_800D08B0[3];
        } else {
            return -D_800D08A0[3] - D_800D08B0[3];
        }
    }
    if (ix < 0x3EE00000) {
        if (ix < 0x31000000) {
            if (1.0e30f + x > 1.0f) {
                return x;
            }
        }
        id = -1;
    } else {
        x = func_80059BA0(x);
        if (ix < 0x3F980000) {
            if (ix < 0x3F300000) {
                id = 0;
                x = (2.0f * x - 1.0f) / (2.0f + x);
            } else {
                id = 1;
                x = (x - 1.0f) / (x + 1.0f);
            }
        } else {
            if (ix < 0x401C0000) {
                id = 2;
                x = (x - 1.5f) / (1.0f + 1.5f * x);
            } else {
                id = 3;
                x = -1.0f / x;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (D_800D08C0[0] + w * (D_800D08C0[2] + w * (D_800D08C0[4] + w * (D_800D08C0[6] + w * (D_800D08C0[8] + w * D_800D08C0[10])))));
    s2 = w * (D_800D08C0[1] + w * (D_800D08C0[3] + w * (D_800D08C0[5] + w * (D_800D08C0[7] + w * D_800D08C0[9]))));
    if (id < 0) {
        return x - x * (s1 + s2);
    } else {
        z = D_800D08A0[id] - ((x * (s1 + s2) - D_800D08B0[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005A580);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005ACF8);

Unk8012F720 *func_8005AF50(void) {
    func_8005AF74();
    return &D_8012F720;
}

Unk801323A0 *func_8005AF74(void) {
    return &D_801323A0;
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005AF80);

void func_8005B03C(void) {
    Unk8012F720 *p = func_8005AF50();

    func_80099490();
    func_8005DF54(p, 0);
}

s32 func_8005B070(s32 arg0) {
    s32 i;

    for (i = 5; i != 0; i--) {
        if (arg0 >= D_800C2B28[i]) {
            break;
        }
    }
    return i + 1;
}

s32 func_8005B0A0(s32 arg0) {
    return D_800C2B28[arg0];
}

/* 0x68-byte record (the same layout is loaded into D_80105F40 in 396C0). Placeholder. */
typedef struct Unk80131510 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x28];
    /* 0x2C */ s8 unk2C;
    /* 0x2D */ u8 pad2D[0xD];
    /* 0x3A */ u8 unk3A;
    /* 0x3B */ u8 pad3B[0x2D];
} Unk80131510; /* size = 0x68 */

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005B0B4);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005B150);


extern Unk80131510 D_80131510[];

void func_8005B28C(s32 i, Unk80131510 *src) {
    D_80131510[i] = *src;
    func_8005DF54(func_8005AF50(), 1);
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005B314);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005B7BC);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005BC10);

void func_8005C018(u32 arg0) {
    u32 *p = &D_8012F724;

    if (*p < arg0) {
        *p = arg0;
    }
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005C038);

s32 func_8005C458(void) {
    Unk8012F720 *p = func_8005AF50();
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            count += p->unk1320[i][j] != 0;
        }
    }
    return count == 36;
}

s32 func_8005C4B4(void) {
    Unk8012F720 *p = func_8005AF50();
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            count += p->unk1320[i][j] != 0;
        }
    }
    return count >= 30;
}

s32 func_8005C510(void) {
    Unk8012F720 *p = func_8005AF50();
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            count += p->unk1320[i][j] != 0;
        }
    }
    if (count == 4) {
        return 1;
    }
    if (count == 8) {
        return 2;
    }
    if (count == 12) {
        return 3;
    }
    if (count == 16) {
        return 4;
    }
    return (count == 20) ? 5 : 0;
}

s32 func_8005C5B4(void) {
    Unk8012F720 *p = func_8005AF50();
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 18; j++) {
            count += p->unkA84[i][j] != 0;
        }
    }
    return count >= 50;
}

s32 func_8005C614(void) {
    Unk8012F720 *p = func_8005AF50();
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 18; j++) {
            count += p->unkA84[i][j] != 0;
        }
    }
    return count == 108;
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005C674);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005CA48);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005CEE0);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005CF78);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005D0D8);

void func_8005D1E4(void) {
    Unk801323A0 *p = func_8005AF74();

    p->unk2E = D_801B6098;
    p->unk2F = D_801B6094;
}

s32 func_8005D218(void) {
    /* case 0 shares the default; the redundant test is in the original. */
    switch (D_80105DC1) {
        case 0:
        default:
            return 0;
        case 1:
            return 7;
    }
}

s32 func_8005D23C(void) {
    return D_80105DC2;
}

s32 func_8005D248(void) {
    return D_80105DC4 != 0;
}

s32 func_8005D258(void) {
    s32 v = D_80105DC8;

    if (v < 0) {
        v = 0;
    }
    return v + 0x16F;
}

s32 func_8005D274(void) {
    s32 v = func_8005D23C();

    if (v < 0) {
        v = 0;
    }
    return v + 0x1EB;
}

s32 func_8005D2A0(void) {
    s32 v = D_80105DCC;

    if (v <= 0) {
        v = 1;
    }
    return v;
}

void func_8005D2B8(u8 *dst) {
    s32 i;

    for (i = 0; i != 3; i++) {
        *dst++ = D_8012D400[i];
    }
}

s32 func_8005D2E4(void) {
    /* case 0 shares the default; the redundant test is in the original. */
    switch (D_80105DC1) {
        case 0:
        default:
            return 0x9E;
        case 1:
            return 0x9D;
    }
}

s32 func_8005D308(void) {
    s32 v = D_80105DC2;
    s32 ret;

    if (v >= 6) {
        if (v >= 9) {
            ret = 0xC8;
        } else {
            ret = 0xC7;
        }
    } else {
        ret = v + 0x1EB;
    }
    return ret;
}

typedef struct Unk800FE3D8 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u8 unk8[12];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
} Unk800FE3D8; /* size = 0x16 */

extern Unk800FE3D8 D_800FE3D8[4];

void func_8005D334(void) {
    s32 i;
    s32 j;

    for (i = 0; i != 4; i++) {
        D_800FE3D8[i].unk0 = 0;
        D_800FE3D8[i].unk2 = 0;
        D_800FE3D8[i].unk4 = 0;
        D_800FE3D8[i].unk6 = 0;
        for (j = 0; j != 12; j++) {
            D_800FE3D8[i].unk8[j] = 0;
        }
        D_800FE3D8[i].unk14 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005D3B8);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005D9A0);

void func_8005DAD4(void) {
    D_800FE334 = 0;
    D_801052E8 = 1;
    D_801B9410 = 0;
    D_800C2BD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005DAFC);

s32 func_8005D9A0();
extern s8 D_800C1FF4;
extern s8 D_800C1FF5;
extern s8 D_800C1FF6;
extern s8 D_800C1FF7;
extern s8 D_800FE3EC;
extern s8 D_800FE402;
extern s8 D_800FE418;
extern s8 D_800FE42E;

void func_8005DC50(void) {
    func_8005D9A0();
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_800FE3EC = 0;
    D_800FE402 = 0;
    D_800FE418 = 0;
    D_800FE42E = 0;
    D_800C1FF4 = -1;
    D_800C1FF5 = -1;
    D_800C1FF6 = -1;
    D_800C1FF7 = -1;
    D_801EFFA0 = 0;
}

void func_8005DCDC(void) {
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_801EFFA0 = 0x17;
}

void func_8005DD10(void) {
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_801EFFA0 = 5;
}

void func_8005DD44(void) {
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_801EFFA0 = 0x12;
}

void func_8005DD78(void) {
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_801EFFA0 = 0xD;
}

s32 func_80029A6C(s32);
extern s8 D_801B60B9;

void func_8005DDAC(void) {
    D_800FE334 = 0;
    D_801052E8 = 1;
    D_800C2BD4 = 0;
    D_801B9410 = 1;
    D_801B60B9 = 0;
    func_80029A6C(0x1E);
    D_801EFFA0 = 0xC;
}

s32 func_8005DE00(void) {
    return func_8005AF50()->unk28;
}

s32 func_8005DE20(void) {
    return func_8005AF50()->unk29;
}

s32 func_8005DE40(void) {
    return func_8005AF50()->unk2B;
}

void func_8005DE60(void) {
    func_8005DF54(func_8005AF50(), 1);
}

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005DE88);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005DF54);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005DFE8);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005E180);
