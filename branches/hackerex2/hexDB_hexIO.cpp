#include "hexDB_hexIO.hpp"
bool xsDLL GetHex( void* to, Text  from, ui08 tSize, ui08 tType )
{
	switch ( tType )
	{
	case HEX_TYPE_UI: return GetHexFromUI( to, from, tSize );
	case HEX_TYPE_SI: return GetHexFromSI( to, from, tSize );
	case HEX_TYPE_SF_IEEE754:
		return GetHexFromSF_IEEE754( to, from, tSize );
	}
	ui08* data = reinterpret_cast< ui08* >( to );
	for ( ui08 i = 0u; i < tSize; ++i )
		data[ i ] = 0u;
	return false;
}
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetHexFromSI( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) { return false; }
