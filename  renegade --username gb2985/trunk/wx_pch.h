/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED_
#define WX_PCH_H_INCLUDED_

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
#include "cleanAll.h"
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED
