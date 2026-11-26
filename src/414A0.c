#include "common.h"

extern s8 D_800C3100;

void func_800660A0(void) {
    D_800C3100 = 1;
}

INCLUDE_ASM("asm/nonmatchings/414A0", func_800660B0);

INCLUDE_ASM("asm/nonmatchings/414A0", func_80066B50);

INCLUDE_ASM("asm/nonmatchings/414A0", func_800674B8);

void func_800679DC(void);
extern s32 D_8018D220;
extern s16 D_8018D228;
extern s16 D_8018D22A;
extern s16 D_8018D22C;
extern s16 D_8018D238;
extern s16 D_8018D23A;
extern s16 D_8018D23C;
extern s16 D_8018D248;
extern s16 D_8018D24A;
extern s16 D_8018D24C;

void func_800676B0(void) {
    D_8018D220 = 1;
    D_8018D228 = 0x800;
    D_8018D22A = -0x100;
    D_8018D22C = 0x1000;
    D_8018D238 = 0x800;
    D_8018D23A = -0x100;
    D_8018D23C = 0xF00;
    D_8018D248 = 0x700;
    D_8018D24A = -0x100;
    D_8018D24C = 0xF00;
    func_800679DC();
}

INCLUDE_ASM("asm/nonmatchings/414A0", func_80067730);

INCLUDE_ASM("asm/nonmatchings/414A0", func_800679DC);

INCLUDE_ASM("asm/nonmatchings/414A0", func_80067A60);
