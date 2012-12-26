#include "hex2_G.h"
Pfl  G::LoadPfls( Pfl& old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
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
void G::LoadPflD( Pfl& obj, TxtF& file, bool isTmpFile )
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
	txt = cBrS + obj.nameOld + wxT(']');
	file.AddLine( txt, wxTextFileType_Dos );
	// Data
	txt = obj.fileOld;
	txt += cBS + CheckRegion( obj.region );
	txt += cBS + obj.serial;
	val.Printf( wxT("%u"), obj.profile );
	txt += cBS + val;
	if ( isTmpFile )
		txt += cBS + obj.nameNow + cBS + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
	// Notes
	val = HexNotes_TA->GetValue();
	tzr.SetString( val, nl );
	for ( txt = tzr.GetNextToken(); tzr.HasMoreTokens(); txt = tzr.GetNextToken() )
	{
		if ( txt[ 0 ] == cBS || txt[ 0 ] == cBrS || txt[ 0 ] == cSemC )
			txt = cBS + txt;
		file.AddLine( txt, wxTextFileType_Dos );
	}
}
