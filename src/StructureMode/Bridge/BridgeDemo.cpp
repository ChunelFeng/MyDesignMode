/*
桥接模式用于把抽象化与实现化解耦，使得二者可以独立变化

主要解决：
有多种可能会变化的情况下，用继承会造成类爆炸的问题，扩展不灵活

例子：
本例中，不同的手机类型，可以配饰不同的操作系统类型
通过桥接模式，完成OS和Phone的匹配，不需要依次创建新的类
最后使用的时候，还是使用Phone类中的函数
但是实际上，是调用了OS中的内容
*/

#include "Bridge_OS.h"
#include "Bridge_Phone.h"

void main()
{
    cout << "Bridge Pattern Demo : " << endl;

    /* 通过桥接模式，使得不同的OS类和不同的Phone类可以无缝连接 */
    OS* pIOS1 = new IOSSubSystem1();    //创建一个操作系统
    Phone* iPhone4 = new iPhone(pIOS1);    //应用到该手机上
    iPhone4->SetOS();    // Phone类的SetOS()，调用OS类中GetOS()，从而获取信息

    OS* pIOS2 = new IOSSubSystem2();    //创建一个操作系统
    Phone* iPhone6 = new iPhone(pIOS2);    //应用到该手机上
    iPhone6->SetOS();

    OS* pSaiBian1 = new SaiBianSubSystem1();    //创建一个操作系统
    Phone* Nokia1 = new Nokia(pSaiBian1);    //应用到该手机上
    Nokia1->SetOS();

    OS* pSaiBian2 = new SaiBianSubSystem2();    //创建一个操作系统
    Phone* Nokia2 = new Nokia(pSaiBian2);    //应用到该手机上
    Nokia2->SetOS();

    /* 删除内存信息 */
    DELETE_OBJECT(iPhone4);
    DELETE_OBJECT(iPhone6);
    DELETE_OBJECT(Nokia1);
    DELETE_OBJECT(Nokia2);

    system("PAUSE");
    return;
}