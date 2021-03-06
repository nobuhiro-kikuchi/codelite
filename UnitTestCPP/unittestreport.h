//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : unittestreport.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef UNITTESTREPORT_BASE_CLASSES_H
#define UNITTESTREPORT_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include "progressctrl.h"
#include <wx/listctrl.h>

class UnitTestsBasePage : public wxPanel
{
protected:
    wxStaticText* m_staticText7;
    ProgressCtrl* m_progressPassed;
    wxStaticText* m_staticText8;
    ProgressCtrl* m_progressFailed;
    wxStaticText* m_staticText10;
    wxStaticText* m_staticTextTotalTests;
    wxStaticText* m_staticText12;
    wxStaticText* m_staticTextFailTestsNum;
    wxStaticText* m_staticText14;
    wxStaticText* m_staticTextSuccessTestsNum;
    wxListCtrl* m_listCtrlErrors;

protected:
    virtual void OnItemActivated(wxListEvent& event) { event.Skip(); }

public:
    UnitTestsBasePage(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~UnitTestsBasePage();
};

#endif
