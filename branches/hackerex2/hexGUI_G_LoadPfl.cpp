#include "hexGUI_G.hpp"
Pfl  G::LoadPfls( Pfl& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Pfl pfl, tmp;
	Text txt;
	bool dPfl = false, dObj = false;
	const wxChar hOpen = wxT('[');
	const Text Def = _("Default");
	data.Add( Def );
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() )
			continue;
		if ( txt[ 0 ] == hOpen )
		{
			LoadPflD( tmp, file, isFileTmp );
			data.Add( tmp.nameOld );
			if ( !dPfl && tmp.nameOld == name )
			{
				pfl  = tmp;
				dPfl = true;
			}
			if ( !dObj && tmp.nameOld == obj.nameOld )
			{
				SavePflD( obj, temp, isTempTmp );
				dObj = true;
			}
			else
				SavePflD( tmp, temp, isTempTmp );
		}
	}
	if ( !dObj && obj.nameOld != Def && dataNow[ HEX_LIST_PFL ] == dataOld[ HEX_LIST_PFL ] )
	{
		SavePflD( obj, temp, isTempTmp );
		data.Add( obj.nameOld );
	}
	return pfl;
}
void G::LoadPflD( Pfl& obj, TxtF& file, bool isTmpFile )
{
	const wxChar hOpen = wxT('[');
	const Text del = wxT('=');
	const Text sc = wxT(';');
	const Text fs = wxT('\\');
	Text txt	= file.GetLine( file.GetCurrentLine() );
	Text oldN	= txt.SubString( 1, txt.Length() - 2 );
	Text val, nowN, nowF;
	TxtT tzr;
	ui16 pid = 0u;
	txt = file.GetNextLine();
	tzr.SetString( txt, sc );
	tzr.GetNextToken();
	Text oldF	= tzr.GetNextToken();
	obj.region	= CheckRegion( tzr.GetNextToken() );
	obj.serial	= tzr.GetNextToken();
	GetHex( &pid, tzr.GetNextToken(), 2u );
	obj.profile	= pid;
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
	for ( txt = file.GetNextLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0u ] == hOpen )
			break;
		if ( txt.StartsWith( fs ) )
			txt = txt.Right( txt.Length() - 2 );
		obj.notes += txt;
	}
	obj.fileNow = nowF;
	obj.fileOld = oldF;
	obj.nameNow = nowN;
	obj.nameOld = oldN;
	file.GetPrevLine();
}
void G::SavePflD( Pfl& obj, TxtF& file, bool isTmpFile )
{
	TxtT tzr;
	Text txt, val;
	const Text nl = wxT('\n');
	const wxChar sColon	= wxT(';');
	const wxChar hOpen	= wxT('[');
	const wxChar fSlash	= wxT('\\');
	txt = hOpen + obj.nameOld + wxT(']');
	file.AddLine( txt, wxTextFileType_Dos );
	// Data
	txt = obj.fileOld;
	txt += fSlash + CheckRegion( obj.region );
	txt += fSlash + obj.serial;
	val.Printf( wxT("%u"), obj.profile );
	txt += fSlash + val;
	if ( isTmpFile )
		txt += fSlash + obj.nameNow + fSlash + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
	// Notes
	val = HexNotes_TA->GetValue();
	tzr.SetString( val, nl );
	for ( txt = tzr.GetNextToken(); tzr.HasMoreTokens(); txt = tzr.GetNextToken() )
	{
		if ( txt[ 0u ] == fSlash || txt[ 0u ] == hOpen || txt[ 0u ] == sColon )
			txt = fSlash + txt;
		file.AddLine( txt, wxTextFileType_Dos );
	}
}
