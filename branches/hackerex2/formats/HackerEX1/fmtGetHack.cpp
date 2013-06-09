#include "main.h"
void fmtGetHack( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block )
{
	Text txt, name;
	TxtT tzr;
	ui64 v64 = 0u;
	ui32 v1, v2;
	txt = file.GetLine( file.GetCurrentLine() );
	name = txt.SubString( 1, txt.Length() - 2 );
	txt	 = file.GetNextLine();
	wxChar cSemC = wxT(';');
	v64 = zxGetHex( ( txt.Left( 8 ) + txt.Right( 8 ) ).data() ).getIntLL();
	v2 = ( v64 & zxF8LL );
	v1 = zxGETHEX( v64, zxF8LL, 32u );
	hackIndex = ( v1 & 0xFFFF );
	if ( hackIndex == 0u )
		name	= wxT("(m)");
	hack.isActive	= ( ( v1 & 0x10000000 ) >> 28u ) > 0u;
	hack.isRadio	= ( ( v1 & 0x20000000 ) >> 28u ) > 0u;
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
void fmtSaveHack( TxtF& file, Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block )
{
	Text txt;
	int i = 0, iEnd = block.GetCount();
	file.AddLine( cQuot + hack.name + cQuot );
	ui08 info = hack.isActive ? 1u : 0u;
	info += hack.isRadio ? 2u : 0u;
	txt.Printf( wxT("%01X000%04X %04X%04X"), info, hackIndex, codeCount, hack.parent );
	file.AddLine( txt );
	for ( ; i < iEnd; ++i )
		file.AddLine( block[i], wxTextFileType_Dos );
}