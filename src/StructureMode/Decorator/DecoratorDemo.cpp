#include <iostream>
#include "Decorator.h"

using namespace std;

void main()
{
    /* 创建一个DarkRoast的饮料对象,
       然后通过Mocha和Whip类来装饰它 */
    cout << "Decorator Pattern Demo : " << endl;
    Beverage * beverage = new DarkRoast();
    beverage = new Mocha(beverage);    // Mocha返回的实际上是Beverage类的继承的继承
    beverage = new Whip(beverage);

    // 打印出来饮料+配料的收费情况
    cout << beverage->getDescription()
         << " cost "
         << beverage->cost() << endl;

    system("PAUSE");
    return;
}