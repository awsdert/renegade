#include "wx_pch.h"
#include "hexObjs_main.h"
nsREGION::nsREGION( void )
{
	m_txt.SetCount( REG_COUNT );
	m_txt[ REG_UK	] = wxT("UK"); 
	m_bit[ REG_UK	] = REGION_UK;
	m_txt[ REG_US	] = wxT("US"); 
	m_bit[ REG_US	] = REGION_US;
	m_txt[ REG_AUS	] = wxT("AUS");
	m_bit[ REG_AUS	] = REGION_AUS;
	m_txt[ REG_CA	] = wxT("CA");
	m_bit[ REG_CA	] = REGION_CA;
	m_txt[ REG_DE	] = wxT("DE");
	m_bit[ REG_DE	] = REGION_DE;
	m_txt[ REG_JP	] = wxT("JP"); 
	m_bit[ REG_JP	] = REGION_JP;
}
si32 nsREGION::getId( Text name )
{
	name.UpperCase();
	for ( si32 i = 0; i < REG_COUNT; ++i )
	{
		if ( name == oRegion.m_txt[ i ] )
			return i;
	}
	return -1;
}
Text nsREGION::getName( si32 id )
{
	if ( id < 0 || id >= REG_COUNT )
		return wxT( "INVALID_ID" );
	return oRegion.m_txt[ id ];
}
Text nsREGION::getNames( ui32 value )
{
	Text names;
	for ( si32 i = 0; i < REG_COUNT; ++i )
	{
		if ( ( value & oRegion.m_bit[ i ] ) > 0u )
			names += wxT(", ") + oRegion.m_txt[ i ];
	}
	if ( !names.empty() )
		names = names.SubString( 2, names.length() );
	return names;
}
ui32 nsREGION::getValue( Text names )
{
	ui32 value = 0u;
	TxtT tkn;
	Text txt;
	si32 i;
	tkn.SetString( names, wxT( ", " ) );
	for ( txt = tkn.GetNextToken(); tkn.HasMoreTokens(); txt = tkn.GetNextToken() )
	{
		for ( i = 0; i < REG_COUNT; ++i )
		{
			if ( txt == oRegion.m_txt[ i ] )
				value |= oRegion.m_bit[ i ];
		}
	}
	tkn.SetString( names, wxT( "," ) );
	for ( txt = tkn.GetNextToken(); tkn.HasMoreTokens(); txt = tkn.GetNextToken() )
	{
		for ( i = 0; i < REG_COUNT; ++i )
		{
			if ( txt == oRegion.m_txt[ i ] )
				value |= oRegion.m_bit[ i ];
		}
	}
	return value;
}