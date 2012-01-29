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
		CHAR c1, c2, c3, c4, repeat;
		DWORD32 address, incA, decA;
		DWORD32 value, incV, decV;
};
class DBI: public wxTreeItemData {
	public:
		DBI(void);
		DBI(wxTreeItemData*);
		~DBI(void);
	public:
		CHAR afr;
		WORD afi;
		wxString afn, afs, afp;
};
class HACK: public wxTreeItemData {
	public:
		HACK();
		HACK(wxTreeItemData*);
		~HACK();
	public:
		bool use;
		WORD hid;
		unsigned int length;
		wxArrayString cPart1;
		wxArrayString cPart2;
		int GetLen();
		void SetLen(int l);
};
#endif
