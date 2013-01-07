#include "wx_pch.h"
#include "hexG_db.h"
hexDB::hexDB()
{
	showHacks	= true;
	showAllApps	= true;
	tmpCfg		= false;
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
Text hexDB::getDir( void )
{
	Text path = nowP[ HEX_LIST_HACK ] + wxT("_files");
	if ( !path.IsEmpty() && !wxDirExists( path ) )
		wxMkdir( path );
	return path;
}
Text hexDB::getPath( ui32 c )
{
	Text path = getDir(), name;
	if ( c < 256u )
		name.Printf( wxT("%04X.bin"), c );
	else
		name = wxT("temp.bin");
	path += xsDirSep + name;
	return path;
}

void hexDB::setCodes( void )
{
	Text path = getPath( hacks.hackOld );
	BinF file;
	ui32 i = 0u, iEnd = codes.size();
	size_t bytes = 2100;
	ui08* data = new ui08[ bytes ];
	file.Create( path, true );
	file.Open( path, file.write_append );
	for ( ; i < iEnd; ++i )
	{
		setCode( codes[ i ], data );
		file.Write( data, bytes );
	}
	file.Close();
	delete [] data;
}
void hexDB::getCodes( ui32 c, bool internBool )
{
	setCodes();
	Text path = getPath( c );
	BinF file;
	if ( !file.Exists( path ) && !internBool )
		loadCodes();
	codes.clear();
	if ( !file.Exists( path ) )
		return;
	file.Open( path );
	size_t bytes = 2100;
	ui32 i = 0u, iEnd = file.Length() / bytes;
	codes.resize( iEnd );
	ui08* data = new ui08[ bytes ];
	for ( ; i < iEnd; ++i )
	{
		file.Read( data, bytes );
		getCode( codes[ i ], data );
	}
	hacks.hackNow = c;
	delete data;
}
void hexDB::setCode( Code& obj, ui08* data )
{
	int i = 0, j;
	for ( ; i < 2040; ++i )
		data[ i ] = obj.data[ i ];
	for ( j = 0; j < 2; ++j, i += 8 )
		*( reinterpret_cast< ui64* >( &( data[ i ] ) ) ) = obj.addr[ j ];
	ui16 v16[ 3 ] = { obj.info, obj.loop, obj.size() };
	for ( j = 0; j < 3; ++j, i += 2 )
		*( reinterpret_cast< ui16* >( &( data[ i ] ) ) ) = v16[ j ];
	data[ i ]	= obj.type;
	data[ ++i ]	= obj.bytes;
	data[ ++i ]	= obj.depth;
	data[ ++i ]	= obj.ram;
	data[ ++i ]	= obj.mode;
	data[ ++i ]	= obj.hex;
}
void hexDB::getCode( Code& obj, ui08* data )
{
	int i = 2040, j;
	for ( j = 0; j < 2; ++j, i += 8 )
		obj.addr[ j ] = *( reinterpret_cast< ui64* >( &( data[ i ] ) ) );
	ui16 v16[ 3 ];
	for ( j = 0; j < 3; ++j, i += 2 )
		v16[ j ]	  = *( reinterpret_cast< ui16* >( &( data[ i ] ) ) );
	obj.type	= data[ i ];
	obj.bytes	= data[ ++i ];
	obj.depth	= data[ ++i ];
	obj.ram		= data[ ++i ];
	obj.mode	= data[ ++i ];
	obj.hex		= data[ ++i ];
	obj.info	= v16[ 0 ];
	obj.loop	= v16[ 1 ];
	obj.resize( v16[ 2 ] );
	for ( i = 0; i < 2040; ++i )
		obj.data[ i ] = data[ i ];
}
