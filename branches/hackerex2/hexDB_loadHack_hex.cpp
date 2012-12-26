#include "hexDB_main.h"
void  xsDLL LoadCodes_Hex1( Codes& obj, TxtF& file )
{
	// TODO(awsdert) LoadCodes_Hex1( Codes&, TxtF& )
}
void	xsDLL SaveCodes_Hex1( Codes& obj, TxtF& file )
{
	// TODO(awsdert) SaveCodes_Hex1( Codes&, TxtF& )
}
Codes xsDLL LoadHacks_Hex( Hack& obj, Codes& codes, TxtF& file, TxtF& temp, Hacks& data, ui08 index, ui08 obj_index, int version, bool addifnot )
{
	if ( version < 1 || version > 1 )
		return Codes();
	Text txt;
	ui08 hi, cc;
	ui64 val;
	Hack hack;
	Codes tmp, codesr;
	bool dObj = false, dCodes = false;
	const wxChar quote = wxT('"');
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == quote )
		{
			tmp.clear();
			hack.name = txt.SubString( 1, txt.Length() - 2 );
			hack.line = file.GetCurrentLine() + 1;
			temp.AddLine( txt );
			txt = file.GetNextLine();
			GetHex( &val, txt );
			hi			= ( val & ( 0xFFFFLL << 32u ) ) >> 32u;
			hack.info	= ( val & ( 0xFFFFLL << 24u ) ) >> 24u;
			cc			= ( val & ( 0xFFFFLL << 16u ) ) >> 16u;
			hack.parent	= ( val & 0xFFFFLL );
			tmp.resize( cc );
			// Code load
			switch ( version )
			{
				case HL_HEX1: LoadCodes_Hex1( tmp, file ); break;
			}
			if ( !dObj && obj_index == hi )
			{
				tmp = codes;
				dObj = true;
			}
			if ( !dCodes && index == hi )
			{
				codesr = tmp;
				dCodes = true;
			}
			switch ( version )
			{
				case HL_HEX1: SaveCodes_Hex1( tmp, temp ); break;
			}
		}
		else
			temp.AddLine( txt );
	}
	if ( !dObj && addifnot )
		SaveCodes_Hex1( codes, temp );
	return codesr;
}
/*
bool xsDLL LoadHckT_Hex( TxtF&	file, Hacks& hacks, ui08 version )
{
	if ( file.GetLineCount() > 0 )
	{
		Text name, text;
		Hack hack;
		TxtA block;
		ui32 next = 1u;
		ui32 h = 0u, hCount = 1u;
		hacks.resize( 1u );
		long line;
		ui08 cCount = 0u; // Speedup - reduces the number of times the vector is resized
		bool b = false, done = false;
		int c;
		ui32 l;
		for
		(
			text = file.GetFirstLine()
			; hCount < 0xFFFF;
			text = file.GetNextLine()
		)
		{
			if ( text.IsEmpty() )
			{
				done = true;
				continue;
			}
			if ( next > 0u )
			{
				if ( text[ 0 ] == cQuot )
				{
					if ( next == 2u )
					{
						l = 0u;
						c = 0;
						switch ( version )
						{
						case 1u: b = MakeHack_Hex_1( hack, block, c, l ); break;
						case 2u: b = MakeHack_Hex_2( hack, block, c, l, cCount ); break;
						}
						if ( !b )
							return false;
						hacks[ h ] = hack;
					}
					block.Clear();
					hack.hckClear();
					name = text.SubString( 1u, text.Length() - 2 );
					next = 0u;
					done = false;
				}
				else if ( !done && next == 2u )
					block.Add( text );
			}
			else if ( !done )
			{
				if ( !GetHex( &line, text, 8u ) )
					return false;
				h = ( line & g_hackID ) >> 32u;
				if ( h >= hCount )
				{
					hCount	= h + 1u;
					hacks.resize( h + 1u );
				}
				hack	= hacks[ h ];
				cCount	= ( line & g_cCount ) >> 16u;
				hack.resize( cCount );
				hack.hckName	= name;
				hack.hckParent	= ( line & g_parent );
				hack.hckUse		= ( line & g_use ) >> 44u;
				next = 2u;
			}

		}
		hacks[ 0u ].hckName = _( "(m)" );
		return true;
	}
	return false;
}
*/
