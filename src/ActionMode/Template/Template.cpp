#include <iostream>
#include "Template.h"

using namespace std;

void Company::Recruit()
{
    /* 定义了招聘流程，主要有以下几步：
       1，接受简历
       2，面试
       3，发Offer
       接受简历的过程是相同的，故不为虚函数，并且在基类中自行实现
       其他两个过程是不同的，设定为虚函数 */
    ReceiveResume();

    Interview();
    SendOffer();
}

void Company::ReceiveResume()
{
    cout << "Company::ReceiveResume()" << endl;
    return;
}

void Hikvision::Interview()
{
    cout << "Hikvision Interview" << endl;
    return;
}

void Hikvision::SendOffer()
{
    cout << "Hikvision SendOffer" << endl;
    return;
}

void IFlyTek::Interview()
{
    cout << "IFlyTek Interview" << endl;
    return;
}

void IFlyTek::SendOffer()
{
    cout << "IFlyTek SendOffer" << endl;
    return;
}
