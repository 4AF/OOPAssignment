﻿/*
1、定义类A，有数据成员name（char*），用于存放姓名。有show函数，用于显示名字。有构造函数及析构函数，其中析构函数除完成必要功能外，还显示“destructor A”。
2、由A派生B、C类，B增加数据成员年龄（int），C增加数据成员性别（char）；均有一个print函数，分别只能显示年龄或性别。B、C类是否需要构造函数,请自行决定，如果需要构造函数，函数体必须为空。析构函数必须有，但只有一条语句，显示"destructor B"或"destructor C"。
3、定义manage类，有：
（0）有array（指针类型），用于指向一个数组，该数组存放B、C类的对象。array、数组的类型请自行考虑确定，但禁止以后使用诸如dynamic_cast进行转换。
（1）构造函数带一个参数（int），在函数中创建上述数组，大小由该参数指定。
（2）析构函数，须保证无内存泄漏。
（3）成员函数add，用于向数组中加入一个对象，带三个参数，第一个参数指定加入数组的索引（int），第二、三参数根据加入对象类型不同，是char*,int（若加入B类对象）或char*,char（若加入C类对象）。
（4）数据成员len（int），记录数组中加入对象的数量。
（5）成员函数display(void)，通过循环语句显示数组中各对象的信息，包括姓名、年龄或性别。在显示B、C类对象姓名时，在姓名前增加显示“B:”或“C:”。应充分利用运行时多态机制，不得使用type_info、typeid等歪门邪道。
4、上述四个类，数据成员均为私有且谢绝定义其它数据成员；除构造、析构、print、show、display、add外，谢绝定义其它成员函数。
5、main函数定义为（不能修改）：
int main(){
manager m(4);
m.add(0,"zhang",18);
m.add(1,"wang",'F');
m.add(3,"liu",'M');
m.display();
return 0;
}
6、无输入，输出为：
B:zhang
18
C:wang
F
C:liu
M
destructor B
destructor A
destructor C
destructor A
destructor C
destructor A
7、提示：应充分利用虚函数、纯虚函数、重载等多态手段。
*/

#include <iostream>
#include <cstring>
using namespace std;

class A
{
    char *name;

public:
    A() {}
    A(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual ~A()
    {
        delete[] name;
        cout << "destructor A" << endl;
    }
    virtual void show()
    {
        cout << name << endl;
    }
    virtual void print() {}
};

class B : public A
{
    int age;

public:
    B() {}
    B(const char *name, int age) : A(name), age(age) {}
    ~B()
    {
        cout << "destructor B" << endl;
    }
    void print()
    {
        cout << age << endl;
    }
    void show()
    {
        cout << "B:";
        A::show();
    }
};

class C : public A
{
    char gender;

public:
    C() {}
    C(const char *name, char gender) : A(name), gender(gender) {}
    ~C()
    {
        cout << "destructor C" << endl;
    }
    void print()
    {
        cout << gender << endl;
    }
    void show()
    {
        cout << "C:";
        A::show();
    }
};

class manager
{
    A **array;
    int len;

public:
    manager(int n)
    {
        array = new A *[n + 1];
        for (int i = 0; i < n; i++)
            array[i] = NULL;
        len = 0;
    }
    ~manager()
    {
        for (int i = 0, j = 0; i < len;)
        {
            if (!array[i + j])
                j++;
            else
            {
                delete array[i + j];
                i++;
            }
        }
        delete[] array;
    }
    void add(int n, const char *name, int age)
    {
        array[n] = new B(name, age);
        len++;
    }
    void add(int n, const char *name, char gender)
    {
        array[n] = new C(name, gender);
        len++;
    }
    void display()
    {
        for (int i = 0, j = 0; i < len;)
        {
            if (!array[i + j])
                j++;
            else
            {
                array[i + j]->show();
                array[i + j]->print();
                i++;
            }
        }
    }
};

int main()
{
    manager m(4);
    m.add(0, "zhang", 18);
    m.add(1, "wang", 'F');
    m.add(3, "liu", 'M');
    m.display();
    return 0;
}