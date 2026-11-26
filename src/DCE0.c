#define F3DEX_GBI_2
#include "common.h"

void func_80064D80(s32, s32, Vp *);
extern Vp D_800B7790[];
extern Gfx D_800B77F0[];
extern Gfx D_800B7820[];

/* Sets viewport n (segment 0 set to 0) and draws D_800B7820 then D_800B77F0. */
void func_800328E0(s32 n, Gfx **gdl) {
    Gfx *gfx = *gdl;

    gDPPipeSync(gfx++);
    gSPSegment(gfx++, 0, 0);
    gSPViewport(gfx++, &D_800B7790[n]);
    func_80064D80(0, 0, &D_800B7790[n]);
    gSPDisplayList(gfx++, D_800B7820);
    gSPDisplayList(gfx++, D_800B77F0);
    gDPPipeSync(gfx++);
    *gdl = gfx;
}

extern Gfx *D_801B93DC;
void func_800328E0(s32, Gfx **);

void func_800329B8(s32 arg0) {
    func_800328E0(arg0, &D_801B93DC);
}

extern s32 D_800B7840;
extern s32 D_800B7844;
extern s32 D_800B7848;

void func_800329D8(s32 arg0, s32 arg1, s32 arg2) {
    D_800B7840 = arg0;
    D_800B7844 = arg1;
    D_800B7848 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/DCE0", func_800329F4);

INCLUDE_ASM("asm/nonmatchings/DCE0", func_80032B78);

void func_80032B78(s32, Gfx **);

void func_80032E34(s32 arg0) {
    func_80032B78(arg0, &D_801B93DC);
}
