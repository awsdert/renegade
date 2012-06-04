#include "cleanType.h"
u8    gQATest[ QA_COUNT ];
u8    gQVTest[ QV_COUNT ];
xAStr gValMode;
u8*   gGetQATest(   void ) { return gQATest; }
u8*   gGetQVTest(   void ) { return gQVTest; }
xAStr gGetValModes( void ) { return gValMode; }
u64   gGetValue( xStr text, u8 mode, u8 size )
{
	u64 value = 0u;
	switch ( mode )
	{
		case VAL_HEX: value = GetHex( text, size ); break;
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
	gQATest[ QA_MT  ] = gTMoreT;
	gQATest[ QA_MTE ] = gTMoreE;
	gQATest[ QA_LT  ] = gTLessT;
	gQATest[ QA_LTE ] = gTLessE;
	// Value
	gQVTest[ QV_EQUAL   ] = gTEqual;
	gQVTest[ QV_NOT     ] = gTNotE;
	gQVTest[ QV_MT      ] = gTMoreT;
	gQVTest[ QV_MTE     ] = gTMoreE;
	gQVTest[ QV_LT      ] = gTLessT;
	gQVTest[ QV_LTE     ] = gTLessE;
	gQVTest[ QV_GOT     ] = gTGot;
	gQVTest[ QV_NOT_GOT ] = gTNotG;
	// Value Mode
	gValMode.SetCount( VAL_COUNT );
	gValMode[ VAL_HEX  ] = wxT( "Hexadecimal" );
	gValMode[ VAL_SINT ] = wxT( "Signed Integer" );
	gValMode[ VAL_UINT ] = wxT( "Unsigned Integer" );
	gValMode[ VAL_SFLT ] = wxT( "Signed Float" );
}
