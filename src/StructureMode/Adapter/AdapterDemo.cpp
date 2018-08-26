/*
适配器模式主要解决：
将现有项放到新环境中，而新环境接口无法满足现有项的情况
依赖已有的对象，实现想要的目标接口
*/

#include <iostream>
#include "Adapter.h"

using namespace std;

void main()
{
    cout << "Adapter Pattern Demo : " << endl;

    /* En表示新接口，Cn表示老接口
       新接口En中，需要传入string和int
       老接口Cn中，仅传入string */
    CEnOutlet * pEnOutlet = new CEnOutlet;

    /* 将一个中式插头的CnPlug函数，输出成英式插头的样式 */
    int year = 2018;
    CCnOutlet * pCnOutlet = new CCnOutletAdapter(pEnOutlet, year);

    /* CnPlug接口只能传递string，而EnPlug接口可以传递string和int
       在Adapter类的构造函数中，添加int信息，以便在调用CnPlug的情况下，也能带入int信息
       这一点体现了老接口（Cn）和新接口（En）无法兼容的情况下，需要的处理方式 */
    pCnOutlet->CnPlug("hello,world");

    delete pEnOutlet;
    delete pCnOutlet;
    system("PAUSE");
    return;
}