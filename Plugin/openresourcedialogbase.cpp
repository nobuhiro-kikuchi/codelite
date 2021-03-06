//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: openresourcedialogbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "openresourcedialogbase.h"


// Declare the bitmap loading function
extern void wxCFB13InitBitmapResources();

static bool bBitmapLoaded = false;


OpenResourceDialogBase::OpenResourceDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCFB13InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_textCtrlResourceName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), wxTE_PROCESS_ENTER);
    m_textCtrlResourceName->SetToolTip(_("Type resource name to open.\nYou may use a space delimited list of words to narrow down the list of choices\ne.g. Typing: 'Open Dialog' will include results that contain both words \"Open\" _and_ \"Dialog\""));
    m_textCtrlResourceName->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlResourceName->SetHint(wxT(""));
    #endif
    
    mainSizer->Add(m_textCtrlResourceName, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* fgSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer1->AddGrowableCol(0);
    
    mainSizer->Add(fgSizer1, 0, wxEXPAND, 5);
    
    m_listOptions = new wxListView( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
    mainSizer->Add(m_listOptions, 1, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer2 = new wxStdDialogButtonSizer();
    
    mainSizer->Add(m_stdBtnSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer2->AddButton(m_buttonOK);
    
    m_button6 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer2->AddButton(m_button6);
    m_stdBtnSizer2->Realize();
    
    SetName(wxT("OpenResourceDialogBase"));
    SetMinSize( wxSize(400,300) );
    SetSizeHints(600,400);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_textCtrlResourceName->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(OpenResourceDialogBase::OnKeyDown), NULL, this);
    m_textCtrlResourceName->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(OpenResourceDialogBase::OnText), NULL, this);
    m_textCtrlResourceName->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(OpenResourceDialogBase::OnEnter), NULL, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OpenResourceDialogBase::OnOK), NULL, this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(OpenResourceDialogBase::OnOKUI), NULL, this);
    
}

OpenResourceDialogBase::~OpenResourceDialogBase()
{
    m_textCtrlResourceName->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(OpenResourceDialogBase::OnKeyDown), NULL, this);
    m_textCtrlResourceName->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(OpenResourceDialogBase::OnText), NULL, this);
    m_textCtrlResourceName->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(OpenResourceDialogBase::OnEnter), NULL, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OpenResourceDialogBase::OnOK), NULL, this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(OpenResourceDialogBase::OnOKUI), NULL, this);
    
}
