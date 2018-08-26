/*
* 文件名称：Singleton.h
* 摘    要：单例模式头文件
*
* 当前版本：1.0.0
* 作    者：Chunel
* 日    期：2018-08-18
* 备    注：新建
*/

#ifndef _SINGLETON_PATTERN_H_
#define _SINGLETON_PATTERN_H_

using namespace std;

class Singleton
{
public:
    static Singleton * getInstance();

private:
    Singleton();
    ~Singleton();

    // 本类对外仅通过这种方式提供
    static Singleton * ms_instance;
};

#endif