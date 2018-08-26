/**
* 文件名称：Adapter.h
* 摘    要：适配器模式头文件
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-08-23
* 备    注：新建
*/

#ifndef _ADAPTER_PATTERN_H_
#define _ADAPTER_PATTERN_H_

#include <iostream>
#include <string>

using namespace std;

class CCnOutlet
{
public:
    CCnOutlet()
    {
        cout << "CCnOutlet::CCnOutlet" << endl;
    }

    virtual ~CCnOutlet()
    {
        cout << "CCnOutlet::~CCnOutlet" << endl;
    }

    virtual void CnPlug(string cn)
    {
        cout << "中式插座！" << endl;
        cout << "cn plug : " << cn << endl;
    }
};

class CEnOutlet
{
public:
    CEnOutlet()
    {
        cout << "CEnOutlet::CEnOutlet" << endl;
    }

    ~CEnOutlet()
    {
        cout << "CEnOutlet::~CEnOutlet" << endl;
    }

    void EnPlug(string en, int year)
    {
        // 注意，EnPlug的接口和CnPlug的接口类型，是不同的
        cout << "use en plug" << endl;
        cout << "en info : " << en << ", year : " << year << endl;
        return;
    }
};

class CCnOutletAdapter : public CCnOutlet
{
    /* 使用Adapter类，将Cn插头的函数接口，转成En的实现
       类中包含了一个En插口类 */
public:
    CCnOutletAdapter(CEnOutlet * pEnOutlet, int year)
    {
        cout << "CCnOutletAdapter::CCnOutletAdapter" << endl;
        m_pEnOutlet = pEnOutlet;
        m_year = year;    // 这一点，解决了Cn和En接口不同的问题
    }

    virtual ~CCnOutletAdapter()
    {
        cout << "CCnOutletAdapter::~CCnOutletAdapter" << endl;
    }

    virtual void CnPlug(string cn)
    {
        cout << "adapter transfer" << endl;
        m_pEnOutlet->EnPlug(cn, m_year);
    }

private:
    CEnOutlet * m_pEnOutlet;
    int m_year;
};

#endif