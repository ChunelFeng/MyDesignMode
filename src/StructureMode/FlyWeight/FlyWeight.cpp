#include "FlyWeight.h"

using namespace std;

ConcreteFlyWeight::ConcreteFlyWeight()
{
    /* 实现的具体享元类 */
    cout << "ConcreteFlyWeight::ConcreteFlyWeight()" << endl;
    return;
}

ConcreteFlyWeight::~ConcreteFlyWeight()
{
    cout << "ConcreteFlyWeight::~ConcreteFlyWeight()" << endl;
    return;
}

void ConcreteFlyWeight::operation(FlyWeightType type)
{
    /* 具体享元类的功能函数，根据type来区分具体功能 */
    switch (type)
    {
    case FIRST_TYPE: { cout << "ConcreteFlyWeight First Type." << endl; break; }
    case SECOND_TYPE: { cout << "ConcreteFlyWeight Second Type." << endl; break; }
    default: break;
    }

    return;
}

FlyWeightFactory::FlyWeightFactory(int total_num)
{
    cout << "FlyWeightFactory::FlyWeightFactory()" << endl;
    for (int i = 0; i < total_num; i++)
    {
        /* 创建num个享元对象，实际上创建的是FirstFlyWeight功能类 */
        FlyWeight * temp = new ConcreteFlyWeight();
        m_flyweights.push_back(temp);
    }
    m_num = total_num;
    return;
}

FlyWeightFactory::~FlyWeightFactory()
{
    cout << "FlyWeightFactory::~FlyWeightFactory()" << endl;
    for (int i = 0; i < m_num; i++)
    {
        FlyWeight * temp = m_flyweights.at(i);
        delete temp;
        temp = NULL;
    }

    return;
}

FlyWeight * FlyWeightFactory::GetFlyWeight(int key_num)
{
    // 返回对应的第key个元素
    // 其实，这其中可以做一些类似与hash匹配之类的获取方式，这里用vector做一个最简单的示范
    return m_flyweights.at(key_num);
}