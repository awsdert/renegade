#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::loadCodes( void )
{
	Text path = m_getDir(), name, txt;
	wxRmDir( path );
	wxMkDir( path );
	TxtF tFile;
	TxtA block;
	tFile.Open( nowP[ HEX_LIST_HACK ] );
	BinF bFile;
	ui32 hi, hc = 0u, hp, ht;
	ui16 cc, ci;
	bool gotHack = false;
	Hack hack;
	size_t bytes = 2100;
	ui08* data = new ui08[ bytes ], pc, pcNext = 20;
	hacks.clear();
	hacks.resize( 0xFFFF );
	codes.clear();
	hacks.hackNow = 0;
	hacks.hackOld = 0;
	codeNo = 0;
	pb->SetValue( 0 );
	bool isQuot = false;
	double ln, le = tFile.GetLineCount();
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
		ln = tFile.GetCurrentLine();
		pc = ( ( ln / le ) * 100.0 );
		if ( pc >= pcNext )
		{
			pb->SetValue( pc );
			pcNext += 20;
		}
		if ( gotHack )
		{
			if ( hi >= hc )
				hc = hi + 1u;
			hacks[ hi ] = hack;
			name.Printf( wxT("%04X.bin"), hi );
			codes.resize( cc );
			switch ( format.format )
			{
			case HL_HEX1: MakeObj_Hex1( codes, block ); break;
			}
			txt = path + xsDirSep + name;
			bFile.Create( txt, true );
			bFile.Open( txt, bFile.write_append );
			cc = codes.size();
			for ( ci = 0u; ci < cc; ++ci )
			{
				m_setCode( codes[ ci ], data );
				bFile.Write( data, bytes );
			}
			if ( !bFile.Close() )
				break;
			block.Clear();
		}
	}
	for ( hi = 1u; hi < hc; ++hi )
	{
		hp = hacks[ hi ].parent;
		ht = hacks[ hp ].first;
		if ( ht == 0xFFFFF )
			hacks[ hp ].first = hi;
		else
		{
			while ( hacks[ ht ].next != 0xFFFFF )
				ht = hacks[ ht ].next;
			hacks[ ht ].next = hi;
		}
	}
	pb->SetValue( 100 );
	hacks.resize( hc );
	m_getCodes( codes, 0u, true);
	delete [] data;
}
