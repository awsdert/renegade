#include "cleanCLS.h"
HACK::HACK(  void ) { Clear(); }
HACK::~HACK( void ) { Clear(); }
CODE& HACK::operator[] ( s32 index )
{
	if ( index < 0 || index >= GetCount() )
		throw std::out_of_range( "Hack tried to access Code outside of range" );
	return p_data[ index ];
}
CODE& HACK::operator[] ( u32 index )
{
	if ( index >= ( u8 )GetCount() )
		throw std::out_of_range( "Hack tried to access Code outside of range" );
	return p_data[ index ];
}
void HACK::Clear( void )
{
	id    = 0u;
	use   = false;
	useRB = false;
	p_data.clear();
}
void HACK::SetCount( s8 count )
{
	if ( count < 0 )   count = 0;
	if ( count > 100 ) count = 100;
	p_data.resize( count );
}
s8   HACK::GetCount( void )
{
	s8 count = p_data.size();
	return count;
}
s8   HACK::NewCode( CODE code )
{
	s8 index = -1;
	s8 count = GetCount();
	if ( count < 100 )
	{
		p_data.push_back( code );
		index = count;
	}
	return index;
}
void HACK::DelCode( s8 index )
{
	if ( index >= 0 && index < GetCount() )
		p_data.erase( p_data.begin() + index );
}
