//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : SFTPTreeView.h
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

#ifndef SFTPTREEVIEW_H
#define SFTPTREEVIEW_H

#include "UI.h"
#include "cl_sftp.h"
#include "bitmap_loader.h"
#include "ssh_account_info.h"
#include <vector>
#include "cl_command_event.h"

class MyClientData;
class SFTP;

typedef std::vector<MyClientData*> MyClientDataVect_t;

class SFTPTreeView : public SFTPTreeViewBase
{
    clSFTP::Ptr_t m_sftp;
    BitmapLoader m_bmpLoader;
    SSHAccountInfo m_account;
    SFTP* m_plugin;
    wxString m_commandOutput;
    
public:
    enum {
        ID_SFTP_BOOKMARK_FIRST = 13000,
        ID_SFTP_BOOKMARK_LAST = 13100,
        ID_SFTP_BOOKMARK_SETTINGS = 13101,
    };

public:
    SFTPTreeView(wxWindow* parent, SFTP* plugin);
    virtual ~SFTPTreeView();
    bool IsConnected() const { return m_sftp && m_sftp->IsConnected(); }

protected:
    virtual void OnOpenTerminal(wxCommandEvent& event);
    virtual void OnOpenTerminalUI(wxUpdateUIEvent& event);
    virtual void OnConnection(wxCommandEvent& event);
    virtual void OnSelectionChanged(wxTreeListEvent& event);
    virtual void OnChoiceAccount(wxCommandEvent& event);
    virtual void OnChoiceAccountUI(wxUpdateUIEvent& event);
    virtual void OnGotoLocation(wxCommandEvent& event);
    virtual void OnGotoLocationUI(wxUpdateUIEvent& event);
    virtual void OnAddBookmark(wxAuiToolBarEvent& event);
    virtual void OnAddBookmarkUI(wxUpdateUIEvent& event);
    virtual void OnContextMenu(wxTreeListEvent& event);
    virtual void OnDisconnect(wxCommandEvent& event);
    virtual void OnDisconnectUI(wxUpdateUIEvent& event);
    virtual void OnConnectUI(wxUpdateUIEvent& event);
    virtual void OnConnect(wxCommandEvent& event);
    virtual void OnMenuNew(wxCommandEvent& event);
    virtual void OnMenuOpen(wxCommandEvent& event);
    virtual void OnMenuDelete(wxCommandEvent& event);
    virtual void OnMenuRename(wxCommandEvent& event);
    virtual void OnMenuNewFile(wxCommandEvent& event);
    virtual void OnMenuRefreshFolder(wxCommandEvent& event);
    void OnShowSizeCol(wxCommandEvent& event);
    void OnShowTypeCol(wxCommandEvent& event);

    // Edit events
    void OnCopy(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);

    void DoCloseSession();
    void DoOpenSession();
    bool DoExpandItem(const wxTreeListItem& item);
    void DoBuildTree(const wxString& initialFolder);
    void ManageBookmarks();
    
    int IsSizeColumnShown() const;
    int IsTypeColumnShown() const;
    int GetSizeColumnIndex() const;
    int GetTypeColumnIndex() const;
    
    wxTreeListItem DoAddFolder(const wxTreeListItem& parent, const wxString& path);
    wxTreeListItem DoAddFile(const wxTreeListItem& parent, const wxString& path);

    MyClientData* GetItemData(const wxTreeListItem& item);
    MyClientDataVect_t GetSelectionsItemData();
    bool DoOpenFile(const wxTreeListItem& item);
    void DoDeleteColumn(int colIdx);
    
protected:
    virtual void OnItemActivated(wxTreeListEvent& event);
    virtual void OnItemExpanding(wxTreeListEvent& event);
    virtual void OnOpenAccountManager(wxCommandEvent& event);
};
#endif // SFTPTREEVIEW_H
