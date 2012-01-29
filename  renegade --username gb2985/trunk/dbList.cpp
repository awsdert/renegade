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
void hexWin::DBSet(void) {
	int afi = cbGroup->GetSelection();
	if (afi < 0) { afi = PS2; }
	wxString p, s; p = wxGetCwd();
	if (p.Find(wxT('\\'))) { myDiv = wxT('\\'); }
	else { myDiv = wxT('/'); }
	wxChar d = myDiv;
	dir.Open(p);
	p << d << wxT("db");
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s << p << d << dbFile[afi] << wxT(".hexdb");
	if (!db.Open(s)) {
		db.Create(s);
		db.Open(s);
	}
}
void hexWin::DBLoad(void) {
	DBSet();
	wxString t, t1, t2, t3;
	dbList->Delete(rdi);
	DBI* cv = new DBI; int j, m = 0, m2;
	for (t = db.GetFirstLine(); !db.Eof(); t = db.GetNextLine()) {
		switch (m) {
		case 1: dbListAdd(t1, cv);
			cv = new DBI;
			cv->afp = t3;
			m = 0; t1.Clear();
		break;
		case 2: m2 = -1;
			for (j = 0;j < (int)t.Length();j++) {
				t3 = t.GetChar(j);
				if (t3.Cmp(wxT(";")) == 0) {
					m2++;
					if (m2 == 1) { t1 = t2; }
					else if (m2 == 3) { cv->afs = t2; }
					else if (m2 == 4) { cv->afi = getHEX(t2); }
					t2.Clear();
				} else { t2 << t3; }
			} m = 3; break;
		case 3:
			if (t.StartsWith(wxT("["))) {
				t3 = t.SubString(1, t.length() - 2);
				m = 1;
			} else { cv->afn += t; }
			break;
		default:
			if (t.StartsWith(wxT("["))) {
				cv->afp = t.SubString(1, t.length() - 2);
				m = 2;
			}
		}
	} if (!!t1) { dbListAdd(t1, cv); }
}
void hexWin::DBLoadBOnClick(wxCommandEvent& event) { DBLoad(); }
void hexWin::DBSave(void) {
	DBSet(); wxString s, l, n; wxChar c = wxT(';');
	wxTreeItemId i;
	wxTreeItemIdValue v; DBI* d;
	wxTextFileType t = wxTextFileType_Dos;
	i = dbList->GetFirstChild(rdi, v);
	while (i.IsOk()) {
		d = (DBI*)dbList->GetItemData(i);
		s = wxT("[") + d->afp + wxT("]");
		wxMessageBox(s);
		db.AddLine(s, t);
		l = dbList->GetItemText(i);
		n.Printf(wxT("%04X"), d->afi);
		s = c + l + c + wxT("uk") + c + d->afs + c + n;
		db.AddLine(s, t);
		i = dbList->GetNextChild(rdi, v);
	} db.Write(t);
	db.Close();
}
void hexWin::DBSaveBOnClick(wxCommandEvent& event) { DBSave(); }
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
