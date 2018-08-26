/**
责任链模式

意图：
避免请求发送者与接收者耦合在一起，让多个对象都有可能接收请求，将这些对象连接成一条链，并且沿着这条链传递请求，直到有对象处理它为止。

主要解决：
客户只要将请求，发到责任链的最外层即可，不需要关心具体的过程

适用场景：
1，写log的时候，区分debug和error等级别

缺点：
很大程度上，可以通过switch代替
*/

#include "ResponsibilityChain.h"

void main()
{
    cout << "ResponsibilityChain Pattern Demo : " << endl;

    /* 默认，一级管理级别最高，故不设定上级 */
    Manager * first = new FirstManager(nullptr, "First");

    /* 创建二级管理类，并将其上级设置为first */
    Manager * second = new SecondManager(first, "Second");
    Manager * third = new ThirdManager(second, "Third");

    /* 开始处理加薪请求，每个级别的经理，有不同权限的加薪阈值
       如果这个级别的经理，无法处理salary数字，则将该请求发送到更高级别的经理处 */
    third->DealWithRequest("add_500", 500);
    third->DealWithRequest("add_1500", 1500);
    third->DealWithRequest("add_3500", 3500);
    third->DealWithRequest("add_5500", 5500);

    delete third;
    delete second;
    delete first;

    system("PAUSE");
    return;
}