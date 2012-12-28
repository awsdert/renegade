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
	ui16 hi, hn = data.hackNow, ho = data.hackOld, cc, hc = 1u, oc;
	ui64 val;
	ui32 v1, v2;
	Hack hack;
	Codes tmp, now;
	bool dOld = false, dNow = false;
	data.resize( 0xFFFF );
	now.resize( 0 );
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == cQuot )
		{
			name = txt.SubString( 1, txt.Length() - 2 );
			hack.line = file.GetCurrentLine() + 1;
			txt = file.GetNextLine();
			tt = txt;
			line = txt.Left( 8 ) + txt.Right( 8 );
			/*
			tt.Printf( wxT("%i"), line.Length() );
			wxMessageBox( line, tt );//*/
			GetHex( &val, line, 8u );
			v2 = ( val & xsF8LL );
			v1 = GETHEX( val, xsF8LL, 32u );
			line.Printf( wxT("%08X %08X"), v1, v2 );
			hi = ( v1 & 0xFFFF );
			if ( hi == 0u )
				name	= wxT("(m)");
			hack.info	= ( ( v1 & 0x30000000 ) >> 28u );
			hack.name	= name;
			hack.parent	= ( v2 & 0xFFFF );
			cc			= ( ( v2 & 0xFFFF0000 ) >> 16u );
			// Code load
			if ( hi >= hc )
				hc = hi + 1u;
			if ( hi == ho && addObj )
			{
				oc	 = old.size();
				hack = data[ hi ];
			}
			else
				oc = cc;
			data[ hi ] = hack;
			temp.AddLine( cQuot + hack.name + cQuot, wxTextFileType_Dos );
			txt.Printf( wxT("%01X000%04X %04X%04X"), hack.info, hi, oc, hack.parent );
			temp.AddLine( txt, wxTextFileType_Dos );
			if ( hi == ho || hi == hn )
			{
				tmp.clear();
				tmp.resize( cc );
				switch ( version )
				{
					case 1: LoadCodes_Hex1( tmp, file ); break;
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
				switch ( version )
				{
					case 1: SaveCodes_Hex1( tmp, temp ); break;
				}
			}
			else
			{
				for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
				{
					if ( txt.IsEmpty() || txt[0] == cQuot )
						break;
					temp.AddLine( txt, wxTextFileType_Dos );
				}
				file.GetPrevLine();
			}
		}
		else
			temp.AddLine( txt, wxTextFileType_Dos );
	}
	if ( !dOld && addObj )
	{
		++hc;
		hack = data[ ho ];
		txt = cQuot + hack.name + cQuot;
		temp.AddLine( txt, wxTextFileType_Dos );
		oc = old.size();
		txt.Printf( wxT("%01X000%04X %04X%04X"), hack.info, ho, oc, hack.parent );
		temp.AddLine( txt, wxTextFileType_Dos );
		SaveCodes_Hex1( old, temp );
		if ( ho == hn )
			now = old;
	}
	data.resize( hc );
	return now;
}
void	xsDLL LoadCodes_Hex1( Codes& data, TxtF& file )
{
	Text txt;
	TxtT tzr;
	TxtA block;
	for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() || txt[0] == cQuot )
			break;
		if ( txt.Contains( cSemC ) )
		{
			tzr.SetString( txt, cSemC );
			txt = tzr.GetNextToken();
		}
		block.Add( txt );
	}
	file.GetPrevLine();
	int i = 0, iEnd = block.GetCount(), c = 0, cEnd = data.size();
	MakeObj_Hex1( data, block, i, iEnd, c, cEnd );
}
void	xsDLL SaveCodes_Hex1( Codes& data, TxtF& file )
{
	TxtA block;
	MakeTxt_Hex1( data, block );
	int i = 0, iEnd = block.GetCount();
	for ( ; i < iEnd; ++i )
		file.AddLine( block[i], wxTextFileType_Dos );
}
