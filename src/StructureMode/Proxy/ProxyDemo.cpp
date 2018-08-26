/*
通过代理类，去访问真实类中的函数
Subject：基类，申明了代理类和真实对象的共同点
RealSubject：真正需要被调用的类
Proxy：代理对象

Tips:
1，装饰器模式是为对象添加一个或者多个功能，而代理则是控制对对象的访问

代理模式主要适用于：
1，在某些情况下，一个对象不适合或者不能直接引用另一个对象，而代理对象可以在客户端和目标对象之间起到中介的作用

*/

#include <iostream>
#include "Proxy.h"

using namespace std;

void main()
{
    cout << "Proxy Pattern Demo : " << endl;
    Subject * proxy = new Proxy();

    // 这里实际上调用的是RealSubject类的Request函数
    // 在proxy的函数中，有new RealSubject的代码
    proxy->Request();

    delete proxy;
    proxy = NULL;

    system("PAUSE");
    return;
}