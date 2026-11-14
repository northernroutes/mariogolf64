#include "common.h"

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_802033B0);

void func_ovl7_80203620(void);
/* Camera look-at state; splat also labels each field separately. */
typedef struct CameraView {
    /* 0x00 */ f32 eye[3];
    /* 0x0C */ f32 at[3];
    /* 0x18 */ f32 yaw;
    /* 0x1C */ f32 pitch;
    /* 0x20 */ f32 dist;
} CameraView;
extern CameraView D_ovl7_8022BE30;

f32 func_80059FAC(f32, f32);

void func_ovl7_8020356C(f32 eyeX, f32 eyeY, f32 eyeZ, f32 atX, f32 atY, f32 atZ) {
    D_ovl7_8022BE30.eye[0] = eyeX;
    D_ovl7_8022BE30.eye[1] = eyeY;
    D_ovl7_8022BE30.eye[2] = eyeZ;
    D_ovl7_8022BE30.at[0] = atX;
    D_ovl7_8022BE30.at[1] = atY;
    D_ovl7_8022BE30.at[2] = atZ;
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

    dx = D_ovl7_8022BE30.at[0] - D_ovl7_8022BE30.eye[0];
    dz = D_ovl7_8022BE30.at[2] - D_ovl7_8022BE30.eye[2];
    D_ovl7_8022BE30.pitch = func_80059FAC(D_ovl7_8022BE30.at[1] - D_ovl7_8022BE30.eye[1], sqrtf(dx * dx + dz * dz));
    D_ovl7_8022BE30.yaw = func_80059FAC(D_ovl7_8022BE30.at[2] - D_ovl7_8022BE30.eye[2],
                                        D_ovl7_8022BE30.at[0] - D_ovl7_8022BE30.eye[0]);
    D_ovl7_8022BE30.dist = sqrtf(SQ(D_ovl7_8022BE30.at[0] - D_ovl7_8022BE30.eye[0]) +
                                 SQ(D_ovl7_8022BE30.at[1] - D_ovl7_8022BE30.eye[1]) +
                                 SQ(D_ovl7_8022BE30.at[2] - D_ovl7_8022BE30.eye[2]));
}

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_8020370C);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203984);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203A30);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203B60);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203C90);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203DC4);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203DE8);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203E14);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80203F70);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_80204EA8);

INCLUDE_ASM("asm/nonmatchings/145A30", func_ovl7_802065FC);
