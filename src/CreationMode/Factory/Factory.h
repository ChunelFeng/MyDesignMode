/**
* 文件名称：Factory.h
* 摘    要：工厂模式头文件（工厂方法模式）
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-08-21
* 备    注：新建
*/

#ifndef _FACTORY_PATTERN_H_
#define _FACTORY_PATTERN_H_

#include <iostream>

using namespace std;

class SingleCore
{
public:
    virtual void Show() = 0;
};

//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout << "SingleCore A" << endl; }
};

//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show() { cout<<"SingleCore B"<<endl; }
};

class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};

//生产A核的工厂
class FactoryA: public Factory
{
public:
    SingleCoreA * CreateSingleCore() { return new SingleCoreA; }
};  

//生产B核的工厂
class FactoryB: public Factory
{
public:
    SingleCoreB* CreateSingleCore() { return new SingleCoreB; }
};

#endif
