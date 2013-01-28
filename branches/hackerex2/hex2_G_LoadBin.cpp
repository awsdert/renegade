#include "wx_pch.h"
#include "hexDB_main.h"
void LoadBinD( Bin& obj, TxtF& file, bool isTmpFile );
void SaveBinD( Bin& obj, TxtF& file, bool isTmpFile );
xsDLL Bin  LoadBins( Bin& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
{
	Bin bin, tmp;
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
			LoadBinD( tmp, file, isFileTmp );
			if ( !dOld && obj.nameOld == tmp.nameOld )
			{
				tmp  = obj;
				dOld = true;
			}
			data.Add( tmp.nameNow );
			if ( !dNow && tmp.nameNow == name )
			{
				bin  = tmp;
				dNow = true;
			}
			SaveBinD( tmp, temp, isTempTmp );
		}
	}
	i = HEX_LIST_BIN;
	if ( !dOld && obj.nameOld != Def && addObj )
	{
		SaveBinD( obj, file, isTempTmp );
		data.Add( obj.nameNow );
	}
	return bin;
}
void LoadBinD( Bin& obj, TxtF& file, bool isTmpFile )
{
	Ram  ram;
	TxtT tzr;
	ui64 v64 = 0u;
	ui08 r = 0u, rEnd = 1u;
	Text txt, oldN, oldF, nowN, nowF, val, key;
	const Text Data		= wxT("data");
	const Text app		= wxT("app");
	const Text win		= wxT("win");
	obj.resize( 0u );
	obj.resize( 1u );
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
					obj.type = 1u;
				else if ( val == win )
					obj.type = 2u;
				else
					obj.type = 0u;
				oldF = tzr.GetNextToken();
				obj.name = tzr.GetNextToken();
				obj.path = tzr.GetNextToken();
				obj.path.Replace( wxT("\\\\"), wxT("\\"), true );
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
					obj.resize( rEnd );
				}
				obj[ r ] = ram;
			}
		}
	}
	txt = obj.name;
	if ( !osDotExe.IsEmpty() && txt.EndsWith( osDotExe ) )
		obj.name = txt.Left( txt.Length() - osDotExe.Length() );
	obj.nameNow = nowN;
	obj.nameOld = oldN;
	obj.fileNow = nowF;
	obj.fileOld = oldF;
	file.GetPrevLine();
}
void SaveBinD( Bin& obj, TxtF& file, bool isTmpFile )
{
	Ram ram;
	Text txt, val;
	const wxChar eq = wxT('=');
	const wxChar sc = wxT(';');
	txt = wxT('[') + obj.nameOld + wxT(']');
	file.AddLine( txt, wxTextFileType_Dos );
	txt = wxT("data=");
	switch ( obj.type )
	{
		case 1u: txt += wxT("app"); break;
		case 2u: txt += wxT("win"); break;
		default: txt += wxT("file");
	}
	txt += sc + obj.fileOld + sc + obj.name + sc + obj.path;
	if ( isTmpFile )
		txt += sc + obj.nameNow + sc + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
	ui08 j, jEnd = obj.size();
	for ( j = 0u; j < jEnd; ++j )
	{
		ram = obj[ j ];
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
