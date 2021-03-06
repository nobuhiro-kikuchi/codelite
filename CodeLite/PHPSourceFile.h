#ifndef PHPPARSER_H
#define PHPPARSER_H

#include "codelite_exports.h"
#include <wx/filename.h>
#include "PhpLexerAPI.h"
#include "PHPEntityBase.h"
#include <vector>

class WXDLLIMPEXP_CL PHPSourceFile
{
    wxString m_text;
    PHPEntityBase::List_t m_scopes;
    PHPEntityBase::List_t m_defines;
    PHPScanner_t m_scanner;
    wxFileName m_filename;
    std::vector<phpLexerToken> m_lookBackTokens;
    std::vector<phpLexerToken> m_comments;
    bool m_parseFunctionBody;
    int m_depth;
    bool m_reachedEOF;
    // aliases defined by the 'use' operator
    std::map<wxString, wxString> m_aliases;

public:
    typedef wxSharedPtr<PHPSourceFile> Ptr_t;

protected:
    /**
     * @brief calls phpLexerNextToken. Use this call instead of the global phpLexerNextToken
     * since this function will handle all PHP comments found
     */
    bool NextToken(phpLexerToken& token);

    /**
     * @brief read until we found 'delim' (consume it)
     */
    bool ReadUntilFound(int delim, phpLexerToken& token);

    /**
     * @brief read until we found 'delim1' or delim2 (return which one was found)
     * or wxNOT_FOUND if non found
     */
    int ReadUntilFoundOneOf(int delim1, int delim2, phpLexerToken& token);

    /**
     * @brief read expression from the current position until we hit
     * semi colon
     * @param tokens [output]
     */
    bool ReadExpression(wxString& expression);

    /**
     * @brief unget the token
     */
    void UngetToken(const phpLexerToken& token);

    /**
     * @brief run the lexer until we find 'delim' - consume delim as well
     */
    bool ConsumeUntil(int delim);

    /**
     * @brief read list of identifiers separated by comma until we find 'delim'
     * note that this function does not consume the 'delim' token
     */
    bool ReadCommaSeparatedIdentifiers(int delim, wxArrayString& list);

    /**
     * @brief read the type
     */
    wxString ReadType();
    
    /**
     * @brief read the value that comes after the 'extends' keyword
     */
    wxString ReadExtends();
    
    /**
     * @brief read the tokens after the implements keyword
     */
    void ReadImplements(wxArrayString& impls);
    
    
    /**
     * @brief parse 'use' statements (outer scope, for aliasing)
     */
    void OnUse();
    
    /**
     * @brief parse 'use' statements inside class (usually this is done for 'traits')
     */
    void OnUseTrait();
    
    /**
     * @brief 'namespace' keyword found
     */
    void OnNamespace();

    /**
     * @brief 'function' keyword found
     */
    void OnFunction();
    
    /**
     * @brief found catch keyword
     */
    void OnCatch();
    
    /**
     * @brief found a global variable
     */
    void OnVariable(const phpLexerToken& token);

    /**
     * @brief 'class' keyword found
     */
    void OnClass(const phpLexerToken& tok);

    /**
     * @brief a define keyword was found
     */
    void OnDefine(const phpLexerToken& tok);

    /**
     * @brief go over the look back tokens and extract all function flags
     */
    size_t LookBackForFunctionFlags();

    /**
     * @brief go over the look back tokens and extract all variable flags
     */
    size_t LookBackForVariablesFlags();

    /**
     * @brief return true of the look back tokens contains 'type'
     */
    bool LookBackTokensContains(int type) const;
    /**
     * @brief parse function signature
     */
    void ParseFunctionSignature(int startingDepth);

    /**
     * @brief consume the function body
     */
    void ConsumeFunctionBody();

    /**
     * @brief parse function body and collect local variables +
     * possible return statements
     */
    void ParseFunctionBody();

    /**
     * @brief go over the loop back tokens and construct the type hint
     */
    wxString LookBackForTypeHint();

    /**
     * @brief parse phase 2.
     * On this stage, all phpdoc comments are assigned to the proper PHP entity
     */
    void PhaseTwo();

public:
    PHPSourceFile(const wxFileName& filename);
    PHPSourceFile(const wxString& content);
    virtual ~PHPSourceFile();

    /**
     * @brief return list of aliases (their short name) that appears on this file
     */
    PHPEntityBase::List_t GetAliases() const;
    
    /**
     * @brief return list of defines defined in this source file
     */
    const PHPEntityBase::List_t& GetDefines() const { return m_defines; }

    /**
     * @brief attempt to resolve 'type' to its full path
     */
    wxString MakeIdentifierAbsolute(const wxString& type);

    /**
     * @brief return the source file text
     */
    const wxString& GetText() const { return m_text; }

    /**
     * @brief parse the source file
     */
    void Parse(int exitDepth = -1);

    /**
     * @brief return the current scope
     */
    PHPEntityBase::Ptr_t CurrentScope();

    /**
     * @brief return the inner most class of the 'CurrentScope'
     * Note that this function return a const raw pointer to the
     * class
     */
    const PHPEntityBase* Class();

    /**
     * @brief return the namespace scope of this file
     */
    PHPEntityBase::Ptr_t Namespace();

    // Accessors
    void SetFilename(const wxFileName& filename) { this->m_filename = filename; }
    const wxFileName& GetFilename() const { return m_filename; }
    void SetParseFunctionBody(bool parseFunctionBody) { this->m_parseFunctionBody = parseFunctionBody; }
    bool IsParseFunctionBody() const { return m_parseFunctionBody; }
    void PrintStdout();
};

#endif // PHPPARSER_H
