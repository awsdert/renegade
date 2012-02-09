/***************************************************************
 * Name:      HT.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexVar.h"
CL::CL(void) {
	t = 0; s = 0;
	r = 0; m = 0;
	j = 0; f = true;
	x = 0; v = 0; i = 0;
}
CL::~CL(void) {
	t = 0; s = 0;
	r = 0; m = 0;
	j = 0; f = true;
	x = 0; v = 0; i = 0;
}
DBI::DBI(void) : wxTreeItemData() {
	afr = 0;
	afi = 0;
	afn = wxT("");
	afs = wxT("");
}
DBI::DBI(wxTreeItemData*) : wxTreeItemData() {}
/*DBI::~DBI(void) {
	afr = 0; afi = 0x0000;
	afn.Clear(); afs.Clear();
}*/
HACK::HACK() : wxTreeItemData() { hid = 0; use = false; }
HACK::HACK(wxTreeItemData*) : wxTreeItemData() { hid = 0; use = false; }
/*HACK::~HACK() {
	hid = 0x0000;
	use = false;
	cPart1.Empty();
	cPart2.Empty();
	cLines.Empty();
}*/
int HACK::GetLen() { return cPart1.GetCount(); }
