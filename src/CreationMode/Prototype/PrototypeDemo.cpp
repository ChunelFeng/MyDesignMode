/*
原型模式
用于创建重复的对象，同时又能保证性能（使用拷贝构造函数）

主要解决：
利用已有的一个原型对象，来生成和原型对象一样的实例

何时使用：
比如：p1中已经有一些参数被赋值了，p1_clone可以直接生成跟p1一样的对象
*/

#include "Prototype.h"

void main()
{
    cout << "Prototype Pattern Demo : " << endl;

    /* 注意，Prototype的构造函数是protected类型，无法直接new Prototype() */
    /* 创建一个实体类 */
    Prototype * p1 = new ConcretePrototype1();

    /* 通过拷贝构造函数，来实现p2 */
    Prototype * p1_clone = p1->Clone();

    delete p1;
    /* 析构的时候，发现p1_clone是ConcretePrototype1类型 */
    delete p1_clone;

    Prototype * p2 = new ConcretePrototype2();
    Prototype * p2_clone = p2->Clone();
    delete p2;
    delete p2_clone;

    system("PAUSE");
    return;
}