/**
观察者模式

意图：
定义对象的一种一对多的以来关系，
当一个对象的状态发生改变时，
所有被注册到其中的对象都会被通知到，并自动更新

主要解决：
一个对象状态改变，其他有关对象均进行更新，保证高度的协作
*/

#include <iostream>
#include <string>
#include "Observer.h"

using namespace std;

void main()
{
    cout << "Observer Pattern Demo : " << endl;

    /* 创建三个RoomMate对象，等待被通知信息 */
    RoomMate * MateA = new RoomMate("A", "A current action", "A next action");
    RoomMate * MateB = new RoomMate("B", "B current action", "B next action");
    RoomMate * MateC = new RoomMate("C", "C current action", "C next action");

    /* 创建QQGroup对象，将三个RoomMate注册进去 */
    QQGroup * group = new QQGroup();
    group->registerObserver(MateA);
    group->registerObserver(MateB);
    group->registerObserver(MateC);

    /* 在QQ群里发“current”消息
       目标对象（group）状态发生改变
       所有的Observer均有针对性的相应 */
    string message = "current";
    group->notifyObserver(message);

    /* 在QQ群里删除MateB，并群发“next”消息 */
    group->removeObserver(MateB);
    message = "next";
    group->notifyObserver(message);

    delete MateA;
    delete MateB;
    delete MateC;
    delete group;

    system("PAUSE");
    return;
}