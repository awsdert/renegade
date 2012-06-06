#include "cleanType.h"
u8    lQATest[ QA_COUNT ];
u8    lQVTest[ QV_COUNT ];
xAStr lValMode;
u8*   gGetQATest(   void ) { return lQATest; }
u8*   gGetQVTest(   void ) { return lQVTest; }
xAStr gGetValModes( void ) { return lValMode; }
u64   gGetValue( xStr text, u8 mode, u8 size )
{
	u64 value = 0u;
	switch ( mode )
	{
		case VAL_HEX: value  = GetHex( text, size ); break;
		case VAL_UINT: value = GetHexFromU64( text, size ); break;
		case VAL_SINT: value = GetHexFromS64( text, size ); break;
		case VAL_SFLT: value = GetHexFromF64( text, size ); break;
	}
	return value;
}
void gSetQTests( void )
{
	// DO NOT MODIFY
	// Address
	lQATest[ QA_MT  ] = gTMoreT;
	lQATest[ QA_MTE ] = gTMoreE;
	lQATest[ QA_LT  ] = gTLessT;
	lQATest[ QA_LTE ] = gTLessE;
	// Value
	lQVTest[ QV_EQUAL   ] = gTEqual;
	lQVTest[ QV_NOT     ] = gTNotE;
	lQVTest[ QV_MT      ] = gTMoreT;
	lQVTest[ QV_MTE     ] = gTMoreE;
	lQVTest[ QV_LT      ] = gTLessT;
	lQVTest[ QV_LTE     ] = gTLessE;
	lQVTest[ QV_GOT     ] = gTGot;
	lQVTest[ QV_NOT_GOT ] = gTNotG;
	// Value Mode
	lValMode.SetCount( VAL_COUNT );
	lValMode[ VAL_HEX  ] = wxT( "Hexadecimal" );
	lValMode[ VAL_SINT ] = wxT( "Signed Integer" );
	lValMode[ VAL_UINT ] = wxT( "Unsigned Integer" );
	lValMode[ VAL_SFLT ] = wxT( "Signed Float" );
}
