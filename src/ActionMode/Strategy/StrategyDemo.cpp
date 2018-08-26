/**
  策略模式封装了算法族，分别封装起来，使得他们之间可以相互替换
*/

#include <iostream>
#include "Strategy.h"

using namespace std;

void main()
{
    cout << "Strategy Pattern Demo : " << endl;
    Strategy * pStr = new ConcreteStrategyA();
    // 将pStr传递给上下文类pCon，实现类的组合
    Context * pCon = new Context(pStr);
    pCon->DoAction();

    pStr = new ConcreteStrategyB();
    pCon = new Context(pStr);
    pCon->DoAction();

    system("PAUSE");
    return;
}