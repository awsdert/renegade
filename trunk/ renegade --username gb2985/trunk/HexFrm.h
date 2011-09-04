///-----------------------------------------------------------------
///
/// @file      HexFrm.h
/// @author    admin
/// Created:   28/08/2011 17:54:25
/// @section   DESCRIPTION
///            HexFrm class declaration
///
///------------------------------------------------------------------

#ifndef __HEXFRM_H__
#define __HEXFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/scrolwin.h>
#include <wx/gauge.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/checkbox.h>
#include <wx/filepicker.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/notebook.h>
////Header Include End
#include "wxApp.h"
////Dialog Style Start
#undef HexFrm_STYLE
#define HexFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class HexFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		HexFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("HackerEx"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = HexFrm_STYLE);
		virtual ~HexFrm();
		void hexBTNSoftwareOnClick(wxCommandEvent& event);
		PROCESSENTRY32 getApp(DWORD id);
        void getApps(bool user);
		void HexFrmIdle(wxIdleEvent& event);
		void hexDBGroupSelected(wxCommandEvent& event );
		int pLen, gLen;
        wxString* groups;
        int* group;
        wxString* preset;
        xApp* apps;
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxChoice *hexDBGroup;
		wxPanel *hexNB7;
		wxPanel *hexNB6;
		wxPanel *hexNB5;
		wxPanel *hexNB4;
		wxPanel *hexNB3;
		wxCheckBox *hexCBEIgnore16R;
		wxCheckBox *hexCBEIgnore8R;
		wxCheckBox *hexCBEIgnore64;
		wxCheckBox *hexCBEIgnore32;
		wxCheckBox *hexCBEIgnore16;
		wxCheckBox *hexCBEIgnore8;
		wxCheckBox *hexCBEN64;
		wxTextCtrl *hexTXTValue7;
		wxTextCtrl *hexTXTValue6;
		wxTextCtrl *hexTXTValue3;
		wxTextCtrl *hexTXTValue5;
		wxTextCtrl *hexTXTValue4;
		wxCheckBox *hexCBENRange;
		wxCheckBox *hexCBERange;
		wxCheckBox *hexCBEIgnoreV;
		wxCheckBox *hexCBEIgnoreF;
		wxCheckBox *hexCBEIgnore0;
		wxCheckBox *hexCBESigned;
		wxScrolledWindow *hexSCLExtend;
		wxStaticText *hexLBLExtend;
		wxGauge *hexPBProgress;
		wxStaticText *hexLBLProgress;
		wxTextCtrl *hexTXTValue2;
		wxChoice *hexDBValue;
		wxTextCtrl *hexTXTValue1;
		wxStaticBox *hexBValue;
		wxChoice *hexDBSType;
		wxButton *hexBTNMLast;
		wxButton *hexBTNLLast;
		wxButton *hexBTNLast;
		wxButton *hexBTNNLast;
		wxButton *hexBTNMore;
		wxButton *hexBTNLess;
		wxButton *hexBTNNot;
		wxButton *hexBTNIs;
		wxButton *hexBTNDump;
		wxStaticBox *hexBSType;
		wxButton *hexBTNSearch;
		wxButton *hexBTNSNew;
		wxChoice *hexDBSearch;
		wxChoice *hexDBSGroup;
		wxChoice *hexDBSSize;
		wxStaticText *hexLBLSSize;
		wxPanel *hexNB2;
		wxButton *hexBTNSoftware;
		wxDirPickerCtrl *hexDIRDump;
		wxStaticText *hexLBLDump;
		wxButton *hexBTNUse;
		wxButton *hexBTNRemove;
		wxButton *hexBTNDefault;
		wxButton *hexBTNUpdate;
		wxListBox *hexLBSoftware;
		wxChoice *hexDBAccess;
		wxStaticText *hexLBLAccess;
		wxChoice *hexDBFind;
		wxTextCtrl *hexTXTFind;
		wxStaticText *hexLBLFind;
		wxCheckBox *hexCBEnd;
		wxChoice *hexDBOrder;
		wxStaticText *hexLBLOrder;
		wxTextCtrl *hexTXTESize;
		wxStaticText *hexLBLESize;
		wxChoice *hexDBType;
		wxStaticText *hexLBLType;
		wxDirPickerCtrl *hexDIRPath;
		wxStaticText *hexLBLPath;
		wxChoice *hexDBEType;
		wxStaticText *hexLBLEType;
		wxTextCtrl *hexTXTEPoint;
		wxStaticText *hexLBLEPoint;
		wxComboBox *hexDBMode;
		wxStaticText *hexLBLMode;
		wxTextCtrl *hexTXTName;
		wxStaticText *hexLBLName;
		wxComboBox *hexDBPreset;
		wxStaticText *hexLBLPreset;
		wxStaticText *hexLBLGroup;
		wxPanel *hexNB1;
		wxNotebook *hexNB;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_HEXDBGROUP = 1103,
			ID_HEXNB7 = 1008,
			ID_HEXNB6 = 1007,
			ID_HEXNB5 = 1006,
			ID_HEXNB4 = 1005,
			ID_HEXNB3 = 1004,
			ID_HEXCBEIGNORE16R = 1097,
			ID_HEXCBEIGNORE8R = 1096,
			ID_HEXCBEIGNORE64 = 1095,
			ID_HEXCBEIGNORE32 = 1094,
			ID_HEXCBEIGNORE16 = 1093,
			ID_HEXCBEIGNORE8 = 1092,
			ID_HEXCBEN64 = 1091,
			ID_HEXTXTVALUE7 = 1090,
			ID_HEXTXTVALUE6 = 1089,
			ID_HEXTXTVALUE3 = 1088,
			ID_HEXTXTVALUE5 = 1087,
			ID_HEXTXTVALUE4 = 1086,
			ID_HEXCBENRANGE = 1085,
			ID_HEXCBERANGE = 1084,
			ID_HEXCBEIGNOREV = 1083,
			ID_HEXCBEIGNOREF = 1082,
			ID_HEXCBEIGNORE0 = 1081,
			ID_HEXCBESIGNED = 1080,
			ID_HEXSCLEXTEND = 1079,
			ID_HEXLBLEXTEND = 1076,
			ID_HEXPBPROGRESS = 1075,
			ID_HEXLBLPROGRESS = 1074,
			ID_HEXTXTVALUE2 = 1073,
			ID_HEXDBVALUE = 1072,
			ID_HEXTXTVALUE1 = 1071,
			ID_HEXBVALUE = 1070,
			ID_HEXDBSTYPE = 1069,
			ID_HEXBTNMLAST = 1065,
			ID_HEXBTNLLAST = 1064,
			ID_HEXBTNLAST = 1063,
			ID_HEXBTNNLAST = 1062,
			ID_HEXBTNMORE = 1060,
			ID_HEXBTNLESS = 1059,
			ID_HEXBTNNOT = 1058,
			ID_HEXBTNIS = 1057,
			ID_HEXBTNDUMP = 1056,
			ID_HEXBSTYPE = 1055,
			ID_HEXBTNCOMPARE = 1054,
			ID_HEXBTNSNEW = 1053,
			ID_HEXDBSEARCH = 1052,
			ID_HEXDBSGROUP = 1051,
			ID_HEXDBSSIZE = 1049,
			ID_HEXLBLSSIZE = 1048,
			ID_HEXNB2 = 1003,
			ID_HEXBTNSOFTWARE = 1102,
			ID_HEXDIRDUMP = 1047,
			ID_HEXLBLDUMP = 1046,
			ID_HEXBTNUSE = 1045,
			ID_HEXBTNREMOVE = 1044,
			ID_HEXBTNDEFAULT = 1043,
			ID_HEXBTNUPDATE = 1042,
			ID_HEXLBSOFTWARE = 1040,
			ID_HEXDBACCESS = 1039,
			ID_HEXLBLACCESS = 1038,
			ID_HEXDBFIND = 1037,
			ID_HEXTXTFIND = 1036,
			ID_HEXLBLFIND = 1035,
			ID_HEXCBEND = 1034,
			ID_HEXDBORDER = 1033,
			ID_HEXLBLORDER = 1032,
			ID_HEXTXTESIZE = 1031,
			ID_HEXLBLESIZE = 1030,
			ID_HEXDBTYPE = 1029,
			ID_HEXLBLTYPE = 1028,
			ID_HEXDIRPATH = 1027,
			ID_HEXLBLPATH = 1025,
			ID_HEXDBETYPE = 1022,
			ID_HEXLBLETYPE = 1021,
			ID_HEXTXTEPOINT = 1020,
			ID_HEXLBLEPOINT = 1019,
			ID_HEXDBMODE = 1018,
			ID_HEXLBLMODE = 1017,
			ID_HEXTXTNAME = 1016,
			ID_HEXLBLNAME = 1014,
			ID_HEXDBPRESET = 1013,
			ID_HEXLBLPRESET = 1012,
			ID_HEXLBLGROUP = 1010,
			ID_HEXNB1 = 1002,
			ID_HEXNB = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
