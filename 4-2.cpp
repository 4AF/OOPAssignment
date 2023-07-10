﻿/*
1、设计一个基类Base，包含姓名（char*）、年龄（int）私有类型数据成员、带两个参数的构造函数（不能带默认参数）、析构函数。
2、由Base派生出领导类Leader，增加职务（char[10]）私有数据成员，带三个参数构造函数及析构函数。再由Base派生出工程师类Engineer，增加专业（char[10]）私有数据成员，带三个参数构造函数及析构函数。
3、由Leader和Engineer类公有派生出主任工程师类Chairman。
4、上述类的构造函数、析构函数需要做相应输出，比如Base 的构造函数输出“Base constructor”，析构函数输出“Base destructor”，其它类类似。
5、Base中增加void show()函数，显示名字、年龄。在Leader和Engineer中重新定义该函数，调用基类show函数显示姓名、年龄，并分别增加显示职务、专业。在Chairman中进一步重新定义show函数，显示所有信息，但不能重复显示。
6、题目未指定Base到Leader和Engineer的派生方式，请研究自行确定，但尽可能维护封装性。
7、main函数中如下定义Chairman对象：
Chairman a("Li","chair","computer",20);
并调用a的show函数显示其4个信息。
8、程序无输入，输出如下，注意，单词间只有1个空格，每行结束无空格，只有换行符：
Base constructor
Leader constructor
Engineer constructor
Chairman constructor
Li 20 chair computer
Chairman destructor
Engineer destructor
Leader destructor
Base destructor
9、注意：（1）几个类的show函数要求首部相同；（2）根据封装原则，孙子最好不要直接访问爷爷的成员，包括成员函数。
*/

#include <iostream>
#include <cstring>

class Base
{
private:
    char *name;
    int age;

protected:
    bool flag;

public:
    Base(const char *name, int age) : age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        flag = true;
        std::cout << "Base constructor" << std::endl;
    }
    ~Base()
    {
        delete[] name;
        std::cout << "Base destructor" << std::endl;
    }
    void show()
    {
        std::cout << name << " " << age;
        flag = false;
    }
};

class Leader : virtual public Base
{
private:
    char position[10];

public:
    Leader(const char *name, int age, const char *position) : Base(name, age)
    {
        strcpy(this->position, position);
        std::cout << "Leader constructor" << std::endl;
    }
    ~Leader()
    {
        std::cout << "Leader destructor" << std::endl;
    }
    void show()
    {
        if (flag)
            Base::show();
        std::cout << " " << position;
    }
};

class Engineer : virtual public Base
{
private:
    char major[10];

public:
    Engineer(const char *name, int age, const char *major) : Base(name, age)
    {
        strcpy(this->major, major);
        std::cout << "Engineer constructor" << std::endl;
    }
    ~Engineer()
    {
        std::cout << "Engineer destructor" << std::endl;
    }
    void show()
    {
        if (flag)
            Base::show();
        std::cout << " " << major;
    }
};

class Chairman : public Leader, public Engineer
{
public:
    Chairman(const char *name, const char *position, const char *major, int age) : Base(name, age), Leader(name, age, position), Engineer(name, age, major)
    {
        std::cout << "Chairman constructor" << std::endl;
    }
    ~Chairman()
    {
        std::cout << "Chairman destructor" << std::endl;
    }
    void show()
    {
        Leader::show();
        Engineer::show();
        std::cout << std::endl;
    }
};

int main()
{
    Chairman a("Li", "chair", "computer", 20);
    a.show();

    return 0;
}