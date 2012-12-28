#ifndef HEXDB_HACK_H
#define HEXDB_HACK_H
#include "hex2_global.h"
xsC_START
// DO NOT MODIFY ORDER
enum
{
	HEX_CDE_W = 0, // Normal processing
	HEX_CDE_R, // Displays current value, looping permitted, info contains the value index to use for loop
	HEX_CDE_COUNT
};

enum
{
	HEX_CT_WRITE = 0u,
	HEX_CT_COPY,
	HEX_CT_INC,
	HEX_CT_DEC,
	HEX_CT_TEST,
	HEX_CT_LIST
};
enum
{
	HL_HEX1 = 0,
	HL_HEX2,
	HL_SONY_PS2_ARMAX_RAW,
	HL_COUNT
};
class xsDLL Code
{
	ui16 m_count;
public:
	Code( void );
	TrId item;
	ui16 size(	void );
	void clear(	void );
	ui16 resize( ui16 count );
	ui08& operator[] ( ui08 i );
	ui08 data[ 2040u ];
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
	ui16	parent;
	ui08	info;
	size_t	line;
	TrId	item;
};

Text	xsDLL getFormatName( int format );
class	xsDLL Format
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
class	xsDLL Hacks : public Vect< Hack >
{
public:
	Hacks();
	int find( Text name, ui16 parent = 0u );
	int hackOld;
	int hackNow;
};
class	xsDLL Codes : public Vect< Code >
{
public:
	Codes();
};
int		xsDLL getFormat( Text	name );
Text	xsDLL getFormatName( int	format );
Format	xsDLL LoadFormats( Format& obj, TxtF& file, TxtF& temp, TxtA& data, Text name, bool addObj, bool isFileTmp, bool isTempTmp );
void	xsDLL ListHacks( TrCO* tree, Hacks& hacks );
void	xsDLL ListCodes( TrCO* tree, LBox* lbox, Codes& codes, int format, int listCode, bool relist );

xsC_END
#endif // HEXDB_HACK_H
