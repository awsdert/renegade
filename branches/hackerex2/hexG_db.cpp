#include "hexG_db.h"
xsDLL hexDB::hexDB()
{
	nowP.SetCount( HEX_LIST_COUNT );
	oldP.SetCount( HEX_LIST_COUNT );
	mode[ HEX_LIST_SESSION ]	= HEX_LIST_ORG;
	mode[ HEX_LIST_ORG ]		= HEX_LIST_ORG;
	mode[ HEX_LIST_PFM ]		= HEX_LIST_PFM;
	mode[ HEX_LIST_BIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_APP ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_WIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_RAM ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_PFL ]		= HEX_LIST_PFL;
	mode[ HEX_LIST_FORMAT ]		= HEX_LIST_FORMAT;
	mode[ HEX_LIST_HACK ]		= HEX_LIST_HACK;
	mode[ HEX_LIST_CODE ]		= HEX_LIST_HACK;
	mode[ HEX_LIST_FIND ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_OUT ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_EDIT ]		= HEX_LIST_BIN;
}
Text xsDLL hexDB::getNowN( int inMode )
{
	Text name = getGlobalName();
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
		name = state.nameNow;
		break;
	case HEX_LIST_ORG:
		name = org.nameNow;
		break;
	case HEX_LIST_PFM:
		name = pfm.nameNow;
		break;
	case HEX_LIST_BIN:
		name = bin.nameNow;
		break;
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
		name = bin.name;
		break;
	case HEX_LIST_RAM:
		name = bin[ ramNo ].name;
		break;
	case HEX_LIST_PFL:
		name = pfl.nameNow;
		break;
	case HEX_LIST_FORMAT:
		name = format.name;
		break;
	case HEX_LIST_HACK:
		name = hacks[ hacks.hackNow ].name;
	}
	return name;
}
Text xsDLL hexDB::getDir( void )
{
	Text path = nowP[ HEX_LIST_HACK ] + wxT("_files");
	if ( !wxDirExists( path ) )
		wxMkdir( path );
	return path;
}
Text xsDLL hexDB::getPath( ui32 c )
{
	Text path = getDir(), name;
	name.Printf( wxT("%04X.bin"), c );
	path += xsDirSep + name;
	return path;
}
void xsDLL hexDB::loadCodes( void )
{
	Text path = getDir(), name, txt;
	TxtF tFile;
	TxtA block;
	tFile.Open( nowP[ HEX_LIST_HACK ] );
	BinF bFile;
	ui32 hi, hc = 0u;
	ui16 cc, ci;
	bool gotHack = false;
	Hack hack;
	Codes tmp;
	size_t bytes = 2100;
	ui08* data = new ui08[ bytes ];
	hacks.clear();
	codes.clear();
	hacks.hackNow = 0;
	hacks.hackOld = 0;
	codeNo = 0;
	hacks.resize( 0xFFFF );
	bool isQuot = false;
	for ( txt = tFile.GetFirstLine(); !tFile.Eof(); txt = tFile.GetNextLine() )
	{
		isQuot = ( txt[ 0 ] == cQuot );
		switch ( format.format )
		{
			case HL_HEX1:
			case HL_HEX2:
			{
				gotHack = isQuot;
				if ( gotHack )
					LoadHack_Hex( tFile, hack, hi, cc, block );
				break;
			}
			default: gotHack = false;
		}
		if ( gotHack )
		{
			if ( hi >= hc )
				hc = hi + 1u;
			hacks[ hi ] = hack;
			name.Printf( wxT("%04X.bin"), hi );
			tmp.resize( cc );
			switch ( format.format )
			{
			case HL_HEX1: MakeObj_Hex1( tmp, block ); break;
			}
			txt = path + xsDirSep + name;
			bFile.Create( txt, true );
			bFile.Open( txt, bFile.write_append );
			cc = tmp.size();
			for ( ci = 0u; ci < cc; ++ci )
			{
				setCode( tmp[ ci ], data );
				bFile.Write( data, bytes );
			}
			bFile.Close();
			tmp.clear();
			block.Clear();
		}
	}
	hacks.resize( hc );
	getCodes( 0u );
	delete [] data;
}
void xsDLL hexDB::saveCodesIntern( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p )
{
	Text name, txt;
	BinF temp;
	Hack hack;
	ui16 c, cEnd;
	for ( ui32 h = 0u; h < hEnd; ++h )
	{
		hack = hacks[ h ];
		if ( hack.parent == p )
		{
			name.Printf( wxT("%04X.bin") );
			temp.Open( path + xsDirSep + name );
			if ( !temp.IsOpened() )
				continue;
			cEnd = temp.Length() / 2100;
			codes.resize( cEnd );
			for ( c = 0u; c < cEnd; ++c )
			{
				temp.Read( data, 2100 );
				getCode( codes[ c ], data );
			}
			temp.Close();
			switch ( format.format )
			{
				case HL_HEX1:
					MakeTxt_Hex1( codes, block );
					SaveHack_Hex( file, hack, h, cEnd, block );
			}
			codes.clear();
			block.Clear();
			saveCodesIntern( data, path, block, file, hEnd, h );
		}
	}
}
void xsDLL hexDB::saveCodes( bool addObj )
{
	Text path = getDir(), txt = oldP[ HEX_LIST_HACK ];
	TxtF file;
	if ( wxFileExists( txt ) )
		wxRemoveFile( txt );
	file.Create( txt );
	file.Open( txt );
	if ( addObj )
		setCodes();
	ui32 hEnd = hacks.size();
	ui08* data = new ui08[ 2100 ];
	TxtA block;
	saveCodesIntern( data, path, block, file, hEnd, 0u );
	delete [] data;
}
void xsDLL hexDB::setCodes( void )
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
void xsDLL hexDB::getCodes( ui32 c )
{
	setCodes();
	Text path = getPath( c );
	BinF file;
	if ( !file.Exists( path ) )
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
void xsDLL hexDB::setCode( Code& obj, ui08* data )
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
void xsDLL hexDB::getCode( Code& obj, ui08* data )
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
