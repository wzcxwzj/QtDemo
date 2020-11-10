// XMLFileLoad.cpp: implementation of the CXMLFileLoad class.
//
//////////////////////////////////////////////////////////////////////

#include "XMLFileLoad.h"
#include "WriteLog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CXMLFileLoad g_XMLFile;

CXMLFileLoad::CXMLFileLoad()
{

}

CXMLFileLoad::~CXMLFileLoad()
{

}

bool CXMLFileLoad::Init( char* szConfig )
{
	if ( true == InitXMLGenerate())
	{
		m_pDllXML->Init( szConfig );
	}
	
	
	return true;
}

bool CXMLFileLoad::InitXMLGenerate()
{
	bool bRet = false;
	
	if (NULL == m_pDllXML)
	{
		if (NULL == m_pXMLloader)
			m_pXMLloader = new QLibrary("CommparaGen.dll");
		
		if(m_pXMLloader->load())
		{
			GetXMLFileObject* pMethod = (GetXMLFileObject*)m_pXMLloader->resolve("GetSCDXmlFileObject");
			if (pMethod)
			{
				m_pDllXML = (SCDXmlFileGenInterFace *)pMethod();
				bRet = true;
			}
		}
		else
		{
			LOGXJ_ERROR(("CommparaGen.dll load error,please check path"));
		}
	}
	
	return bRet;
}
