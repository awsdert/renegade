#ifndef HEXDB_MAIN_H
#define HEXDB_MAIN_H
#include "hex2_global.h"
#include "hexDLL_global.hpp"
#include "hexDB_app.h"
#include "hexDB_hack.h"
#include "hexDB_hexIO.h"
#include "hexG_db.h"

#define GETHEX( m_val, m_bits, m_movebits ) ( ( m_val & ( m_bits << m_movebits ) ) >> m_movebits )
#define xsF8LL 0xFFFFFFFFLL

xsC_START

void	xsDLL ListApps( hexDB& db );
Codes	xsDLL LoadHacks( Codes& old, TxtF& file, TxtF& temp, Hacks& data, ui16 pid, bool addObj, int format );
Codes	xsDLL LoadHacks_Hex( Codes& old, TxtF& file, TxtF& temp, Hacks& data, bool addObj, int version );
void	xsDLL LoadHack_Hex( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
void	xsDLL SaveHack_Hex( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
void	xsDLL MakeTxt_Hex1( Codes& data, TxtA& block );
void	xsDLL Maketxt_Hex1( Code& obj,	 TxtA& block );
void	xsDLL MakeObj_Hex1( Codes& data, TxtA& block );

xsC_END

#endif // HEXDB_MAIN_H
