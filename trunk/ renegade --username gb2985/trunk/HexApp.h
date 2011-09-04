//---------------------------------------------------------------------------
//
// Name:        HexApp.h
// Author:      admin
// Created:     28/08/2011 17:54:25
// Description: 
//
//---------------------------------------------------------------------------

#ifndef HEXAPP_H
#define HEXAPP_H

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif
class HexFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};
#endif
