#include "common.h"

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_802033B0);

void func_ovl7_80203620(void);
/* Camera look-at state; splat also labels each field separately. */
typedef struct CameraView {
    /* 0x00 */ f32 pos[2][3]; /* [0] = eye, [1] = at */
    /* 0x18 */ f32 yaw;
    /* 0x1C */ f32 pitch;
    /* 0x20 */ f32 dist;
    /* 0x24 */ u8 pad24[0x4];
    /* 0x28 */ f32 target[2][3];
    /* 0x40 */ u8 pad40[0x30];
    /* 0x70 */ f32 speed[2];
    /* 0x78 */ f32 accel[2];
    /* 0x80 */ u8 pad80[0x18];
    /* 0x98 */ f32 brake[2];
    /* 0xA0 */ u8 padA0[0xC];
    /* 0xAC */ s32 flags[2];
    /* 0xB4 */ s32 axis[2];
} CameraView;
extern CameraView D_ovl7_8022BE30;

f32 func_80059FAC(f32, f32);

void func_ovl7_8020356C(f32 eyeX, f32 eyeY, f32 eyeZ, f32 atX, f32 atY, f32 atZ) {
    D_ovl7_8022BE30.pos[0][0] = eyeX;
    D_ovl7_8022BE30.pos[0][1] = eyeY;
    D_ovl7_8022BE30.pos[0][2] = eyeZ;
    D_ovl7_8022BE30.pos[1][0] = atX;
    D_ovl7_8022BE30.pos[1][1] = atY;
    D_ovl7_8022BE30.pos[1][2] = atZ;
    func_ovl7_80203620();
}

extern s32 D_ovl7_8022BEA0[2];
extern s32 D_ovl7_8022BEA8[2];

void func_ovl7_802035BC(s32 i, s32 a, s32 b) {
    s32 pad[2];

    D_ovl7_8022BEA0[i] = a;
    D_ovl7_8022BEA8[i] = b;
}

extern s32 D_ovl7_8022BEB0;
extern s32 D_ovl7_8022BEB4;

void func_ovl7_802035E4(s32 arg0, s32 arg1, s32 arg2) {
    D_ovl7_8022BEB0 = arg1;
    D_ovl7_8022BEB4 = arg2;
}

extern s32 D_ovl7_8022BEB8;
extern s32 D_ovl7_8022BEBC;

void func_ovl7_802035F8(s32 arg0, s32 arg1, s32 arg2) {
    D_ovl7_8022BEB8 = arg1;
    D_ovl7_8022BEBC = arg2;
}

extern s32 D_ovl7_8022BEC0;
extern s32 D_ovl7_8022BEC4;

void func_ovl7_8020360C(s32 arg0, s32 arg1, s32 arg2) {
    D_ovl7_8022BEC0 = arg1;
    D_ovl7_8022BEC4 = arg2;
}

#define SQ(x) ((x) * (x))

/* Recomputes pitch, yaw and distance from the camera's eye and at points. */
void func_ovl7_80203620(void) {
    f32 dx, dz;

    dx = D_ovl7_8022BE30.pos[1][0] - D_ovl7_8022BE30.pos[0][0];
    dz = D_ovl7_8022BE30.pos[1][2] - D_ovl7_8022BE30.pos[0][2];
    D_ovl7_8022BE30.pitch = func_80059FAC(D_ovl7_8022BE30.pos[1][1] - D_ovl7_8022BE30.pos[0][1], sqrtf(dx * dx + dz * dz));
    D_ovl7_8022BE30.yaw = func_80059FAC(D_ovl7_8022BE30.pos[1][2] - D_ovl7_8022BE30.pos[0][2],
                                        D_ovl7_8022BE30.pos[1][0] - D_ovl7_8022BE30.pos[0][0]);
    D_ovl7_8022BE30.dist = sqrtf(SQ(D_ovl7_8022BE30.pos[1][0] - D_ovl7_8022BE30.pos[0][0]) +
                                 SQ(D_ovl7_8022BE30.pos[1][1] - D_ovl7_8022BE30.pos[0][1]) +
                                 SQ(D_ovl7_8022BE30.pos[1][2] - D_ovl7_8022BE30.pos[0][2]));
}

extern f64 D_ovl7_8020C090;

/* Starts moving camera point i (0 = eye, 1 = at) towards (x, y, z) over `frames`
 * frames, or snaps it there when already close. */
void func_ovl7_8020370C(s32 i, f32 x, f32 y, f32 z, s32 frames) {
    f32 dx, dy, dz, dist;
    s32 q;

    dx = x - D_ovl7_8022BE30.pos[i][0];
    dy = y - D_ovl7_8022BE30.pos[i][1];
    dz = z - D_ovl7_8022BE30.pos[i][2];
    dist = sqrtf(dx * dx + dy * dy + dz * dz);
    if (dist < 0.1f) {
        D_ovl7_8022BE30.pos[i][0] = x;
        D_ovl7_8022BE30.pos[i][1] = y;
        D_ovl7_8022BE30.pos[i][2] = z;
        return;
    }
    if (frames != 0) {
        q = frames / 4;
        D_ovl7_8022BE30.speed[i] = dist / (frames - q);
        D_ovl7_8022BE30.accel[i] = D_ovl7_8022BE30.speed[i] / (q + 1);
        D_ovl7_8022BE30.brake[i] = dist * D_ovl7_8020C090;
        if (!(D_ovl7_8022BE30.flags[i] & 0x80)) {
            if (!(D_ovl7_8022BE30.flags[i] & 2)) {
                D_ovl7_8022BE30.flags[i] ^= 2;
            }
            if (D_ovl7_8022BE30.flags[i] & 4) {
                D_ovl7_8022BE30.flags[i] ^= 4;
            }
        }
    } else {
        if (!(D_ovl7_8022BE30.flags[i] & 4)) {
            D_ovl7_8022BE30.flags[i] ^= 4;
        }
        if (D_ovl7_8022BE30.flags[i] & 2) {
            D_ovl7_8022BE30.flags[i] ^= 2;
        }
    }
    D_ovl7_8022BE30.target[i][0] = x;
    x -= D_ovl7_8022BE30.pos[i][0];
    D_ovl7_8022BE30.target[i][2] = z;
    z -= D_ovl7_8022BE30.pos[i][2];
    D_ovl7_8022BE30.target[i][1] = y;
    y -= D_ovl7_8022BE30.pos[i][1];
    D_ovl7_8022BE30.axis[i] = 1;
    if (fabsf(x) < fabsf(z)) {
        D_ovl7_8022BE30.axis[i] = 3;
        x = z;
    }
    if (fabsf(x) < fabsf(y)) {
        D_ovl7_8022BE30.axis[i] = 2;
    }
}

/* Like func_ovl7_8020370C, but marks point i as the one being driven (0x80, 8)
 * and clears those bits on the other point. */
void func_ovl7_80203984(s32 i, f32 x, f32 y, f32 z, s32 frames) {
    if (!(D_ovl7_8022BE30.flags[i] & 0x80)) {
        D_ovl7_8022BE30.flags[i] ^= 0x80;
    }
    if (D_ovl7_8022BE30.flags[i ^ 1] & 0x80) {
        D_ovl7_8022BE30.flags[i ^ 1] ^= 0x80;
    }
    if (!(D_ovl7_8022BE30.flags[i] & 8)) {
        D_ovl7_8022BE30.flags[i] ^= 8;
    }
    if (D_ovl7_8022BE30.flags[i ^ 1] & 8) {
        D_ovl7_8022BE30.flags[i ^ 1] ^= 8;
    }
    func_ovl7_8020370C(i, x, y, z, frames);
}

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203A30);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203B60);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203C90);

/* Returns 1 when neither camera point has any motion flags set. */
s32 func_ovl7_80203DC4(void) {
    if (D_ovl7_8022BE30.flags[0] == 0 && D_ovl7_8022BE30.flags[1] == 0) {
        return 1;
    }
    return 0;
}

/* Returns 1 when neither camera point has any of `mask` set. */
s32 func_ovl7_80203DE8(s32 mask) {
    if (!(D_ovl7_8022BE30.flags[0] & mask) && !(D_ovl7_8022BE30.flags[1] & mask)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203E14);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203F70);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80204EA8);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_802065FC);
