#include "common.h"

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32 *, s32 *);
s32 func_80051A60();
extern s32 D_801B54EC;
extern s32 D_801B54F0;
extern s32 D_801B54F4;
extern s32 D_801B54F8;
extern s32 D_801B54FC;
extern f32 D_801B5500;
extern s32 D_801B5508;
extern s32 D_801B550C;
extern s32 D_801B5510;
extern s32 D_801B5514;
extern s32 D_801B5518;
extern s32 D_801B551C;
extern s32 D_801B5520;
extern s32 D_801B5524;
extern f32 D_801B5528;
extern s32 D_801B552C;
extern f32 D_801B5530;
extern s32 D_ovl9_801F57D0;
extern s32 D_ovl9_801F69E0;
extern s32 D_ovl9_801F8D30;

void func_ovl9_801F4A40(void) {
    s32 sp10[8];

    func_8005062C(0x702, sp10);
    func_800506D4(&D_ovl9_801F57D0, sp10);
    func_8005062C(0x6F6, sp10);
    func_800506D4(&D_ovl9_801F69E0, sp10);
    func_8005062C(0x97F, sp10);
    func_800506D4(&D_ovl9_801F8D30, sp10);
    func_80051A60();
    D_801B5508 = 8;
    D_801B550C = 8;
    D_801B5510 = 0x130;
    D_801B5514 = 0xE0;
    D_801B5518 = 0xE0;
    D_801B551C = 0xE0;
    D_801B5520 = 0x140;
    D_801B5524 = 0xF0;
    D_801B54EC = 0;
    D_801B54F0 = 0;
    D_801B54F4 = 0;
    D_801B54F8 = 0;
    D_801B54FC = 0;
    D_801B552C = 1;
    D_801B5500 = -100.0f;
    D_801B5528 = 1.0f;
    D_801B5530 = 45.0f;
}

INCLUDE_ASM("asm/nonmatchings/14FB60", func_ovl9_801F4B68);

INCLUDE_ASM("asm/nonmatchings/14FB60", func_ovl9_801F4DA0);

INCLUDE_ASM("asm/nonmatchings/14FB60", func_ovl9_801F4FF4);
