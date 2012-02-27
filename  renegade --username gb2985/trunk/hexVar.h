#ifndef HEXVAR_H
#define HEXVAR_H
#include "hexApp.h"
#include "GUIFrame.h"
enum HPF {
	PC32 = 0, PC64,
	PS1, PS2,
	N64, NGB, NDS, NWII,
	HPFL
}; // Hack Platform
class CL {
	public:
		CL(void);
		~CL(void);
	public:
	/*
		T = Code Type
		S = Code Size
		R = Repeat
		M = Memory ID
		I? = In/Decrement Value
		J = In/Decrement Address
		V? = Value
		L = Code Lines
		F = Fixed Address?
	*/
		u32 test;
		u32 codeType;
		u32 size;
		u32 reiterate;
		u32 ram;
		u32 inc_address;
		u64 address;
		u32 addressSize;
		u64 value;
		u64 inc_value;
		xAStr valueArray;
		bool fixed;
};
class BIN: public wxClientData
{
	public:
		BIN( void );
		BIN( wxClientData* );
	public:
		u32 GetCount( void );
		xStr binName;
		xAStr ramName;
		xAStr ramFixed;
		xAStr ramStart;
		xAStr ramSize;
};
class DBI: public wxTreeItemData {
	public:
		DBI(void);
		DBI(wxTreeItemData*);
		//~DBI(void);
	public:
		u8 afr;
		u16 afi;
		xStr afn, afs, afp;
};
class HACK: public wxTreeItemData {
	public:
		HACK();
		HACK(wxTreeItemData*);
		//~HACK();
	public:
		bool use;
		u16 hid;
		xAStr cPart1;
		xAStr cPart2;
		xAInt cLines;
		xAInt sLines;
		s32 GetLen();
};
#endif
