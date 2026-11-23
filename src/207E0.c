#include "common.h"

/* Placeholder for the object passed to func_80045A9C; real type unknown. */
typedef struct Unk80045A9C {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x4];
    /* 0x18 */ s32 unk18;
} Unk80045A9C;

extern s32 D_800BE62C;
extern s32 D_800BE688;
extern s32 D_800BE68C;
extern u8 D_800BE6D8;

void func_80040E3C(s32 arg0, s32 arg1);
void func_8004CDA0(void);

INCLUDE_ASM("asm/nonmatchings/207E0", func_800453E0);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80045734);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80045910);

void func_80045A9C(Unk80045A9C *arg0) {
    func_80040E3C(arg0->unk10, arg0->unk18);
}

s32 func_80045AC0(void) {
    return D_800BE62C == 4;
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_80045AD4);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80045B14);

s32 func_800510EC(s32, s32);
s32 func_8009226C(s32);
s32 func_80205AE4(s32, s32);
s32 func_80216B74(s32);
extern s32 D_800BE660;
extern s32 D_800BE698;
extern s32 D_800BE69C;
extern s32 D_800C5AAC;
extern s32 D_800FBE74;
extern s32 D_80132CF0;
extern f32 D_801B5530;
extern s32 D_801B557C;
extern s32 D_801B7F70;
extern s32 D_801B7F74;
extern s32 D_80250AEC;
extern s8 D_80250B61;

void func_80045C00(void) {
    D_800BE698 = 1;
    D_800BE69C = 0;
    D_800BE660 = 0;
    D_800C5AAC = 0;
    D_801B5530 = 45.0f;
    func_8009226C(-1);
    D_801B7F70 = 0;
    D_801B7F74 = 0;
    D_801B557C = 0;
    func_800510EC(0xB, 0x78);
    func_800510EC(0xF, 0x78);
    func_80216B74(0);
    D_800BE62C = -1;
    if (D_80132CF0 == D_80250AEC) {
        osSyncPrintf("\nCheckWater1\n");
        if (D_80250B61 != 0) {
            osSyncPrintf("\nCheckWater2\n");
            func_80205AE4(D_800FBE74, 0xB);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_80045CE0);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80046604);

s32 func_800467DC(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    if (var_s0 == 0) {
        var_s0 = 1;
    }
    return (s32) (guRandom() >> 2) % var_s0;
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004683C);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80046898);

s32 func_800469E0(void) {
    return D_800BE688;
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_800469EC);

INCLUDE_ASM("asm/nonmatchings/207E0", func_800479C0);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80047B34);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80047CAC);

extern s32 D_800DAEEC;
extern s32 D_800DAEF0;
extern s32 D_800DAEF4;
extern f32 D_800DAF30;
extern f32 D_800DAF34;
extern f32 D_800DAF38;

void func_80047D68(void) {
    D_800DAF30 = (f32) D_800DAEEC * 0.0009765625f;
    D_800DAF34 = (f32) D_800DAEF0 * 0.0009765625f;
    D_800DAF38 = (f32) D_800DAEF4 * 0.0009765625f;
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_80047DBC);

INCLUDE_ASM("asm/nonmatchings/207E0", func_80047E9C);

void func_800934CC(s32);
void func_80051C08(s32, s32);
s32 func_8005244C(s32, s32);
s32 func_80052220(void);
extern s8 D_801061CE;
extern s8 D_801061B8;
extern s8 D_801061C0;
extern s8 D_801061C3;
extern s32 D_801B7F70;
extern s32 D_801B7F74;
extern s32 D_800BE694;
extern f32 D_801B5530;
extern f32 D_801B5580;
extern s8 D_801B60B9;
extern s8 D_801B60C2;
extern s32 D_801B608C;
extern s32 D_801B6090;
extern s32 D_801B6098;

void func_800484F8(void) {
    func_800934CC(-1);
    D_801061CE = 1;
    D_801061B8 = -1;
    D_801061C0 = 1;
    D_801061C3 = 1;
    D_801B7F70 = 0;
    D_801B7F74 = 0;
    D_800BE694 = 0;
    D_801B5530 = 45.0f;
    D_801B5580 = 45.0f;
    if (D_801B60B9) {
        func_80051C08(0x1F, 0x11);
        return;
    }
    switch (D_801B608C) {
        case 3:
            func_80051C08(0x1A, 1);
            break;
        case 2:
        case 4:
            if (func_8005244C(0, 1)) {
                func_80051C08(0x14, 1);
            } else {
                func_80051C08(0x19, 1);
            }
            break;
        case 10:
            if (func_80052220() == D_801B6098) {
                func_80051C08(0x14, 1);
            } else {
                func_80051C08(0x2E, 1);
            }
            break;
        case 5:
            func_80051C08(0x0B, 1);
            break;
        case 7:
            func_80051C08(0x18, 1);
            break;
        case 9:
            func_80051C08(0x1D, 1);
            D_801061C0 = 0;
            D_801061C3 = 0;
            return;
        case 11:
            if (func_80052220() == D_801B6098) {
                func_80051C08(0x14, 1);
            } else {
                func_80051C08(0x2B, 1);
            }
            break;
        case 0:
        case 1:
        case 6:
        case 8:
        default:
            if (D_801B6098 == func_80052220() && D_801B6090 != 1) {
                func_80051C08(0x14, 1);
            } else if (D_801B60C2) {
                func_80051C08(0x2D, 1);
            } else {
                func_80051C08(0x1B, 1);
            }
            break;
    }
}

s32 func_800326FC(s32, s32, s32, s32);
s32 func_8004887C();
s32 func_800719A0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800BE694;
extern s8 D_801061CE;
extern s32 D_801B5534;
extern s32 D_801B5584;

void func_80048690(void) {
    D_800BE694 = 0;
    D_801061CE = 0;
    D_801B7F70 = 0;
    D_801B7F74 = 0;
    D_801B557C = 0;
    D_801B5534 = 1;
    D_801B5584 = 1;
    D_801B5530 = 80.0f;
    func_800719A0(0, 0, -1, 1, 0, 0, 0, 0, 0, 0);
    func_800719A0(0, 0, -1, 1, 1, 0, 0, 0, 0, 0);
    func_800326FC(0xA0, 0x70, 0x80, 0x80);
    func_8004887C();
}

void func_8004876C(void) {
    D_801061CE = 0;
    func_800719A0(0, 0, -1, 1, 0, 0, 0, 0, 0, 0);
    func_800719A0(0, 0, -1, 1, 1, 0, 0, 0, 0, 0);
}

s32 func_800299F4(s32 arg0);
void func_80216130(s32 arg0);
extern s32 D_800BA9F0;
extern s32 D_801B608C;
extern s8 D_801B60C2;

/* s32 with no return: implicit int (empty delay-slot pattern). */
s32 func_800487E4(void) {
    D_800BE694 = -1;
    D_801B7F70 = 0;
    D_801B7F74 = 0;
    D_801B557C = 0;
    if (D_801B608C != 7 && D_801B60C2 == 0) {
        if (func_800299F4(0x48) != 0 || D_800BA9F0 / 0x10000 >= 6) {
            func_80216130(1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004887C);

f32 func_80059FAC(f32, f32);
extern f32 D_800BE654;
extern f32 D_800DAF24;
extern f32 D_800DAF2C;

void func_80048CF8(void) {
    f32 temp_fa0;
    f32 temp_fa1;

    temp_fa0 = D_800DAF30 - D_800DAF24;
    temp_fa1 = D_800DAF38 - D_800DAF2C;
    if (((s32) temp_fa0 != 0) || ((s32) temp_fa1 != 0)) {
        D_800BE654 = (f32) (3.141592653589793 - (f64) func_80059FAC(temp_fa0, temp_fa1));
    }
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_80048D7C);

s32 func_8003E648(void);
s32 func_80045B14(s32);
s32 func_8005DE40(void);
extern s8 D_800B67C0;
extern s32 D_800BE628;
extern s32 D_800BE630;
extern s32 D_800BE63C;
extern s32 D_800BE640;
extern s32 D_800BE644;
extern s32 D_800BE64C;
extern s32 D_800BE658;
extern s32 D_800BE664;
extern s32 D_800BE674;
extern s32 D_800BE690;
extern s32 *D_800DAF4C;
extern s32 D_800DAF50;
extern u16 D_800FBDCE;
extern s32 D_80250B28;
extern s32 D_80250B2C;
extern s32 D_80250B30;

void func_8004AC04(void) {
    s32 se;
    s32 next;
    s32 t;
    u8 pad[0x38]; /* unused locals: the original frame is 0x58 */

    se = -1;
    D_800BE630 = 0;
    next = 0;
    if (D_80250B28 != 0) {
        switch (D_800DAF50) {
            case 1:
                if (!(D_800BE664 & 2) && func_800467DC(2) == 0 && func_8003E648() == 0 &&
                    D_800BE644 >= 0x1201 && D_800BE644 < 0x4B000) {
                    next = 0x13;
                    if (D_80250B30 != 0 || D_800BE63C < 0x1E00) {
                        break;
                    }
                }
                if (D_801B60C2 != 0) {
                    t = func_800467DC(10);
                    switch (t) {
                        case 0:
                        case 1:
                            next = 3;
                            break;
                        case 2:
                            next = 0xB;
                            break;
                        case 3:
                        case 4:
                            next = 0xC;
                            break;
                        default:
                            next = 0x12;
                            break;
                    }
                } else {
                    t = func_800467DC(6);
                    if (t < 3) {
                        next = 3;
                    } else if (t == 3) {
                        if ((D_800BE658 & 2) || D_80250AEC >= 0x79) {
                            next = 0xB;
                        } else {
                            next = 4;
                        }
                    } else if (t == 4) {
                        next = 0xB;
                    } else {
                        next = 0xC;
                    }
                }
                break;
            case 3:
                if (D_800BE62C != 0x12 && D_800BE62C != 0x13 && D_800BE62C != 0xB) {
                    next = 0xC;
                }
                break;
            case 6:
                if (D_800BE62C != 0x12 && D_800BE62C != 0x13) {
                    next = 0xC;
                }
                break;
            case 7:
                if (D_80250B30 == 0 && func_800467DC(2) == 0) {
                    next = 0xD;
                }
                break;
        }
    } else if (func_8005DE40() == 0) {
        switch (D_800DAF50) {
            case 1:
                t = func_80045B14(1);
                if (D_800BE64C != -1) {
                    next = 3;
                } else if (t < 4) {
                    next = 3;
                } else if (t == 4) {
                    if (D_800BE640 > 0xBB7FF) {
                        next = 3;
                    } else {
                        next = 5;
                    }
                } else if (t == 5) {
                    if (D_800BE690 != 1 || D_80250AEC < 0x3D) {
                        next = 3;
                    } else {
                        next = 4;
                    }
                } else if (t == 6) {
                    if (D_800BE640 <= 0xBB7FF) {
                        next = 0xC;
                    } else {
                        next = 0xA;
                    }
                } else if (t == 7) {
                    if (D_800BE640 <= 0xBB7FF) {
                        next = 0xC;
                    } else {
                        next = 6;
                    }
                } else if (t == 8) {
                    next = 0xA;
                } else if (t == 9) {
                    next = 3;
                    if (D_800BE640 > 0x4B000) {
                        next = (D_80250AEC >= 0x10) ? 7 : 3;
                    }
                }
                break;
            case 2:
                if (D_800BE62C == 7) {
                    se = 3;
                    next = 0xA;
                } else if (D_800BE62C == 3) {
                    if (func_800467DC(3) == 0) {
                        next = 0xA;
                    }
                    if (D_800BE640 > 0x1C1FFF && func_800467DC(4) == 0) {
                        next = 9;
                    }
                } else if (D_800BE62C == 4) {
                    if (D_80250AEC < 0x78) {
                        next = 0xA;
                    } else if (D_80250B2C != 0) {
                        next = 0xB;
                    } else if (D_800BE640 > 0x1C1FFF) {
                        next = (func_800467DC(4) == 0) ? 9 : 0xA;
                    } else {
                        next = 0xA;
                    }
                }
                break;
            case 3:
                if (D_800BE62C == 4) {
                    if (D_80250AEC < 0x78) {
                        next = 0xA;
                    } else if (D_80250B2C != 0) {
                        next = 0xA;
                    }
                } else {
                    if (D_800BE62C == 6) {
                        break;
                    }
                    if (D_800BE62C == 9) {
                        break;
                    }
                    if (D_800BE62C == 10) {
                        break;
                    }
                    switch (func_800467DC(5)) {
                                case 0:
                                    next = 0xA;
                                    break;
                                case 1:
                                    next = 0xA;
                                    break;
                                case 2:
                                    next = 0xC;
                                    break;
                            }
                }
                break;
            case 4:
                if (D_800BE674 != 0) {
                    D_800BE630 = 1;
                } else {
                    switch (D_800BE62C) {
                        case 6:
                        case 9:
                            break;
                        default:
                            if (D_800BE63C <= 0xBB7FF) {
                        if (func_800467DC(2) == 0) {
                            next = 0xC;
                        }
                    } else if (func_800467DC(8) == 0) {
                        next = 0xC;
                        se = 3;
                    } else if (func_800467DC(8) < 4) {
                        next = 0xC;
                    }
                            break;
                    }
                }
                break;
            case 5:
                t = *D_800DAF4C;
                if ((t == 6 || t == 7) || (t == 8 || t == 10) || t == 13) {
                    next = 0xC;
                    break;
                }
                if (D_800BE62C == 9) {
                    next = 0xC;
                    break;
                }
                next = 0xC;
                t = next; /* dead store: keeps the original's empty beq/j shape */
                break;
            case 6:
                if (D_800BE674 == 0) {
                    next = 0xC;
                } else {
                    D_800BE630 = 1;
                }
                break;
            case 7:
                t = *D_800DAF4C;
                if ((t == 6 || t == 7) || (t == 8 || t == 10) || t == 13 || D_80250B30 != 0) {
                    break;
                }
                if (D_800BE674 != 0 || D_80250AEC < 0x15) {
                    D_800BE630 = 1;
                } else if (D_800BE63C <= 0xBB7FF) {
                    next = 0xD;
                } else if (D_800BE62C == 0xC) {
                    next = 0xD;
                }
                break;
        }
    } else {
        switch (D_800DAF50) {
            case 5:
                next = 0xC;
                D_800BE630 = 1;
                break;
            case 6:
                break;
            case 1:
                t = func_800467DC(9);
                switch (t) {
                    case 0:
                    case 1:
                    case 2:
                        next = 3;
                        break;
                    case 3:
                    case 4:
                    case 5:
                        if (D_800BE640 <= 0xBB7FF) {
                            next = 0xC;
                        } else {
                            next = 3;
                        }
                        break;
                    case 6:
                        next = 3;
                        if (D_800BE690 == 1 && D_80250AEC >= 0x3D) {
                            next = 4;
                        }
                        break;
                    case 7:
                        next = 0xA;
                        break;
                    case 8:
                        next = 0xC;
                        break;
                }
                D_800BE630 = 1;
                break;
        }
    }
    if (D_800BE62C < next) {
        D_800BE628 = 1;
        func_8009226C(-1);
        if (se == -1) {
            if (D_800DAF50 >= 4 && D_80250B28 == 0 && D_800BE640 > 0xBB7FF) if (next == 0xC) {
                if (func_800467DC(0x10) == 0 && D_800BE62C == 0xA) {
                    func_8009226C(3);
                } else if (func_800467DC(8) == 0) {
                    func_8009226C(1);
                } else if (func_800467DC(3) == 0) {
                    func_8009226C(9);
                }
            }
        } else if (D_800BE640 > 0xBB7FF) {
            func_8009226C(se);
        }
        D_800BE62C = next;
        D_800BE674 = 0x14;
    }
    if (D_800B67C0 != 0) {
        if (D_800FBDCE & 0x4000) {
            D_800BE62C = 4;
        }
        if (D_800FBDCE & 0x8000) {
            D_800BE62C = 5;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004B474);

void func_8004C510(s32 arg0) {
    D_800BE68C = arg0;
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004C51C);

void func_8004C6A8(void) {
}

void func_8004C6B0(void) {
}

void func_8004C6B8(void) {
}

/* Fills a 32x32 byte mask with a radial falloff from (32, 32); mode 0 is a ring,
 * otherwise a disc that fades out past radius 15. */
void func_8004C6C0(u8 *buf, s32 mode) {
    s32 i = 0;
    s32 w = 32, h = 32, m = 31;
    s32 x, y, d, v, k;
    f32 dist;

    if (mode == 0) {
        for (y = 0; y != h; y++) {
            for (x = 0; x != w; x++) {
                s32 dy = y - h;
                s32 dx = x - w;
                d = sqrtf((f32)(dy * dy + dx * dx));
                if (d < 17) {
                    v = 210;
                } else if (d < 25) {
                    v = 210 - (d - 16) * 26;
                } else if (d < 32) {
                    v = (d - 24) * 16;
                } else {
                    v = 0;
                }
                buf[i++] = v;
            }
        }
    } else {
        for (y = 0, k = 15; y != h; y++) {
            for (x = 0; x != w; x++) {
                s32 dy = y - h;
                s32 dx = x - w;
                dist = sqrtf((f32)(dy * dy + dx * dx));
                if ((s32)dist <= k) {
                    v = 210;
                } else if ((s32)dist <= m) {
                    v = 210 - (s32)(dist - k) * 12;
                } else {
                    v = 0;
                }
                buf[i++] = v;
            }
        }
    }
}

/* Fills a w*h byte mask with a radial ring falloff centred on (w, h). */
void func_8004C860(u8 *buf, s32 w, s32 h) {
    s32 x, y, d, v, i = 0;
    f32 dist;

    for (y = 0; y != h; y++) {
        for (x = 0; x != w; x++) {
            s32 dy = y - h;
            s32 dx = x - w;
            dist = sqrtf((f32)(dy * dy + dx * dx));
            d = dist;
            if (d < 5) {
                v = 0;
            } else if (d < 55) {
                v = (s32)(dist - 5.0f) * 5 + 10;
            } else if (d < 62) {
                v = 255 - (s32)(dist - 55.0f) * 36;
            } else {
                v = 0;
            }
            buf[i++] = v;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004C958);

INCLUDE_ASM("asm/nonmatchings/207E0", func_8004CDA0);

void func_8004D148(void) {
    s32 i;

    D_800BE6D8 = 1;
    for (i = 0; i < 0x40; i++) {
        func_8004CDA0();
    }
}
