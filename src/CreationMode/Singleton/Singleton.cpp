#include <iostream>
#include "Singleton.h"

using namespace std;

void locked()
{
    // 模拟多线程中的线程锁，加锁过程
    cout << "locked" << endl;
    return;
}

void unlocked()
{
    // 模拟多线程中的线程锁，去锁过程
    cout << "unlocked" << endl;
    return;
}

// 切记使用前需要初始化，否则无法通过编译
Singleton * Singleton::ms_instance = NULL;

Singleton::Singleton()
{
    // 将构造函数设置为私有方法
    cout << "Singleton Init" << endl;
    return;
}

Singleton::~Singleton()
{
    cout << "Singleton Deinit" << endl;
    return;
}

Singleton * Singleton::getInstance()
{
    // 静态成员方法，外部调用使用
    if (NULL == ms_instance)
    {
        locked();
        if (NULL == ms_instance)
        {
            // 多线程情况下，如果没有被创建过，则创建
            // 属于优化后的懒汉模式
            ms_instance = new Singleton();
        }
        unlocked();
    }

    return ms_instance;
};