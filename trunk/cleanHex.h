#ifndef CLEANHEX_H_
#define CLEANHEX_H_
#include "cleanType.h"
u64 GetHex( wxString text, u8 size = 0u );
u64 GetHexFromS64( wxString text, u8 size = 0u );
u64 GetHexFromU64( wxString text, u8 size = 0u );
u64 GetHexFromF64( wxString text, u8 size = 0u );
#endif
