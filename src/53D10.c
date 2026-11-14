#define F3DEX_GBI_2
#include "common.h"

/* Effect pool D_801B74E0 (40 entries); state -1 = free. */
typedef struct Effect {
    /* 0x00 */ f32 pos[3];
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x10];
    /* 0x28 */ f32 alpha;
    /* 0x2C */ f32 alphaVel;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ s16 unk38;
    /* 0x3A */ s8 state;
    /* 0x3B */ s8 unk3B;
    /* 0x3C */ s8 mtxIndex;
    /* 0x3D */ u8 pad3D[3];
} Effect;
extern Effect D_801B74E0[40];


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

/* Frees every effect slot. */
void func_80078D94(void) {
    s32 i;
    Effect *e;

    for (i = 0; i != 40; i++) {
        e = &D_801B74E0[i];
        e->state = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078DC0);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80078FA8);

INCLUDE_ASM("asm/nonmatchings/53D10", func_80079358);

void func_80065B98(f32 (*mf)[4], f32 *rot, f32 *pos, f32 *scale);
void func_80065DD8(f32 (*mf)[4], Mtx *m);
extern s32 D_800C52B4;
extern Mtx D_800FD8F0[];

/* Spawns an effect at pos (1/1024 units) with its own matrix slot from the
 * rotating counter D_800C52B4, and builds that matrix. */
void func_8007955C(s32 *pos) {
    f32 p[3];
    f32 rot[3];
    f32 scale[3];
    f32 mf[4][4];
    s32 i;
    Effect *e;

    for (i = 0; i != 40; i++) {
        e = &D_801B74E0[i];
        if (e->state == -1) {
            e->pos[0] = pos[0] * 0.0009765625f;
            e->pos[1] = pos[1] * 0.0009765625f;
            e->pos[2] = pos[2] * 0.0009765625f;
            e->state = 12;
            e->unk3B = 0;
            e->mtxIndex = D_800C52B4;
            D_800C52B4 = (D_800C52B4 + 1) % 40;
            e->unk0C = 0.0f;
            e->unk10 = 0.0f;
            e->unk14 = 0.0f;
            e->alpha = 95.0f;
            e->alphaVel = -2.0f;
            e->unk30 = 1.0f;
            e->unk34 = 0.1f;
            p[0] = e->pos[0];
            p[1] = e->pos[1];
            p[2] = e->pos[2];
            rot[0] = 0.0f;
            rot[1] = 0.0f;
            rot[2] = 0.0f;
            scale[0] = e->unk30;
            scale[1] = e->unk30;
            scale[2] = e->unk30;
            func_80065B98(mf, rot, p, scale);
            func_80065DD8(mf, &D_800FD8F0[e->mtxIndex]);
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_800796F8);

/* Spawns an effect at pos (1/1024 units) in the first free slot, if any. */
void func_80079940(s32 *pos) {
    s32 i;
    Effect *e;

    for (i = 0; i != 40; i++) {
        e = &D_801B74E0[i];
        if (e->state == -1) {
            e->pos[0] = pos[0] * 0.0009765625f;
            e->pos[1] = pos[1] * 0.0009765625f;
            e->pos[2] = pos[2] * 0.0009765625f;
            e->unk0C = 0.0f;
            e->unk10 = 0.0025585936f;
            e->unk14 = 0.0f;
            e->unk38 = 0;
            e->alpha = 255.0f;
            e->alphaVel = -4.0f;
            e->unk30 = 24.0f;
            e->unk34 = -0.2f;
            e->state = 8;
            e->unk3B = 0;
            return;
        }
    }
}

s32 func_8005483C(s32, s32, f32 *);
/* -0.15; const so its load is hoisted like a literal-pool constant. */
extern const f64 D_800D1988;

/* Spawns an effect at the point func_8005483C(arg0, arg1) reports, if it
 * succeeds and a slot is free. */
void func_80079A08(s32 arg0, s32 arg1) {
    f32 unused[28]; /* never touched; keeps the frame layout */
    f32 pos[3];
    s32 i;
    u16 n;
    Effect *e;

    if (func_8005483C(arg0, arg1, pos) == 0) {
        n = 1;
        for (i = 0; i != 40; i++) {
            e = &D_801B74E0[i];
            if (e->state == -1) {
                e->pos[0] = pos[0];
                e->pos[1] = pos[1];
                e->pos[2] = pos[2];
                e->unk0C = 0.0f;
                e->unk10 = n * D_800D1988;
                e->unk14 = 0.0f;
                e->unk38 = 0;
                e->alpha = 230.0f;
                e->alphaVel = -2.0f;
                e->unk30 = 2.0f;
                e->unk34 = 0.02f;
                e->state = 14;
                e->unk3B = 0;
                return;
            }
        }
    }
}

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

extern Mtx D_800FD8F0[];
extern Vtx D_800C5338[];

/* Draws a grey quad (vertices D_800C5338) with the effect's alpha under matrix
 * D_800FD8F0[e->mtxIndex]. */
void func_8007DE9C(Gfx **gdl, Effect *e) {
    Gfx *gfx = *gdl;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0xE6, 0xE6, 0xE6, (u32)e->alpha);
    gSPMatrix(gfx++, (u8 *)&D_800FD8F0[e->mtxIndex] - 0x80000000, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPVertex(gfx++, D_800C5338, 4, 0);
    gDPPipeSync(gfx++);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

extern Vtx D_800C5378[];

/* As func_8007DE9C, with vertices D_800C5378. */
void func_8007DFD0(Gfx **gdl, Effect *e) {
    Gfx *gfx = *gdl;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0xE6, 0xE6, 0xE6, (u32)e->alpha);
    gSPMatrix(gfx++, (u8 *)&D_800FD8F0[e->mtxIndex] - 0x80000000, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPVertex(gfx++, D_800C5378, 4, 0);
    gDPPipeSync(gfx++);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E104);

INCLUDE_ASM("asm/nonmatchings/53D10", func_8007E19C);

typedef struct Vec3fs {
    f32 x, y, z;
} Vec3fs;

extern Vec3fs D_80104F44; /* wind velocity */
extern f32 D_801049FC;    /* wind x per unit */
extern f32 D_800FE380;    /* wind z per unit */

/* Weather particle pool (D_801EFFA8, 0x900 bytes = 48 entries). */
typedef struct Particle {
    /* 0x00 */ f32 pos[3];
    /* 0x0C */ f32 tail[3];
    /* 0x18 */ f32 ground;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ u8 pad20[0xA];
    /* 0x2A */ u16 flags;
    /* 0x2C */ s8 timer;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ u8 pad2E[2];
} Particle;

/* Particle emitters (D_801B8BB8, 0x380 bytes = 32 entries). */
typedef struct Emitter {
    /* 0x00 */ f32 pos[3];
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ u8 pad10[6];
    /* 0x16 */ s8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 pad19[3];
} Emitter;

s32 func_8004E2DC(s32);
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
void func_8007E7B8(void);
extern s32 D_800C5448;
extern s32 D_800FF4CC;
extern Emitter *D_801B8BB8;
extern Particle *D_801EFFA8;

void func_8007E234(s32 arg0) {
    s32 sp10[8];
    s32 temp_v0;

    if (arg0 == 2) {
        temp_v0 = func_8004E2DC(func_8005062C(0x6BC, sp10));
        D_800FF4CC = temp_v0;
        func_800506D4(temp_v0, sp10);
        D_801EFFA8 = (Particle *)func_8004E2DC(0x900);
        D_801B8BB8 = (Emitter *)func_8004E2DC(0x380);
        func_8007E7B8();
    }
    D_800C5448 = arg0;
}

s32 func_8004E47C(s32 *);
s32 func_80050F68(s32);
extern s32 D_800C5448;
extern s32 D_800FF4CC;
extern Emitter *D_801B8BB8;
extern Particle *D_801EFFA8;

void func_8007E2B0(void) {
    if (D_800C5448 == 2) {
        func_8004E47C(&D_800FF4CC);
        func_8004E47C((s32 *)&D_801EFFA8);
        func_8004E47C((s32 *)&D_801B8BB8);
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

s32 rand(void);
extern f32 D_801B54F0;

/* Respawns a particle at a random x/z around D_800FF418, 105..404 units back
 * along its fall (y) from the camera height, shifted against the wind by the
 * same number of frames; its tail is a 90-unit streak along the wind. */
void func_8007E438(Particle *p) {
    f32 t;
    f32 len;

    p->pos[0] = (f32)((rand() % 200 - 100) * 0x600) * 0.0009765625f + D_800FF418.x;
    p->pos[1] = (f32)(-0x1A400 - (rand() % 200) * 0x600) * 0.0009765625f;
    p->pos[2] = (f32)((rand() % 200 - 100) * 0x600) * 0.0009765625f + D_800FF418.z;
    t = p->pos[1] / D_80104F44.y;
    p->pos[1] += D_801B54F0 + 15.0f;
    p->pos[0] += D_80104F44.x * t;
    p->pos[2] += D_80104F44.z * t;
    len = 90.0f;
    p->tail[1] = p->pos[1] + len;
    p->tail[0] = p->pos[0] + D_801049FC * len;
    p->tail[2] = p->pos[2] + D_800FE380 * len;
    p->ground = 0.0f;
    p->timer = -1;
    p->unk2D = 0;
    p->unk1C = 1.0f;
    p->flags = 0;
}

s32 rand(void);
s32 func_80043A04(s32, s32);

/* Respawns an emitter at a random point within +/-375 units (x/z) of
 * D_800FF418, on the ground. */
void func_8007E664(Emitter *e) {
    e->pos[0] = (f32)((rand() % 500 - 250) * 0x600) * 0.0009765625f + D_800FF418.x;
    e->pos[2] = (f32)((rand() % 500 - 250) * 0x600) * 0.0009765625f + D_800FF418.z;
    e->pos[1] = func_80043A04(e->pos[0] * 1024.0f, e->pos[2] * 1024.0f) * 0.0009765625f;
    e->unk18 = 0;
}

void func_8007E438(Particle *);
void func_8007E664(Emitter *);
extern s32 D_800BA9F0;
extern u16 D_800BA9F4;
extern s32 D_80104AC0;

/* Initialises the weather: wind from D_800BA9F0/D_800BA9F4, then spawns all 48
 * particles and 32 emitters (emitter timers staggered by i % 9). */
void func_8007E7B8(void) {
    f32 dir, speed;
    s32 i;

    D_80104AC0 = 0;
    dir = D_800BA9F4 * 9.58738e-05f;
    speed = (D_800BA9F0 / 65536) * 0.1f;
    D_801049FC = cosf(dir) * speed;
    D_800FE380 = sinf(dir) * speed;
    D_80104F44.y = 60.0f;
    D_80104F44.x = D_801049FC * 60.0f;
    D_80104F44.z = D_800FE380 * 60.0f;
    func_8007E30C();
    for (i = 0; i != 48; i++) {
        func_8007E438(&D_801EFFA8[i]);
        D_801EFFA8[i].flags = 0;
    }
    for (i = 0; i != 32; i++) {
        func_8007E664(&D_801B8BB8[i]);
        D_801B8BB8[i].unk0C = 1.0f;
        D_801B8BB8[i].timer = i % 9 - 1;
        D_801B8BB8[i].unk17 = 0;
    }
}

extern Vec3fs D_800D1A88;
extern s32 D_800BA9F8;
extern s32 D_800BA9F0;
extern u16 D_800BA9F4;
extern f32 D_80106190;
extern f32 D_801B54F0;
extern Vec3fs D_800C544C; /* previous eye */
extern s32 D_80104AC0;
extern s32 D_800C5400;
extern s32 D_800C5404;
void func_80051024(s32, s32);
s32 func_80043A04(s32, s32);
void func_8007E664(Emitter *);
void func_8007E438(Particle *);

/* Per-frame weather update: eases D_80106190 down to 80, derives the wind from
 * D_800BA9F0/D_800BA9F4, drifts the particles with camera movement, refreshes one
 * particle's ground height per frame, and ticks the emitters and particles. */
void func_8007E980(void) {
    Vec3fs drift = D_800D1A88;
    f32 dir, speed, dx, dz;
    s32 i;
    Particle *p;

    if (D_800BA9F8 == 1 && D_800C5448 == 2) {
        if (D_80106190 > 80.0f) {
            D_80106190 -= 0.5f;
        }
        func_80051024(9, D_80106190);
        dir = D_800BA9F4 * 9.58738e-05f;
        speed = (D_800BA9F0 / 65536) * 0.1f;
        D_801049FC = cosf(dir) * speed;
        D_800FE380 = sinf(dir) * speed;
        D_80104F44.y = 60.0f;
        D_80104F44.x = D_801049FC * 60.0f;
        D_80104F44.z = D_800FE380 * 60.0f;
        func_8007E30C();
        dx = D_801B54EC - D_800C544C.x;
        dz = D_801B54F4 - D_800C544C.z;
        if (sqrtf(dx * dx + dz * dz) > 15.0f) {
            drift.x += dx;
            drift.z += dz;
        } else if (D_800C544C.y < D_801B54F0) {
            drift.y = D_801B54F0 - D_800C544C.y;
        }
        D_800C544C.x = D_801B54EC;
        D_800C544C.y = D_801B54F0;
        D_800C544C.z = D_801B54F4;
        D_801EFFA8[D_80104AC0].ground =
            func_80043A04(D_801EFFA8[D_80104AC0].pos[0] * 1024.0f, D_801EFFA8[D_80104AC0].pos[2] * 1024.0f) * 0.0009765625f;
        for (i = 0; i != D_800C5404; i++) {
            Emitter *e = &D_801B8BB8[i];

            if (++e->timer == 8) {
                func_8007E664(&D_801B8BB8[i]);
                e->timer = 0;
            }
        }
        for (i = 0; i != D_800C5400; i++) {
            p = &D_801EFFA8[i];
            if (p->pos[1] < p->ground) {
                p->pos[0] += D_80104F44.x;
                p->pos[1] += D_80104F44.y;
                p->pos[2] += D_80104F44.z;
            }
            if (p->pos[1] > p->ground) {
                p->flags |= 0x10;
            }
            if (p->timer == -1) {
                if (p->pos[1] < p->ground) {
                    p->pos[0] += drift.x;
                    p->pos[1] += drift.y;
                    p->pos[2] += drift.z;
                }
                p->tail[0] += D_80104F44.x + drift.x;
                p->tail[1] += D_80104F44.y + drift.y;
                p->tail[2] += D_80104F44.z + drift.z;
                if (p->tail[1] > p->ground) {
                    p->timer = 0;
                    p->tail[0] = p->pos[0] + (p->ground - p->pos[1]) * D_801049FC;
                    p->tail[1] = p->pos[1] + (p->ground - p->pos[1]);
                    p->tail[2] = p->pos[2] + (p->ground - p->pos[1]) * D_800FE380;
                }
            } else {
                p->timer++;
            }
            if (p->timer == 8) {
                func_8007E438(p);
            }
        }
        D_80104AC0 = (D_80104AC0 + 1) % D_800C5400;
    }
}

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
