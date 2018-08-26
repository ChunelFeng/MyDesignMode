/*
工厂方法模式跟简单工厂模式的区别，主要在于：
工厂模式方法，通过区分工厂来创建对象
而简单工厂模式在同一个工厂中创建不同对象

主要适用于：
明确了不同条件下，创建不同实例的情况
*/

#include <iostream>
#include "Factory.h"

using namespace std;

void main()
{
    cout << "Factory Pattern Demo : " << endl;

    /* 创建工厂A对象，直接生产出产品A
       优点是：一个工厂对应一个产品
       缺点是：如果增加产品，就需要增加工厂 */
    Factory * factory = new FactoryA();
    factory->CreateSingleCore()->Show();
    delete factory;

    system("PAUSE");
    return;
}