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
void	xsDLL LoadCodes_Hex1( Codes& data, TxtF& file );
void	xsDLL SaveCodes_Hex1( Codes& data, TxtF& file );
void	xsDLL MakeTxt_Hex1( Codes& data, TxtA& block );
void	xsDLL MakeObj_Hex1( Codes& data, TxtA& block, int& l, int& lEnd, int& c, int& cEnd );

xsC_END

#endif // HEXDB_MAIN_H
