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
CL::CL( void )
{
	codeType = 0;
	size = 0;
	reiterate = 0;
	ram = 0;
	inc_address = 0;
	addressSize = 0;
	fixed = true;
	address = 0;
	value = 0;
	inc_value = 0;
	test = 0;
}
CL::~CL( void )
{
	codeType = 0;
	size = 0;
	reiterate = 0;
	ram = 0;
	inc_address = 0;
	fixed = false;
	addressSize = 0;
	address = 0;
	value = 0;
	inc_value = 0;
	test = 0;
	valueArray.Clear();
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
s32 HACK::GetLen() { return cPart1.GetCount(); }
