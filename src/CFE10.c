#include "common.h"

extern s8 D_ovl0_80229236[5];
extern s32 D_ovl0_80224860;
extern s32 D_800C1B70;
extern s32 D_ovl0_802246F8;
extern s8 D_ovl0_802291D8[30];

void func_ovl0_80216B10(void) {
    s32 i;

    D_ovl0_80224860 = 0;
    D_800C1B70 = 0;
    D_ovl0_802246F8 = -1;
    for (i = 0; i != 5; i++) {
        D_ovl0_80229236[i] = -1;
    }
    for (i = 0; i != 30; i++) {
        D_ovl0_802291D8[i] = 0;
    }
}

s32 func_80078D94();
s32 func_8008679C(s32);
s32 func_ovl0_801FD8DC();
s32 func_ovl0_8020D9F0();
s32 func_ovl0_8020E7B4(s32);
s32 func_ovl0_8020FFEC(s32);
s32 func_ovl0_80213D70(s32);
s32 func_ovl0_80216130(s32);
s32 func_ovl0_80217F5C(s32);
extern s32 D_800C1B70;
extern s32 D_ovl0_80224860;
extern s8 D_ovl0_80225410;

void func_ovl0_80216B74(s32 arg0) {
    osSyncPrintf(&D_ovl0_80225410, arg0);
    func_ovl0_80216130(-1);
    func_8008679C(-1);
    func_80078D94();
    D_ovl0_80224860 = 0;
    D_800C1B70 = 0;
    func_ovl0_8020D9F0();
    func_ovl0_80213D70(-1);
    if (arg0 == 2) {
        func_ovl0_8020E7B4(-2);
    }
    if (arg0 == 1) {
        func_ovl0_8020FFEC(-1);
        func_ovl0_8020E7B4(-1);
    }
    func_ovl0_801FD8DC();
    func_ovl0_80217F5C(-1);
}

s32 func_80050F68(s32);

void func_ovl0_80216C18(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_80050F68(var_s0);
        var_s0 += 1;
    } while (var_s0 != 0x10);
}

extern s8 D_ovl0_80229236[5];
extern s8 D_ovl0_8022923B[5];

/* Claims the first free (-1) slot of five: marks it 1 with a timer of 20. */
s32 func_ovl0_80216C58(void) {
    s32 found = -1;
    s32 i;

    for (i = 0; i != 5; i++) {
        if (D_ovl0_80229236[i] == -1) {
            found = i;
            D_ovl0_80229236[i] = 1;
            D_ovl0_8022923B[found] = 20;
            break;
        }
    }
    return found;
}

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_80216CAC);

s32 func_8004E2DC(s32);
s32 func_8005062C(s32, s32 *);
s32 func_800506D4(s32, s32 *);
extern s32 D_8012D3C0;
extern s32 D_ovl0_8022927C;
extern s32 D_ovl0_80229280;

void func_ovl0_80216EDC(void) {
    s32 sp10[8];
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_8004E2DC(func_8005062C(0x561, sp10));
    D_ovl0_8022927C = temp_v0;
    func_800506D4(temp_v0, sp10);
    temp_v0_2 = func_8004E2DC(func_8005062C(0x973, sp10));
    D_ovl0_80229280 = temp_v0_2;
    func_800506D4(temp_v0_2, sp10);
    D_8012D3C0 = func_8004E2DC(0x2180);
    func_8005062C(0x6AD, sp10);
    func_800506D4(D_8012D3C0, sp10);
    func_8005062C(0x969, sp10);
    func_800506D4(D_8012D3C0 + 0x648, sp10);
}

s32 func_8004E47C(s32 *);
extern s32 D_8012D3C0;
extern s32 D_ovl0_8022927C;
extern s32 D_ovl0_80229280;

void func_ovl0_80216F8C(void) {
    func_8004E47C(&D_ovl0_8022927C);
    func_8004E47C(&D_ovl0_80229280);
    func_8004E47C(&D_8012D3C0);
}

void func_ovl0_80216FC4(void) {
}

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_80216FCC);

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_80217164);

void func_ovl0_80217F44(void) {
}

void func_ovl0_80217F4C(void) {
}

void func_ovl0_80217F54(void) {
}

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_80217F5C);

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_80218238);

INCLUDE_ASM("asm/nonmatchings/CFE10", func_ovl0_8021857C);
