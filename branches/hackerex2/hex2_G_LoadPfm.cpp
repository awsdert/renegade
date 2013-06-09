#include "wx_pch.h"
#include "hex2_G.h"
/* *
void LoadPfmD( Pfm& obj, TxtF& file, bool isTmpFile );
void SavePfmD( Pfm& obj, TxtF& file, bool isTmpFile );
xsDLL Pfm	LoadPfms( Pfm& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
{
	Text txt;
	const Text Def = getGlobalName();
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
		if ( !dObj && tmp.nameOld == obj.nameOld && addObj )
		{
			tmp  = obj;
			dObj = true;
		}
		data.Add( tmp.nameNow );
		if ( !dPfm && tmp.nameNow == name )
		{
			pfm  = tmp;
			dPfm = true;
		}
		SavePfmD( tmp, temp, isTempTmp );
	}
	if ( !dObj && obj.nameOld != Def && addObj )
	{
		SavePfmD( obj, temp, isTempTmp );
		data.Add( obj.nameNow );
	}
	return pfm;
}
void LoadPfmD( Pfm& obj, TxtF& file, bool isTmpFile )
{
	TxtT tzr;
	ui08 edn = 0u;
	Text txt = file.GetLine( file.GetCurrentLine() ), val;
	Text oldN, oldF, nowN, nowF;
	tzr.SetString( txt, cEqual );
	oldN = tzr.GetNextToken();
	val  = tzr.GetNextToken();
	tzr.SetString( val, cSemC );
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
void SavePfmD( Pfm& obj, TxtF& file, bool isTmpFile )
{
	Text txt, eTxt;
	eTxt.Printf( wxT( "%u" ), obj.endian );
	txt = obj.nameOld + cEqual + obj.fileOld + cSemC + eTxt;
	if ( isTmpFile )
		txt += cSemC + obj.nameNow + cSemC + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
}
/* */