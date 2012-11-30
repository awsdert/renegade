#ifndef HEXDB_HACK_H
#define HEXDB_HACK_H
#include "hexGUI_global.hpp"
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
	HEX_CT_LIST,
	HEX_CT_TEST
};
class xsDLL Code : public Vect< ui08 >
{
public:
	Code( void );
	~Code( void );
	void cdeClear( void );
	// TSRPLLLL
	ui08 cdeType;
	ui08 cdeSize;
	ui08 cdeRam;
	ui08 cdeDepth; // Depth of pointer
	ui16 cdeLoop;
	// HHMMIIII
	ui08 cdeHex; // How to interpret the value
	ui08 cdeMode; // 0 = Normal ( Plain write / copy ), 1 = Display ( Read out current value into GUI, write what is displayed in GUI, special code types blocked )
	ui16 cdeInfo;
	/* VVVVVVVV XXXXXXXX Or
	XXXXXXXX XXXXXXXX
	VVVVVVVV VVVVVVVV in this order:
	Address, Value, Modify Address, Modify Value */
	ui64 cdeAddr[2]; // 2nd Value used for modifying addresss
};

class xsDLL Hack : public Vect< Code >
{
public:
	Hack( void );
	~Hack( void );
	void hckClear( void );
	Text hckName;
	/* PPPPHHHH UUTTOOOO
	Profile Id, Hack Id, Use & / or Radio List, Code Total ( Uncounted will be added still ), Parent(Owner) Id */
	ui16 hckParent;
	ui08 hckUse;
	TrId hckItem;
};

class xsDLL HckV : public Vect< Hack > {};

xsC_END
#endif // HEXDB_HACK_H
