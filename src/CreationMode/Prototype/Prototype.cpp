#include "Prototype.h"

Prototype::Prototype()
{
    cout << "Prototype" << endl;
}

Prototype::~Prototype()
{
    cout << "~Prototype" << endl;
}

//ConcretePrototype1
ConcretePrototype1::ConcretePrototype1()
{
    cout << "ConcretePrototype1" << endl;
}

ConcretePrototype1::~ConcretePrototype1()
{
    cout << "~ConcretePrototype1" << endl;
}

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& cp)
{
    cout << "ConcretePrototype1 copy" << endl;
}

Prototype* ConcretePrototype1::Clone() const
{
    return new ConcretePrototype1(*this);
}

//ConcretePrototype2
ConcretePrototype2::ConcretePrototype2()
{
    cout << "ConcretePrototype2" << endl;
}

ConcretePrototype2::~ConcretePrototype2()
{
    cout << "~ConcretePrototype2" << endl;
}

Prototype* ConcretePrototype2::Clone() const
{
    return new ConcretePrototype2(*this);
}

ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2 & cp)
{
    cout << "ConcretePrototype2 copy" << endl;
}
