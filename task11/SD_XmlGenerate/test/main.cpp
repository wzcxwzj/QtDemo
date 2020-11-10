// EvcEvent.cpp : Defines the entry point for the console application.
//

#pragma warning(disable: 4231 4018 4521)
#include "WriteLog.h"
#include "XMLFileLoad.h"
#include <qapplication.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	char *szConfig = "./xml/";

	LOG4CXX_INIT("Log.EVCDataTr",szConfig);  
	
	if (g_XMLFile.Init(szConfig) == false)
    {
		LOGXJ_WARN(("EvcDataTrans ��ʼ��ʧ��"));
		return 0;
    }

	return app.exec();
}
