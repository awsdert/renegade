#include "cleanType.h"
#ifdef wx2_9_H_CPP
wxArrayString wxSplit( const wxString& str, const wxChar sep, const wxChar escape )
{
	wxArrayString array;
	wxString txt;
	wxChar   c;
	int  iCount = str.length();
	bool e = false;
	for ( int i = 0; i < iCount; ++i )
	{
		c = str[ i ];
		if ( e )
		{
			e    = false;
			txt += c;
			continue;
		}
		if ( c == escape )
		{
			e = true;
			continue;
		}
		if ( c == sep )
		{
			array.Add( txt );
			txt.Clear();
			continue;
		}
		txt += c;
	}
	if ( !txt.IsEmpty() ) array.Add( txt );
	return array;
}
#endif
