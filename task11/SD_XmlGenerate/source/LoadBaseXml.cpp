// LoadBaseXml.cpp: implementation of the CLoadBaseXml class.
//
//////////////////////////////////////////////////////////////////////

#include "LoadBaseXml.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLoadBaseXml * CLoadBaseXml::m_spInstance = 0;

CLoadBaseXml::CLoadBaseXml()
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
}

CLoadBaseXml::~CLoadBaseXml()
{

}

CLoadBaseXml* CLoadBaseXml::Instance()
{
	if ( 0 == m_spInstance )
	{
		m_spInstance = new CLoadBaseXml;
	}

	return m_spInstance;
}

bool CLoadBaseXml::LoadBaseXMLFile( char * szConfig, QValueList<XMLPARA> * pBaseParaList, QValueList<QString> * pBaseTitleList, QValueList<XMLPARA> * pAddParaList, QValueList<QString> * pAddTitleList )
{
	QString strfileName = szConfig;
	strfileName += "commpara_base.xml";
	
	QFile OpmlFile( strfileName );
	
	QDomDocument DomTree;
	
	if (!OpmlFile.open( IO_ReadOnly ))
    {
        QMessageBox::critical( 0,
			QObject::tr( "Critical Error" ),
			QObject::tr( "Cannot open file %1" ).arg( strfileName ) );
		
		return false;
    }
	
	if ( !DomTree.setContent( &OpmlFile ) ) 
	{
		QMessageBox::critical( 0,
			QObject::tr( "Critical Error" ),
			QObject::tr( "file %1 parsing error" ).arg( strfileName ) );
		
		OpmlFile.close();
		return false;
    }
	
	OpmlFile.close();
	
	QDomElement Root = DomTree.documentElement();
	
	m_pBaseDataTitleList = pBaseTitleList;
	m_pBaseDataList = pBaseParaList;
	
	m_pAddDataTitleList = pAddTitleList;
	m_pAddDataItemList = pAddParaList;
		
	return ParseXMLBody( Root );
}

bool CLoadBaseXml::ParseXMLBody( const QDomElement &Element )
{
	bool bRet = false;

	QDomNode node = Element.firstChild();
	QDomNode nodeItem;

	while ( !node.isNull() )
	{
		qDebug(node.nodeName());
		if ( ( node.isElement() && node.nodeName() == "body" ))
		{
			nodeItem = node.firstChild();
			ParseBaseData( nodeItem );
			qDebug(nodeItem.nodeName());
		}
		else if ( ( node.isElement() && node.nodeName() == "addbody" ))
		{
			nodeItem = node.firstChild();
			ParseAddData( nodeItem );
			qDebug(nodeItem.nodeName());
		}

		node = node.nextSibling();
	}

	return true;
}

bool CLoadBaseXml::ParseBaseData( QDomNode node )
{
	QDomNode nodeItem;
	QDomElement body;
	QString strId, strValue, strDes;

	while ( !node.isNull() )							//搜索当前路径下所有的数据
	{
		if ( node.isElement() )
		{
			nodeItem = node.firstChild();
			while (!nodeItem.isNull())
			{
				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
				{
					body = nodeItem.toElement();
					strId = body.attribute("id");
					strValue = body.attribute("value");
					strDes = body.attribute("desc");

					ComposeBaseValueList(node.nodeName(), strId, strValue, strDes );
				}
				nodeItem = nodeItem.nextSibling();
			}
		}

		node = node.nextSibling();
	}

// 	while ( !node.isNull() )							//搜索当前路径下所有的数据
// 	{
// 		if ( node.isElement() && node.nodeName() == "ModBusCommPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 
// 					ComposeBaseValueList("ModBusCommPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "RS485CommPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 
// 					ComposeBaseValueList("RS485CommPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "CanCommPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("CanCommPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "SCADAPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");				
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");				
// 										
// 					ComposeBaseValueList("SCADAPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "YXPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("YXPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "YCPara")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("YCPara", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "FROM_UT_CMD")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("FROM_UT_CMD", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "FROM_UT_DATA")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("FROM_UT_DATA", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "TO_UT_CMD")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("TO_UT_CMD", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "TO_UT_DATA")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("TO_UT_DATA", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "FROM_EMS_CMD")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("FROM_EMS_CMD", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "FROM_EMS_DATA")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("FROM_EMS_DATA", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "TO_EMS_CMD")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("TO_EMS_CMD", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		else if ( node.isElement() && node.nodeName() == "TO_EMS_DATA")
// 		{
// 			nodeItem = node.firstChild();
// 			while (!nodeItem.isNull())
// 			{
// 				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
// 				{
// 					body = nodeItem.toElement();
// 					strId = body.attribute("id");
// 					strValue = body.attribute("value");
// 					strDes = body.attribute("desc");
// 					
// 					ComposeBaseValueList("TO_EMS_DATA", strId, strValue, strDes );
// 				}
// 				nodeItem = nodeItem.nextSibling();
// 			}
// 		}
// 
// 		node = node.nextSibling();
// 	}

	return true;
}

void CLoadBaseXml::ComposeBaseValueList( QString strIndex, QString strId, QString strValue, QString strDesc )
{
	if (!m_pBaseDataTitleList->contains(strIndex))
		m_pBaseDataTitleList->push_back(strIndex);

	structXmlpara.strIndex = strIndex;
	structXmlpara.strId = strId;
	structXmlpara.strValue = strValue;
	structXmlpara.strDes = strDesc;
	m_pBaseDataList->push_back(structXmlpara);
}

bool CLoadBaseXml::ParseAddData( QDomNode node )
{
	QDomNode nodeItem;
	QDomElement body;
	QString strId, strValue, strDes;
	
	while ( !node.isNull() )							//搜索当前路径下所有的数据
	{
		if ( node.isElement() )
		{
			nodeItem = node.firstChild();
			while (!nodeItem.isNull())
			{
				if ( nodeItem.isElement() && nodeItem.nodeName() == "ITEM")
				{
					body = nodeItem.toElement();
					strId = body.attribute("id");
					strValue = body.attribute("value");
					strDes = body.attribute("desc");
					
					ComposeAddValueList(node.nodeName(), strId, strValue, strDes );
				}
				nodeItem = nodeItem.nextSibling();
			}
		}
		
		node = node.nextSibling();
	}

	return true;
}

void CLoadBaseXml::ComposeAddValueList( QString strIndex, QString strId, QString strValue, QString strDesc )
{
	if (!m_pAddDataTitleList->contains(strIndex))
		m_pAddDataTitleList->push_back(strIndex);
	
	structXmlpara.strIndex = strIndex;
	structXmlpara.strId = strId;
	structXmlpara.strValue = strValue;
	structXmlpara.strDes = strDesc;
	m_pAddDataItemList->push_back(structXmlpara);
}
