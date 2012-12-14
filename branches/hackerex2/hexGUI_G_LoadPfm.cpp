#include "hexGUI_G.hpp"
Pfm  G::LoadPfms( Pfm& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Text txt;
	const Text Def	= _("Default");
	data.Add( Def );
	bool dPfm = false, dObj = false;
	Pfm pfm, tmp;
	for
	(
		txt = file.GetFirstLine();
		!file.Eof();
		txt = file.GetNextLine()
	)
	{
		if ( txt.IsEmpty() )
			continue;
		LoadPfmD( tmp, file, isFileTmp );
		data.Add( tmp.nameOld );
		if ( !dPfm && tmp.nameOld == name )
		{
			pfm  = tmp;
			dPfm = true;
		}
		if ( !dObj && tmp.nameOld == obj.nameOld )
		{
			SavePfmD( obj, temp, isTempTmp );
			dObj = true;
		}
		else
			SavePfmD( tmp, temp, isTempTmp );
	}
	if ( !dObj && obj.nameOld != Def && dataNow[ HEX_LIST_PFM ] == dataOld[ HEX_LIST_PFM ] )
	{
		SavePfmD( obj, temp, isTempTmp );
		data.Add( obj.nameOld );
	}
	return pfm;
}
void G::LoadPfmD( Pfm& obj, TxtF& file, bool isTmpFile )
{
	TxtT tzr;
	ui08 edn = 0u;
	const Text eq = wxT('=');
	const Text sc = wxT(';');
	Text txt = file.GetLine( file.GetCurrentLine() ), val;
	Text oldN, oldF, nowN, nowF;
	tzr.SetString( txt, eq );
	oldN = tzr.GetNextToken();
	val  = tzr.GetNextToken();
	tzr.SetString( val, sc );
	oldF = tzr.GetNextToken();
	GetHex( &edn, tzr.GetNextToken() );
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
	obj.nameOld = oldN;
	obj.fileOld = oldF;
	obj.nameNow = nowN;
	obj.fileNow = nowF;
	obj.endian	= edn;
}
void G::SavePfmD( Pfm& obj, TxtF& file, bool isTmpFile )
{
	Text txt, eTxt, sc = wxT(';');
	eTxt.Printf( wxT( "%u" ), obj.endian );
	txt = obj.nameOld + wxT('=') + obj.fileOld + sc + eTxt;
	if ( isTmpFile )
		txt += sc + obj.nameNow + sc + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
}
