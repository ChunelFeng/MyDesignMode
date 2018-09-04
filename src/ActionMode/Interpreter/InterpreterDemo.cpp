/*
解释器模式

这个例子找的不太好，也没找到像样的例子，
本模式主要是为了解决一些特定信息的解析，如"3+5-2+6"的信息，然后进行计算

应用场景：
软件开A/B/C/D等多个功能中的任意几个，可以写 "A | B | D"，然后解析该字符串
*/

#include "Interpreter.h"

void main()
{
    cout << "Interpreter Pattern Demo : " << endl;

    Context* c = new Context();
    AbstractExpression* abs = new TerminalExpression("Hello");
    AbstractExpression* nabs = new NonterminalExpression(abs, 2);
    nabs->Interpret(*c);

    delete nabs;
    delete abs;
    delete c;

    system("PAUSE");
    return;
}