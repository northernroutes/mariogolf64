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
    /* 0xAF0 */ u8 padAF0[0x2D0];
    /* 0xDC0 */ s32 unkDC0[6][3];
    /* 0xE08 */ u8 padE08[0x518];
    /* 0x1320 */ s8 unk1320[6][6];
} Unk8012F720;

/* D_801323A0, returned by func_8005AF74. */
typedef struct Unk801323A0 {
    /* 0x00 */ u8 pad0[0x2E];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
} Unk801323A0;

/* Game state saved into a record: copied from D_801B55F0 on save and restored
 * into D_801B6088 on load. */
typedef struct SaveRecordInfo {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 mode;
    /* 0x08 */ s32 numPlayers;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 pad14[0x26];
    /* 0x3A */ s8 unk3A;
    /* 0x3B */ u8 pad3B[2];
    /* 0x3D */ s8 saveCount;
    /* 0x3E */ u8 pad3E[6];
} SaveRecordInfo; /* size = 0x44 */

typedef struct SaveBlob34 {
    s32 w[13];
} SaveBlob34; /* D_800BA9D8's state */

typedef struct SaveBlob1C {
    s32 w[7];
} SaveBlob1C; /* D_800FF4D0's state */

typedef struct SaveRecord {
    /* 0x00 */ s32 used;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ SaveBlob34 course;
    /* 0x3C */ SaveRecordInfo info;
    /* 0x80 */ SaveBlob1C extra;
    /* 0x9C */ u8 pad9C[4];
} SaveRecord; /* size = 0xA0 */

typedef struct SavePlayer {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u8 pad10[0xD];
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[0x5D];
    /* 0x7B */ u8 unk7B;
    /* 0x7C */ u8 pad7C[0x3C];
} SavePlayer; /* size = 0xB8 */

typedef struct SaveData {
    /* 0x0000 */ u8 pad0[0x1FF8];
    /* 0x1FF8 */ SaveRecord rec[3];
    /* 0x21D8 */ SavePlayer players[3][4];
} SaveData;

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
static const f32 AC_ONE = 1.0f;
static const f32 AC_PI = 3.1415925026e+00f;
static const f32 AC_PIO2_HI = 1.5707962513e+00f;
static const f32 AC_PIO2_LO = 7.5497894159e-08f;
static const f32 AC_PS0 = 1.6666667163e-01f;
static const f32 AC_PS1 = -3.2556581497e-01f;
static const f32 AC_PS2 = 2.0121252537e-01f;
static const f32 AC_PS3 = -4.0055535734e-02f;
static const f32 AC_PS4 = 7.9153501429e-04f;
static const f32 AC_PS5 = 3.4793309169e-05f;
static const f32 AC_QS1 = -2.4033949375e+00f;
static const f32 AC_QS2 = 2.0209457874e+00f;
static const f32 AC_QS3 = -6.8828397989e-01f;
static const f32 AC_QS4 = 7.7038154006e-02f;

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

static const f32 AT2_TINY = 1.0e-30f;
static const f32 AT2_ZERO = 0.0f;
static const f32 AT2_PI_O_4 = 7.8539818525e-01f;
static const f32 AT2_PI_O_2 = 1.5707963705e+00f;
static const f32 AT2_PI_LO = 1.5099578832e-07f;
#define AT2_PI 3.1415925026e+00f /* not a static in this version */
/* fdlibm returns -zero here; the compiler as built for this project folds that to
 * +0.0, so the original's -0.0 constant is spelled out. */
static const union {
    u32 i;
    f32 f;
} AT2_NEG_ZERO = { 0x80000000 };
f32 func_80059BA0(f32 x);
f32 func_8005A2AC(f32 x);

/* fdlibm __ieee754_atan2f(y, x) (e_atan2f.c), the older version with
 * pi = 0x40490fda and pi_lo = 0x34222168. */

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
                    return AT2_NEG_ZERO.f;
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

static const f32 atanhi[] = {
    4.6364760399e-01f, 7.8539812565e-01f, 9.8279368877e-01f, 1.5707962513e+00f,
};
static const f32 atanlo[] = {
    5.0121582440e-09f, 3.7748947079e-08f, 3.4473217170e-08f, 7.5497894159e-08f,
};
static const f32 aT[] = {
    3.3333334327e-01f, -2.0000000298e-01f, 1.4285714924e-01f, -1.1111110449e-01f,
    9.0908870101e-02f, -7.6918758452e-02f, 6.6610731184e-02f, -5.8335702866e-02f,
    4.9768779427e-02f, -3.6531571299e-02f, 1.6285819933e-02f,
};
static const f32 huge = 1.0e30f;
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
            return atanhi[3] + atanlo[3];
        } else {
            return -atanhi[3] - atanlo[3];
        }
    }
    if (ix < 0x3EE00000) {
        if (ix < 0x31000000) {
            if (huge + x > 1.0f) {
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
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0) {
        return x - x * (s1 + s2);
    } else {
        z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
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

/* Resets the save data to defaults (magic word set, all unkDC0 slots -1) and
 * writes it out. */
void func_8005AF80(void) {
    Unk8012F720 *p = func_8005AF50();
    s8 i;
    s8 j;

    memset(p, 0, 0x2A78);
    *(s32 *)p = 0x12345678;
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 3; j++) {
            p->unkDC0[i][j] = -1;
        }
    }
    func_8005DF54(p, 1);
}

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

extern s32 D_801B6090;
extern SavePlayer D_8012D0C8[];
extern SavePlayer D_801B71D0[];
extern SaveRecordInfo D_801B55F0;
extern SaveRecordInfo D_801B6088;
extern SaveBlob34 D_800BA9D8;
extern SaveBlob1C D_800FF4D0;
extern s8 D_801B60B8;
extern s32 D_801B608C;
extern SavePlayer D_8012FB60[];
extern SavePlayer D_8012FAA8[];
extern SavePlayer D_8012F938[];
void func_80029A30(s32);

typedef struct SaveBlob68 {
    s32 w[26];
} SaveBlob68; /* per-player block of D_800FEDD8 */
extern SaveBlob68 D_800FEDD8[];

/* Saves (or with `load`, restores) the in-progress round for the current game
 * mode: the player states, their D_800FEDD8 blocks and the course state. */
s32 func_8005B7BC(s32 load) {
    SavePlayer *pl;
    SaveBlob68 *ex;
    SaveRecord *r;
    s32 count = 0;
    s32 i;
    s32 bad;

    switch (D_801B608C) {
        case 0:
        case 6:
        case 10:
            pl = D_8012FB60;
            ex = (SaveBlob68 *)((u8 *)pl + 0x3B0);
            r = (SaveRecord *)((u8 *)pl - 0x2C8);
            count = 4;
            break;
        case 5:
            pl = D_8012FAA8;
            ex = (SaveBlob68 *)((u8 *)pl + 0x400);
            r = (SaveRecord *)((u8 *)pl - 0x2B0);
            osSyncPrintf("Record/Play -Tour-/\n");
            count = 1;
            break;
        case 4:
            pl = D_8012F938;
            ex = (SaveBlob68 *)((u8 *)pl + 0x508);
            r = (SaveRecord *)((u8 *)pl - 0x1E0);
            count = 2;
            break;
    }
    if (!load) {
        bad = 0;
        if (count < D_801B6090) {
            osSyncPrintf("Too Many Players\n");
            return -1;
        }
        count = D_801B6090;
        r->used = 0;
        for (i = 0; i < count; i++) {
            pl[i] = D_801B71D0[i];
            switch (pl[i].unkC) {
                case 0:
                case 2:
                case 3:
                case 21:
                    pl[i].unkC = 0;
                    break;
                case 17:
                case 20:
                    break;
                default:
                    osSyncPrintf("Illegal PlayerState\n");
                    bad = 1;
                    break;
            }
            ex[i] = D_800FEDD8[i];
        }
        r->info = D_801B6088;
        r->course = D_800BA9D8;
        if (bad) {
            goto fail;
        }
        r->used = 1;
    } else {
        if (r->used == 1) {
            if (count < r->info.numPlayers) {
                osSyncPrintf("Too Many Players\n");
            fail:
                return -1;
            }
            count = r->info.numPlayers;
            for (i = 0; i < count; i++) {
                D_801B71D0[i] = pl[i];
                D_800FEDD8[i] = ex[i];
            }
            D_801B6088 = r->info;
            D_801B6088.unk0 = 1;
            func_80029A30(30);
            D_800BA9D8 = r->course;
        }
        D_801B60B8 = 2;
        osSyncPrintf("Go Continue\n");
    }
    return 0;
}


/* Saves the current game into record `slot` (players, course state, globals),
 * or loads it back when `load` is set. Returns -1 on bad data. */
s32 func_8005BC10(s32 slot, s32 load) {
    SavePlayer *pl = ((SaveData *)&D_8012F720)->players[slot];
    SaveRecord *r = &((SaveData *)&D_8012F720)->rec[slot];
    s32 count = 4;
    s32 i;
    s32 bad;

    if (!load) {
        bad = 0;
        if (count < D_801B6090) {
            goto err;
        }
        count = D_801B6090;
        r->used = 0;
        for (i = 0; i < count; i++) {
            pl[i] = D_8012D0C8[i];
            switch (pl[i].unkC) {
                case 0:
                case 2:
                case 3:
                case 21:
                    pl[i].unkC = 0;
                    break;
                case 17:
                case 20:
                    break;
                default:
                    osSyncPrintf("Illegal PlayerState\n");
                    bad = 1;
                    break;
            }
        }
        r->info = D_801B55F0;
        if (r->info.saveCount < 99) {
            r->info.saveCount++;
        }
        r->course = D_800BA9D8;
        r->extra = D_800FF4D0;
        if (bad) {
            return -1;
        }
        r->used = 1;
    } else {
        if (r->used == 1) {
            if (count < r->info.numPlayers) {
            err:
                osSyncPrintf("Too Many Players\n");
                return -1;
            }
            count = r->info.numPlayers;
            for (i = 0; i < count; i++) {
                D_801B71D0[i] = pl[i];
            }
            D_801B6088 = r->info;
            D_801B6088.unk0 = 1;
            func_80029A30(30);
            D_800BA9D8 = r->course;
            D_800FF4D0 = r->extra;
        }
        D_801B60B8 = 2;
        osSyncPrintf("Go Continue\n");
    }
    if (!load) {
        func_8005DF54(func_8005AF50(), 1);
    }
    return 0;
}

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


/* Clears any saved record whose mode, counts or player bytes are out of range. */
void func_8005CF78(void) {
    s32 bad[3];
    SaveData *sd = (SaveData *)func_8005AF50();
    s32 i, j;
    SaveRecord *r;
    SaveRecordInfo *info;
    SavePlayer *pl;

    for (i = 0; i != 3; i++) {
        bad[i] = 0;
    }
    for (i = 0; i != 3; i++) {
        if (sd->rec[i].used != 0) {
            r = &sd->rec[i];
            info = &r->info;
            if (r->info.unk3A == 0) {
                switch (info->mode) {
                    case 1:
                    case 3:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    default:
                        bad[i] = 1;
                        break;
                    case 0:
                    case 2:
                    case 4:
                    case 5:
                    case 10:
                    case 11:
                        break;
                }
            }
            if ((u32)(info->numPlayers - 1) >= 4) {
                bad[i] = 1;
            }
            if (info->unkC >= 12) {
                bad[i] = 1;
            }
            if (info->unk10 >= 18) {
                bad[i] = 1;
            }
            for (j = 0; j != info->numPlayers; j++) {
                pl = &sd->players[i][j];
                if (pl->unk1D >= 18) {
                    bad[i] = 1;
                }
                if (pl->unk7B >= 4) {
                    bad[i] = 1;
                }
            }
        }
    }
    for (i = 0; i != 3; i++) {
        if (bad[i] == 1) {
            sd->rec[i].used = 0;
        }
    }
}

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

extern s32 D_801B608C;
extern s8 D_800FF4C0;
extern s8 D_80105268;
extern s8 D_801B5634;
extern s32 D_80105B68;
extern s8 D_800C2BD5;

/* Sets per-game-mode flags (D_800FF4C0, D_80105268, D_801B5634) from
 * D_801B608C and resets some shared state. */
void func_8005DAFC(void) {
    switch (D_801B608C) {
        case 5:
            D_800FF4C0 = 2;
            D_80105268 = 0;
            D_801B5634 = 0;
            break;
        case 0:
            D_800FF4C0 = 1;
            D_80105268 = 1;
            if (D_80105B68 == 4) {
                D_801B5634 = 2;
            } else {
                D_801B5634 = 1;
            }
            D_800C2BD5 = 1;
            break;
        case 2:
            D_800FF4C0 = 1;
            D_80105268 = 1;
            D_801B5634 = 3;
            break;
        case 10:
            D_800FF4C0 = 1;
            D_80105268 = 1;
            D_801B5634 = 4;
            break;
        case 3:
        case 4:
        case 6:
        case 7:
        case 9:
            D_800FF4C0 = 1;
            D_80105268 = 2;
            D_801B5634 = 0;
            break;
        case 11:
            D_800FF4C0 = 1;
            D_80105268 = 1;
            D_801B5634 = 5;
            break;
    }
    D_801052E8 = 1;
    D_801B9410 = 1;
    D_800FE334 = 0;
    D_800C2BD4 = 0;
    D_801EFFA0 = 6;
}

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

extern u8 D_801323E5;
extern u8 D_800C1FFC;

/* After a load (`toSave` == 0) packs the saved option flags p->unk28/29/2B into
 * the live D_801323E5 bitmask (cleared if the load failed, `loaded` <= 0);
 * before a save copies the live bits back into the save data. */
void func_8005DE88(Unk8012F720 *p, s32 toSave, s32 loaded) {
    s8 *f = &p->unk28;

    u8 *m;

    if (toSave == 0) {
        m = &D_801323E5;
        *m = 0;
        if (loaded > 0) {
            if (p->unk28) {
                *m = 1;
            }
            if (p->unk29) {
                *m |= 2;
                D_800C1FFC = *m;
            }
            if (p->unk2B) {
                *m |= 4;
            }
        }
    } else {
        if (D_801323E5 & 1) {
            f[0] = 1;
        } else {
            f[0] = 0;
        }
        if (D_801323E5 & 2) {
            f[1] = 1;
        } else {
            f[1] = 0;
        }
        if (D_801323E5 & 4) {
            f[3] = 1;
        } else {
            f[3] = 0;
        }
    }
}

s32 func_800299F4(s32);
s32 func_8005DFE8(Unk8012F720 *, u8);
s32 func_8005E180(Unk8012F720 *, u8);

/* Loads the save (`save` == 0) or writes it back. Uses SRAM unless
 * func_800299F4(0x53) says otherwise. */
void func_8005DF54(Unk8012F720 *data, u8 save) {
    u8 sram = func_800299F4(0x53) == 0;
    u8 sram2 = sram;
    s32 result;

    if (save == 0) {
        result = func_8005DFE8(data, sram);
        func_8005DE88(data, 0, result);
    } else {
        func_8005DE88(data, 1, result);
        func_8005E180(data, sram2);
    }
}

typedef struct SaveSlotAddr {
    s32 file;
    s32 crcFile;
    s32 sram;
    s32 crcSram;
} SaveSlotAddr; /* where each of the two save copies lives */
extern SaveSlotAddr D_800C2BE0[];
s32 func_80028110(s32, s32);
s32 func_80028204(s32, s32 *);
u16 func_8006A1EC(void *, s32);
void nuPiReadWriteSram(u32, void *, u32, s32);
s32 rand(void);

INCLUDE_ASM("asm/nonmatchings/34FA0", func_8005DFE8);

extern u8 D_801B5588[];

/* Writes the save data and its checksum to both copies (SRAM, or the files
 * when `toSram` is 0). */
s32 func_8005E180(Unk8012F720 *save, u8 toSram) {
    u8 buf[0xC0];
    u16 *crc = (u16 *)(((u32)buf + 0xF) & ~0xF);
    s32 i;
    s32 j;
    u16 sum;

    for (i = 0; i < 32; i++) {
        save->pad0[8 + i] = ~D_801B5588[i];
    }
    sum = func_8006A1EC(save, 0x2A78);
    for (j = 0; j < 2; j++) {
        crc[0] = rand();
        crc[1] = crc[0] ^ sum;
        if (!toSram) {
            if (func_80028110(D_800C2BE0[j].file, 0x2A78) == 0) {
                func_80028110(D_800C2BE0[j].crcFile, 4);
            }
        } else {
            nuPiReadWriteSram(D_800C2BE0[j].sram, save, 0x2A78, 1);
            nuPiReadWriteSram(D_800C2BE0[j].crcSram, crc, 4, 1);
        }
    }
    return 1;
}
