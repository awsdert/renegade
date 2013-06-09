#include "wx_pch.h"
#include "hexDB_main.h"
/* *
void LoadBinD( Bin& obj, TxtF& file, bool isTmpFile );
void SaveBinD( Bin& obj, TxtF& file, bool isTmpFile );
xsDLL Bin  LoadBins( Bin& m_now, Bin& m_old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
{
	Bin src, tmp, now, old;
	Text txt;
	const Text Def = getGlobalName();
	const wxChar hOpen = wxT('[');
	data.Add( Def );
	bool dNow = false, dOld = false;
	int i = 0;
	for ( txt = file.GetFirstLine(); !file.Eof(); ++i, txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == hOpen )
		{
			LoadBinD( src, tmp, file, isFileTmp );
			if ( !dOld && m_old.name == src.name )
			{
				src  = m_now;
				tmp	 = m_old;
				dOld = true;
			}
			data.Add( src.name );
			if ( !dNow && src.name == name )
			{
				now  = src;
				old  = tmp;
				dNow = true;
			}
			SaveBinD( tmp, temp, isTempTmp );
		}
	}
	i = HEX_LIST_BIN;
	if ( !dOld && m_now.name != Def && addObj )
	{
		SaveBinD( m_now, m_now, file, isTempTmp );
		data.Add( m_now.name );
	}
	return now;
}
void LoadBinD( Bin& now, Bin& old, TxtF& file, bool isTmpFile )
{
	Ram  ram;
	TxtT tzr;
	ui64 v64 = 0u;
	ui08 r = 0u, rEnd = 1u;
	Text txt, oldN, oldF, nowN, nowF, val, key;
	const Text Data		= wxT("data");
	const Text app		= wxT("app");
	const Text win	    = wxT("win");
	now.clear();
	old.clear();
	now.resize( 1u );
	old.resize( 1u );
	txt		= file.GetLine( file.GetCurrentLine() );
	oldN	= txt.SubString( 1, txt.Length() - 2 );
	for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() || txt[ 0u ] == cBrS )
			break;
		else
		{
			tzr.SetString( txt, cEqual );
			key = tzr.GetNextToken();
			val = tzr.GetNextToken();
			tzr.SetString( val, cSemC );
			val = tzr.GetNextToken();
			if ( key == Data )
			{
				val.LowerCase();
				if ( val == app )
					now.type = 1u;
				else if ( val == win )
					now.type = 2u;
				else
					now.type = 0u;
				oldF = tzr.GetNextToken();
				now.name = tzr.GetNextToken();
				now.path = tzr.GetNextToken();
				now.path.Replace( wxT("\\\\"), wxT("\\"), true );
				if ( isTmpFile )
				{
					nowN = tzr.GetNextToken();
					nowF = tzr.GetNextToken();
				}
				else
				{
					nowN = oldN;
					nowF = oldF;
				}
			}
			else
			{
				GetHexFromUI( &r, key );
				ram.name	= val;
				GetHexFromUI( &( ram.depth ), tzr.GetNextToken() );
				GetHex( &v64, tzr.GetNextToken(), 8u );
				ram.addr	= v64;
				GetHex( &v64, tzr.GetNextToken(), 8u );
				ram.bytes	= v64;
				if ( r >= rEnd )
				{
					rEnd = r + 1;
					now.resize( rEnd );
				}
				now[ r ] = ram;
			}
		}
	}
	txt = now.name;
	if ( !osDotExe.IsEmpty() && txt.EndsWith( osDotExe ) )
		now.name = txt.Left( txt.Length() - osDotExe.Length() );
	now.name = nowN;
	old.name = oldN;
	now.file = nowF;
	old.file = oldF;
	file.GetPrevLine();
}
void SaveBinD( Bin& now, Bin& old, TxtF& file, bool isTmpFile )
{
	Ram ram;
	Text txt, val;
	const wxChar eq = wxT('=');
	const wxChar sc = wxT(';');
	txt = wxT('[') + old.name + wxT(']');
	file.AddLine( txt, wxTextFileType_Dos );
	txt = wxT("data=");
	switch ( now.type )
	{
		case 1u: txt += wxT("app"); break;
		case 2u: txt += wxT("win"); break;
		default: txt += wxT("file");
	}
	txt += sc + old.file + sc + old.name + sc + old.path;
	if ( isTmpFile )
		txt += sc + now.name + sc + now.file;
	file.AddLine( txt, wxTextFileType_Dos );
	ui08 j, jEnd = now.size();
	for ( j = 0u; j < jEnd; ++j )
	{
		ram = now[ j ];
		txt.Clear();
		txt.Printf( wxT( "%u" ), j );
		txt += eq + ram.name;
		val.Printf( wxT( "%u" ), ram.depth );
		txt += sc + val;
		val.Printf( wxT( "%llu" ), ram.addr );
		txt += sc + val;
		val.Printf( wxT( "%llu" ), ram.bytes );
		txt += sc + val;
		file.AddLine( txt, wxTextFileType_Dos );
	}
}
/* */