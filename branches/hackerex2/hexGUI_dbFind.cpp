#include "hexGUI_G.hpp"
int  G::FindName( TxtA& data, Text name )
{
	data.Sort();
	int i, iEnd = data.GetCount();
	for ( i = 0; i < iEnd; ++i )
	{
		if ( data[ i ] == name )
			return i;
	}
	return -1;
}
