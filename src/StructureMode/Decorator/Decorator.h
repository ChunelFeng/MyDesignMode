/**
* 文件名称：Decorator.h
* 摘    要：装饰器模式头文件
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-08-10
* 备    注：新建
*/

#ifndef _DECORATOR_PATTERN_H_
#define _DECORATOR_PATTERN_H_

#include <iostream>
#include <string>

using namespace std;

/* 定义不同咖啡和配料的价格 */
const unsigned int ESPRESSO_PRICE = 25;
const unsigned int DRAKROAST_PRICE = 20;
const unsigned int MOCHA_PRICE = 10;
const unsigned int WHIP_PRICE = 8;

class Beverage
{
    //饮料
protected:
    string description;

public:
    virtual string getDescription()
    {
        return description;
    }

    virtual int cost() = 0;
};

class CondimentDecorator : public Beverage
{
    // 配料
protected:
    // 这个指针，用于回溯之前已经存在的内容
    Beverage * beverage;
};

class Espresso : public Beverage
{
    // 蒸馏咖啡
public:
    Espresso()
    {
        description = "Espresso"; 
    }

    int cost()
    {
        return ESPRESSO_PRICE;
    }
};

class DarkRoast : public Beverage
{
    // 深度烘焙咖啡
public:
    DarkRoast()
    {
        description = "DardRoast"; 
    }

    int cost()
    {
        cout << "DarkRoast cost." << endl;
        return DRAKROAST_PRICE; 
    }
};

class Mocha : public CondimentDecorator
{
    // 摩卡（配料）
public:
    Mocha(Beverage * beverage)
    {
        this->beverage = beverage; 
    }

    string getDescription()
    {
        /* 摩卡类可以被beverage装饰一次或者多次
           每次装饰之后，description和cost都会有相应的变化 */
        return beverage->getDescription() + ",Mocha"; 
    }

    int cost()
    {
        cout << "Mocha cost." << endl;
        return MOCHA_PRICE + beverage->cost(); 
    }
};

class Whip : public CondimentDecorator
{
    // 奶泡（配料）
public:
    Whip(Beverage * beverage)
    {
        this->beverage = beverage; 
    }

    string getDescription()
    {
        return beverage->getDescription() + ",Whip"; 
    }

    int cost()
    {
        cout << "Whip cost." << endl;
        return WHIP_PRICE + beverage->cost(); 
    }
};

#endif