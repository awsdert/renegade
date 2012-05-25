#include "cleanCLS.h"
CODE::CODE(  void ) { Clear(); }
CODE::~CODE( void ) { Clear(); }
u64& CODE::operator[] ( s32 index )
{
	if ( index < 0 || index >= GetCount() )
		throw std::out_of_range( "Code tried to access value outside range" );
	return p_value[ index ];
}
u64& CODE::operator[] ( u32 index )
{
	if ( index >= ( u8 )GetCount() )
		throw std::out_of_range( "Code tried to access value outside range" );
	return p_value[ index ];
}
void CODE::Clear( void )
{
	ram = 0u;
	type = 0u;
	size = 0u;
	byte = 0u;
	test = 0u;
	slide = 0u;
	loop = 0u;
	ptrDepth = 0u;
	increment = 0u;
	isBigByte = false;
	p_value.resize( 1, 0u );
}
void CODE::SetCount( s16 count )
{
	if ( count < 1 ) count = 1;
	if ( count < 256 )
	{
		p_value.resize( count, 0u );
	}
}
u8   CODE::GetCount( void )
{
	u8 count = p_value.size();
	return count;
}
s16  CODE::NewItem( u64 value )
{
	s16 index = -1;
	s16 count = GetCount();
	if ( count < 256 )
	{
		SetCount( count + 1 );
		p_value[ count ] = value;
		index = count;
	}
	return index;
}
void CODE::DelItem( s16 index )
{
	s16 count = GetCount();
	if ( index < 0 || index >= count )
		p_value.erase( p_value.begin() + index );
}
