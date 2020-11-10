/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2010-2011   */
/*****************************************************************************/
/* 本源代码及其相关文档为河南许昌许继电气股份有限公司独家所有，未经明文许    */
/* 可不得擅自修改或发布，否则将追究相关的法律责任。                          */
/*                                                                           */
/*                      河南许昌许继股份有限公司                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/

#pragma warning(disable: 4018 4091 4083 4231)

#ifndef SCDXMLGEN_H
#define SCDXMLGEN_H

#ifdef WIN32
#ifdef SCDXMLGEN_EXPORTS
class _declspec(dllexport) SCDXmlFileGenCallBackInterface;  
class _declspec(dllexport) SCDXmlFileGenInterFace;    

extern "C" 
{
	_declspec(dllexport) SCDXmlFileGenInterFace* GetSCDXmlFileObject();
}

#else
class _declspec(dllimport) SCDXmlFileGenCallBackInterface;  
class _declspec(dllimport) SCDXmlFileGenInterFace;    

extern "C" 
{
	_declspec(dllimport) SCDXmlFileGenInterFace* GetSCDXmlFileObject();
}

#endif
#else

class SCDXmlFileGenCallBackInterface;
class SCDXmlFileGenInterFace;    

extern "C" 
{
	SCDXmlFileGenInterFace* GetSCDXmlFileObject();
}

#endif

class SCDXmlFileGenCallBackInterface
{
public:
	
	virtual bool MsgReturn(unsigned int nSrc, float fCost, int nCause) = 0;
};

class SCDXmlFileGenInterFace
{
public:
	
	virtual bool Init(char * szConfig) = 0; 

	
	virtual bool GenerateXMLBySCDNum( unsigned int * pXMLNum, unsigned int uSCDNum = 120) = 0;

	
	virtual bool GenerateXMLByRackNo( unsigned int uRackNo, unsigned int * pXMLNum ) = 0;

	
	virtual bool GenerateXMLBySCDNo( unsigned int uSCDNo ) = 0;

	
	virtual void Advise(SCDXmlFileGenCallBackInterface* pCallBackInterface)   = 0;
};

#endif