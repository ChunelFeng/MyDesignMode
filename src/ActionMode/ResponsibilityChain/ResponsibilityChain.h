/**
* 文件名称：ResposibilityChain.h
* 摘    要：责任链模式头文件
*
* 当前版本: 1.0.0
* 作    者: Chunel
* 日    期：2018-08-26
* 备    注：新建
*/

#ifndef _RESPONSIBILITY_CHAIN_PATTERN_H_
#define _RESPONSIBILITY_CHAIN_PATTERN_H_

#include <iostream>
#include <string>

using namespace std;

/* 设定，一级领导为最高的领导级别 */
#define FIRST_LEVEL_SALARY  (5000)    // 一级领导可以审批
#define SECOND_LEVEL_SALARY (3000)    // 二级领导可以审批
#define THIRD_LEVEL_SALARY  (1000)    // 三级领导可以审批

class Manager
{
public:
    /* manager 上级的级别
       name 上级的名字 */
    Manager(Manager * manager, string name);
    virtual ~Manager();

    /* 申请加薪的请求
       name : 申请加薪的人
       salary : 申请的加薪的数量 */
    virtual void DealWithRequest(string name, int salary);

protected:
    /* 这里要被继承者用到，所以设定为protected类型 */
    Manager * m_manager;
    string m_name;
};

class ThirdManager : public Manager
{
public:
    ThirdManager(Manager * manager, string name);
    virtual ~ThirdManager();

    void DealWithRequest(string name, int salary);
};

class SecondManager : public Manager
{
public:
    SecondManager(Manager * manager, string name);
    virtual ~SecondManager();

    void DealWithRequest(string name, int salary);
};

class FirstManager : public Manager
{
public:
    FirstManager(Manager * manager, string name);
    virtual ~FirstManager();

    void DealWithRequest(string name, int salary);
};
#endif