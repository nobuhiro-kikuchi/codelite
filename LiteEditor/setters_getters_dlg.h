//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : setters_getters_dlg.h
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
#ifndef __setters_getters_dlg__
#define __setters_getters_dlg__

#include "setters_getters.h"
#include "manager.h"
#include "ctags_manager.h"

//----------------------------------------------------

class SettersGetterData : public clConfigItem
{
    size_t m_flags;
public:
    enum {
        FunctionStartWithUpperCase = 0x00000001,
        FormatFileWhenDone         = 0x00000002,
    };
    
public:
    virtual void FromJSON(const JSONElement& json);
    virtual JSONElement ToJSON() const;
    
    SettersGetterData();
    virtual ~SettersGetterData();

    void SetFlags(size_t flags) {
        this->m_flags = flags;
    }
    size_t GetFlags() const {
        return m_flags;
    }
};

//----------------------------------------------------
class SettersGettersTreeData : public wxTreeItemData
{
public:
    enum { Kind_Getter = 0, Kind_Setter, Kind_Parent, Kind_Root };

    TagEntryPtr m_tag;
    int         m_kind;
    bool        m_checked;
    
public:
    SettersGettersTreeData(TagEntryPtr tag, int kind, bool checked) : m_tag(tag), m_kind(kind), m_checked(checked) {}
    virtual ~SettersGettersTreeData() {}
};

class SettersGettersDlg : public SettersGettersBaseDlg
{
    std::vector<TagEntryPtr>        m_members;
    wxFileName                      m_file;
    int                             m_lineno;
    std::map<wxString, TagEntryPtr> m_tagsMap;
    wxString                        m_code;
    bool                            m_checkForDuplicateEntries;
    SettersGetterData               m_settings;
    
protected:
    virtual void OnValueChanged(wxDataViewEvent& event);
    void OnCheckStartWithUpperCase(wxCommandEvent &event);
    void OnCheckAll(wxCommandEvent &e);
    void OnUncheckAll(wxCommandEvent &e);
    void OnUpdatePreview(wxCommandEvent &e);
    void OnButtonOk(wxCommandEvent &e);
    int  BuildTree ();
    void UpdateTree();

    wxString GenerateFunctions();
    wxString GenerateSetter(TagEntryPtr tag, bool &alreadyExist, wxString &displayName);
    wxString GenerateSetter(TagEntryPtr tag);
    wxString GenerateGetter(TagEntryPtr tag, bool &alreadyExist, wxString &displayName);
    wxString GenerateGetter(TagEntryPtr tag);

    void FormatName(wxString &name);
    void UpdatePreview();
    void GenerateGetters(wxString &code);
    void GenerateSetters(wxString &code);
    bool DoCheckExistance(const wxString &scope, const wxString &name, const wxString &method_signature);
public:
    /** Constructor */
    SettersGettersDlg(wxWindow* parent);
    virtual ~SettersGettersDlg();
    wxString GetGenCode() ;
    bool GetFormatText() const {
        return m_checkBoxForamtFileWhenDone->IsChecked();
    }
    
    bool Init(const std::vector<TagEntryPtr> &tags, const wxFileName &file, int lineno);
};
#endif // __setters_getters_dlg__
