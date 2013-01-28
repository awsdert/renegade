#include "hex2_global.h"
#include "hexDB_hack.h"

#ifndef HEXGUI_DB_H
#define HEXGUI_DB_H

enum
{
	HEX_LIST_THEME = 0,
	HEX_LIST_SESSION,
	HEX_LIST_ORG,
	HEX_LIST_PFM,
	HEX_LIST_BIN,
	HEX_LIST_APP,
	HEX_LIST_WIN,
	HEX_LIST_RAM,
	HEX_LIST_PFL,
	HEX_LIST_FORMAT,
	HEX_LIST_HACK,
	HEX_LIST_CODE,
	HEX_LIST_FIND,
	HEX_LIST_OUT,
	HEX_LIST_EDIT,
	HEX_LIST_COUNT
};

xsDLL Text getGlobalName( void );

class xsDLL State
{
public:
	State();
	void clear();
	Text nameNow;
	Text nameOld;
	Text orgName;
	Text pfmName;
	Text binName;
	Text pflName;
	Text hckFormat;
};
//*/
class xsDLL Org
{
public:
	Org( void );
	Text fileNow;
	Text fileOld;
	Text nameNow;
	Text nameOld;
};

class xsDLL Pfm : public Org
{
public:
	Pfm( void );
	ui08 endian;
};

class xsDLL Ram
{
public:
	Ram( void );
	void clear( void );
	ui64 addr;
	ui08 depth;
	ui64 bytes;
	Text name;
};

class xsDLL Bin : public Org, public xsArray< Ram, 0x10 >
{
public:
	Bin( void );
	Text name;
	Text path;
	ui08 type;
	ui08 ramNo;
};

#define REGION_ALL	0xFFFFFFFF
#define REGION_UK	0x1
#define REGION_US	0x10
#define REGION_DE	0x2
#define REGION_JP	0x100
#define REGION_AUS	0x8

class xsDLL Pfl : public Org
{
public:
	Pfl( void );
	ui32 region;
	ui16 profile;
	Text serial;
	Text notes;
};

xsDLL State	LoadStates(	State&	old, CfgF& file, CfgF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp );
xsDLL Org	LoadOrgs(	Org&	old, CfgF& file, CfgF& temp, TxtA& data, Text name, bool isFileTmp, bool isTempTmp );
xsDLL Pfm	LoadPfms(	Pfm&	old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );
xsDLL Bin	LoadBins(	Bin&	old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );

xsDLL int	getRegionCount( void );
xsDLL void	getRegionData( TxtA& data );
xsDLL void	getRegions( ui32* data );
xsDLL ui32	CheckRegion( Text region );
xsDLL Text	CheckRegion( ui32 region );
xsDLL Pfl	LoadPfls(	Pfl&	old, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );

#endif
