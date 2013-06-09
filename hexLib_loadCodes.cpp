#include "wx_pch.h"
#include "hexLib_gui.h"
/* *
void hexDB::loadCodes( Text path, Hacks& hData, Codes& cData )
{
	Text name, txt, text;
	TxtF tFile;
	TxtA block;
	tFile.Open( path );
	path += wxT("_file~");
	wxRmDir( path );
	wxMkDir( path );
	BinF bFile;
	ui32 hi, hc = 0u, hp, ht;
	ui16 cc, ci;
	bool gotHack = false;
	Hack hack;
	ui08* data = new ui08[ m_codeBytes ], pc, pcNext = 20;
	hData.resize( 0, Hack() );
	hData.resize( 0xFFFF );
	cData.resize( 0, Code() );
	hData.hackNow = 0;
	hData.hackOld = 0;
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
				{
					LoadHack_Hex( tFile, hack, hi, cc, block );
					cData.resize( cc );
					MakeObj_Hex1( cData, block );
				}
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
			hack.used = true;
			hData[ hi ] = hack;
			name.Printf( wxT("%04X.bin"), hi );
			block.Clear();
			txt = path + xsDirSep + name;
			bFile.Create( txt, true );
			bFile.Open( txt, bFile.read_write );
			cc = cData.size();
			for ( ci = 0u; ci < cc; ++ci )
			{
				m_setCode( cData[ ci ], data );
				bFile.Write( data, m_codeBytes );
			}
			hack.used = false;
			bFile.Close();
			cData.resize( 0 );
		}
	}
	delete [] data;
	for ( hi = 1u; hi < hc; ++hi )
	{
		hp = hData[ hi ].parent;
		ht = hData[ hp ].first;
		if ( ht == 0xFFFFF )
			hData[ hp ].first = hi;
		else
		{
			while ( hData[ ht ].next != 0xFFFFF )
				ht = hData[ ht ].next;
			hData[ ht ].next = hi;
		}
	}
	pb->SetValue( 100 );
	hData.resize( hc );
	hData.hackNow = 0;
	hData.hackOld = 0;
	m_getCodes( cData, 0u, true );
}
/* */