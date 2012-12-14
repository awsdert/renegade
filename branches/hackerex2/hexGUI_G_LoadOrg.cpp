#include "hexGUI_G.hpp"
Org  G::LoadOrgs( Org& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Text txt, val;
	TxtT tzr;
	const wxChar hOpen = wxT('[');
	const Text head = wxT("[Organisation]");
	const Text eq	= wxT('=');
	const Text Def	= _("Default");
	data.Add( Def );
	bool inOrg = false, dOrg = false, dObj = false, done = false;
	Org org, tmp;
	for
	(
		txt = file.GetFirstLine();
		!file.Eof();
		txt = file.GetNextLine()
	)
	{
		if ( !inOrg )
		{
			inOrg = ( !done && txt == head );
			temp.AddLine( txt, wxTextFileType_Dos );
		}
		else
		{
			if ( txt.IsEmpty() || txt[ 0u ] == hOpen )
			{
				if ( !dObj && obj.nameOld != Def )
				{
					SaveOrgD( obj, temp, isTempTmp );
					data.Add( obj.nameOld );
				}
				temp.AddLine( txt, wxTextFileType_Dos );
				done = true;
				inOrg = false;
				continue;
			}
			tzr.SetString( txt, eq );
			val = tzr.GetNextToken();
			data.Add( val );
			LoadOrgD( tmp, file, isFileTmp );
			if ( !dOrg && val == name )
			{
				org  = tmp;
				dOrg = true;
			}
			if ( !dObj && val == obj.nameOld )
			{
				SaveOrgD( obj, temp, isTempTmp );
				dObj = true;
			}
			else
				SaveOrgD( tmp, temp, isTempTmp );
		}
	}
	return org;
}
void G::LoadOrgD( Org& obj, TxtF& file, bool isTmpFile )
{
	TxtT tzr;
	const Text eq = wxT('=');
	const Text sc = wxT(';');
	Text oldN, oldF, nowN, nowF, txt;
	txt = file.GetLine( file.GetCurrentLine() );
	tzr.SetString( txt, eq );
	oldN = tzr.GetNextToken();
	txt = tzr.GetNextToken();
	if ( isTmpFile )
	{
		tzr.SetString( txt, sc );
		oldF = tzr.GetNextToken();
		nowN = tzr.GetNextToken();
		nowF = tzr.GetNextToken();
	}
	else
	{
		oldF = txt;
		nowN = oldN;
		nowF = txt;
	}
	obj.nameOld = oldN;
	obj.fileOld = oldF;
	obj.nameNow = nowN;
	obj.fileNow = nowF;
}
void G::SaveOrgD( Org& obj, TxtF& file, bool isTmpFile )
{
	const wxChar eq = wxT('=');
	const wxChar sc = wxT(';');
	Text txt = obj.nameOld + eq + obj.fileOld;
	if ( isTmpFile )
		txt += sc + obj.nameNow + sc + obj.fileNow;
	file.AddLine( txt, wxTextFileType_Dos );
}
