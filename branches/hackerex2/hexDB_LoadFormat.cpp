#include "hexDB_hack.h"
void LoadFormatD( Format& obj, Text& txt, bool isTmpFile );
void SaveFormatD( Format& obj, TxtF& file, bool isTmpFile );
Format	xsDLL LoadFormats( Format& old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp )
{
	Text txt;
	Format tmp, now;
	bool dNow = false, dOld = false;
	for ( txt = file.GetFirstLine(); !file.Eof(); txt = file.GetNextLine() )
	{
		if ( txt.IsEmpty() )
			continue;
		LoadFormatD( tmp, txt, isFileTmp );
		if ( !dOld && tmp.name == old.name )
		{
			tmp  = old;
			dOld = true;
		}
		data.Add( tmp.name );
		if ( !dNow && tmp.name == name )
		{
			now  = tmp;
			dNow = true;
		}
		SaveFormatD( tmp, temp, isTempTmp );
	}
	if ( !dOld && addObj )
	{
		data.Add( old.name );
		SaveFormatD( old, temp, isTempTmp );
	}
	return now;
}
void LoadFormatD( Format& obj, Text& txt, bool isTmpFile )
{
	TxtT tzr;
	Text val;
	tzr.SetString( txt, cEqual );
	obj.name	= tzr.GetNextToken().Upper();
	obj.format	= getFormat( obj.name );
	val = tzr.GetNextToken();
	tzr.SetString( val, cSemC );
	if ( tzr.HasMoreTokens() )
		obj.fileOld = tzr.GetNextToken().Lower();
	if ( obj.fileOld.IsEmpty() )
		obj.fileOld = obj.name.Lower();
	if ( isTmpFile && tzr.HasMoreTokens() )
		obj.fileNow = tzr.GetNextToken().Lower();
	else
		obj.fileNow = obj.fileOld;
}
void SaveFormatD( Format& obj, TxtF& file, bool isTmpFile )
{
	Text txt = obj.name + cEqual + obj.fileOld.Upper();
	if ( isTmpFile )
		txt += cSemC + obj.fileNow.Upper();
	file.AddLine( txt, wxTextFileType_Dos );
}
