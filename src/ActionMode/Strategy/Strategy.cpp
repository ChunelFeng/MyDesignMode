#include "Strategy.h"
#include "iostream"

using namespace std;

/* Strategy 类实现 */
Strategy::Strategy()
{
    cout << "Strategy::Strategy" << endl;
}

Strategy::~Strategy()
{
    cout << "Strategy::~Strategy" << endl;
}


/* ConcreteStrategyA 类实现 */
ConcreteStrategyA::ConcreteStrategyA()
{
    cout << "ConcreteStrategyA::ConcreteStrategyA" << endl;
}

ConcreteStrategyA::~ConcreteStrategyA()
{
    cout << "ConcreteStrategyA::~ConcreteStrategyA" << endl;
}

void ConcreteStrategyA::AlgrithmInterface()
{
    cout << "ConcreteStrategyA::AlgrithmInterface" << endl;
}


/* ConcreteStrategyB 类实现 */
ConcreteStrategyB::ConcreteStrategyB()
{
    cout << "ConcreteStrategyB::ConcreteStrategyB" << endl;
}

ConcreteStrategyB::~ConcreteStrategyB()
{
    cout << "ConcreteStrategyB::~ConcreteStrategyB" << endl;
}

void ConcreteStrategyB::AlgrithmInterface()
{
    cout << "ConcreteStrategyB::AlgrithmInterface" << endl;
}


/* Context 类实现 */
Context::Context(Strategy * strategy)
{
    this->m_strategy = strategy;
    return;
}

Context::~Context()
{
    if (this->m_strategy)
    {
        delete this->m_strategy;
        this->m_strategy = NULL;
    }

    return;
}

void Context::DoAction()
{
    // 根据m_strategy类型，确定具体的执行函数
    this->m_strategy->AlgrithmInterface();
    return;
}