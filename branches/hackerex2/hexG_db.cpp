#include "wx_pch.h"
#include "hexG_db.h"
hexDB::hexDB()
{
	ini = NULL;
	killThreads = false;
	showHacks	= true;
	showAllApps	= true;
	tmpCfg		= false;
	m_hooked	= false;
	m_addrSize	= sizeof( size_t );
	switch ( m_addrSize )
	{
	case 8: m_moveAddr = 0; break;
	case 4: m_moveAddr = 32u; break;
	default: m_moveAddr = 64u; break;
	}
	tmpMode		= -1;
	codeNo		= -1;
	hacks.hackNow = -1;
	hacks.hackOld = -1;
	nowP.SetCount( HEX_LIST_COUNT );
	oldP.SetCount( HEX_LIST_COUNT );
	mode[ HEX_LIST_THEME	] = HEX_LIST_ORG;
	mode[ HEX_LIST_SESSION	] = HEX_LIST_ORG;
	mode[ HEX_LIST_ORG		] = HEX_LIST_ORG;
	mode[ HEX_LIST_PFM		] = HEX_LIST_PFM;
	mode[ HEX_LIST_BIN		] = HEX_LIST_BIN;
	mode[ HEX_LIST_APP		] = HEX_LIST_BIN;
	mode[ HEX_LIST_WIN		] = HEX_LIST_BIN;
	mode[ HEX_LIST_RAM		] = HEX_LIST_BIN;
	mode[ HEX_LIST_PFL		] = HEX_LIST_PFL;
	mode[ HEX_LIST_FORMAT	] = HEX_LIST_FORMAT;
	mode[ HEX_LIST_HACK		] = HEX_LIST_HACK;
	mode[ HEX_LIST_CODE		] = HEX_LIST_HACK;
	mode[ HEX_LIST_FIND		] = HEX_LIST_BIN;
	mode[ HEX_LIST_OUT		] = HEX_LIST_BIN;
	mode[ HEX_LIST_EDIT		] = HEX_LIST_BIN;
	for ( int i = 0; i < HEX_LIST_COUNT; ++i )
		nowM[ i ] = false;
}
Text hexDB::getDefN( int inMode, bool forRoot )
{
	switch ( inMode )
	{
		case HEX_LIST_RAM:	return _("Memory Part");
		case HEX_LIST_HACK: return forRoot ? _("(m)") : _("Hack");
		case HEX_LIST_CODE: return _("(Codelist)");
		default: return getGlobalName();
	}
}
Text hexDB::getNowN( int inMode )
{
	int hn = hacks.hackNow;
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
		return state.nameNow;
	case HEX_LIST_ORG:
		return org.nameNow;
	case HEX_LIST_PFM:
		return pfm.nameNow;
	case HEX_LIST_BIN:
		return bin.nameNow;
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
		return bin.name;
	case HEX_LIST_RAM:
		if ( ramNo >= 0)
			return bin[ ramNo ].name;
		break;
	case HEX_LIST_PFL:
		return pfl.nameNow;
	case HEX_LIST_FORMAT:
		return format.name;
	case HEX_LIST_HACK:
		if ( hn >= 0 )
			return hacks[ hn ].name;
	}
	return getDefN( inMode, true );
}
Text hexDB::m_getDir( void )
{
	Text path = nowP[ HEX_LIST_HACK ] + wxT("_files");
	if ( !path.IsEmpty() && !wxDirExists( path ) )
		wxMkdir( path );
	return path;
}
Text hexDB::m_getPath( ui32 h )
{
	Text path = m_getDir(), name;
	if ( h <= 0xFFFF )
		name.Printf( wxT("%04X.bin"), h );
	else
		name = wxT("temp.bin");
	path += xsDirSep + name;
	return path;
}

void hexDB::m_setCodes( void )
{
	Text path = m_getPath( hacks.hackOld );
	BinF file;
	ui32 i = 0u, iEnd = codes.size();
	size_t bytes = 2100;
	ui08* data = new ui08[ bytes ];
	file.Create( path, true );
	file.Open( path, file.write_append );
	for ( ; i < iEnd; ++i )
	{
		m_setCode( codes[ i ], data );
		file.Write( data, bytes );
	}
	file.Close();
	delete [] data;
}
void hexDB::m_getCodes( Codes& obj, ui32 h, bool insideCall )
{
	Text path = m_getPath( h );
	BinF file;
	if ( !file.Exists( path ) && h != 0xFFFFF && !insideCall )
		loadCodes();
	if ( !file.Exists( path ) )
		return;
	file.Open( path );
	size_t bytes = 2100;
	ui32 i = 0u, iEnd = file.Length() / bytes;
	obj.resize( iEnd );
	ui08* data = new ui08[ bytes ];
	for ( ; i < iEnd; ++i )
	{
		file.Read( data, bytes );
		m_getCode( obj[ i ], data );
	}
	delete data;
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
		obj[ j ] = *( reinterpret_cast< ui64* >( &( data[ i ] ) ) );
	for ( j = 0; j < 2; i += 8, ++j )
		obj.addr[ j ] = *( reinterpret_cast< ui64* >( &( data[ i ] ) ) );
	ui16 v16[ 2 ];
	for ( j = 0; j < 2; i += 2, ++j )
		v16[ j ]	  = *( reinterpret_cast< ui16* >( &( data[ i ] ) ) );
	obj.type	= data[ i ];
	obj.bytes	= data[ ++i ];
	obj.depth	= data[ ++i ];
	obj.ram		= data[ ++i ];
	obj.mode	= data[ ++i ];
	obj.hex		= data[ ++i ];
	obj.info	= v16[ 0 ];
	obj.loop	= v16[ 1 ];
}
