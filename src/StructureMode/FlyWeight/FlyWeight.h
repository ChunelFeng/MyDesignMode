/**
* 文件名称：FlyWeight.h
* 摘    要：享元模式头文件
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-08-24
* 备    注：新建
*/

#ifndef _FLYWEIGHT_PATTERN_H_
#define _FLYWEIGHT_PATTERN_H_

#include <iostream>
#include <vector>

using namespace std;

typedef enum
{
    /* 具体享元功能类的类型 */
    FIRST_TYPE = 1,
    SECOND_TYPE = 2
}FlyWeightType;

class FlyWeight
{
    /* 享元的抽象基类，无实际功能 */
public:
    FlyWeight()
    {
        cout << "FlyWeight::FlyWeight()" << endl;
    }
    virtual ~FlyWeight()
    {
        cout << "FlyWeight::~FlyWeight()" << endl;
    }

    virtual void operation(FlyWeightType type) = 0;
};

class ConcreteFlyWeight : public FlyWeight
{
    /* 具体实现FlyWeight功能的类-1 */
public:
    ConcreteFlyWeight();
    ~ConcreteFlyWeight();

    /* 具体享元类的功能函数 */
    void operation(FlyWeightType type);
};

class FlyWeightFactory
{
public:
    /* num 一共创建多少个对象
       type 创建何种类型的对象 */
    FlyWeightFactory(int total_num);
    ~FlyWeightFactory();

    FlyWeight * GetFlyWeight(int key_num);

private:
    vector<FlyWeight *> m_flyweights;    // 供查找的地方
    int m_num;    // 享元个数
};

#endif