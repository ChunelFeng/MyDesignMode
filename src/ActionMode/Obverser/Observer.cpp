#include <iostream>
#include <list>
#include "Observer.h"

using namespace std;

/* 具体目标，用于存储具体的RoomMate对象 */
QQGroup::QQGroup()
{
    cout << "QQGroup::QQGroup()" << endl;
    m_observers = new list<Observer *>();

    return;
}

QQGroup::~QQGroup()
{
    cout << "QQGroup::~QQGroup()" << endl;
    delete m_observers;
    return;
}

void QQGroup::registerObserver(Observer * observer)
{
    cout << "QQGroup::registerObserver()" << endl;
    m_observers->push_back(observer);
    return;
}

void QQGroup::removeObserver(Observer * observer)
{
    cout << "QQGroup::removeObserver()" << endl;
    if (m_observers->size() > 0)
    {
        m_observers->remove(observer);
    }
    return;
}

void QQGroup::notifyObserver(string & message)
{
    /* 依次通知注册到QQGroup中的Observer成员 */
    cout << "QQGroup::notifyObserver()" << endl;
    for (list<Observer *>::iterator iter = m_observers->begin();
         iter != m_observers->end();
         iter++)
    {
        // *iter就是被注册的观察者
        (*iter)->Update(message);
    }

    return;
}

/* 被通知的实体类，继承自Observer类 */
RoomMate::RoomMate(string name, string current_action, string next_action)
{
    cout << "RoomMate::RoomMate(), name = " << name << endl;
    m_name = name;
    m_current_action = current_action;
    m_next_action = next_action;
}

RoomMate::~RoomMate()
{
    cout << "RoomMate::~RoomMate" << endl;
    return;
}

void RoomMate::Update(const string & message)
{
    /* 被注册的对象接受通知信息的函数，由QQGroup类中依次调用 */
    cout << "This is " << getName() << endl;
    if (message == "next")
    {
        cout << "Next action : " << m_next_action << endl;
    }
    else
    {
        cout << "Current action : " << m_current_action << endl;
    }

    return;
}

string RoomMate::getName()
{
    return m_name;
}