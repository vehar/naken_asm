/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2016 by Michael Kohn
 *
 */

#include <stdlib.h>

#include "table/ps2_ee_vu.h"

struct _table_ps2_ee_vu table_ps2_ee_vu_upper[] =
{
  { "abs", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x000001fd, 0x060007ff, FLAG_DEST },
  { "add", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000028, 0x0600003f, FLAG_DEST },
  { "addi", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x00000022, 0x061f003f, FLAG_DEST },
  { "addq", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x00000020, 0x061f003f, FLAG_DEST },
  { "addx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000000, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "addy", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000001, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "addz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000002, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "addw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000003, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "adda", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000002bc, 0x060007ff, FLAG_DEST },
  { "addai", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000023e, 0x061f07ff, FLAG_DEST },
  { "addaq", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x0000023c, 0x061f07ff, FLAG_DEST },
  { "addax", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000003c, 0x060007ff, FLAG_DEST },
  { "adday", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000003d, 0x060007ff, FLAG_DEST },
  { "addaz", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000003e, 0x060007ff, FLAG_DEST },
  { "addaw", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000003f, 0x060007ff, FLAG_DEST },
  { "clipw", { EE_VU_OP_FS, EE_VU_OP_FT, EE_VU_OP_NONE }, 2, 0x000001ff, 0x060003ff, FLAG_DEST | FLAG_XYZ },
  { "ftoi0", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000017c, 0x060003ff, FLAG_DEST },
  { "ftoi4", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000017d, 0x060003ff, FLAG_DEST },
  { "ftoi12", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000017e, 0x060003ff, FLAG_DEST },
  { "ftoi15", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000017f, 0x060003ff, FLAG_DEST },
  { "itof0", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000013c, 0x060003ff, FLAG_DEST },
  { "itof4", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000013d, 0x060003ff, FLAG_DEST },
  { "itof12", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000013e, 0x060003ff, FLAG_DEST },
  { "itof15", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x0000013f, 0x060003ff, FLAG_DEST },
  { "madd", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000029, 0x0600003f, FLAG_DEST },
  { "maddi", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x00000023, 0x061f003f, FLAG_DEST },
  { "maddq", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x00000021, 0x061f003f, FLAG_DEST },
  { "maddx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000008, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maddy", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000009, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maddz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000a, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maddw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000b, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "madda", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000002bd, 0x060007ff, FLAG_DEST },
  { "maddai", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000023f, 0x061f07ff, FLAG_DEST },
  { "maddaq", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x0000023d, 0x061f07ff, FLAG_DEST },
  { "maddax", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000bc, 0x060007ff, FLAG_DEST },
  { "madday", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000bd, 0x060007ff, FLAG_DEST },
  { "maddaz", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000be, 0x060007ff, FLAG_DEST },
  { "maddaw", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000bf, 0x060007ff, FLAG_DEST },
  { "max", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002b, 0x0600003f, FLAG_DEST },
  { "maxi", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000001d, 0x061f003f, FLAG_DEST },
  { "maxx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000010, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maxy", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000011, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maxz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000012, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "maxw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000013, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "mini", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002f, 0x0600003f, FLAG_DEST },
  { "minii", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000001f, 0x061f003f, FLAG_DEST },
  { "minix", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000014, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "miniy", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000015, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "miniz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000016, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "miniw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000017, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "msub", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002d, 0x0600003f, FLAG_DEST },
  { "msubi", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x00000027, 0x061f003f, FLAG_DEST },
  { "msubq", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x00000025, 0x061f003f, FLAG_DEST },
  { "msubx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000c, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "msuby", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000d, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "msubz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000e, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "msubw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000000f, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "msuba", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000002fd, 0x060007ff, FLAG_DEST },
  { "msubai", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000027f, 0x061f07ff, FLAG_DEST },
  { "msubaq", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x0000027d, 0x061f07ff, FLAG_DEST },
  { "msubax", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000fc, 0x060007ff, FLAG_DEST },
  { "msubay", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000fd, 0x060007ff, FLAG_DEST },
  { "msubaz", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000fe, 0x060007ff, FLAG_DEST },
  { "msubaw", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000000ff, 0x060007ff, FLAG_DEST },
  { "mul", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002a, 0x0600003f, FLAG_DEST },
  { "muli", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000001e, 0x061f003f, FLAG_DEST },
  { "mulq", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x0000001c, 0x061f003f, FLAG_DEST },
  { "mulx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000018, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "muly", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000019, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "mulz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000001a, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "mulw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000001b, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "mula", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000002be, 0x060007ff, FLAG_DEST },
  { "mulai", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x000001fe, 0x061f07ff, FLAG_DEST },
  { "mulaq", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x000001fc, 0x061f07ff, FLAG_DEST },
  { "mulax", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000001bc, 0x060007ff, FLAG_DEST },
  { "mulay", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000001bd, 0x060007ff, FLAG_DEST },
  { "mulaz", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000001be, 0x060007ff, FLAG_DEST },
  { "mulaw", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000001bf, 0x060007ff, FLAG_DEST },
  { "nop", { EE_VU_OP_NONE, EE_VU_OP_NONE, EE_VU_OP_NONE }, 0, 0x000002ff, 0x07ffffff, FLAG_NONE },
  { "opmula", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x01c002fe, 0x07e007ff, FLAG_DEST | FLAG_XYZ },
  { "opmsub", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002e, 0x07e0003f, FLAG_DEST | FLAG_XYZ },
  { "sub", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000002c, 0x0600003f, FLAG_DEST },
  { "subi", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x00000026, 0x061f003f, FLAG_DEST },
  { "subq", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x00000024, 0x061f003f, FLAG_DEST },
  { "subx", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000004, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "suby", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000005, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "subz", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000006, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "subw", { EE_VU_OP_FD, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x00000007, 0x0600003f, FLAG_DEST | FLAG_BC },
  { "suba", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x000002fc, 0x060007ff, FLAG_DEST },
  { "subai", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_I }, 3, 0x0000027e, 0x061f07ff, FLAG_DEST },
  { "subaq", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_Q }, 3, 0x0000027c, 0x061f07ff, FLAG_DEST },
  { "subax", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000007c, 0x060007ff, FLAG_DEST },
  { "subay", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000007d, 0x060007ff, FLAG_DEST },
  { "subaz", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000007e, 0x060007ff, FLAG_DEST },
  { "subaw", { EE_VU_OP_ACC, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x0000007f, 0x060007ff, FLAG_DEST },
  { NULL, { 0, 0, 0 }, 0, 0, 0, 0 }
};

struct _table_ps2_ee_vu table_ps2_ee_vu_lower[] =
{
  { "b", { EE_VU_OP_OFFSET, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x40000000, 0xfffff800, FLAG_NONE },
  { "bal", { EE_VU_OP_VIT, EE_VU_OP_OFFSET, EE_VU_OP_NONE }, 2, 0x42000000, 0xfffff800, FLAG_NONE },
  { "div", { EE_VU_OP_Q, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x800003bc, 0xfe0007ff, FLAG_TE | FLAG_SE },
  { "eatan", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007fd, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "eatanxy", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8180077c, 0xffff07ff, FLAG_VU1_ONLY },
  { "eatanxz", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8140077d, 0xffff07ff, FLAG_VU1_ONLY },
  { "eexp", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007fe, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "eleng", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x81c0073e, 0xffff07ff, FLAG_VU1_ONLY },
  { "ercpr", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007be, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "erleng", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x81c0073f, 0xffff07ff, FLAG_VU1_ONLY },
  { "ersadd", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x81c0073d, 0xffff07ff, FLAG_VU1_ONLY },
  { "ersqrt", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007bd, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "esadd", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x81c0073c, 0xffff07ff, FLAG_VU1_ONLY },
  { "esin", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007fc, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "esqrt", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800007bc, 0xff9f07ff, FLAG_SE | FLAG_VU1_ONLY },
  { "esum", { EE_VU_OP_P, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x81e0077e, 0xffff07ff, FLAG_VU1_ONLY },
  { "fcand", { EE_VU_OP_VI01, EE_VU_OP_IMMEDIATE24, EE_VU_OP_NONE }, 2, 0x24000000, 0xff000000, FLAG_NONE },
  { "fceq", { EE_VU_OP_VI01, EE_VU_OP_IMMEDIATE24, EE_VU_OP_NONE }, 2, 0x20000000, 0xff000000, FLAG_NONE },
  { "fcget", { EE_VU_OP_VIT, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x38000000, 0xffe0ffff, FLAG_NONE },
  { "fcor", { EE_VU_OP_VI01, EE_VU_OP_IMMEDIATE24, EE_VU_OP_NONE }, 2, 0x26000000, 0xff000000, FLAG_NONE },
  { "fcset", { EE_VU_OP_IMMEDIATE24, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x22000000, 0xff000000, FLAG_NONE },
  { "fmand", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_NONE }, 2, 0x34000000, 0xffe007ff, FLAG_NONE },
  { "fmeq", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_NONE }, 2, 0x30000000, 0xffe007ff, FLAG_NONE },
  { "fmor", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_NONE }, 2, 0x36000000, 0xffe007ff, FLAG_NONE },
  { "fsand", { EE_VU_OP_VIT, EE_VU_OP_IMMEDIATE12, EE_VU_OP_NONE }, 2, 0x2c000000, 0xffc0f800, FLAG_NONE },
  { "fseq", { EE_VU_OP_VIT, EE_VU_OP_IMMEDIATE12, EE_VU_OP_NONE }, 2, 0x28000000, 0xffc0f800, FLAG_NONE },
  { "fsor", { EE_VU_OP_VIT, EE_VU_OP_IMMEDIATE12, EE_VU_OP_NONE }, 2, 0x2e000000, 0xffc0f800, FLAG_NONE },
  { "fsset", { EE_VU_OP_IMMEDIATE12, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x2a000000, 0xffdff800, FLAG_NONE },
  { "iadd", { EE_VU_OP_VID, EE_VU_OP_VIS, EE_VU_OP_VIT }, 3, 0x80000030, 0xffe0003f, FLAG_NONE },
  { "iaddi", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_IMMEDIATE5 }, 3, 0x80000032, 0xffe0003f, FLAG_NONE },
  { "iaddiu", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_IMMEDIATE15 }, 3, 0x10000000, 0xfe000000, FLAG_NONE },
  { "iand", { EE_VU_OP_VID, EE_VU_OP_VIS, EE_VU_OP_VIT }, 3, 0x80000034, 0xffe0003f, FLAG_NONE },
  { "ibeq", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_OFFSET }, 3, 0x50000000, 0xffe00000, FLAG_NONE },
  { "ibgez", { EE_VU_OP_VIS, EE_VU_OP_OFFSET, EE_VU_OP_NONE }, 2, 0x5e000000, 0xffff0000, FLAG_NONE },
  { "ibgtz", { EE_VU_OP_VIS, EE_VU_OP_OFFSET, EE_VU_OP_NONE }, 2, 0x5a000000, 0xffff0000, FLAG_NONE },
  { "iblez", { EE_VU_OP_VIS, EE_VU_OP_OFFSET, EE_VU_OP_NONE }, 2, 0x5c000000, 0xffff0000, FLAG_NONE },
  { "ibne", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_OFFSET }, 3, 0x52000000, 0xffe00000, FLAG_NONE },
  { "ilw", { EE_VU_OP_VIT, EE_VU_OP_OFFSET_BASE, EE_VU_OP_NONE }, 2, 0x08000000, 0xfe000000, FLAG_DEST },
  { "ilwr", { EE_VU_OP_VIT, EE_VU_OP_BASE, EE_VU_OP_NONE }, 2, 0x800003fe, 0xfe0007ff, FLAG_DEST },
  { "ior", { EE_VU_OP_VID, EE_VU_OP_VIS, EE_VU_OP_VIT }, 3, 0x80000035, 0xffe0003f, FLAG_NONE },
  { "isub", { EE_VU_OP_VID, EE_VU_OP_VIS, EE_VU_OP_VIT }, 3, 0x80000031, 0xffe0003f, FLAG_NONE },
  { "isubiu", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_IMMEDIATE15 }, 3, 0x12000000, 0xfe000000, FLAG_NONE },
  { "isw", { EE_VU_OP_VIT, EE_VU_OP_OFFSET_BASE, EE_VU_OP_NONE }, 2, 0x0a000000, 0xfe000000, FLAG_DEST },
  { "iswr", { EE_VU_OP_VIT, EE_VU_OP_BASE, EE_VU_OP_NONE }, 2, 0x800003ff, 0xfe0007ff, FLAG_DEST },
  { "jalr", { EE_VU_OP_VIT, EE_VU_OP_VIS, EE_VU_OP_NONE }, 2, 0x4a000000, 0xffe007ff, FLAG_NONE },
  { "jr", { EE_VU_OP_VIS, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x48000000, 0xffff07ff, FLAG_NONE },
  { "lq", { EE_VU_OP_FT, EE_VU_OP_OFFSET_BASE, EE_VU_OP_NONE }, 2, 0x00000000, 0xfe000000, FLAG_DEST },
  { "lqd", { EE_VU_OP_FT, EE_VU_OP_BASE_DEC, EE_VU_OP_NONE }, 2, 0x8000037e, 0xfe0007ff, FLAG_DEST },
  { "lqi", { EE_VU_OP_FT, EE_VU_OP_BASE_INC, EE_VU_OP_NONE }, 2, 0x8000037c, 0xfe0007ff, FLAG_DEST },
  { "mfir", { EE_VU_OP_FT, EE_VU_OP_VIS, EE_VU_OP_NONE }, 2, 0x800003fd, 0xfe0007ff, FLAG_DEST },
  { "mfp", { EE_VU_OP_FT, EE_VU_OP_P, EE_VU_OP_NONE }, 2, 0x8000067c, 0xfe0007ff, FLAG_DEST },
  { "nop", { EE_VU_OP_NONE, EE_VU_OP_NONE, EE_VU_OP_NONE }, 0, 0x8000033c, 0xffffffff, FLAG_NONE }, // This is move vf0, vf0
  { "move", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8000033c, 0xfe0007ff, FLAG_DEST },
  { "mr32", { EE_VU_OP_FT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8000033d, 0xfe0007ff, FLAG_DEST },
  { "mtir", { EE_VU_OP_VIT, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x800003fc, 0xff8007ff, FLAG_SE },
  { "rget", { EE_VU_OP_FT, EE_VU_OP_R, EE_VU_OP_NONE }, 2, 0x8000043d, 0xfe00ffff, FLAG_DEST },
  { "rinit", { EE_VU_OP_R, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8000043e, 0xff9f07ff, FLAG_SE },
  { "rnext", { EE_VU_OP_FT, EE_VU_OP_R, EE_VU_OP_NONE }, 2, 0x8000043c, 0xfe00ffff, FLAG_DEST },
  { "rsqrt", { EE_VU_OP_Q, EE_VU_OP_FS, EE_VU_OP_FT }, 3, 0x800003be, 0xfe0007ff, FLAG_TE | FLAG_SE },
  { "rxor", { EE_VU_OP_R, EE_VU_OP_FS, EE_VU_OP_NONE }, 2, 0x8000043f, 0xff9f07ff, FLAG_SE },
  { "sq", { EE_VU_OP_FS, EE_VU_OP_OFFSET_BASE, EE_VU_OP_NONE }, 2, 0x02000000, 0xfe000000, FLAG_DEST },
  { "sqd", { EE_VU_OP_FS, EE_VU_OP_BASE_DEC, EE_VU_OP_NONE }, 2, 0x8000037f, 0xfe0007ff, FLAG_DEST },
  { "sqi", { EE_VU_OP_FS, EE_VU_OP_BASE_INC, EE_VU_OP_NONE }, 2, 0x8000037d, 0xfe0007ff, FLAG_DEST },
  { "sqrt", { EE_VU_OP_Q, EE_VU_OP_FT, EE_VU_OP_NONE }, 2, 0x800003bd, 0xfe60ffff, FLAG_TE },
  { "waitp", { EE_VU_OP_NONE, EE_VU_OP_NONE, EE_VU_OP_NONE }, 0, 0x800007bf, 0xffffffff, FLAG_NONE },
  { "waitq", { EE_VU_OP_NONE, EE_VU_OP_NONE, EE_VU_OP_NONE }, 0, 0x800003bf, 0xffffffff, FLAG_NONE },
  { "xgkick", { EE_VU_OP_VIS, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x800006fc, 0xffff07ff, FLAG_VU1_ONLY },
  { "xitop", { EE_VU_OP_VIT, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x800006bd, 0xffe0ffff, FLAG_VU1_ONLY },
  { "xtop", { EE_VU_OP_VIT, EE_VU_OP_NONE, EE_VU_OP_NONE }, 1, 0x800006bc, 0xffe0ffff, FLAG_VU1_ONLY },
  { NULL, { 0, 0, 0 }, 0, 0, 0, 0 }
};

