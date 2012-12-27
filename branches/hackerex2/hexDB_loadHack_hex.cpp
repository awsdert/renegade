#include "hexDB_main.h"
Codes	xsDLL LoadHacks( Codes& old, TxtF& file, TxtF& temp, Hacks& data, ui16 pid, int format )
{
	switch ( format )
	{
	case HL_HEX1: return LoadHacks_Hex( old, file, temp, data, 1 );
	case HL_HEX2: return LoadHacks_Hex( old, file, temp, data, 2 );
	default: return Codes();
	}
}
Codes	xsDLL LoadHacks_Hex( Codes& old, TxtF& file, TxtF& temp, Hacks& data, int version )
{
	if ( version < 1 || version > 1 )
		return Codes();
	Text txt;
	ui16 hi, hn = data.hackNow, ho = data.hackOld, cc, hc = 1u;
	ui64 val;
	Hack hack;
	Codes tmp, now;
	bool dOld = false, dNow = false;
	data.resize( 1 );
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == cQuot )
		{
			tmp.clear();
			hack.name = txt.SubString( 1, txt.Length() - 2 );
			hack.line = file.GetCurrentLine() + 1;
			temp.AddLine( txt, wxTextFileType_Dos );
			txt = file.GetNextLine();
			txt.Replace( wxT(" "), wxT("") );
			GetHex( &val, txt, 8u );
			hack.info	= GETHEX( val, 0xFLL, 56u );
			hi			= GETHEX( val, 0xFFFFLL, 32u );
			cc			= GETHEX( val, 0xFFFFLL, 16u );
			hack.parent	= ( val & 0xFFFFLL );
			tmp.resize( cc );
			temp.AddLine( txt, wxTextFileType_Dos );
			// Code load
			switch ( version )
			{
				case HL_HEX1: LoadCodes_Hex1( tmp, file ); break;
			}
			if ( !dOld && ho == hi )
			{
				tmp  = old;
				dOld = true;
			}
			if ( hi >= hc )
			{
				hc = hi + 1u;
				data.resize( hc );
			}
			data[ hi ] = hack;
			if ( !dNow && hn == hi )
			{
				now  = tmp;
				dNow = true;
			}
			switch ( version )
			{
				case HL_HEX1: SaveCodes_Hex1( tmp, temp ); break;
			}
		}
		else
			temp.AddLine( txt );
	}
	if ( !dOld )
	{
		hack = data[ ho ];
		txt = cBrS + hack.name + wxT(']');
		temp.AddLine( txt, wxTextFileType_Dos );
		cc = old.size();
		txt.Printf( wxT("%01X000%04X %04X%04X"), hack.info, ho, cc, hack.parent );
		temp.AddLine( txt, wxTextFileType_Dos );
		SaveCodes_Hex1( old, temp );
	}
	return now;
}
void	xsDLL LoadCodes_Hex1( Codes& data, TxtF& file )
{
	Text txt;
	TxtA block;
	for ( txt = file.GetLine( file.GetCurrentLine() ); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() || txt[0] == cQuot )
			break;
		block.Add( txt );
	}
	file.GetPrevLine();
	int i = 0, iEnd = block.GetCount();
	MakeObj_Hex1( data, block, i, iEnd );
}
void	xsDLL SaveCodes_Hex1( Codes& data, TxtF& file )
{
	TxtA block;
	MakeTxt_Hex1( data, block );
	int i = 0, iEnd = block.GetCount();
	for ( ; i < iEnd; ++i )
		file.AddLine( block[i], wxTextFileType_Dos );
}
