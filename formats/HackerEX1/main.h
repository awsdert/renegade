#include "../../hexFmt_base.h"

#ifndef HACKEREX1_main_h
#define HACKEREX1_main_h

// This setup is probably going to be the most common
void	fmtLoadHack( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
void	fmtSaveHack( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
// Here l stands for line but I used that word for the textual format so l was chosen instead
void	fmtGetCode( Code& obj, TxtA& block, int& l, int& lEnd );
void	fmtGetCodes( Codes& data, TxtA& block );
TxtA	fmtGetCodes( Codes& data );

#endif