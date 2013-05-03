#include "hex2_global.h"
#include "hexDLL_global.hpp"
#include "hexDB_app.h"
#include "hexDB_hack.h"
#include "hexDB_hexIO.h"
#include "hexG_db.h"
#ifndef HEXDB_MAIN_H
#define HEXDB_MAIN_H

#define GETHEX( m_val, m_bits, m_movebits ) ( ( m_val & ( m_bits << m_movebits ) ) >> m_movebits )
#define xsF8LL 0xFFFFFFFFLL

xsC_START

void	xsDLL ListApps( hexDB& db );

xsC_END

#endif // HEXDB_MAIN_H
