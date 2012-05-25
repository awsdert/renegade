#include "cleanCLS.h"
BIN::BIN( void ) : ORG()
{
	isFile = false;
	bind   = wxT( "" );
	path   = wxT( "" );
	SetCount( 1 );
}
BIN::~BIN( void )
{
	p_data.clear();
}
RAM& BIN::operator[] ( unsigned int index )
{
	if ( index >= ( u8 )GetCount() )
		throw std::out_of_range( "BIN tried to access RAM outside it's range" );
	return p_data[ index ];
}
RAM& BIN::operator[] (   signed int index )
{
	if ( index < 0 || index >= GetCount() )
		throw std::out_of_range( "BIN tried to access RAM outside it's range" );
	return p_data[ index ];
}
void BIN::SetCount( s8 count )
{
	if ( count > 0 && count < 16 )
	{
		p_data.resize( count );
	}
}
s8   BIN::GetCount( void )
{
	return ( s8 )p_data.size();
}
s8   BIN::Append( RAM ram )
{
	s8 index = -1;
	s8 count = GetCount();
	if ( count < 15 )
	{
		SetCount( count + 1 );
		p_data[ count ] = ram;
		index         = count;
	}
	return index;
}
