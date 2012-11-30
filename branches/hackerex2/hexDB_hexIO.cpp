#include "hexDB_hexIO.hpp"
bool xsDLL GetHex( void* to, Text  from, ui08 tSize, ui08 tType )
{
	bool r;
	switch ( tType )
	{
	case HEX_TYPE_UI: r = GetHexFromUI( to, from, tSize ); break;
	case HEX_TYPE_SI: r = GetHexFromSI( to, from, tSize ); break;
	case HEX_TYPE_SF_IEEE754:
		r = GetHexFromSF_IEEE754( to, from, tSize );
		break;
	default: r = false;
	}
	return r;
}
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetHexFromSI( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetTxt( Text& to, void* from, ui08 fSize, ui08 fType ) { return false; }
bool xsDLL GetTxtFromSI( Text& to, void* from, ui08 fSize ) { return false; }
bool xsDLL GetTxtFromUI( Text& to, void* from, ui08 fSize ) { return false; }
bool xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) { return false; }
