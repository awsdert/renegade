#include "hex2_G.h"
Org  G::LoadOrgs( Org& old, CfgF& file, CfgF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Text key, val;
	const Text Def	= getGlobalName();
	const Text head = wxT("/Organisation");
	file.SetPath( head );
	temp.SetPath( head );
	long i;
	data.Add( Def );
	bool dNow = false, dOld = false;
	Org now, tmp;
	bool validEntry = false;
	for ( validEntry = file.GetFirstEntry( key, i ); validEntry; validEntry = file.GetNextEntry( key, i ) )
	{
		file.Read( key, &val, key );
		LoadOrgD( tmp, key, val, isFileTmp );
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
		SaveOrgD( tmp, temp, isTempTmp );
	}
	if ( !dOld && old.nameOld != Def )
	{
		data.Add( old.nameNow );
		SaveOrgD( old, temp, isTempTmp );
	}
	return now;
}
void G::LoadOrgD( Org& obj, Text& key, Text& val, bool isTmpFile )
{
	TxtT tzr;
	Text oldN = key, oldF, nowN, nowF;
	tzr.SetString( val, cSemC );
	oldF = tzr.GetNextToken();
	if ( isTmpFile && tzr.HasMoreTokens() )
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
}
void G::SaveOrgD( Org& obj, CfgF& file, bool isTmpFile )
{
	Text txt = obj.fileOld;
	if ( isTmpFile )
		txt += cSemC + obj.nameNow + cSemC + obj.fileNow;
	file.Write( obj.nameOld, txt );
}
