/**
* 文件名称：Interpreter.h
* 摘    要：解释器头文件
*
* 当前版本：1.0.0
* 作    者: Chunel
* 日    期：2018-09-04
* 备    注：新建
*/

#ifndef _INTERPRETER_PATTERN_H_
#define _INTERPRETER_PATTERN_H_

#include <iostream>
#include <string>

using namespace std;

class Context
{
public:
    Context() {}
    virtual ~Context() {}
};

class AbstractExpression
{
public:
    virtual ~AbstractExpression() {}
    virtual void Interpret(const Context& c) {}

protected:
    AbstractExpression() {}
};

class TerminalExpression :public AbstractExpression
{
    /* 终端节点 */
public:
    TerminalExpression(const string& statement)
    {
        m_statement = statement;
    }
    virtual ~TerminalExpression() {}

    void Interpret(const Context& c)
    {
        cout << "TerminalExpression Interpret, " << m_statement << endl;
    }

private:
    string m_statement;
};

class NonterminalExpression :public AbstractExpression
{
    /* 非终端节点 */
public:
    NonterminalExpression(AbstractExpression* ex, int times)
    {
        m_ex = ex;
        m_times = times;
    }
    ~NonterminalExpression() {};

    void Interpret(const Context& c)
    {
        /* 解释为：打印times次的ex信息 */
        for (int i = 0; i < m_times; i++)
        {
            m_ex->Interpret(c);
        }
    }

private:
    AbstractExpression * m_ex;
    int m_times;
};

#endif