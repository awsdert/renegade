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

class xsDLL State : public dBase
{
public:
	State();
	void clear();
	Text orgName;
	Text pfmName;
	Text binName;
	Text pflName;
	Text fmtName;
};
//*/
class xsDLL Org : public dBase
{
public:
	Org( void );
	Text file;
	bool operator!= ( Org &obj ) { return ( name != obj.name || file != obj.file ); };
	bool operator== ( Org &obj ) { return ( name == obj.name && file == obj.file ); };
};
enum
{
	HEX_ENDIAN_LITTLE = 0,
	HEX_ENDIAN_BIG,
	HEX_ENDIAN_LBIG,
	HEX_ENDIAN_COUNT
};
class xsDLL Pfm : public Org
{
public:
	Pfm( void );
	ui08 endian;
	bool operator!= ( Pfm &obj ) { return ( name != obj.name || file != obj.file || endian != obj.endian ); };
	bool operator== ( Pfm &obj ) { return ( name == obj.name && file == obj.file && endian == obj.endian ); };
};

class xsDLL Ram : public dBase
{
public:
	Ram( void );
	void clear( void );
	ui64 addr, bytes;
	ui08 depth;
	bool operator!= ( Ram &obj ) { return ( name != obj.name || addr != obj.addr || depth != obj.depth || bytes != obj.bytes ); };
	bool operator== ( Ram &obj ) { return ( name == obj.name && addr == obj.addr && depth == obj.depth && bytes == obj.bytes ); };
};

class xsDLL Bin : public Org, public xsArray< Ram, 0x10 >
{
public:
	Bin( void );
	Text bind, path;
	ui08 type, ramNo;
	ui16 done;
	bool operator!= ( Bin& obj )
	{
		if ( name != obj.name || file != obj.file || bind != obj.bind || path != obj.path || type != obj.type || m_count != obj.m_count )
			return true;
		else
		{
			for ( ui32 i = 0u; i < m_count; ++i )
			{
				if ( at( i ) != obj[ i ] )
					return true;
			}
			return false;
		}
	};
	bool operator== ( Bin& obj )
	{
		if ( name != obj.name || file != obj.file || bind != obj.bind || path != obj.path || type != obj.type || m_count != obj.m_count )
			return false;
		else
		{
			for ( ui32 i = 0u; i < m_count; ++i )
			{
				if ( at( i ) != obj[ i ] )
					return false;
			}
			return true;
		}
	};
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
	Text serial, notes;
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
