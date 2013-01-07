#ifndef HEXDB_HEXIO_H
#define HEXDB_HEXIO_H
#include "hex2_global.h"
// Hex Grabbing
// Hex Types, DO NOT MODIFY ORDER
enum
{
	HEX_TYPE_HEX = 0,
	HEX_TYPE_UI,
	HEX_TYPE_SI,
	HEX_TYPE_SF_IEEE754,
	HEX_TYPE_TEXT,
	HEX_TYPE_WTEXT,
	HEX_TYPE_COUNT
};

// Added for completeness, used for Hacking Codes at the very least
#define HEX_IS_EQ 0x1
#define HEX_IS_NE 0x10

// Greater / Less Than or Equal to
#define HEX_IS_GT 0x2
#define HEX_IS_GE 0x20
#define HEX_IS_LT 0x4
#define HEX_IS_LE 0x40

// Does Contain
#define HEX_IS_DC 0x8

// Not Containing
#define HEX_IS_NC 0x80

xsC_START

bool xsDLL GetHex( void* to, Text  from, ui08 tSize	= 1u, ui08 tType = HEX_TYPE_HEX );
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize = 1u );
bool xsDLL GetHexFromSI( void* to, Text  from, ui08 tSize = 1u );
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize = 1u );
bool xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize = 1u );
// Bool is for Equal (true) / not equal (false), result is 0x0 plus above
bool xsDLL CmpHex( void* compare, void* to, ui08& result, ui08 cSize = 1u, ui08 tSize = 1u, ui08 cType = HEX_TYPE_SF_IEEE754, ui08 tType = HEX_TYPE_SF_IEEE754 );

xsC_END

#endif // HEXDB_HEXIO_H
