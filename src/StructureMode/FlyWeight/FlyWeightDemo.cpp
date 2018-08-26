/*
享元模式

主要解决：
有大量对象时，可能会造成内存溢出
把其中的共同部分抽象出来，如果有相同的业务请求
则直接返回内存中已有的对象，避免重新创建

设计思路：
用唯一标识码（key_num）判断，返回标识码所对应的具体对象
*/

#include <iostream>
#include "FlyWeight.h"

using namespace std;

#define TOTAL_NUM (2)            // 总共创建多少个对象
#define KEY_NUM (1)              // 使用第几个对象

void main()
{
    cout << "FlyWeight Pattern Demo : " << endl;

    /* 在Factory中，创建TOTAL_NUM个具体享元类 */
    FlyWeightFactory * factory = new FlyWeightFactory(TOTAL_NUM);
    /* 获取其中的第key_num个元素，然后调用其功能函数 */
    FlyWeight * flyweight = factory->GetFlyWeight(KEY_NUM);
    flyweight->operation(SECOND_TYPE);

    /* 删除之前所创建的所有的具体享元类 */
    delete factory;

    system("PAUSE");
    return;
}