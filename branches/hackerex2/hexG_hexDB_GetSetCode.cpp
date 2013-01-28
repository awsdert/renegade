#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::m_setCodes( void )
{
	Text path = m_getPath( hacks.hackOld );
	BinF file;
	ui32 i = 0u, iEnd = codes.size();
	ui08* data = new ui08[ m_codeBytes ];
	file.Create( path, true );
	file.Open( path, file.write_append );
	for ( ; i < iEnd; ++i )
	{
		m_setCode( codes[ i ], data );
		file.Write( data, m_codeBytes );
	}
	file.Close();
	delete [] data;
}
void hexDB::m_getCodes( Codes& obj, ui32 h, bool insideCall )
{
	Text path = m_getPath( h );
	BinF file;
	if ( !file.Exists( path ) && h != 0xFFFFF && !insideCall )
		loadCodes( nowP[ HEX_LIST_HACK ], hacks, codes );
	if ( !file.Exists( path ) )
		return;
	file.Open( path );
	ui32 i = 0u, iEnd = ( file.Length() / m_codeBytes );
	obj.resize( 0, Code() );
	obj.resize( iEnd );
	ui08* data = new ui08[ m_codeBytes ];
	for ( ; i < iEnd; ++i )
	{
		file.Read( data, m_codeBytes );
		m_getCode( obj[ i ], data );
	}
	file.Close();
	delete [] data;
}
void hexDB::getCodes( ui32 hackIndex )
{
	m_setCodes();
	m_getCodes( codes, hackIndex, false );
	hacks.hackNow = hackIndex;
}
void hexDB::m_setCode( Code& obj, ui08* data )
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
void hexDB::m_getCode( Code& obj, ui08* data )
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