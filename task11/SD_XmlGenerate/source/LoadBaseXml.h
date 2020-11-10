// LoadBaseXml.h: interface for the CLoadBaseXml class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOADBASEXML_H__E4CF75AA_F502_4814_8F2D_6BD96C0FB739__INCLUDED_)
#define AFX_LOADBASEXML_H__E4CF75AA_F502_4814_8F2D_6BD96C0FB739__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <qfile.h>
#include <qxml.h>
#include <qdom.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qtextcodec.h>
#include <map>

#include "StructDefine.h"

using namespace std;

class CLoadBaseXml  
{
public:
	CLoadBaseXml();
	virtual ~CLoadBaseXml();

public:
	static CLoadBaseXml* Instance();
	bool LoadBaseXMLFile(	char * szConfig, QValueList<XMLPARA> * pBaseParaList, QValueList<QString> * pBaseTitleList,
							QValueList<XMLPARA> * pAddParaList, QValueList<QString> * pAddTitleList);

private:
	static CLoadBaseXml* m_spInstance;

private:
	bool ParseXMLBody( const QDomElement &Element );

	bool ParseBaseData( QDomNode node );
	bool ParseAddData( QDomNode node );

	void ComposeBaseValueList( QString strIndex, QString strId, QString strValue, QString strDesc );
	void ComposeAddValueList( QString strIndex, QString strId, QString strValue, QString strDesc );

	QValueList<QString> * m_pBaseDataTitleList;
	QValueList<XMLPARA> * m_pBaseDataList;

	QValueList<QString> * m_pAddDataTitleList;
	QValueList<XMLPARA> * m_pAddDataItemList;
	XMLPARA structXmlpara;
};

#endif // !defined(AFX_LOADBASEXML_H__E4CF75AA_F502_4814_8F2D_6BD96C0FB739__INCLUDED_)
