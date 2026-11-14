#ifndef OVL7_CAMERA_H
#define OVL7_CAMERA_H

#include "common.h"

/* Camera look-at state; splat also labels each field separately. */
typedef struct CameraView {
    /* 0x00 */ f32 pos[2][3]; /* [0] = eye, [1] = at */
    /* 0x18 */ f32 yaw;
    /* 0x1C */ f32 pitch;
    /* 0x20 */ f32 dist;
    /* 0x24 */ f32 fov;
    /* 0x28 */ f32 target[2][3];
    /* 0x40 */ f32 vel[2][3];
    /* 0x58 */ u8 pad58[0xC];
    /* 0x64 */ f32 pitchDelta;
    /* 0x68 */ f32 yawDelta;
    /* 0x6C */ f32 distTarget;
    /* 0x70 */ f32 speed[2];
    /* 0x78 */ f32 accel[2];
    /* 0x80 */ f32 yawSpeed;
    /* 0x84 */ f32 yawAccel;
    /* 0x88 */ f32 pitchSpeed;
    /* 0x8C */ f32 pitchAccel;
    /* 0x90 */ f32 distSpeed;
    /* 0x94 */ f32 distAccel;
    /* 0x98 */ f32 brake[2];
    /* 0xA0 */ f32 pitchBrake;
    /* 0xA4 */ f32 yawBrake;
    /* 0xA8 */ f32 distBrake;
    /* 0xAC */ s32 flags[2];
    /* 0xB4 */ s32 axis[2];
} CameraView;
extern CameraView D_ovl7_8022BE30;

void func_ovl7_80203620(void);

#endif
