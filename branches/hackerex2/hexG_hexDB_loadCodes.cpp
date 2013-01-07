#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::loadCodes( bool getCodeData )
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
			if ( getCodeData )
			{
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
			}
			block.Clear();
		}
	}
	hacks.resize( hc );
	getCodes( 0u, true );
	delete [] data;
}
