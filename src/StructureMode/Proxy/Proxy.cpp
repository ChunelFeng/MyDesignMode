#include <iostream>
#include "Proxy.h"

using namespace std;

Subject::Subject()
{
    cout << "Subject constructor" << endl;
}

Subject::~Subject()
{
    cout << "Subject destructor" << endl;
}

RealSubject::RealSubject()
{
    cout << "RealSubject constructor" << endl;
}

RealSubject::~RealSubject()
{
    cout << "RealSubject destructor" << endl;
}

void RealSubject::Request()
{
    cout << "RealSubject Request Function" << endl;
}

Proxy::Proxy()
    :m_RealSubject(NULL)
{
    cout << "Proxy constructor" << endl;
}

Proxy::~Proxy()
{
    if (m_RealSubject)
    {
        delete m_RealSubject;
        m_RealSubject = NULL;
    }

    cout << "Proxy destructor" << endl;
}

void Proxy::Request()
{
    // 在调用Proxy的时候，实际上调用的是RealSubject中的内容
    if (!m_RealSubject)
    {
        m_RealSubject = new RealSubject();
    }

    cout << "Proxy Request" << endl;
    m_RealSubject->Request();
}
