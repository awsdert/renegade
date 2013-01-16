#include "hex2_global.h"

#ifndef HEXDB_HACK_H
#define HEXDB_HACK_H
// DO NOT MODIFY ORDER
enum
{
	HEX_CDE_W = 0, // Normal processing
	HEX_CDE_R, // Displays current value, looping permitted, info contains the value index to use for loop
	HEX_CDE_COUNT
};
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

enum
{
	HL_HEX1 = 0,
	HL_HEX2,
	HL_SONY_PS2_ARMAX_RAW,
	HL_COUNT
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
	Text	name;
	/** PPPPHHHH UUTTOOOO
	Profile ID, Hack Index, Use & / or Radio List, Code Total ( Uncounted will be added still ), Parent(Owner) Id **/
	ui32	parent;
	ui32	first;
	ui32    next;
	ui08	info;
	size_t	line;
	TrId	item;
};

class xsDLL Format
{
public:
	Format(		int theFormat = HL_HEX1 );
	void clear(	int theFormat = HL_HEX1 );
	Text	name;
	int		format;
	Text 	fileNow;
	Text	fileOld;
};
class xsDLL TrID : public wxTreeItemData
{
public:
	TrID( int i );
	int index;
};
class xsDLL Hacks : public xsArray< Hack, 0x10000 >
{
public:
	Hacks( void );
	ui32 find( Text name, ui32 parent = 0u );
	int hackOld;
	int hackNow;
};
class xsDLL Codes : public xsArray< Code, 0x100 >
{
public:
	Codes( void );
	int codeOld;
	int codeNow;
};
xsDLL Text		getFormatName( int format );
xsDLL int		getFormat( Text	name );
xsDLL Text		getFormatName( int	format );
xsDLL Format	LoadFormats( Format& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );
xsDLL void		ListHacks( TrCO* tree, Hacks& hacks );
xsDLL void		ListCodes( TrCO* tree, LBox* lbox, Codes& codes, int format, int listCode, bool relist );
xsDLL Codes		LoadHacks( Codes& old, TxtF& file, TxtF& temp, Hacks& data, ui16 pid, bool addObj, int format );
xsDLL Codes		LoadHacks_Hex( Codes& old,	TxtF& file, TxtF& temp, Hacks& data, bool addObj, int version );
xsDLL void		LoadHack_Hex( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void		SaveHack_Hex( TxtF& file,	Hack& hack, ui32& hackIndex, ui16& codeCount, TxtA& block );
xsDLL void		MakeTxt_Hex1( Codes& data,	TxtA& block );
xsDLL void		Maketxt_Hex1( Code& obj,	TxtA& block );
xsDLL void		MakeObj_Hex1( Codes& data,	TxtA& block );

#endif // HEXDB_HACK_H
