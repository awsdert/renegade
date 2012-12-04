#include "hexGUI_G.hpp"
void G::SaveData( int inMode )
{
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		inMode = m_ListNow;
	TxtF file, temp;
	const wxChar tild = wxT('~');
	Text path, leaf, subP, nowP, tmpP;
	if ( !CheckFilesT( path, leaf, subP ) )
		return;
	nowP = path + m_sep + leaf;
	tmpP = nowP + tild;
	if ( !wxFileExists( tmpP ) )
		temp.Create( tmpP );
	if ( !file.Open( nowP ) || !temp.Open( tmpP ) )
		return;
	file.Clear();
	switch ( inMode )
	{
		case HEX_LIST_ORG:
		{
			OrgV dat1;
			LoadOrgs( dat1, temp );
			SaveOrgs( dat1, temp, file, false );
			break;
		}
		case HEX_LIST_PFM:
		{
			PfmV dat2;
			LoadPfms( dat2, temp );
			SavePfms( dat2, file, false );
			break;
		}
	}
	file.Close();
	temp.Close();
	wxRemoveFile( tmpP );
}
void G::SaveOrgs( OrgV& dat, TxtF& file, TxtF& temp, bool isTmpFile )
{
	Text lineTxt;
	const Text orgHead = wxT("[Organisation]");
	const wxChar sc = wxT(';');
	bool inOrg = false, done = false;
	Org obj;
	for
	(
		lineTxt = file.GetFirstLine();
		!file.Eof();
		lineTxt = file.GetNextLine()
	)
	{
		if ( !inOrg )
		{
			if ( !done && lineTxt == orgHead )
			{
				inOrg = true;
				done = true;
				continue;
			}
			temp.AddLine( lineTxt, wxTextFileType_Dos );
		}
		else if ( lineTxt.IsEmpty() )
			inOrg = false;
	}
	int i, iEnd = dat.size();
	lineTxt.Clear();
	temp.AddLine( lineTxt, wxTextFileType_Dos );
	temp.AddLine( orgHead, wxTextFileType_Dos );
	for ( i = 1; i < iEnd; ++i )
	{
		obj = dat[ i ];
		lineTxt = obj.nameOld + wxT("=") + obj.fileOld;
		if ( isTmpFile )
			lineTxt += sc + obj.nameNow + sc + obj.fileNow;
		temp.AddLine( lineTxt, wxTextFileType_Dos );
	}
	temp.Write( wxTextFileType_Dos );
}
void G::SavePfms( PfmV& dat, TxtF& file, bool isTmpFile )
{
	Text lineTxt, eTxt;
	Pfm obj;
	ui08 edn = 0u;
	const wxChar del = wxT('=');
	const wxChar sc = wxT(';');
	int i, iEnd = dat.size();
	for ( i = 1; i < iEnd; ++i )
	{
		obj = dat[ i ];
		edn = obj.endian;
		GetTxt( eTxt, &edn );
		lineTxt = obj.nameOld + del + obj.fileOld + sc + eTxt;
		if ( isTmpFile )
			lineTxt += sc + obj.nameNow + sc + obj.fileNow;
		file.AddLine( lineTxt, wxTextFileType_Dos );
	}
	file.Write( wxTextFileType_Dos );
}
