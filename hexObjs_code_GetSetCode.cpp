#include "wx_pch.h"
#include "hexObjs_main.h"
void Hacks::setCodes( si32 i, Codes& codes )
{
	BinF file;
	ui32 size = sizeof( Code );
	ui32 c = 0u, cEnd = codes.size();
	ui08* data = (ui08*)malloc( size );
	file.Create( path, true );
	file.Open( path, file.write_append );
	for ( ; c < cEnd; ++c )
	{
		m_setCode( codes[ c ], data );
		file.Write( data, size );
	}
	file.Close();
	free( data );
}
Codes	Hacks::getCodes( si32 i )
{
	Codes codes;
	BinF file;
	if ( !file.Exists( path ) )
		return codes;
	file.Open( path );
	ui32 size = sizeof( Code );
	ui08* data = (ui08*)malloc( size );
	ui32 c = 0u, cEnd = ( file.Length() / size );
	codes.resize( cEnd );
	for ( ; c < cEnd; ++c )
	{
		file.Read( data, size );
		m_getCode( codes[ c ], data );
	}
	free( data );
	file.Close();
	return codes;
}
void	Hacks::m_setCode( Code& obj, ui08* data )
{
	int i = 0, j = 0;
	for ( ; j < 256; i += 8, ++j )
		*( reinterpret_cast< ui64* >( &( data[ i ] ) ) ) = obj[ j ];
	for ( j = 0; j < 2; i += 8, ++j )
		*( reinterpret_cast< ui64* >( &( data[ i ] ) ) ) = obj.addr[ j ];
	ui16 v16[ 2 ] = { obj.info, obj.loop };
	for ( j = 0; j < 2; i += 2, ++j )
		*( reinterpret_cast< ui16* >( &( data[ i ] ) ) ) = v16[ j ];
	data[ i ]	= obj.type;
	data[ ++i ]	= obj.bytes;
	data[ ++i ]	= obj.depth;
	data[ ++i ]	= obj.ram;
	data[ ++i ]	= obj.mode;
	data[ ++i ]	= obj.hex;
}
void	Hacks::m_getCode( Code& obj, ui08* data )
{
	int i = 0, j = 0;
	for ( ; j < 256; i += 8, ++j )
		obj[ j ]		= *( reinterpret_cast< ui64* >( &( data[ i ] ) ) );
	for ( j = 0; j < 2; i += 8, ++j )
		obj.addr[ j ]	= *( reinterpret_cast< ui64* >( &( data[ i ] ) ) );
	ui16 v16[ 2 ]= { 0u, 0u };
	for ( j = 0; j < 2; i += 2, ++j )
		v16[ j ]		= *( reinterpret_cast< ui16* >( &( data[ i ] ) ) );
	obj.type	= data[ i ];
	obj.bytes	= data[ ++i ];
	obj.depth	= data[ ++i ];
	obj.ram		= data[ ++i ];
	obj.mode	= data[ ++i ];
	obj.hex		= data[ ++i ];
	obj.info	= v16[ 0 ];
	obj.loop	= v16[ 1 ];
}