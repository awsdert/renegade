#include "wx_pch.h"
#include "hexLib_main.h"
/* *
void LoadStateD( State& obj, CfgF& file );
void LoadStateD( State& obj, Text& key, Text& val, bool isTmpFile );
void SaveStateD( State& obj, CfgF& file, bool isTmpFile );
zxDLL State LoadStates( State& old, CfgF& file, CfgF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp )
{
	Text key, val, txt, noname;
	bool dOld = false, dNow = false;
	TxtA head;
	head.SetCount( 6 );
	long i, total = 0;
	head[0] = wxT("/Sessions");
	State tmp, now;
	temp.SetPath( head[ 0 ] );
	for ( i = 1; i < 6; ++i )
	{
		head[i].Printf( wxT("/Session_%i"), i );
		if ( !file.HasGroup( head[ i ] ) )
			continue;
		file.SetPath( head[ i ] );
		noname.Printf( _("Session %i"), i );
		LoadStateD( tmp, file );
		tmp.nameNow = noname;
		tmp.nameOld = noname;
		file.SetPath( head[0] );
		SaveStateD( tmp, file, isFileTmp );
		SaveStateD( tmp, temp, isTempTmp );
		file.DeleteGroup( head[i] );
	}
	bool validEntry = false;
	file.SetPath( head[0] );
	for ( validEntry = file.GetFirstEntry( key, i ); validEntry; validEntry = file.GetNextEntry( key, i ), ++total )
	{
		if ( total >= 10 )
		{
			file.DeleteEntry( key, false );
			continue;
		}
		file.Read( key, &val );
		LoadStateD( tmp, key, val, isFileTmp );
		if ( !dOld && key == old.nameOld )
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
		SaveStateD( tmp, temp, isTempTmp );
	}
	if ( !dOld&& old.nameOld != getGlobalName() && total < 11 )
	{
		data.Add( old.nameNow );
		SaveStateD( old, temp, isTempTmp );
	}
	return now;
}
void LoadStateD( State& obj, CfgF& file )
{
	const Text Def = getGlobalName();
	file.Read( wxT("Organisation"),	&obj.orgName, Def );
	file.Read( wxT("Platform"),		&obj.pfmName, Def );
	file.Read( wxT("Binary"),		&obj.binName, Def );
	file.Read( wxT("Profile"),		&obj.pflName, Def );
}
void LoadStateD( State& obj, Text& key, Text& val, bool isTmpFile )
{
	TxtT tzr;
	Text now;
	tzr.SetString( val, cSemC );
	obj.orgName = tzr.GetNextToken();
	obj.pfmName = tzr.GetNextToken();
	obj.binName = tzr.GetNextToken();
	obj.pflName = tzr.GetNextToken();
	if ( tzr.HasMoreTokens() )
		obj.hckFormat = tzr.GetNextToken().Upper();
	else
		obj.hckFormat = getFormatName( HL_HEX1 );
	if ( isTmpFile && tzr.HasMoreTokens() )
		now = tzr.GetNextToken();
	else
		now = key;
	obj.nameNow = now;
	obj.nameOld = key;
}
void SaveStateD( State& obj, CfgF& file, bool isTmpFile )
{
	Text txt = obj.orgName;
	txt += cSemC + obj.pfmName;
	txt += cSemC + obj.binName;
	txt += cSemC + obj.pflName;
	txt += cSemC + obj.hckFormat;
	if ( isTmpFile )
		txt += cSemC + obj.nameNow;
	file.Write( obj.nameOld, txt );
}
/* */