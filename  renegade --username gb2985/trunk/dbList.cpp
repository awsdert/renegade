/***************************************************************
 * Name:      dbList.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <string.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
DBI::DBI(void) : wxTreeItemData() {
	afr = 0x00;
	afi = 0x00000;
	afn = wxT("");
	afs = wxT("");
}
DBI::DBI(wxTreeItemData*) : wxTreeItemData() {}
DBI::~DBI(void) {
	afr = 0x00; afi = 0x0000;
	afn.Clear(); afs.Clear();
}
void hexWin::dbListAdd(void) {
	DBI* cv = new DBI;
	wxString s;
	s.Printf(wxT("New Hack Tree %i"), dl);
	cv->afn = wxT("Notes");
	dbListAdd(s, cv);
}
void hexWin::dbListAdd(wxString s, DBI* cv) {
	if (dl < 1) { rdi = dbList->GetRootItem(); }
	di = dbList->AppendItem(rdi, s, -1, -1, cv);
	if (dl < 1) { rdi = dbList->GetItemParent(di); }
	dbList->SelectItem(di); dl++;
}
void hexWin::dbListAddBClick(wxCommandEvent& event) { dbListAdd(); }
void hexWin::dbListSelect(void) {
	if (di != pdi) {
		pdi = di;
		DBI* cv = (DBI*)dbList->GetItemData(di);
		dbListNotes->SetValue(cv->afn);
	}
}
void hexWin::dbListSelectC(wxTreeEvent& event) {
	di = event.GetItem();
	dbListSelect();
}
