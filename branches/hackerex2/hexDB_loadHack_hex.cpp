#include "hexDB_main.hpp"
bool xsDLL LoadHckT_Hex( TxtF&	file, ui08 version )
{
	if ( file.GetLineCount() > 0 )
	{
		Text name, text;
		Hack hack;
		HckV hacks;
		hacks.resize( 1u );
		TxtA block;
		ui32 next = 1u;
		ui32 h = 0u, hCount = 1u;
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
				if ( !GetHex( &line, text, 8u ) ) return false;
				h = ( line & g_hackID ) >> 32u;
				if ( h >= hCount )
				{
					hCount	= h + 1u;
					hacks.resize( hCount );
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
