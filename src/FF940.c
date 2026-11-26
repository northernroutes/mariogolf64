#include "common.h"

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_802159C0);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_80215B84);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_80215DC4);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_8021640C);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_802169CC);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_80216C14);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_8021730C);

INCLUDE_ASM("asm/nonmatchings/FF940", func_ovl3_80217464);

s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
s32 func_800504E8(s32 id, void *obj);
s32 func_80050598(void *obj);
s32 func_800505A0(s32 handle, s32 arg1, void *obj);
void *func_8005AF50(void);
extern u16 D_ovl3_802308A4[18];
extern s32 D_8012D430[18];
extern s16 D_ovl3_802308C8[18][4];
extern u8 D_ovl3_8023BFF0[18][0x200];

void func_ovl3_802177D0(void) {
    s32 sp10[8];
    s32 sp30[4];
    s32 i;

    func_8005AF50();
    for (i = 0; i != 18; i++) {
        func_8005062C(D_ovl3_802308A4[i], sp10);
        func_800506D4(D_8012D430[i], sp10);
        func_800504E8(D_ovl3_802308C8[i][0], sp30);
        func_800505A0((s32) D_ovl3_8023BFF0[i], func_80050598(sp30), sp30);
    }
}
