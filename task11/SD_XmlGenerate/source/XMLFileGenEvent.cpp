// XMLFileGenEvent.cpp: implementation of the CXMLFileGenEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "XMLFileGenEvent.h"
#include "WriteNewXMLFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SCDXmlFileGenCallBackInterface * g_pCallBack = NULL;

CXMLFileGenEvent::CXMLFileGenEvent()
{
	m_pXMLBaseDataList = new QValueList<XMLPARA>;
	m_pXMLBaseTitleList = new QValueList<QString>;

	m_pXMLAddDataList = new QValueList<XMLPARA>;
	m_pXMLAddTitleList = new QValueList<QString>;

	m_pszConfig = new char[100];
	memset(m_pszConfig, 0, 100);
}

CXMLFileGenEvent::~CXMLFileGenEvent()
{
	delete m_pXMLBaseDataList;
	delete m_pXMLBaseTitleList;

	delete m_pXMLAddDataList;
	delete m_pXMLAddTitleList;

	delete m_pszConfig;
}

SCDXmlFileGenInterFace* GetSCDXmlFileObject()
{
	SCDXmlFileGenInterFace* pObj = new CXMLFileGenEvent;
	
	return pObj;
}

bool CXMLFileGenEvent::Init( char * szConfig )
{
	strcpy( m_pszConfig, szConfig );
	LOG4CXX_INIT("Log.SCDXmlFile",szConfig);

	m_pXMLBaseDataList->clear();
	m_pXMLBaseTitleList->clear();
	m_pXMLAddDataList->clear();
	m_pXMLAddTitleList->clear();

 	CLoadBaseXml::Instance()->LoadBaseXMLFile(szConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList);
// 	CWriteNewXMLFile::Instance()->WriteXMLFile(m_pszConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList, WRITEBYSCDNO, 1);
// 	CWriteNewXMLFile::Instance()->WriteXMLFile(m_pszConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList, WRITEBYSCDNO, 11);
	
	GenerateXMLBySCDNum(NULL);

	return true;
}

bool CXMLFileGenEvent::GenerateXMLBySCDNum( unsigned int * pXMLNum, unsigned int uSCDNum /*= 120*/ )
{
	return CWriteNewXMLFile::Instance()->WriteXMLFile(m_pszConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList, WRITEBYSCDNUM, uSCDNum);
}

bool CXMLFileGenEvent::GenerateXMLByRackNo( unsigned int uRackNo, unsigned int * pXMLNum )
{
	return CWriteNewXMLFile::Instance()->WriteXMLFile(m_pszConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList, WRITEBYRACKID, uRackNo);
}

bool CXMLFileGenEvent::GenerateXMLBySCDNo( unsigned int uSCDNo )
{
	return CWriteNewXMLFile::Instance()->WriteXMLFile(m_pszConfig, m_pXMLBaseDataList, m_pXMLBaseTitleList, m_pXMLAddDataList, m_pXMLAddTitleList, WRITEBYSCDNO, uSCDNo);
}

void CXMLFileGenEvent::Advise( SCDXmlFileGenCallBackInterface* pCallBackInterface )
{
	g_pCallBack = pCallBackInterface;
}