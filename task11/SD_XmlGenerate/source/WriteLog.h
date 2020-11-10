#ifndef USERLOG4CXX_H
#define USERLOG4CXX_H

#define LOG_LENGTH_MAX         1024             // 一条日志的最大长度,可不用修改

//考虑到unix下共享库的原因，这个必须修改，不同的模块要改成不成的名称，如104模块改成CWriteLog_M104,61850模块改成CWriteLog_M61850
#define  CWRITELOG              CWriteLog_SCDXmlFile

#include "../../include/CustomLog4cxx.h"

#endif