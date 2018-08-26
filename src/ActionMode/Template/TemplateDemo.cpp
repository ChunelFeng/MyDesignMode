/**
模板模式

主要解决：
一些流程通用，但是流程的具体实现不同

使用场景：
1，有多个子类共用的方法，且逻辑相同
2，重要的、复杂的方法，可以考虑作为模板方法

区别：
工厂模式更关心对象的创建过程
而模板模式关系的是被创建的对象有通用的流程
*/

#include <iostream>
#include "Template.h"

using namespace std;

void main()
{
    cout << "Template Pattern Demo : " << endl;

    /* 创建一个IFlyTek类的对象（注意，是使用Company类型的指针）
       然后实现其Recruit的流程 */
    Company * iflytek = new IFlyTek();
    iflytek->Recruit();

    /* 所有的Company子类均有Recruit()流程 */
    Company * hikvision = new Hikvision();
    hikvision->Recruit();

    delete iflytek;
    delete hikvision;

    system("PAUSE");
    return;
}