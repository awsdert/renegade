#include "wx_pch.h"
#include "hexDB_main.h"
Codes	xsDLL LoadHacks( Codes& old, TxtF& file, TxtF& temp, Hacks& data, ui16 pid, bool addObj, int format )
{
	switch ( format )
	{
	case HL_HEX1: return LoadHacks_Hex( old, file, temp, data, addObj, 1 );
	case HL_HEX2: return LoadHacks_Hex( old, file, temp, data, addObj, 2 );
	default: return Codes();
	}
}
Codes	xsDLL LoadHacks_Hex( Codes& old, TxtF& file, TxtF& temp, Hacks& data, bool addObj, int version )
{
	if ( version < 1 || version > 1 )
		return Codes();
	Text txt, name, line, tt;
	ui32 hi, hn = data.hackNow, ho = data.hackOld, hc = 1u;
	ui16 cc, oc;
	Hack hack;
	Codes tmp, now;
	bool dOld = false, dNow = false;
	data.resize( 0xFFFF );
	now.resize( 0 );
	TxtA block;
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == cQuot )
		{
			LoadHack_Hex( file, hack, hi, cc, block );
			// Code load
			if ( hi >= hc )
				hc = hi + 1u;
			if ( hi == ho && addObj )
			{
				oc	 = old.size();
				hack = data[ hi ];
			}
			else
				oc	 = cc;
			data[ hi ] = hack;
			if ( hi == ho || hi == hn )
			{
				tmp.resize( cc );
				switch ( version )
				{
					case 1: MakeObj_Hex1( tmp, block ); break;
				}
				if ( !dOld && ho == hi && addObj )
				{
					tmp  = old;
					dOld = true;
				}
				if ( !dNow && hn == hi )
				{
					now  = tmp;
					dNow = true;
				}
				block.Clear();
				switch ( version )
				{
					case 1: MakeTxt_Hex1( tmp, block ); break;
				}
				tmp.clear();
			}
			SaveHack_Hex( temp, data[ hi ], hi, oc, block );
			block.Clear();
		}
		else
			temp.AddLine( txt, wxTextFileType_Dos );
	}
	if ( !dOld && addObj && ho >= hc )
		hc = ho + 1;
	data.resize( hc );
	if ( !dOld && addObj )
	{
		hack = data[ ho ];
		oc = old.size();
		switch ( version )
		{
			case 1: MakeTxt_Hex1( old, block ); break;
		}
		SaveHack_Hex( temp, data[ ho ], ho, oc, block );
		block.Clear();
		if ( ho == hn )
			now = old;
	}
	return now;
}
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
