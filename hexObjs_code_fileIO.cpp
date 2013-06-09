#include "hexObjs_main.h"
void Codes::saveCodes( Text dir, si32 hackId )
{
	Text path;
	path.Printf( wxT("%04X.hexcodes"), hackId );
	wxFile file;
	file.Create( path, true );
	file.Open( path, file.write );
	ui32 i, size = ( m_count * sizeof( Code ) );
	ui08 *data = new ui08[ size ];
	sint c;
	for ( c = 0; c < m_count; ++c )
	{
		for ( i = 0u; i < size; ++i )
			data[ i ] = 0u;
		m_saveCode( data, m_data[ c ] );
		file.Write( data, size );
	}
	file.Flush();
	file.Close();
	delete data;
}
void Codes::loadCodes( Text dir, si32 hackId )
{
	Text path;
	path.Printf( wxT("%04X.hexcodes"), hackId );
	wxFile file;
	if ( !file.Exists( path ) )
		return;
	file.Open( path );
	ui32 i, size = ( m_count * sizeof( Code ) );
	ui08 *data = new ui08[ size ];
	sint c;
	for ( c = 0; c < m_count; ++c )
	{
		for ( i = 0u; i < size; ++i )
			data[ i ] = 0u;
		file.Read( data, size );
		m_loadCode( data, m_data[ c ] );
	}
	file.Close();
	delete data;
}
void Codes::m_saveCode( ui08* data, Code& code )
{
	ui32 i = 0u, end = CODE_DATA_SIZE, j, size = code.size();
	ui08* dat = (ui08*)code.addr;
	ui16  info[ 2u ] = { code.info, code.loop };
	for ( i; i < end; ++i )
		data[ i ] = code[ i ];
	end = 16u;
	for ( j = 0u; j < end; ++j, ++i )
		data[ i ] = dat[ j ];
	dat = (ui08*)info;
	end = 4u;
	for ( j = 0u; j < end; ++j, ++i )
		data[ i ] = dat[ j ];
	dat = (ui08*)&size;
	end = 4u;
	for ( j = 0u; j < end; ++j, ++i )
		data[ i ] = dat[ j ];
	data[ i ]	= code.type;
	data[ ++i ]	= code.bytes;
	data[ ++i ]	= code.depth;
	data[ ++i ]	= code.hex;
	data[ ++i ]	= code.mode;
	data[ ++i ]	= code.ram;
}
void Codes::m_loadCode( ui08* data, Code& code )
{
	ui32 i = 0u, end = CODE_DATA_SIZE, j, size = 0u;
	ui08* dat = (ui08*)code.addr;
	ui16  info[ 2u ] = { code.info, code.loop };
	for ( i; i < end; ++i )
		code[ i ] = data[ i ];
	end = 16u;
	for ( j = 0u; j < end; ++j, ++i )
		dat[ j ] = data[ i ];
	dat = (ui08*)info;
	end = 4u;
	for ( j = 0u; j < end; ++j, ++i )
		dat[ j ] = data[ i ];
	dat = (ui08*)&size;
	end = 4u;
	for ( j = 0u; j < end; ++j, ++i )
		dat[ j ] = data[ i ];
	code.m_count = size;
	code.type	= data[ i ];
	code.bytes	= data[ ++i ];
	code.depth	= data[ ++i ];
	code.hex	= data[ ++i ];
	code.mode	= data[ ++i ];
	code.ram	= data[ ++i ];
}