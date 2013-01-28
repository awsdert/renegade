#include "wx_pch.h"
#include "hexDB_main.h"
const int  l_regionCount = 5;
TxtA l_regionData;
ui32 l_regions[ l_regionCount ];
bool l_regionsSet = false;
xsDLL void l_setRegions( void )
{
	TxtA txt;
	txt.SetCount( l_regionCount );
	ui32 bit[ l_regionCount ];
	txt[0] = wxT("UK");  bit[0] = REGION_UK;
	txt[1] = wxT("US");  bit[1] = REGION_US;
	txt[2] = wxT("AUS"); bit[2] = REGION_AUS;
	txt[3] = wxT("DE");  bit[3] = REGION_DE;
	txt[4] = wxT("JP");  bit[4] = REGION_JP;
	l_regionData = txt;
	for ( int i = 0; i < l_regionCount; ++i )
		l_regions[ i ] = bit[ i ];
	l_regionsSet = true;
}
xsDLL int  getRegionCount( void ) { return l_regionCount; }
xsDLL void getRegions( ui32* data )
{
	if ( !l_regionsSet )
		l_setRegions();
	for ( int i = 0; i < l_regionCount; ++i )
		data[ i ] = l_regions[ i ];
}
xsDLL void getRegionData( TxtA& data ) {
	if ( !l_regionsSet )
		l_setRegions();
	data = l_regionData;
}
xsDLL ui32 CheckRegion( Text region )
{
	if ( !l_regionsSet )
		l_setRegions();
	int i;
	region.UpperCase();
	ui32 r = 0u;
	Text comma = wxT(',');
	Text txt;
	if ( region.Contains( comma ) )
	{
		TxtT tzr;
		tzr.SetString( region, comma );
		do
		{
			txt = tzr.GetNextToken();
			for ( i = 0; i < l_regionCount; ++i )
			{
				if ( txt == l_regionData[i] )
					r |= l_regions[i];
			}
		}
		while ( tzr.HasMoreTokens() );
	}
	else
	{
		txt = region;
		for ( i = 0; i < l_regionCount; ++i )
		{
			if ( txt == l_regionData[i] )
				r |= l_regions[i];
		}
	}
	return r;
}
xsDLL Text CheckRegion( ui32 region )
{
	if ( !l_regionsSet )
		l_setRegions();
	Text txt;
	const wxChar comma = wxT(',');
	for ( int i = 0; i < l_regionCount; ++i )
	{
		if ( region & l_regions[i] )
			txt += comma + l_regionData[i];
	}
	return txt.Right( txt.Length() - 2 );
}
