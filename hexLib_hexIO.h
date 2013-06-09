#include "hexLib_base.h"
#ifndef hexLib_hexIO_h
#define hexLib_hexIO_h
// Hex Grabbing
// Hex Types, DO NOT MODIFY ORDER
enum
{
	VAL_HEX = 0,
	VAL_UI,
	VAL_SI,
	VAL_SF_IEEE754,
	VAL_TEXT,
	VAL_WTEXT,
	VAL_UTF8,
	VAL_BIN,
	VAL_COUNT
};

// Added for completeness, used for Hacking Codes at the very least
#define HEX_IS_EQ 0x1
#define HEX_IS_NE 0x10

#define HEX_VT_EQ 0u
#define HEX_VT_NE 1u

// Greater / Less Than or Equal to
#define HEX_IS_GT 0x2
#define HEX_IS_GE 0x20
#define HEX_IS_LT 0x4
#define HEX_IS_LE 0x40

#define HEX_VT_GT 2u
#define HEX_VT_GE 3u
#define HEX_VT_LT 4u
#define HEX_VT_LE 5u

#define HEX_AT_GT 0u
#define HEX_AT_GE 1u
#define HEX_AT_LT 2u
#define HEX_AT_LE 3u

// Range from v to i
#define HEX_IS_RT 0x6
#define HEX_IS_RE 0x60

#define HEX_VT_RT 8u
#define HEX_VT_RE 9u

// Does Contain
#define HEX_IS_DC 0x8
#define HEX_VT_DC 6u

// Not Containing
#define HEX_IS_NC 0x80
#define HEX_VT_NC 7u

#define HEX_VT_COUNT 10u
#define HEX_AT_COUNT 4u
#define HEX_QT_COUNT 8u

hexLibDLL bool GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize = 1u );
hexLibDLL Text GetTxtFromSF_IEEE754( void* from, ui08 fSize = 1u );


#endif // HEXDB_HEXIO_H
