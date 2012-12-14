#include "hexGUI_G.hpp"
Bin  G::LoadBins( Bin& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Bin bin, tmp;
	Text txt;
	const wxChar hOpen = wxT('[');
	const Text Def = _("Default");
	data.Add( Def );
	bool dBin = false, dObj = false;
	int i = 0;
	for ( txt = file.GetFirstLine(); !file.Eof(); ++i, txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == hOpen )
		{
			LoadBinD( tmp, file, isFileTmp );
			data.Add( tmp.nameOld );
			if ( !dBin && tmp.nameOld == name )
			{
				bin  = tmp;
				dBin = true;
			}
			if ( !dObj && obj.nameOld == tmp.nameOld )
			{
				SaveBinD( obj, temp, isTempTmp );
				dObj = true;
			}
			else
				SaveBinD( tmp, temp, isTempTmp );
		}
	}
	if ( !dObj && obj.nameOld != Def && dataNow[ HEX_LIST_BIN ] == dataOld[ HEX_LIST_BIN ] )
	{
		SaveBinD( obj, file, isTempTmp );
		data.Add( obj.nameOld );
	}
	return bin;
}
void G::LoadBinD( Bin& obj, TxtF& file, bool isTmpFile )
{
	Ram  ram;
	TxtT tzr;
	unsigned long ulVal = 0u;
	ui64 v64 = 0u;
	ui08 r = 0u, rEnd = 1u;
	Text txt, oldN, oldF, nowN, nowF, val, key;
	const wxChar hOpen	= wxT('[');
	const Text Data		= wxT("data");
	const Text eq		= wxT('=');
	const Text sc		= wxT(';');
	const Text app		= wxT("app");
	const Text win		= wxT("win");
	obj.resize( 1u, true );
	txt		= file.GetLine( file.GetCurrentLine() );
	oldN	= txt.SubString( 1, txt.Length() - 2 );
	for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() || txt[ 0u ] == hOpen )
			break;
		else
		{
			tzr.SetString( txt, eq );
			key = tzr.GetNextToken();
			val = tzr.GetNextToken();
			tzr.SetString( val, sc );
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
				key.ToULong( &ulVal );
				r = ulVal;
				ram.name	= val;
				val = tzr.GetNextToken();
				val.ToULong( &ulVal );
				ram.depth	= ulVal;
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
	obj.nameNow = nowN;
	obj.nameOld = oldN;
	obj.fileNow = nowF;
	obj.fileOld = oldF;
	file.GetPrevLine();
}
void G::SaveBinD( Bin& obj, TxtF& file, bool isTmpFile )
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
