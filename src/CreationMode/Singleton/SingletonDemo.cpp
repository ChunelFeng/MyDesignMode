/*
单例模式主要适用于：
1，一个全局使用的类被频繁的调用和销毁的时候
2，多个线程使用一个共同使用一个文件的时候

单例模式分为饿汉模式和懒汉模式
饿汉模式：类初始化的时候，就开始分配资源
懒汉模式：类被第一次用到的时候，才开始分配资源
*/
#include <iostream>
#include "Singleton.h"

using namespace std;

void main()
{
    cout << "Singleton Pattern Demo : " << endl;
    Singleton * a = Singleton::getInstance();
    Singleton * b = Singleton::getInstance();

    // 此时，可以看出a和b对应的是同一块内存
    cout << a << endl;
    cout << b << endl;

    system("PAUSE");
    return;
}