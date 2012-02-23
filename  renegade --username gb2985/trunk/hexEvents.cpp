#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::PFGetOnClick(wxCommandEvent& event) { HWB = 1000; HCHook(); }
void ME::APPLISTOnClick(wxCommandEvent& event) { setApps(); }
void ME::APPUSEOnClick(wxCommandEvent& event) {
	xAInt a = APPG->GetSelectedRows();
	xStr s;
	if (a.GetCount() > 0) {
		s = APPG->GetCellValue(a[0], 0);
		APPT->SetValue(s);
	} //DBLoad();
}
void ME::bAddHackOnClick(wxCommandEvent& event) {
	xTID i = HT->GetSelection(), p, r; HACK* d = new HACK;
	xStr s; r = HTRoot(i); s32 w = HTAddD->GetSelection();
	if (HTAddC->GetValue() == false) {
		s.Printf(wxT("New Hack %i"), HTCount(r));
		HTAdd(r, s, w, i, d);
	} else {
		s.Printf(wxT("New Hack %i"), HTCount(i));
		HTAdd(i, s, w);
	} HTChange();
}
void ME::bDelHackOnClick(wxCommandEvent& event) { HTDel(ti); }
void ME::mWaitOnChange(wxCommandEvent& event) { AWB = HDT[APPCheck->GetSelection()]; }
// Main Window
void ME::HEXFORMCLOSE(wxCloseEvent& event) { AWB = 0; HWB = 0; EWB = 0; Destroy(); }
void ME::HEXFORMIDLE(wxIdleEvent& event) {
	bool rm = false;
	if (AWB > 0) {
		AW = wxGetLocalTimeMillis();
		if (AW >= AWU) {
			setApps();
		} rm = true;
	}
	if (HWB > 0) {
		HW = wxGetLocalTimeMillis();
		if (HW >= HWU) { HCHook();
			HWU = wxGetLocalTimeMillis() + HWB;
		} rm = true;
	}
	if (EWB > 0 && EP->IsShownOnScreen()) {
		EW = wxGetLocalTimeMillis();
		if (EW >= EWU) { EA();
			EWU = wxGetLocalTimeMillis() + EWB;
		} rm = true;
	} event.RequestMore(rm);
}
// - Hook Tab
// - - Platfrom
void ME::PFOnChange(wxCommandEvent& event) { PFLoad(); }
void ME::PFOnClick(wxCommandEvent& event) { PFLoad(); }
// - - App
void ME::APPDOnChange(wxCommandEvent& event) {
 PresetOnChange();
}
// - Editor Tab
void ME::EAOnClick(wxCommandEvent& event) { EA(); }
void ME::EVOnClick(wxCommandEvent& event) { EV(); }
void ME::EUOnChange(wxCommandEvent& event) { EWB = HDT[EUD->GetSelection()]; }
void ME::EGOnChange(wxGridEvent& event) {
	s32 r = event.GetRow(), c = event.GetCol();
	xStr s = EG->GetCellValue(r, 0);
	if (c > 0) {
		u32 i = getHEX(s) + GARS(0) + c - 1, v = getHEX(EG->GetCellValue(r, c));
		HANDLE p = GAP(); HCWrite(p, i, 1, v);
	} else { EAT->SetValue(s); EA(); }
}
// - Database Tab
void ME::DBSaveBOnClick(wxCommandEvent& event) { DBSave(); }
void ME::DBDelBOnClick(wxCommandEvent& event) { DBDel(); }
void ME::DBSelectC(wxTreeEvent& event) { di = event.GetItem(); DBSelect(); }
void ME::DBLoadBOnClick(wxCommandEvent& event) { DBLoad(); }
// - Hack Tree Tab
/*void ME::HTOnDel(wxTreeEvent& event) {
	xTID i = event.GetItem();
	HACK* h = getIH(i);
	h->hid = 0; h->use = false;
	setIH(i, h);
}*/
void ME::bHTSaveOnClick(wxCommandEvent& event) { HTSave(); }
void ME::bHTLoadOnClick(wxCommandEvent& event) { HTLoad(); }
void ME::HTOnChangeSelT(wxTreeEvent& event) { ti = event.GetItem(); HTChange(); }
void ME::HTOnKeyUp(wxKeyEvent& event) {
	xTID r; xStr s;
	s32 kc = event.GetKeyCode();
	if (event.ControlDown()) {
		switch (kc) {
		case WXK_SPACE:
			HCUseC->SetValue(!HCUseC->GetValue());
			HCUChange();
		break;
		case WXK_EXECUTE: case WXK_ADD: case WXK_NUMPAD_ADD:
			if (HTAddC->GetValue()) {
				s.Printf(wxT("New Hack %i"), HTCount(ti));
				HTAdd(ti, s, 3);
			} else {
				r = HTRoot(ti);
				s.Printf(wxT("New Hack %i"), HTCount(r));
				HTAdd(r, s, HTAddD->GetSelection(), ti);
			}
		break;
		case WXK_DELETE: case WXK_SUBTRACT: case WXK_NUMPAD_SUBTRACT:
			HTDel(ti); break;
		case WXK_UP: HTMove(0); break;
		case WXK_DOWN: HTMove(1); break;
		case WXK_LEFT: HTMove(2); break;
		case WXK_RIGHT: HTMove(3); break;
		default: event.Skip(); break; }
	}
}
void ME::HTOnKeyDown(wxKeyEvent& event) {
	xTID r; xTIDV v; xStr s;
	s32 kc = event.GetKeyCode();
	if (!event.ControlDown()) {
		switch (kc) {
		case WXK_SPACE:
			HCUseC->SetValue(!HCUseC->GetValue());
			HCUChange();
			break;
		case WXK_UP:
			r = HT->GetPrevSibling(ti);
			if (!r) { r = HTRoot(ti); }
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_DOWN:
			r = HT->GetNextSibling(ti);
			if (!r) { r = HT->GetFirstChild(ti, v); }
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_LEFT:
			r = HTRoot(ti);
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_RIGHT:
			r = HT->GetFirstChild(ti, v);
			if (r) { HT->SelectItem(r); }
		break;
		default: event.Skip(); break; }
	}
}
