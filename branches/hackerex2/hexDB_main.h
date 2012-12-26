#ifndef HEXDB_MAIN_H
#define HEXDB_MAIN_H
#include "hex2_global.h"
#include "hexDLL_global.hpp"
#include "hexDB_app.h"
#include "hexDB_hack.h"
#include "hexDB_hexIO.h"

const ui08 g_hckUse	= 0x1;
const ui08 g_hckRad	= 0x2;
const ui64 g_use	= 0xFLL << 44u;
const ui64 g_parent	= 0xFFFFLL;
const ui64 g_cCount	= 0xFFLL << 16u;
const ui64 g_hackID	= g_parent << 32u;

xsC_START

Codes xsDLL LoadHacks_Hex( Codes& codes, TxtF& file, TxtF& temp, Hacks& hacks, int version = 0 );

xsC_END

#endif // HEXDB_MAIN_H
