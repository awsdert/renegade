#include "wx_pch.h"
#include "hexDB_main.h"
void	xsDLL LoadHack_Hex( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block )
{
	Text txt, name;
	TxtT tzr;
	ui64 v64 = 0u;
	ui32 v1, v2;
	txt = file.GetLine( file.GetCurrentLine() );
	name = txt.SubString( 1, txt.Length() - 2 );
	txt	 = file.GetNextLine();
	GetHex( &v64, txt.Left( 8 ) + txt.Right( 8 ), 8u );
	v2 = ( v64 & xsF8LL );
	v1 = GETHEX( v64, xsF8LL, 32u );
	hackIndex = ( v1 & 0xFFFF );
	if ( hackIndex == 0u )
		name	= wxT("(m)");
	hack.info	= ( ( v1 & 0x30000000 ) >> 28u );
	hack.name	= name;
	hack.parent	= ( v2 & 0xFFFF );
	codeCount	= ( ( v2 & 0xFFFF0000 ) >> 16u );
	for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() || txt[ 0 ] == cQuot )
			break;
		if ( txt.Contains( cSemC ) )
		{
			tzr.SetString( txt, cSemC );
			txt = tzr.GetNextToken();
		}
		block.Add( txt );
	}
	file.GetPrevLine();
}
void	xsDLL SaveHack_Hex( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block )
{
	Text txt;
	int i = 0, iEnd = block.GetCount();
	file.AddLine( cQuot + hack.name + cQuot );
	txt.Printf( wxT("%01X000%04X %04X%04X"), ( hack.info & 0xF ), hackIndex, codeCount, hack.parent );
	file.AddLine( txt );
	for ( ; i < iEnd; ++i )
		file.AddLine( block[i], wxTextFileType_Dos );
}
