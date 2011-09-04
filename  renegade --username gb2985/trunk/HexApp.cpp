//---------------------------------------------------------------------------
//
// Name:        HexApp.cpp
// Author:      admin
// Created:     28/08/2011 17:54:25
// Description: 
//
//---------------------------------------------------------------------------

#include "HexApp.h"
#include "HexFrm.h"

IMPLEMENT_APP(HexFrmApp)

bool HexFrmApp::OnInit()
{
    HexFrm* frame = new HexFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int HexFrmApp::OnExit()
{
	return 0;
}
