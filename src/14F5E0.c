#include "common.h"

s32 func_80050BF0(s32, s32, s32);
s32 func_8005AF50();
s32 func_8005DF54(s32, s32);
s32 func_80099490();
s32 func_ovl8_801F5604();
void func_ovl8_801F56E4(void);

void func_ovl8_801F55A0(void) {
    s32 temp_s0;

    temp_s0 = func_8005AF50();
    func_80050BF0(0x69, 0xD, 0x50);
    func_80099490();
    func_8005DF54(temp_s0, 0);
    func_ovl8_801F5604();
    func_ovl8_801F56E4();
    func_8005DF54(temp_s0, 1);
}

/* Parts of the object returned by func_8005AF50 (see Unk8012F720 in 34FA0.c). Placeholder. */
typedef struct Unk8005AF50_14F5E0 {
    /* 0x0000 */ u8 pad0[0xA84];
    /* 0x0A84 */ u8 unkA84[6][18];
    /* 0x0AF0 */ u8 unkAF0[14][18][2];
    /* 0x0CE8 */ u8 padCE8[0x638];
    /* 0x1320 */ u8 unk1320[6][6];
    /* 0x1344 */ u8 unk1344[6][6][18];
    /* 0x15CC */ s32 unk15CC;
} Unk8005AF50_14F5E0;

s32 func_8005C674(s32, s32);

s32 func_ovl8_801F5604(void) {
    Unk8005AF50_14F5E0 *obj = (Unk8005AF50_14F5E0 *) func_8005AF50();
    s32 i;
    s32 j;

    for (i = 0; i != 14; i++) {
        for (j = 0; j != 18; j++) {
            if (!(obj->unkAF0[i][j][1] & 0x7F)) {
                obj->unkAF0[i][j][1] = 1;
            }
        }
    }
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            obj->unk1320[i][j] = 1;
        }
    }
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 18; j++) {
            obj->unkA84[i][j] = 1;
        }
    }
    return func_8005C674(1, 1);
}

void func_ovl8_801F56E4(void) {
    Unk8005AF50_14F5E0 *obj = (Unk8005AF50_14F5E0 *) func_8005AF50();
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i != 6; i++) {
        for (j = 0; j != 6; j++) {
            obj->unk1320[i][j] = 1;
            for (k = 0; k != 13; k++) {
                obj->unk1344[i][j][k] = 1;
            }
        }
    }
    if (obj->unk15CC < 3000) {
        obj->unk15CC = 3000;
    }
}

void func_ovl8_801F5780(void) {
    s32 obj = func_8005AF50();
    s32 i;
    s32 j;

    func_80099490();
    func_8005DF54(obj, 0);
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 3; j++) {
            /* 0x74-byte entries from 0xEA4; s32[3] at 0x24 within each */
            ((s32 *)(obj + i * 0x74 + 0xEC8))[j] = 1;
        }
    }
    func_8005DF54(obj, 1);
}

INCLUDE_ASM("asm/nonmatchings/14F5E0", func_ovl8_801F57F8);
