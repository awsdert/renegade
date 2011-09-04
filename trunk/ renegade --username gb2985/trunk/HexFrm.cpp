///-----------------------------------------------------------------
///
/// @file      HexFrm.cpp
/// @author    admin
/// Created:   28/08/2011 17:54:25
/// @section   DESCRIPTION
///            HexFrm class implementation
///
///------------------------------------------------------------------

#include "HexFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include <iostream>
#include <string.h>
#include <wx/string.h>
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif
//----------------------------------------------------------------------------
// HexFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(HexFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(HexFrm::OnClose)
	EVT_INIT_DIALOG(HexFrm::OnInitDialog)
	EVT_IDLE(HexFrm::HexFrmIdle)
	EVT_CHOICE(ID_HEXDBGROUP,HexFrm::hexDBGroupSelected)
	EVT_BUTTON(ID_HEXBTNSOFTWARE,HexFrm::hexBTNSoftwareOnClick)
END_EVENT_TABLE()
////Event Table End
DWORD getAppId(const wxString appName) {
	PROCESSENTRY32 appInfo;
	appInfo.dwSize = sizeof(appInfo);
	char* exe = "";
/*	HANDLE appShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if ( appShot == INVALID_HANDLE_VALUE )
		return 0;*/

	Process32First(NULL, &appInfo);
	sprintf(exe, "%s", appInfo.szExeFile);
	if (!appName.compare(exe)) {
		return appInfo.th32ProcessID;
	}

	while ( Process32Next(NULL, &appInfo) )
	{
		if ( !appName.compare(appInfo.szExeFile) )
		{
			return appInfo.th32ProcessID;
		}
	}
	
//	CloseHandle(appShot);*/
	return 0;
}
HexFrm::HexFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

HexFrm::~HexFrm()
{
}
void HexFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	hexNB = new wxNotebook(this, ID_HEXNB, wxPoint(0, 0), wxSize(625, 445), wxNB_DEFAULT);

	hexNB1 = new wxPanel(hexNB, ID_HEXNB1, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB1, wxT("Hook"));

	hexLBLGroup = new wxStaticText(hexNB1, ID_HEXLBLGROUP, wxT("Group"), wxPoint(5, 5), wxDefaultSize, 0, wxT("hexLBLGroup"));

	hexLBLPreset = new wxStaticText(hexNB1, ID_HEXLBLPRESET, wxT("Preset"), wxPoint(5, 30), wxDefaultSize, 0, wxT("hexLBLPreset"));

	wxArrayString arrayStringFor_hexDBPreset;
	hexDBPreset = new wxComboBox(hexNB1, ID_HEXDBPRESET, wxT(""), wxPoint(75, 30), wxSize(145, 23), arrayStringFor_hexDBPreset, 0, wxDefaultValidator, wxT("hexDBPreset"));

	hexLBLName = new wxStaticText(hexNB1, ID_HEXLBLNAME, wxT("Name"), wxPoint(5, 80), wxDefaultSize, 0, wxT("hexLBLName"));

	hexTXTName = new wxTextCtrl(hexNB1, ID_HEXTXTNAME, wxT(""), wxPoint(75, 80), wxSize(145, 23), 0, wxDefaultValidator, wxT("hexTXTName"));

	hexLBLMode = new wxStaticText(hexNB1, ID_HEXLBLMODE, wxT("Mode"), wxPoint(5, 180), wxDefaultSize, 0, wxT("hexLBLMode"));

	wxArrayString arrayStringFor_hexDBMode;
	hexDBMode = new wxComboBox(hexNB1, ID_HEXDBMODE, wxT(""), wxPoint(75, 180), wxSize(145, 23), arrayStringFor_hexDBMode, 0, wxDefaultValidator, wxT("hexDBMode"));

	hexLBLEPoint = new wxStaticText(hexNB1, ID_HEXLBLEPOINT, wxT("Entry Pont"), wxPoint(5, 205), wxDefaultSize, 0, wxT("hexLBLEPoint"));
	hexLBLEPoint->SetToolTip(wxT("Hex address of memory"));

	hexTXTEPoint = new wxTextCtrl(hexNB1, ID_HEXTXTEPOINT, wxT(""), wxPoint(75, 205), wxSize(145, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTEPoint"));

	hexLBLEType = new wxStaticText(hexNB1, ID_HEXLBLETYPE, wxT("Entry Type"), wxPoint(5, 230), wxDefaultSize, 0, wxT("hexLBLEType"));

	wxArrayString arrayStringFor_hexDBEType;
	hexDBEType = new wxChoice(hexNB1, ID_HEXDBETYPE, wxPoint(75, 230), wxSize(145, 23), arrayStringFor_hexDBEType, 0, wxDefaultValidator, wxT("hexDBEType"));
	hexDBEType->SetSelection(-1);

	hexLBLPath = new wxStaticText(hexNB1, ID_HEXLBLPATH, wxT("Folder"), wxPoint(5, 55), wxDefaultSize, 0, wxT("hexLBLPath"));

	hexDIRPath = new wxDirPickerCtrl(hexNB1, ID_HEXDIRPATH, wxT(""), wxT("Select a folder"), wxPoint(75, 55), wxSize(145, 23), wxDIRP_DEFAULT_STYLE | wxDIRP_USE_TEXTCTRL | wxDIRP_CHANGE_DIR, wxDefaultValidator, wxT("hexDIRPath"));

	hexLBLType = new wxStaticText(hexNB1, ID_HEXLBLTYPE, wxT("Type"), wxPoint(5, 105), wxDefaultSize, 0, wxT("hexLBLType"));

	wxArrayString arrayStringFor_hexDBType;
	hexDBType = new wxChoice(hexNB1, ID_HEXDBTYPE, wxPoint(75, 105), wxSize(145, 23), arrayStringFor_hexDBType, 0, wxDefaultValidator, wxT("hexDBType"));
	hexDBType->SetSelection(-1);

	hexLBLESize = new wxStaticText(hexNB1, ID_HEXLBLESIZE, wxT("Entry Size"), wxPoint(5, 255), wxDefaultSize, 0, wxT("hexLBLESize"));

	hexTXTESize = new wxTextCtrl(hexNB1, ID_HEXTXTESIZE, wxT(""), wxPoint(75, 255), wxSize(145, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTESize"));

	hexLBLOrder = new wxStaticText(hexNB1, ID_HEXLBLORDER, wxT("Byte Order"), wxPoint(5, 280), wxDefaultSize, 0, wxT("hexLBLOrder"));

	wxArrayString arrayStringFor_hexDBOrder;
	hexDBOrder = new wxChoice(hexNB1, ID_HEXDBORDER, wxPoint(75, 280), wxSize(145, 23), arrayStringFor_hexDBOrder, 0, wxDefaultValidator, wxT("hexDBOrder"));
	hexDBOrder->SetSelection(-1);

	hexCBEnd = new wxCheckBox(hexNB1, ID_HEXCBEND, wxT(""), wxPoint(225, 255), wxSize(70, 23), 0, wxDefaultValidator, wxT("hexCBEnd"));

	hexLBLFind = new wxStaticText(hexNB1, ID_HEXLBLFIND, wxT("Auto Find Software"), wxPoint(5, 130), wxDefaultSize, 0, wxT("hexLBLFind"));

	hexTXTFind = new wxTextCtrl(hexNB1, ID_HEXTXTFIND, wxT(""), wxPoint(120, 130), wxSize(100, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTFind"));
	hexTXTFind->SetToolTip(wxT("0 means don't auto find"));

	wxArrayString arrayStringFor_hexDBFind;
	hexDBFind = new wxChoice(hexNB1, ID_HEXDBFIND, wxPoint(225, 130), wxSize(100, 23), arrayStringFor_hexDBFind, 0, wxDefaultValidator, wxT("hexDBFind"));
	hexDBFind->SetSelection(-1);

	hexLBLAccess = new wxStaticText(hexNB1, ID_HEXLBLACCESS, wxT("Search Access"), wxPoint(5, 155), wxDefaultSize, 0, wxT("hexLBLAccess"));

	wxArrayString arrayStringFor_hexDBAccess;
	hexDBAccess = new wxChoice(hexNB1, ID_HEXDBACCESS, wxPoint(120, 155), wxSize(205, 23), arrayStringFor_hexDBAccess, 0, wxDefaultValidator, wxT("hexDBAccess"));
	hexDBAccess->SetSelection(-1);

	wxArrayString arrayStringFor_hexLBSoftware;
	hexLBSoftware = new wxListBox(hexNB1, ID_HEXLBSOFTWARE, wxPoint(330, 30), wxSize(280, 380), arrayStringFor_hexLBSoftware, wxLB_SINGLE | wxLB_NEEDED_SB);

	hexBTNUpdate = new wxButton(hexNB1, ID_HEXBTNUPDATE, wxT("Update"), wxPoint(5, 365), wxSize(100, 23), 0, wxDefaultValidator, wxT("hexBTNUpdate"));

	hexBTNDefault = new wxButton(hexNB1, ID_HEXBTNDEFAULT, wxT("Make Default"), wxPoint(5, 390), wxSize(100, 23), 0, wxDefaultValidator, wxT("hexBTNDefault"));

	hexBTNRemove = new wxButton(hexNB1, ID_HEXBTNREMOVE, wxT("Remove"), wxPoint(110, 390), wxSize(100, 23), 0, wxDefaultValidator, wxT("hexBTNRemove"));

	hexBTNUse = new wxButton(hexNB1, ID_HEXBTNUSE, wxT("Use"), wxPoint(110, 365), wxSize(100, 23), 0, wxDefaultValidator, wxT("hexBTNUse"));

	hexLBLDump = new wxStaticText(hexNB1, ID_HEXLBLDUMP, wxT("Dump Folder"), wxPoint(5, 305), wxDefaultSize, 0, wxT("hexLBLDump"));

	hexDIRDump = new wxDirPickerCtrl(hexNB1, ID_HEXDIRDUMP, wxT(""), wxT("Select a folder"), wxPoint(120, 305), wxSize(205, 23), wxDIRP_DEFAULT_STYLE, wxDefaultValidator, wxT("hexDIRDump"));

	hexBTNSoftware = new wxButton(hexNB1, ID_HEXBTNSOFTWARE, wxT("Active Software"), wxPoint(330, 5), wxSize(100, 25), 0, wxDefaultValidator, wxT("hexBTNSoftware"));

	hexNB2 = new wxPanel(hexNB, ID_HEXNB2, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB2, wxT("Search"));

	hexLBLSSize = new wxStaticText(hexNB2, ID_HEXLBLSSIZE, wxT("Size"), wxPoint(5, 5), wxDefaultSize, 0, wxT("hexLBLSSize"));

	wxArrayString arrayStringFor_hexDBSSize;
	hexDBSSize = new wxChoice(hexNB2, ID_HEXDBSSIZE, wxPoint(85, 5), wxSize(135, 23), arrayStringFor_hexDBSSize, 0, wxDefaultValidator, wxT("hexDBSSize"));
	hexDBSSize->SetSelection(-1);

	wxArrayString arrayStringFor_hexDBSGroup;
	hexDBSGroup = new wxChoice(hexNB2, ID_HEXDBSGROUP, wxPoint(85, 30), wxSize(135, 23), arrayStringFor_hexDBSGroup, 0, wxDefaultValidator, wxT("hexDBSGroup"));
	hexDBSGroup->SetSelection(-1);

	wxArrayString arrayStringFor_hexDBSearch;
	hexDBSearch = new wxChoice(hexNB2, ID_HEXDBSEARCH, wxPoint(225, 30), wxSize(135, 23), arrayStringFor_hexDBSearch, 0, wxDefaultValidator, wxT("hexDBSearch"));
	hexDBSearch->SetSelection(-1);

	hexBTNSNew = new wxButton(hexNB2, ID_HEXBTNSNEW, wxT("Start"), wxPoint(225, 5), wxSize(75, 23), 0, wxDefaultValidator, wxT("hexBTNSNew"));

	hexBTNSearch = new wxButton(hexNB2, ID_HEXBTNCOMPARE, wxT("Compare To"), wxPoint(6, 31), wxSize(75, 23), 0, wxDefaultValidator, wxT("hexBTNSearch"));

	hexBSType = new wxStaticBox(hexNB2, ID_HEXBSTYPE, wxT("Type"), wxPoint(5, 55), wxSize(250, 65));

	hexBTNDump = new wxButton(hexNB2, ID_HEXBTNDUMP, wxT("D"), wxPoint(10, 70), wxSize(23, 23), 0, wxDefaultValidator, wxT("hexBTNDump"));
	hexBTNDump->SetToolTip(wxT("Dump"));

	hexBTNIs = new wxButton(hexNB2, ID_HEXBTNIS, wxT("="), wxPoint(60, 70), wxSize(23, 23), 0, wxDefaultValidator, wxT("hexBTNIs"));
	hexBTNIs->SetToolTip(wxT("Is value"));

	hexBTNNot = new wxButton(hexNB2, ID_HEXBTNNOT, wxT("!"), wxPoint(35, 70), wxSize(23, 23), 0, wxDefaultValidator, wxT("hexBTNNot"));
	hexBTNNot->SetToolTip(wxT("Is not value"));

	hexBTNLess = new wxButton(hexNB2, ID_HEXBTNLESS, wxT("<"), wxPoint(85, 70), wxSize(23, 23), 0, wxDefaultValidator, wxT("hexBTNLess"));
	hexBTNLess->SetToolTip(wxT("Less than value"));

	hexBTNMore = new wxButton(hexNB2, ID_HEXBTNMORE, wxT(">"), wxPoint(110, 70), wxSize(23, 23), 0, wxDefaultValidator, wxT("hexBTNMore"));
	hexBTNMore->SetToolTip(wxT("More than value"));

	hexBTNNLast = new wxButton(hexNB2, ID_HEXBTNNLAST, wxT("!#"), wxPoint(135, 70), wxSize(28, 23), 0, wxDefaultValidator, wxT("hexBTNNLast"));
	hexBTNNLast->SetToolTip(wxT("Is not value from above search"));

	hexBTNLast = new wxButton(hexNB2, ID_HEXBTNLAST, wxT("=#"), wxPoint(165, 70), wxSize(28, 23), 0, wxDefaultValidator, wxT("hexBTNLast"));
	hexBTNLast->SetToolTip(wxT("Is last value from above search"));

	hexBTNLLast = new wxButton(hexNB2, ID_HEXBTNLLAST, wxT("<#"), wxPoint(195, 70), wxSize(28, 23), 0, wxDefaultValidator, wxT("hexBTNLLast"));
	hexBTNLLast->SetToolTip(wxT("Less than value from above search"));

	hexBTNMLast = new wxButton(hexNB2, ID_HEXBTNMLAST, wxT(">#"), wxPoint(225, 70), wxSize(28, 23), 0, wxDefaultValidator, wxT("hexBTNMLast"));
	hexBTNMLast->SetToolTip(wxT("More than value from above search"));

	wxArrayString arrayStringFor_hexDBSType;
	hexDBSType = new wxChoice(hexNB2, ID_HEXDBSTYPE, wxPoint(10, 94), wxSize(240, 23), arrayStringFor_hexDBSType, 0, wxDefaultValidator, wxT("hexDBSType"));
	hexDBSType->SetSelection(-1);

	hexBValue = new wxStaticBox(hexNB2, ID_HEXBVALUE, wxT("Value"), wxPoint(260, 56), wxSize(100, 90));

	hexTXTValue1 = new wxTextCtrl(hexNB2, ID_HEXTXTVALUE1, wxT(""), wxPoint(265, 95), wxSize(90, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue1"));

	wxArrayString arrayStringFor_hexDBValue;
	hexDBValue = new wxChoice(hexNB2, ID_HEXDBVALUE, wxPoint(265, 70), wxSize(90, 23), arrayStringFor_hexDBValue, 0, wxDefaultValidator, wxT("hexDBValue"));
	hexDBValue->SetSelection(-1);

	hexTXTValue2 = new wxTextCtrl(hexNB2, ID_HEXTXTVALUE2, wxT(""), wxPoint(265, 120), wxSize(90, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue2"));
	hexTXTValue2->Enable(false);

	hexLBLProgress = new wxStaticText(hexNB2, ID_HEXLBLPROGRESS, wxT("Progress"), wxPoint(305, 5), wxDefaultSize, 0, wxT("hexLBLProgress"));

	hexPBProgress = new wxGauge(hexNB2, ID_HEXPBPROGRESS, 100, wxPoint(365, 5), wxSize(135, 23), wxGA_HORIZONTAL, wxDefaultValidator, wxT("hexPBProgress"));
	hexPBProgress->SetRange(100);
	hexPBProgress->SetValue(0);

	hexLBLExtend = new wxStaticText(hexNB2, ID_HEXLBLEXTEND, wxT("More search settings"), wxPoint(11, 127), wxDefaultSize, 0, wxT("hexLBLExtend"));

	hexSCLExtend = new wxScrolledWindow(hexNB2, ID_HEXSCLEXTEND, wxPoint(5, 150), wxSize(605, 260), wxVSCROLL);

	hexCBESigned = new wxCheckBox(hexSCLExtend, ID_HEXCBESIGNED, wxT("Signed"), wxPoint(5, 5), wxSize(100, 23), 0, wxDefaultValidator, wxT("hexCBESigned"));

	hexCBEIgnore0 = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE0, wxT("Ignore results that are 0"), wxPoint(5, 30), wxSize(200, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore0"));

	hexCBEIgnoreF = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNOREF, wxT("Ignore results that are FF etc"), wxPoint(5, 55), wxSize(200, 23), 0, wxDefaultValidator, wxT("hexCBEIgnoreF"));

	hexCBEIgnoreV = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNOREV, wxT("Ignore results that are <value>"), wxPoint(5, 80), wxSize(200, 23), 0, wxDefaultValidator, wxT("hexCBEIgnoreV"));

	hexCBERange = new wxCheckBox(hexSCLExtend, ID_HEXCBERANGE, wxT("Ignore results between <left> and <right>"), wxPoint(5, 105), wxSize(400, 23), 0, wxDefaultValidator, wxT("hexCBERange"));

	hexCBENRange = new wxCheckBox(hexSCLExtend, ID_HEXCBENRANGE, wxT("Ignore results not between <left> and <right>"), wxPoint(5, 130), wxSize(400, 23), 0, wxDefaultValidator, wxT("hexCBENRange"));

	hexTXTValue4 = new wxTextCtrl(hexSCLExtend, ID_HEXTXTVALUE4, wxT(""), wxPoint(410, 105), wxSize(75, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue4"));

	hexTXTValue5 = new wxTextCtrl(hexSCLExtend, ID_HEXTXTVALUE5, wxT(""), wxPoint(490, 105), wxSize(75, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue5"));

	hexTXTValue3 = new wxTextCtrl(hexSCLExtend, ID_HEXTXTVALUE3, wxT(""), wxPoint(410, 80), wxSize(75, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue3"));

	hexTXTValue6 = new wxTextCtrl(hexSCLExtend, ID_HEXTXTVALUE6, wxT(""), wxPoint(410, 130), wxSize(75, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue6"));

	hexTXTValue7 = new wxTextCtrl(hexSCLExtend, ID_HEXTXTVALUE7, wxT(""), wxPoint(490, 130), wxSize(75, 23), wxTE_RIGHT, wxDefaultValidator, wxT("hexTXTValue7"));

	hexCBEN64 = new wxCheckBox(hexSCLExtend, ID_HEXCBEN64, wxT("Ignore Nintendo 64 pointers"), wxPoint(5, 155), wxSize(200, 23), 0, wxDefaultValidator, wxT("hexCBEN64"));

	hexCBEIgnore8 = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE8, wxT("Ignore results that are part of 8bit <value>"), wxPoint(5, 180), wxSize(300, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore8"));

	hexCBEIgnore16 = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE16, wxT("Ignore results that are part of 16bit <value>"), wxPoint(5, 205), wxSize(300, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore16"));

	hexCBEIgnore32 = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE32, wxT("Ignore results that are part of 32bit <value>"), wxPoint(5, 230), wxSize(300, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore32"));

	hexCBEIgnore64 = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE64, wxT("Ignore results that are part of 64bit <value>"), wxPoint(5, 255), wxSize(300, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore64"));

	hexCBEIgnore8R = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE8R, wxT("Ignore results that are part of 8bit range from <left> to <right>"), wxPoint(5, 280), wxSize(400, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore8R"));

	hexCBEIgnore16R = new wxCheckBox(hexSCLExtend, ID_HEXCBEIGNORE16R, wxT("Ignore results that are part of 16bit range from <left> to <right>"), wxPoint(5, 305), wxSize(400, 23), 0, wxDefaultValidator, wxT("hexCBEIgnore16R"));

	hexNB3 = new wxPanel(hexNB, ID_HEXNB3, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB3, wxT("Results"));

	hexNB4 = new wxPanel(hexNB, ID_HEXNB4, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB4, wxT("Memory Editor"));

	hexNB5 = new wxPanel(hexNB, ID_HEXNB5, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB5, wxT("Database"));

	hexNB6 = new wxPanel(hexNB, ID_HEXNB6, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB6, wxT("Hack"));

	hexNB7 = new wxPanel(hexNB, ID_HEXNB7, wxPoint(4, 26), wxSize(617, 415));
	hexNB->AddPage(hexNB7, wxT("About"));

	wxArrayString arrayStringFor_hexDBGroup;
	arrayStringFor_hexDBGroup.Add(wxT("Nintendo 64"));
	arrayStringFor_hexDBGroup.Add(wxT("Nintendo DS / DSi / 3DS"));
	arrayStringFor_hexDBGroup.Add(wxT("Nintendo Gameboy"));
	arrayStringFor_hexDBGroup.Add(wxT("Nintendo Wii"));
	arrayStringFor_hexDBGroup.Add(wxT("PC"));
	arrayStringFor_hexDBGroup.Add(wxT("Sony Playstation 1"));
	arrayStringFor_hexDBGroup.Add(wxT("Sony Playstation 2"));
	hexDBGroup = new wxChoice(hexNB1, ID_HEXDBGROUP, wxPoint(75, 5), wxSize(145, 23), arrayStringFor_hexDBGroup, 0, wxDefaultValidator, wxT("hexDBGroup"));
	hexDBGroup->SetSelection(4);

	SetTitle(wxT("New Dialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,640,480);
	Center();
	
	////GUI Items Creation End
	gLen = 7; pLen = 1;
	groups = new wxString [gLen];
	group = new int [pLen];
	preset = new wxString [pLen];
	groups[0] = "Nintendo 64";
    groups[1] = "Nintendo DS / DSi / 3DS";
    groups[2] = "Nintendo Gameboy";
    groups[3] = "Nintendo Wii";
    groups[4] = "PC";
    groups[5] = "Sony Playstation 1";
    groups[6] = "Sony Playstation 2";
    group[0] = 6;
    preset[0] = "PCSX2 0.9.7+";
}

void HexFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
/*
 * getApps
 */

int appWait = 0;
int appLen = 0;
wxString appS;
PROCESSENTRY32 HexFrm::getApp(DWORD id) {
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    HANDLE app = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    Process32First(app, &pe32);
    do {
        if (pe32.th32ProcessID == id) { break; }
        else { pe32.th32ProcessID = 0; }
    } while (Process32Next(app, &pe32));
    CloseHandle(app);
    return pe32;
}
BOOL getWin(HWND hwnd, LPARAM pe32) {
    try {
        LPTSTR t;
        GetWindowText(hwnd, t, sizeof(LPTSTR));
        appS.Printf(t);
        return TRUE;
    } catch (e) { return FALSE; }
}
void HexFrm::getApps(bool user) {
#ifdef WIN32
    if (appWait > 500 || user == true) {
        appWait = 0;
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
        HANDLE app = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (app != INVALID_HANDLE_VALUE && Process32First(app, &pe32)) {
            do {
                EnumWindows(getWin, (LPARAM)(&pe32));
                HexFrm::hexLBSoftware->Append(appS);
            } while (Process32Next(app, &pe32));
        }
        /*THREADENTRY32 te32 = {0}; GUITHREADINFO *ti32;
        te32.dwSize = sizeof(THREADENTRY32);
        LPTSTR t; DWORD pid;
        hexLBSoftware->Clear();
        if (app != INVALID_HANDLE_VALUE) {
            wxString s; int i = 0;
            if (Thread32First(app, &te32)) {
                do {
                    if (GetGUIThreadInfo(te32.th32ThreadID,ti32) != 0)// && IsWindow(ti32->hwndActive))
                    {
                        //pe32 = getApp(te32.th32OwnerProcessID);
                        //if (pe32.th32ProcessID != 0)
                            i++;
                    }
                } while(Thread32Next(app, &te32));
                Thread32First(app, &te32);
                apps = new xApp [i]; i = 0;
                do {
                    pid = te32.th32OwnerProcessID;
                    if (GetGUIThreadInfo(te32.th32ThreadID,ti32) != 0)// && IsWindow(ti32->hwndActive))
                    {
                        pe32 = getApp(pid);
                        //if (pe32.th32ProcessID != 0) {
                            apps[i].id = pid;
                            apps[i].exe.Printf(pe32.szExeFile);
                            GetWindowText(ti32->hwndActive,t,sizeof(LPTSTR));
                            apps[i].name.Printf(t);
                            apps[i].hwnd = ti32->hwndActive;
                            s = apps[i].exe << " - " << apps[i].name;
                            hexLBSoftware->Append(s); i++;
                        //}
                    }
                } while(Thread32Next(app, &te32)); appLen = i;
                apps[i - 1].last = true; CloseHandle(app);
            }
        }*/
    } else { appWait++; }
#endif
}
/*
 * hexBTNSoftwareOnClick
 */
void HexFrm::hexBTNSoftwareOnClick(wxCommandEvent& event) { getApps(true); }

/*
 * HexFrmIdle
 */
void HexFrm::HexFrmIdle(wxIdleEvent& event) { getApps(false); }

/*
 * hexDBGroupSelected
 */
void HexFrm::hexDBGroupSelected(wxCommandEvent& event )
{
	wxString tmp = hexDBGroup->GetStringSelection();
    hexDBPreset->Clear();
    int i;
    for (i = 0;i < pLen;i++) {
        if (groups[group[i]] == tmp) {
            hexDBPreset->Append(preset[i]);
        }
    }
}
