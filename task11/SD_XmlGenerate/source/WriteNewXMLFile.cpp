// WriteNewXMLFile.cpp: implementation of the CWriteNewXMLFile class.
//
//////////////////////////////////////////////////////////////////////

#include "WriteNewXMLFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWriteNewXMLFile * CWriteNewXMLFile::m_spInstance = 0;

CWriteNewXMLFile::CWriteNewXMLFile()
{

}

CWriteNewXMLFile::~CWriteNewXMLFile()
{

}

CWriteNewXMLFile* CWriteNewXMLFile::Instance()
{
	if ( 0 == m_spInstance )
	{
		m_spInstance = new CWriteNewXMLFile;
	}

	return m_spInstance;
}

bool CWriteNewXMLFile::WriteXMLFile( char * szConfig, QValueList<XMLPARA> * pBaseParaList, QValueList<QString> * pBaseTitleList, 
									 QValueList<XMLPARA> * pAddParaList, QValueList<QString> * pAddTitleList, int nType, int nValue )
{
	m_pTargetBaseXmlList = pBaseParaList;
	m_pTargetBaseTitleList = pBaseTitleList;
	
	m_pTargetAddXmlList = pAddParaList;
	m_pTargetAddTitleList = pAddTitleList;
	
	unsigned int i = 0, uSCDNum, uFirstSCDNo;
	switch (nType)
	{
	case WRITEBYSCDNUM:
		{
			if ( nValue != 120 )
				LOGXJ_WARN((" 步科网关的个数应为120个, 输入参数为nValue = %d ", nValue));
			for ( i = 0; i < nValue; i++)
			{
				uSCDNo = i+1;
				WriteTargetXMLFile( szConfig, uSCDNo );
			}
		}		
		break;
	case WRITEBYRACKID:
		{
			if ((nValue > 12) || (nValue < 1))
			{
				LOGXJ_WARN((" 充电架的ID输入非法, 输入参数为nValue = %d ", nValue));
				return false;
			}
			uSCDNum = 10;
			uFirstSCDNo = GetFirstSCDNoByRack(nValue);
			uSCDNum += uFirstSCDNo;
			for ( i = uFirstSCDNo; i < uSCDNum; i++)
			{
				uSCDNo = i;
				WriteTargetXMLFile( szConfig, uSCDNo );
			}
		}
		break;
	case WRITEBYSCDNO:
		uSCDNo = nValue;
		WriteTargetXMLFile( szConfig, nValue );
		break;
	}
	
	
	return true;
}

bool CWriteNewXMLFile::WriteTargetXMLFile( char * szConfig, int nSCDNum )
{
	QString strfileName = szConfig;
	strfileName += QString("TargetCommpara%1.xml").arg(nSCDNum);

	QFile xmlFile(strfileName);
	if (! xmlFile.open(IO_WriteOnly))
		return false;


	QTextStream stream(&xmlFile);
	stream.setEncoding(QTextStream::Unicode);
	QTextCodec *pCodec = QTextCodec::codecForName("GBK");
	QDomDocument doc;
	QDomElement root = doc.createElement("COMMON_CFG");
	root.setAttribute("xmlns","http://www.xjec.com/csu8000");
	doc.appendChild(root);
	
	SaveXmlBodyContent( doc, root );
	stream << doc.toString();
	xmlFile.close();
	return true;	
}

bool CWriteNewXMLFile::SaveXmlBodyContent( QDomDocument& doc, QDomElement& elem )
{
	QDomElement Element = doc.createElement("body");
	SaveBaseSectionTitle( doc, Element );
	SaveAddSectionTitle( doc, Element );
	elem.appendChild(Element);	

	return true;
}

bool CWriteNewXMLFile::SaveBaseSectionTitle( QDomDocument& doc, QDomElement& elem )
{
	QString strSectionTitle;
	for (int i = 0; i < m_pTargetBaseTitleList->size(); i++)
	{
		strSectionTitle = *m_pTargetBaseTitleList->at(i);
		qDebug(strSectionTitle);

		QDomElement Element = doc.createElement( strSectionTitle );
		SaveXmlBaseItem( doc, Element, strSectionTitle);
		elem.appendChild(Element);
	}
	
	return true;
}

bool CWriteNewXMLFile::SaveXmlBaseItem( QDomDocument& doc, QDomElement& elem, QString strSectionTitle )
{
	for (int i = 0; i < m_pTargetBaseXmlList->size(); i++)
	{
		ItemPara = *m_pTargetBaseXmlList->at(i);
		
		strIndex = ItemPara.strIndex;
		strId = ItemPara.strId;
		strValue = ItemPara.strValue;
		strDesc = ItemPara.strDes;
		
		if (strIndex == strSectionTitle)
		{
			QDomElement Element = doc.createElement("ITEM");

			Element.setAttribute("id", strId);
			Element.setAttribute("value", strValue);
			Element.setAttribute("desc", strDesc);

			elem.appendChild(Element);
		}
	}	
	return true;
}

bool CWriteNewXMLFile::SaveAddSectionTitle( QDomDocument& doc, QDomElement& elem )
{
	QString strSectionTitle;
	for (int i = 0; i < m_pTargetAddTitleList->size(); i++)
	{
		strSectionTitle = *m_pTargetAddTitleList->at(i);

		if (strSectionTitle.contains("DEVLIST"))
		{
			QString strRackId = GetRackIdByDevId(uSCDNo);
			unsigned int uRackId = strRackId.toUInt();
			if ( uRackId%2 != 0)						//当前架子为奇数架子(左边的架子)
			{
				if ("LDEVLIST" == strSectionTitle)
				{
					strSectionTitle = "DEVLIST";
					QDomElement Element = doc.createElement( strSectionTitle );
					SaveXmlAddItem( doc, Element, strSectionTitle);
					elem.appendChild(Element);
				}
				continue;
			}
			else
			{
				if ("RDEVLIST" == strSectionTitle)
				{
					strSectionTitle = "DEVLIST";
					QDomElement Element = doc.createElement( strSectionTitle );
					SaveXmlAddItem( doc, Element, strSectionTitle);
					elem.appendChild(Element);
				}
				continue;
			}
		}

		QDomElement Element = doc.createElement( strSectionTitle );
		SaveXmlAddItem( doc, Element, strSectionTitle);
		elem.appendChild(Element);		
	}
	
	return true;
}

bool CWriteNewXMLFile::SaveXmlAddItem( QDomDocument& doc, QDomElement& elem, QString strSectionTitle )
{
	unsigned int uItemIndex = 0;
	for (int i = 0; i < m_pTargetAddXmlList->size(); i++)
	{
		ItemPara = *m_pTargetAddXmlList->at(i);
		
		strIndex = ItemPara.strIndex;
		strId = ItemPara.strId;
		strValue = ItemPara.strValue;
		strDesc = ItemPara.strDes;
		
		QString strRackId = GetRackIdByDevId(uSCDNo);
		unsigned int uRackId = strRackId.toUInt();
		if ( uRackId%2 != 0)						//当前架子为奇数架子(左边的架子)
		{
			if ("LDEVLIST" == strIndex)
				strIndex = "DEVLIST";
		}
		else
		{
			if ("RDEVLIST" == strIndex)
				strIndex = "DEVLIST";
		}

		if (strIndex == strSectionTitle)
		{
			QDomElement Element = doc.createElement("ITEM");
			if ("DEVADDR" == strSectionTitle)
			{
				int nItemId = uSCDNo - 1;
				strId = QString::null;
				strId.append(QString("%1").arg(nItemId));

				Element.setAttribute("id", strId);
				Element.setAttribute("value", strValue);
				Element.setAttribute("desc", strDesc);
			}

			if ( strIndex.contains("DEVLIST") )
			{
				uItemIndex++;
				Element.setAttribute("id", strId);
				strValue = GetValueByDevId(uSCDNo, uItemIndex);
				Element.setAttribute("value", strValue);
				Element.setAttribute("desc", strDesc);
			}

			if ( "FROM_PCS_YX" == strIndex )
			{
				uItemIndex++;				
				Element.setAttribute("id", strId);
				QString strRackId = GetRackIdByDevId(uSCDNo);
				unsigned int uRackId = strRackId.toUInt();
				if ( uRackId%2 != 0)						//当前架子为奇数架子(左边的架子)
				{
					if ( uItemIndex <= 8)
						strValue = GetRackValueByPara_PCSYX(uRackId, uSCDNo, uItemIndex, LEFTRACK);
					else
						strValue = GetCommValueByPara_PCSYX(uRackId, strValue);
				}
				else
				{
					if ( uItemIndex <= 10)
						strValue = GetRackValueByPara_PCSYX(uRackId, uSCDNo, uItemIndex, RIGHTRACK);
					else
						strValue = GetCommValueByPara_PCSYX(uRackId, strValue);
				}

				Element.setAttribute("value", strValue);
				Element.setAttribute("desc", strDesc);
			}
			
			elem.appendChild(Element);
		}
	}	
	return true;
}

unsigned int CWriteNewXMLFile::GetFirstSCDNoByRack( unsigned int uRack )
{
	unsigned int uSCDNo = 0;

	uSCDNo = (uRack-1) * 10 + 1;
	
	return uSCDNo;
}

QString CWriteNewXMLFile::GetValueByDevId( unsigned int uDevId, unsigned int uItemIndex )
{
	QString strValue, strTmp;

	unsigned int uShiwei, uGewei, uRackId, uChargerId, uCabinet1Id, uCabinet2Id;
	
	uShiwei = uDevId/10;
	uGewei = uDevId - uShiwei*10;
	
	uRackId = uShiwei+1;
	
	uCabinet2Id = 0;
	if ( uRackId%2 != 0)						//当前架子为奇数架子(左边的架子)
	{
		uChargerId = GetChargerIdbyPara(uGewei, uRackId, uItemIndex, LEFTRACK);
		uCabinet1Id = GetCabinetIdbyPara(uGewei, uItemIndex, LEFTRACK);
		if ( 3 == uItemIndex || 4 == uItemIndex)
			uCabinet2Id = uCabinet1Id + 1;
	}
	else
	{
		uChargerId = GetChargerIdbyPara(uGewei, uRackId, uItemIndex, RIGHTRACK);
		uCabinet1Id = GetCabinetIdbyPara(uGewei, uItemIndex, RIGHTRACK);
		if ( 4 == uItemIndex || 5 == uItemIndex)
			uCabinet2Id = uCabinet1Id + 1;
	}
	
	strValue.append(QString("%1").arg(uChargerId));
	strValue += ",";
	
	strTmp.append(QString("%1").arg(uRackId));
	strValue += strTmp;
	strValue += ",";

	strTmp = QString::null;
	strTmp.append(QString("%1").arg(uCabinet1Id));
	strValue += strTmp;
	strValue += ",";

	strTmp = QString::null;
	strTmp.append(QString("%1").arg(uCabinet2Id));
	strValue += strTmp;
	
	return strValue;
}

unsigned int CWriteNewXMLFile::GetChargerIdbyPara( unsigned int uDevId, unsigned int uRackId, unsigned int uSecNo, unsigned int uRackType )
{
	unsigned int uChargerId = 0;

	if ( uRackType == LEFTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			uChargerId = (uDevId*2-1) + (uRackId/2)*140;
			break;
		case 2:
			uChargerId = (uDevId*2) + (uRackId/2)*140;
			break;
		case 3:
			uChargerId = (uDevId*20+uDevId) + (uRackId/2)*140;
			break;
		case 4:
			uChargerId = (uDevId*30+uDevId) + (uRackId/2)*140;
			break;
		case 5:
			uChargerId = (uDevId*40+uDevId*2-1) + (uRackId/2)*140;
			break;
		case 6:
			uChargerId = (uDevId*40+uDevId*2) + (uRackId/2)*140;
			break;		
		default:
			break;
		}
	}
	else if ( uRackType == RIGHTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			uChargerId = (uDevId*2-1) + (uRackId/2-1)*140 + 60;
			break;
		case 2:
			uChargerId = (uDevId*2) + (uRackId/2-1)*140 + 60;
			break;
		case 3:
			uChargerId = (uDevId*20+uDevId) + (uRackId/2-1) + 60;
			break;
		case 4:
			uChargerId = (uDevId*30+uDevId) + (uRackId/2-1) + 60;
			break;
		case 5:
			uChargerId = (uDevId*40+uDevId*2-1) + (uRackId/2-1) + 60;
			break;
		case 6:
			uChargerId = (uDevId*2-1) + (uRackId/2-1)*140 + 60 + 50;
			break;
		case 7:
			uChargerId = (uDevId*2) + (uRackId/2-1)*140 + 60 + 50;
			break;
		case 8:
			uChargerId = (uDevId*20+uDevId) + (uRackId/2-1) + 60 + 50;
			break;
		default:
			break;
		}
	}
	return uChargerId;
}

unsigned int CWriteNewXMLFile::GetCabinetIdbyPara( unsigned int uDevId, unsigned int uSecNo, unsigned int uRackType )
{
	unsigned int uCabinetId = 0;
	
	if ( uRackType == LEFTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			uCabinetId = (uDevId*2-1)+20;
			break;
		case 2:
			uCabinetId = (uDevId*2)+20;
			break;
		case 3:
			uCabinetId = (uDevId*2-1)+40;
			break;
		case 4:
			uCabinetId = (uDevId*2-1)+60;
			break;
		case 5:
			uCabinetId = (uDevId*2-1)+80;
			break;
		case 6:
			uCabinetId = (uDevId*2)+80;
			break;
		default:
			break;
		}
	}
	else if ( uRackType == RIGHTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			uCabinetId = (uDevId*2-1);
			break;
		case 2:
			uCabinetId = (uDevId*2);
			break;
		case 3:
			uCabinetId = (uDevId*2)+20;
			break;
		case 4:
			uCabinetId = (uDevId*2-1)+40;
			break;
		case 5:
			uCabinetId = (uDevId*2-1)+60;
			break;
		case 6:
			uCabinetId = (uDevId*2-1)+80;
			break;
		case 7:
			uCabinetId = (uDevId*2)+80;
			break;
		case 8:
			uCabinetId = (uDevId*2)+100;
			break;
		default:
			break;
		}
	}

	return uCabinetId;
}

QString CWriteNewXMLFile::GetRackIdByDevId( unsigned int uDevId )
{
	QString strValue;
	
	unsigned int uShiwei, uGewei, uRackId;

	uShiwei = uDevId/10;
	uGewei = uDevId - uShiwei*10;
	
	if ( 0 == uGewei)
		uRackId = uShiwei;
	else
		uRackId = uShiwei + 1;

	strValue.append(QString("%1").arg(uRackId));

	return strValue;
}

QString CWriteNewXMLFile::GetRackValueByPara_PCSYX( unsigned int uRackId, unsigned int uDevId, 
											    unsigned int uSecNo, unsigned int uRackType )
{
	unsigned int uShiwei, uGewei;
	
	uShiwei = uDevId/10;
	uGewei = uDevId - uShiwei*10;

	QString strValue, strTmp;
	unsigned int nCabinetId = 0;

	if ( uRackType == LEFTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			nCabinetId = 81 + (uGewei-1)*2;
			break;
		case 2:
			nCabinetId = 82 + (uGewei-1)*2;
			break;
		case 3:
			nCabinetId = 61 + (uGewei-1)*2;
			break;
		case 4:
			nCabinetId = 62 + (uGewei-1)*2;
			break;
		case 5:
			nCabinetId = 41 + (uGewei-1)*2;
			break;
		case 6:
			nCabinetId = 42 + (uGewei-1)*2;
			break;
		case 7:
			nCabinetId = 21 + (uGewei-1)*2;
			break;
		case 8:
			nCabinetId = 22 + (uGewei-1)*2;
			break;
		default:
			break;
		}
	}
	else if ( uRackType == RIGHTRACK)
	{
		switch (uSecNo)
		{
		case 1:
			nCabinetId = 102 + (uGewei-1)*2;
			break;
		case 2:
			nCabinetId = 81 + (uGewei-1)*2;
			break;
		case 3:
			nCabinetId = 82 + (uGewei-1)*2;
			break;
		case 4:
			nCabinetId = 61 + (uGewei-1)*2;
			break;
		case 5:
			nCabinetId = 62 + (uGewei-1)*2;
			break;
		case 6:
			nCabinetId = 41 + (uGewei-1)*2;
			break;
		case 7:
			nCabinetId = 42 + (uGewei-1)*2;
			break;
		case 8:
			nCabinetId = 22 + (uGewei-1)*2;
			break;
		case 9:
			nCabinetId = 1 + (uGewei-1)*2;
			break;
		case 10:
			nCabinetId = 2 + (uGewei-1)*2;
			break;
		default:
			break;
		}
	}

	strValue.append(QString("%1").arg(uRackId));
	strValue += ",";

	strTmp.append(QString("%1").arg(nCabinetId));
	strValue += strTmp;
	strValue += ",";

	strTmp = QString::null;
	strTmp.append(QString("%1").arg(PCSYX_THIRDTHPARA));
	strValue += strTmp;
	strValue += ",";

	strTmp = QString::null;
	if ( 0 == uSecNo%2 )
		strTmp.append(QString("%1").arg(PCSYX_FOURTHPARA2));
	else
		strTmp.append(QString("%1").arg(PCSYX_FOURTHPARA1));

	strValue += strTmp;

	return strValue;
}

QString CWriteNewXMLFile::GetCommValueByPara_PCSYX( unsigned int uRackId, QString strValue )
{
	qDebug(strValue);
	QString strTragetValue, strTmp;
	int nPos = strValue.find(",");
	strTragetValue.append(QString("%1").arg(uRackId));

	strTmp = strValue.right(strValue.length() - nPos);
	qDebug(strTmp);

	strTragetValue += strTmp;

	qDebug(strTragetValue);

	return strTragetValue;
}
