#ifndef _BRIDGE_PHOTO_PATTERN_H_
#define _BRIDGE_PHOTO_PATTERN_H_

#include "Bridge_Phone.h"

#ifndef DELETE_OBJECT
/* 删除内存的宏函数 */
    #define DELETE_OBJECT(p) { if(NULL != (p)) {delete (p); (p) = NULL;}}
#endif

//抽象的手机类
class Phone
{
public:
    virtual void SetOS() = 0;
};

//苹果手机类，依赖抽象的操作系统
class iPhone : public Phone
{
    /* Phone类中包含操作系统的成员变量
       是将Phone类和OS类组合起来 */
public:
    iPhone(OS * os)
    {
        m_pOS = os;
    }
    ~iPhone()
    {
        DELETE_OBJECT(m_pOS);
    }
    virtual void SetOS()
    {
        cout << "Set The OS: " << m_pOS->GetOS().c_str() << endl;
    }

private:
    OS * m_pOS;
};

//诺基亚手机类，以来抽象的操作系统
class Nokia : public Phone
{
public:
    Nokia(OS* os)
    {
        m_pOS = os;
    }
    ~Nokia()
    {
        DELETE_OBJECT(m_pOS);
    }

    virtual void SetOS()
    {
        cout << "Set The OS: " << m_pOS->GetOS().c_str() << endl;
    }

private:
    OS * m_pOS;
};

#endif