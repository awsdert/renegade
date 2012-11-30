#ifndef HEXDB_MAIN_H
#define HEXDB_MAIN_H
#include "hexGUI_global.hpp"
#include "hexDLL_global.hpp"
#include "hexDB_hack.hpp"
#include "hexDB_hexIO.hpp"

const ui08 g_hckUse	= 0x1;
const ui08 g_hckRad	= 0x2;
const ui64 g_use	= 0xFLL << 44u;
const ui64 g_parent	= 0xFFFFLL;
const ui64 g_cCount	= 0xFFLL << 16u;
const ui64 g_hackID	= g_parent << 32u;

xsC_START

bool xsDLL LoadHckT_Hex( TxtF& file, ui08 version );
bool xsDLL MakeHack_Hex_1( Hack& hack, TxtA& block, int& codeIndex, ui32& lineIndex );
bool xsDLL MakeHack_Hex_2( Hack& hack, TxtA& block, int& codeIndex, ui32& lineIndex, ui08& cCount );

xsC_END

#endif // HEXDB_MAIN_H
