// XMLFileGenEvent.h: interface for the CXMLFileGenEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLFILEGENEVENT_H__70C68308_E35D_4F66_930D_8A62005A7FE4__INCLUDED_)
#define AFX_XMLFILEGENEVENT_H__70C68308_E35D_4F66_930D_8A62005A7FE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CommparaGenInterface.h"
#include "LoadBaseXml.h"
#include "WriteLog.h"

class CXMLFileGenEvent : public SCDXmlFileGenInterFace
{
public:
	CXMLFileGenEvent();
	virtual ~CXMLFileGenEvent();

public:
	virtual bool Init(char * szConfig);
	virtual bool GenerateXMLBySCDNum( unsigned int * pXMLNum, unsigned int uSCDNum = 120);
	virtual bool GenerateXMLByRackNo( unsigned int uRackNo, unsigned int * pXMLNum );
	virtual bool GenerateXMLBySCDNo( unsigned int uSCDNo );
	virtual void Advise(SCDXmlFileGenCallBackInterface* pCallBackInterface);

private:
	char * m_pszConfig;
	QValueList<XMLPARA> * m_pXMLBaseDataList;
	QValueList<QString> * m_pXMLBaseTitleList;

	QValueList<XMLPARA> * m_pXMLAddDataList;
	QValueList<QString> * m_pXMLAddTitleList;
};

extern SCDXmlFileGenCallBackInterface * g_pCallBack;

#endif // !defined(AFX_XMLFILEGENEVENT_H__70C68308_E35D_4F66_930D_8A62005A7FE4__INCLUDED_)
