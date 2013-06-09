#include "hexObjs_fmt.h"
#ifndef hexObjs_code_h
#define hexObjs_code_h

const ui32 CODE_DATA_SIZE = sizeof( ui64 ) * 0x100;

enum CODE_TYPE
{
	// DO NOT MODIFY ORDER
	CODE_WRITE = 0u,
	CODE_COPY,
	CODE_INC,
	CODE_DEC,
	CODE_TEST,
	CODE_LIST,
	CODE_WATCH,
	CODE_MASTER,
// For closing  Tesc code blocks that have no code number set.
	CODE_STOP,
	CODE_COUNT
};
enum TEST_TYPE
{
	// DO NOT MODIFY ORDER
	TEST_DC = 0u,
	TEST_NC,
	TEST_DE,
	TEST_NE,
	TEST_MT,
	TEST_ME,
	TEST_LT,
	TEST_LE,
	TEST_COUNT
};

struct hexObjs Code : zxArray< ui08, CODE_DATA_SIZE >
{
	Code( void );
	void	clearCode( void );
	zxInt	getValue( ui08 index );
	void	setValue( ui08 index, zxInt value );
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

struct hexObjs Codes : zxArray< Code, 0x100 >
{
	void m_loadCode( ui08* data, Code& code );
	void m_saveCode( ui08* data, Code& code );
	void saveCodes( Text dir, si32 hackId );
	void loadCodes( Text dir, si32 hackId );
};

#endif