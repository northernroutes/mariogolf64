#include "common.h"

INCLUDE_ASM("asm/nonmatchings/4C3D0", func_80070FD0);

INCLUDE_ASM("asm/nonmatchings/4C3D0", func_800710C4);

/* Sub-object at 0x990 of the object returned by func_8005AF50 (its unkF4 is
 * Unk8012F720.unkA84 in 34FA0.c). Placeholder. */
typedef struct Unk8005AF50_990 {
    /* 0x00 */ u8 pad0[0xF4];
    /* 0xF4 */ s8 unkF4[6][18];
} Unk8005AF50_990;

typedef struct Unk8005AF50_4C3D0 {
    /* 0x000 */ u8 pad0[0x990];
    /* 0x990 */ Unk8005AF50_990 unk990;
} Unk8005AF50_4C3D0;

Unk8005AF50_4C3D0 *func_8005AF50(void);
void func_8007FE44(s32);
extern s32 D_801B608C;
extern s32 D_801B6094;
extern s32 D_801B6098;

void func_8007117C(void) {
    Unk8005AF50_990 *p = &func_8005AF50()->unk990;
    s32 n;
    s32 i;
    s32 j;

    if (D_801B608C == 5 && p->unkF4[D_801B6094][D_801B6098] == 0) {
        n = 0;
        for (i = 0; i != 6; i++) {
            for (j = 0; j != 18; j++) {
                n += p->unkF4[i][j] != 0;
            }
        }
        func_8007FE44(n);
    }
}

INCLUDE_ASM("asm/nonmatchings/4C3D0", func_80071220);
