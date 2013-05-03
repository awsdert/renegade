#include "hex2_global.h"

#ifndef HEXDB_HACK_H
#define HEXDB_HACK_H

#define HACK_USE	0x1
#define HACK_RL		0x2
// This is for runtime use only, should not be stored to file
#define HACK_IMPORT 0x10

#define HEX_CT_WRITE	0u
#define HEX_CT_COPY		1u
#define HEX_CT_INC		2u
#define HEX_CT_DEC		3u
#define HEX_CT_TEST		4u
#define HEX_CT_LIST		5u
#define HEX_CT_WATCH	6u
#define HEX_CT_MASTER	7u
// For closing  Tesc code blocks that have no code number set.
#define HEX_CT_STOP		8u

enum
{
	hexA_MT = 0,
	hexA_ME,
	hexA_LT,
	hexA_LE,
	hexA_COUNT
};

enum
{
	hexQ_NOACT = 0,
	hexQ_DC, hexQ_NC,
	hexQ_DE, hexQ_NE,
	hexQ_MT, hexQ_ME,
	hexQ_LT, hexQ_LE,
	hexQ_COUNT
};

#define hexT_DC	0u
#define hexT_NC 1u
#define hexT_DE 2u
#define hexT_NE 3u
#define hexT_MT 4u
#define hexT_ME 5u
#define hexT_LT 6u
#define hexT_LE 7u
#define hexT_COUNT	8u

enum
{
	HL_HEX1 = 0,
	HL_HEX2,
	HL_SONY_PS2_ARMAX_RAW,
	HL_COUNT
};

class xsDLL dBase
{
public:
	Text name;
};

class xsDLL Code : public xsArray< ui64, 0x100 >
{
public:
	Code( void );
	TrId item;
	void clearCode(	void );
	/// TSRPLLLL
	ui08 type;
	ui08 bytes;	/// Size of Value/s
	ui08 ram;
	ui08 depth;	/// Depth of pointer
	ui16 loop;
	/// HHMMIIII
	ui08 hex;	/// How to interpret the value
	ui08 mode;	/// 0 = Normal ( Plain write / copy ), 1 = Display ( Read out current value into GUI, write what is displayed in GUI, special code types blocked )
	ui16 info;
	/**
	Value, Address; Modify Value, Modify Address
	VVVVVVVV XXXXXXXX
	Or
	Address; Value; Modify Address; Modify Value
	XXXXXXXX XXXXXXXX
	VVVVVVVV VVVVVVVV
	**/
	ui64 addr[2]; // 2nd Value used for modifying addresss
};

class xsDLL Hack
{
public:
	Hack( void );
	void	clear( void );
	/** PPPPHHHH UUTTOOOO
	Profile ID, Hack Index, Use & / or Radio List, Code Total ( Uncounted will be added still ), Parent(Owner) Id **/
	TxtF	*m_txt;
	si32	id, parent, first, next;
	bool	isRadio;
	bool	isActive;
	TrId	item;
};

class xsDLL Fmt : public dBase
{
public:
	Fmt(		int theFormat = HL_HEX1 );
	void clear(	int theFormat = HL_HEX1 );
	int		fmt;
	Text 	ext;
};
class xsDLL TrID : public wxTreeItemData
{
public:
	TrID( int i );
	int index;
};
class xsDLL Hacks
{
private:
	TxtF m_names;
	BinF m_codes, m_hacks;
	bool m_isOpen;
	Text m_path;
	Hack m_hack;
	si32 m_count;
public:
	Hacks( void );
	si32 find( Text name, si32 parent = -1 );
	int hackOld;
	int hackNow;
	void open( Text path = wxEmptyString );
	Hack& operator[] ( ui32 i );
};
class xsDLL Codes : public xsArray< Code, 0x100 >
{
public:
	Codes( void );
	int codeOld;
	int codeNow;
};
xsDLL int	getFormat( Text	name );
xsDLL TxtA	getFormats( void );
xsDLL Text	getFormatName( int	format );
xsDLL Fmt	LoadFormats( Fmt& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );
xsDLL void	ListHacks( TrCO* tree, Hacks& hacks );
xsDLL void	ListCodes( TrCO* tree, LBox* lbox, Codes& codes, int format, int listCode );
//xsDLL Codes		LoadHacks( Codes& old, TxtF& file, TxtF& temp, Hacks& data, ui16 pid, bool addObj, int format );
//xsDLL Codes		LoadHacks_Hex( Codes& old,	TxtF& file, TxtF& temp, Hacks& data, bool addObj, int version );
xsDLL void	LoadHack_Hex( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void	SaveHack_Hex( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void	MakeTxt_Hex1( Codes& data,	TxtA& block );
xsDLL void	Maketxt_Hex1( Code& obj,	TxtA& block );
xsDLL void	MakeObj_Hex1( Codes& data,	TxtA& block );
xsDLL void	LoadHack_Sony_PS2_ARMAX( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void	SaveHack_Sony_PS2_ARMAX( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void	MakeTxt_Sony_PS2_ARMAX( Codes& data,	TxtA& block );
xsDLL void	Maketxt_Sony_PS2_ARMAX( Code& obj,		TxtA& block );
xsDLL void	MakeObj_Sony_PS2_ARMAX( Codes& data,	TxtA& block );
#endif // HEXDB_HACK_H
