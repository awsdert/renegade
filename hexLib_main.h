#include "hexLib.h"
#include "hexLib_enum.h"
#include "hexLib_gui.h"

#ifndef hexLib_main_h
#define hexLib_main_h

#define GETHEX( m_val, m_bits, m_movebits ) ( ( m_val & ( m_bits << m_movebits ) ) >> m_movebits )
#define xsF8LL 0xFFFFFFFFLL

zxC_EXT void hexLibDLL ListApps( hexLib& lib );

#endif
