#ifndef NODEJSWORKSPACECONFIGURATION_H
#define NODEJSWORKSPACECONFIGURATION_H

#include "cl_config.h"
#include <wx/arrstr.h>

class NodeJSWorkspaceConfiguration : public clConfigItem
{
    wxArrayString m_folders;
    bool m_isOk;

public:
    virtual void FromJSON(const JSONElement& json);
    virtual JSONElement ToJSON() const;

    NodeJSWorkspaceConfiguration();
    virtual ~NodeJSWorkspaceConfiguration();

    NodeJSWorkspaceConfiguration& Load(const wxFileName& filename);
    NodeJSWorkspaceConfiguration& Save(const wxFileName& filename);
    NodeJSWorkspaceConfiguration& SetFolders(const wxArrayString& folders)
    {
        this->m_folders = folders;
        return *this;
    }

    const wxArrayString& GetFolders() const { return m_folders; }
    bool IsOk() const { return m_isOk; }
};

#endif // NODEJSWORKSPACECONFIGURATION_H
