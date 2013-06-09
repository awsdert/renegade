#include "hexObjs_main.h"

#ifndef hexFmt_base_h
#define hexFmt_base_h

zxDLL_EXP const Pfm getPfm( void );
zxDLL_EXP Text getName( LANG_TYPE lang );
zxDLL_EXP void getHacks( TxtF *file, Hacks &hacks, Text tmpDir );
// This should just return if the Hack data is needed
zxDLL_EXP void getCode( Code &obj, TxtA& block );

#endif