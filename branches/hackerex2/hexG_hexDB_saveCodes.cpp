#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::m_saveCodes( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p )
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
			cEnd = (temp.Length() / m_codeBytes);
			codes.resize( cEnd );
			for ( c = 0u; c < cEnd; ++c )
			{
				temp.Read( data, m_codeBytes );
				m_getCode( codes[ c ], data );
			}
			temp.Close();
			switch ( format.format )
			{
				case HL_HEX1:
					MakeTxt_Hex1( codes, block );
					SaveHack_Hex( file, hack, h, cEnd, block );
			}
			codes.resize( 0 );
			block.Clear();
			m_saveCodes( data, path, block, file, hEnd, h );
		}
	}
}
void hexDB::saveCodes( bool addObj )
{
	Text path = m_getDir(), txt = oldP[ HEX_LIST_HACK ];
	TxtF file;
	if ( wxFileExists( txt ) )
		wxRemoveFile( txt );
	file.Create( txt );
	file.Open( txt );
	if ( addObj )
		m_setCodes();
	ui32 hEnd = hacks.size();
	ui08* data = new ui08[ m_codeBytes ];
	TxtA block;
	m_saveCodes( data, path, block, file, hEnd, 0u );
	delete [] data;
}
