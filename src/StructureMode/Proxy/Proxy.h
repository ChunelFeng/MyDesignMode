/**
* 文件名称：Proxy.h
* 摘    要：委托模式头文件
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-08-19
* 备    注：新建
*/

#ifndef _PROXY_PATTERN_H_
#define _PROXY_PATTERN_H_

class Subject
{
public:
    Subject();
    virtual ~Subject();
    virtual void Request() = 0;
};

class RealSubject : public Subject
{
public:
    RealSubject();
    virtual ~RealSubject();
    virtual void Request();
};

class Proxy : public Subject
{
    // Proxy和RealSubject都继承自Subject接口
public:
    Proxy();
    virtual ~Proxy();
    virtual void Request();

private:
    RealSubject * m_RealSubject;    // 代理类的具体实现
};

#endif