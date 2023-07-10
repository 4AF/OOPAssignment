/*
1、定义基类Base，有私有数据成员x，int类型。有带一个参数的构造函数为其初始化。有show函数，显示x的值。
2、定义公有派生类derived，增加私有数据成员y，int类型，有带两个参数的构造函数，为其数据成员初始化。有show函数，显示x、y的值。
3、定义外部函数func1、func2，形参分别是Base、derived类对象，函数只有一句，调用形参对象的show函数。
4、在main函数中静态定义derived类对象a，实参为10、20，并调用其show函数。然后分别定义Base指针、derived指针，都指向a，分别用指针调用其show函数。
最后以a为实参，调用函数func1、func2。
5、程序无输入，输出为：
x=10
y=20
x=10
x=10
y=20
x=10
x=10
y=20
6、对上述输出应能够正确解释。
*/

#include <iostream>

class Base
{
private:
    int x;

public:
    Base(int value) : x(value) {}

    void show()
    {
        std::cout << "x=" << x << std::endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int value1, int value2) : Base(value1), y(value2) {}

    void show()
    {
        Base::show();
        std::cout << "y=" << y << std::endl;
    }
};

void func1(Base obj)
{
    obj.show();
}

void func2(Derived obj)
{
    obj.show();
}

int main()
{
    Derived a(10, 20);
    a.show();

    Base *basePtr = &a;
    Derived *derivedPtr = &a;

    basePtr->show();
    derivedPtr->show();

    func1(a);
    func2(a);

    return 0;
}
