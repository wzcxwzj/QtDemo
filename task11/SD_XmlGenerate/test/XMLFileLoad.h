// XMLFileLoad.h: interface for the CXMLFileLoad class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLFILELOAD_H__9358F572_2E73_4047_BF4E_69198D0CC5DE__INCLUDED_)
#define AFX_XMLFILELOAD_H__9358F572_2E73_4047_BF4E_69198D0CC5DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <qlibrary.h>
#include "../source/CommparaGenInterface.h"

class CXMLFileLoad  
{
public:
	CXMLFileLoad();
	virtual ~CXMLFileLoad();

public:
	bool Init( char* szConfig );

private:
	bool InitXMLGenerate();
	typedef SCDXmlFileGenInterFace* (GetXMLFileObject)();
	SCDXmlFileGenInterFace* m_pDllXML;
 	QLibrary *m_pXMLloader;
};

extern CXMLFileLoad g_XMLFile;

#endif // !defined(AFX_XMLFILELOAD_H__9358F572_2E73_4047_BF4E_69198D0CC5DE__INCLUDED_)
