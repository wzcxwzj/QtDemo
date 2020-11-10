// WriteNewXMLFile.h: interface for the CWriteNewXMLFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WRITENEWXMLFILE_H__575C52A0_ABFF_4D45_A3F6_1DDE078522B7__INCLUDED_)
#define AFX_WRITENEWXMLFILE_H__575C52A0_ABFF_4D45_A3F6_1DDE078522B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XMLFileGenEvent.h"

class CWriteNewXMLFile  
{
public:
	CWriteNewXMLFile();
	virtual ~CWriteNewXMLFile();

public:
	static CWriteNewXMLFile* Instance();
	bool WriteXMLFile(	char * szConfig, QValueList<XMLPARA> * pBaseParaList, QValueList<QString> * pBaseTitleList,
						QValueList<XMLPARA> * pAddParaList, QValueList<QString> * pAddTitleList, int nType, int nValue);

private:
	static CWriteNewXMLFile* m_spInstance;

	QValueList<XMLPARA> * m_pTargetBaseXmlList;
	QValueList<QString> * m_pTargetBaseTitleList;

	QValueList<XMLPARA> * m_pTargetAddXmlList;
	QValueList<QString> * m_pTargetAddTitleList;

	XMLPARA ItemPara;

	QString strIndex, strId, strValue, strDesc;
	unsigned int uSCDNum, uRackId, uSCDNo;

private:
	bool WriteTargetXMLFile( char * szConfig, int nSCDNum );
	
	bool SaveXmlBodyContent(QDomDocument& doc, QDomElement& elem );

	bool SaveBaseSectionTitle(QDomDocument& doc, QDomElement& elem );
	bool SaveXmlBaseItem(QDomDocument& doc, QDomElement& elem, QString strSectionTitle );

	bool SaveAddSectionTitle(QDomDocument& doc, QDomElement& elem );	
	bool SaveXmlAddItem(QDomDocument& doc, QDomElement& elem, QString strSectionTitle );

	unsigned int GetFirstSCDNoByRack( unsigned int uRack );
	QString GetValueByDevId(unsigned int uDevId, unsigned int uItemIndex);

	unsigned int GetChargerIdbyPara(unsigned int uDevId, unsigned int uRackId, unsigned int uSecNo, unsigned int uRackType);
	unsigned int GetCabinetIdbyPara(unsigned int uDevId, unsigned int uSecNo, unsigned int uRackType);

	QString GetRackIdByDevId(unsigned int uDevId);
	QString GetRackValueByPara_PCSYX(unsigned int uRackId, unsigned int uDevId, unsigned int uSecNo, unsigned int uRackType);	//根据充电架不同得到各对应的描述
 	QString GetCommValueByPara_PCSYX(unsigned int uRackId, QString strValue);													//根据充电架不同只是将架号替换原来的参引
};

#endif // !defined(AFX_WRITENEWXMLFILE_H__575C52A0_ABFF_4D45_A3F6_1DDE078522B7__INCLUDED_)
