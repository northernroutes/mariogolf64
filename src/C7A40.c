/* This file builds F3DEX2 display lists. */
#define F3DEX_GBI_2
#include "common.h"

s32 func_8004E2DC(s32);
extern s32 D_ovl0_80224114;
extern s32 D_ovl0_80224120;
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_8022D650;

void func_ovl0_8020E740(void) {
    u8 pad_unused[0x20]; /* unused; sizes the stack frame */
    D_ovl0_80224114 = -1;
    D_ovl0_80224124 = 1;
    D_ovl0_8022D650 = func_8004E2DC(0x6270);
    D_ovl0_80224120 = -1;
}

s32 func_8004E47C(s32 *);
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_8022D650;

void func_ovl0_8020E78C(void) {
    D_ovl0_80224124 = 0;
    func_8004E47C(&D_ovl0_8022D650);
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020E7B4);

extern s32 D_ovl0_80224118;
extern s32 D_ovl0_8022411C;
extern Vtx D_ovl0_80224130[4];
extern char D_ovl0_80225290[];
extern u8 D_ovl0_8022BC80[];
extern s32 D_800C54E0;
extern u8 D_80105118[];
void func_8006A84C(Gfx **, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Draws D_ovl0_80224118 as D_ovl0_8022411C billboarded digits (32x64 each;
 * digit 0 uses the first image), one 0x90-byte matrix block per digit. */
void func_ovl0_8020EBBC(Gfx **gdl) {
    Gfx *gfx = *gdl;
    u32 i;
    s32 tex;
    u8 *mtx;
    Gfx *cmd;

    sprintf((char *)D_80105118, D_ovl0_80225290, D_ovl0_80224118);
    for (i = 0; i != D_ovl0_8022411C; i++) {
        if (i == 0) {
            tex = 0;
        } else {
            tex = (((&D_80105118[-1])[i] - '0') << 11) + 0x800;
        }
        func_8006A84C(&gfx, (u8 *)D_ovl0_8022D650 + (tex + 0x208), 2, 1, 0x20, 0x40, 0, 0, 0, 0, 0, 0, 0);
        cmd = gfx++;
        mtx = &D_ovl0_8022BC80[i * 0x90];
        gSPMatrix(cmd, mtx + (D_800C54E0 << 6) - 0x80000000,
                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPVertex(gfx++, D_ovl0_80224130, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

extern s32 D_ovl0_80224114;
extern s8 D_ovl0_80224174[][8];
extern u8 D_ovl0_80227EB0[];

/* Draws D_ovl0_80224174[D_ovl0_80224114][0] 32x64 billboards (consecutive
 * images), loading the camera matrix and multiplying in each one's matrix. */
void func_ovl0_8020ED54(Gfx **gdl) {
    Gfx *gfx = *gdl;
    s32 i;
    u8 *mtx;
    Gfx *cmd;

    for (i = 0; i != D_ovl0_80224174[D_ovl0_80224114][0]; i++) {
        func_8006A84C(&gfx, (u8 *)D_ovl0_8022D650 + (i * 0x800 + 0x208), 2, 1, 0x20, 0x40, 0, 0, 0, 0, 0, 0, 0);
        gSPMatrix(gfx++, D_ovl0_80227EB0 + (D_800C54E0 << 6) - 0x80000000,
                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        cmd = gfx++;
        mtx = &D_ovl0_8022BC80[i * 0x90];
        gSPMatrix(cmd, mtx + (D_800C54E0 << 6) - 0x80000000, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        gSPVertex(gfx++, D_ovl0_80224130, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

void func_ovl0_8020EEEC(s32 *arg0) {
    *arg0 = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020EEF8);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FAE8);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FC10);

extern s32 D_ovl0_80224410;

s32 func_ovl0_8020FFD8(void) {
    return ~D_ovl0_80224410 == 0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8020FFEC);

extern s32 D_ovl0_80224418;

s32 func_ovl0_8021035C(void) {
    return D_ovl0_80224418 >= 0xC;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80210370);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802104BC);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80210F40);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8021169C);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80211D60);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80212590);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802129C0);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80212CE0);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213038);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213634);

extern s32 D_ovl0_802246F8;

s32 func_ovl0_80213C64(void) {
    return ~D_ovl0_802246F8 != 0;
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213C78);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80213D70);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_8021419C);

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_80214250);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
s32 func_800772B0();
extern s32 D_ovl0_80224114;
extern s32 D_ovl0_80224120;
extern s32 D_ovl0_80224124;
extern s32 D_ovl0_80224848;
extern s32 D_ovl0_8022484C;
extern s32 D_ovl0_8022D650;

void func_ovl0_80216130(s32 arg0) {
    s32 sp10[8];

    if (D_ovl0_80224124 == 1) {
        if (arg0 == -1) {
            D_ovl0_80224848 = -1;
            return;
        }
        D_ovl0_80224848 = 0;
        D_ovl0_8022484C = 0x6CF;
        func_8005062C(0x6CF, sp10);
        func_800506D4(D_ovl0_8022D650, sp10);
        func_8005062C(0x6AF, sp10);
        func_800506D4(D_ovl0_8022D650 + 0x808, sp10);
        D_ovl0_80224120 = -1;
        D_ovl0_80224114 = -1;
        func_800772B0();
    }
}

INCLUDE_ASM("asm/nonmatchings/C7A40", func_ovl0_802161D4);
