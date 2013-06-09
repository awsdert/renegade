#include "wx_pch.h"
#include "hexDB_main.h"
/* *
void LoadPflD( Pfl& obj, TxtF& file, bool isTmpFile );
void SavePflD( Pfl& obj, TxtF& file, bool isTmpFile );
xsDLL Pfl  LoadPfls( Pfl& old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
{
	Pfl now, tmp;
	Text txt;
	const Text Def = getGlobalName();
	bool dNow = false, dOld = false;
	data.Add( Def );
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt[ 0 ] == cBrS )
		{
			LoadPflD( tmp, file, isFileTmp );
			if ( !dOld && tmp.nameOld == old.nameOld )
			{
				tmp  = old;
				dOld = true;
			}
			data.Add( tmp.nameNow );
			if ( !dNow && tmp.nameNow == name )
			{
				now  = tmp;
				dNow = true;
			}
			SavePflD( tmp, temp, isTempTmp );
		}
	}
	if ( !dOld && addObj && old.nameOld != Def )
	{
		SavePflD( old, temp, isTempTmp );
		data.Add( old.nameNow );
	}
	return now;
}
void LoadPflD( Pfl& obj, TxtF& file, bool isTmpFile )
{
	Text txt	= file.GetLine( file.GetCurrentLine() );
	Text oldN	= txt.SubString( 1, txt.Length() - 2 );
	Text val, nowN, nowF;
	TxtT tzr;
	ui16 pid = 0u;
	txt = file.GetNextLine();
	tzr.SetString( txt, cSemC );
	tzr.GetNextToken();
	Text oldF	= tzr.GetNextToken();
	obj.region	= CheckRegion( tzr.GetNextToken() );
	obj.serial	= tzr.GetNextToken();
	GetHex( &pid, tzr.GetNextToken(), 2u );
	obj.profile	= pid;
	const wxChar cNL = wxT('\n');
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
		if ( txt[ 0 ] == cBrS )
			break;
		if ( txt[ 0 ] == cBS )
			txt = txt.Right( txt.Length() - 2 );
		obj.notes += cNL + txt;
	}
	obj.notes = obj.notes.Right( txt.Length() - 3 );
	obj.fileNow = nowF;
	obj.fileOld = oldF;
	obj.nameNow = nowN;
	obj.nameOld = oldN;
	file.GetPrevLine();
}
void SavePflD( Pfl& obj, TxtF& file, bool isTmpFile )
{
	TxtT tzr;
	Text txt, val;
	const Text nl = wxT('\n');
	txt = cBrS + obj.nameOld + wxT(']');
	file.AddLine( txt, wxTextFileType_Dos );
	// Data
	txt = cSemC + obj.fileOld;
	txt += cSemC + CheckRegion( obj.region );
	txt += cSemC + obj.serial;
	val.Printf( wxT("%01u"), obj.profile );
	txt += cSemC + val;
	if ( isTmpFile )
		txt += cSemC + obj.nameNow + cSemC + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
	// Notes
	tzr.SetString( obj.notes, nl );
	for ( txt = tzr.GetNextToken(); tzr.HasMoreTokens(); txt = tzr.GetNextToken() )
	{
		if ( txt[ 0 ] == cBS || txt[ 0 ] == cBrS || txt[ 0 ] == cSemC )
			txt = cBS + txt;
		file.AddLine( txt, wxTextFileType_Dos );
	}
}
/* */