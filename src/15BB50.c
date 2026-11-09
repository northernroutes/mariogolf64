#include "common.h"

INCLUDE_ASM("asm/nonmatchings/15BB50", func_ovl12_80241800);

s32 func_800292FC(s32);
s32 func_8002A97C(s32, s32);
s32 func_8004E47C(s32 *);
s32 func_800934CC(s32);
extern s32 D_801B6090;
extern s32 D_ovl12_802450C0;

void func_ovl12_80241EE8(void) {
    s32 var_s0;
    s32 var_s1;

    func_800934CC(-1);
    func_800292FC(3);
    func_8002A97C(4, 0);
    func_8004E47C(D_ovl12_802450C0 + 0x54);
    func_8004E47C(D_ovl12_802450C0 + 0x48);
    func_8004E47C(D_ovl12_802450C0 + 0x4C);
    func_8004E47C(D_ovl12_802450C0 + 0x50);
    func_8004E47C(D_ovl12_802450C0 + 0x40);
    func_8004E47C(D_ovl12_802450C0 + 0x44);
    var_s1 = 0;
    if (D_801B6090 != 0) {
        var_s0 = 0x58;
        do {
            func_8004E47C(D_ovl12_802450C0 + var_s0);
            func_8004E47C(D_ovl12_802450C0 + var_s0 + 4);
            var_s1 += 1;
            var_s0 += 8;
        } while (var_s1 != D_801B6090);
    }
    func_8004E47C(&D_ovl12_802450C0);
}

INCLUDE_ASM("asm/nonmatchings/15BB50", func_ovl12_80241FE0);

INCLUDE_ASM("asm/nonmatchings/15BB50", func_ovl12_8024216C);

extern s32 D_ovl12_80244E10;

s32 func_ovl12_80242418(void) {
    return D_ovl12_80244E10;
}

INCLUDE_ASM("asm/nonmatchings/15BB50", func_ovl12_80242424);

INCLUDE_ASM("asm/nonmatchings/15BB50", func_ovl12_80243E24);

void func_ovl12_80244E04(void) {

}
