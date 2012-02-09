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
		int l;
		u8 t, s, r, m;
		u16 j;
		u32 x, v, i;
		wxArrayString ca;
		bool f;
};
class DBI: public wxTreeItemData {
	public:
		DBI(void);
		DBI(wxTreeItemData*);
		//~DBI(void);
	public:
		u8 afr;
		u16 afi;
		wxString afn, afs, afp;
};
class HACK: public wxTreeItemData {
	public:
		HACK();
		HACK(wxTreeItemData*);
		//~HACK();
	public:
		bool use;
		u16 hid;
		wxArrayString cPart1;
		wxArrayString cPart2;
		wxArrayInt cLines;
		int GetLen();
};
#endif
