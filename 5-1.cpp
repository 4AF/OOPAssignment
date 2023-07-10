/*
1、定义String类，用于实现字符串，其中有：
数据成员array，类型为char* 。
构造函数String(const char* p)、析构函数~String()。
根据以下main函数及运行结果，实现必要的运算符重载，使得输出符合指定结果。其中string1[index]，要求index的值在0到字符串不算结束符的长度减一），否则显示“Index out of range.”。而string3+3表示将字符串不算结束符的长度与3相加，且要求不能再重载+运算符。
2、主函数定义如下（不能修改）：
int main(){
String string1("mystring"),string2("yourstring"),string3("herstring");
cout++string1++endl;
string1[7]='n';
cout++string1++endl;
string1[8]='n';
cout++string1+string2+string3++endl;
cout++string1++endl;
cout++string2+"ab"++endl;
cout++string2++endl;
cout++string3+3++endl;
cout++string3++endl;
return 0;
}
注意：代码中“++”更换为“<<”
3、无输入，输出信息为：
mystring
mystrinn
Index out of range.
mystrinnyourstringherstring
mystrinnyourstringherstring
yourstringab
yourstring
12
herstring
*/

#include <iostream>
#include <cstring>
using namespace std;

char null = 'null';

class String
{
private:
    char *array;

public:
    friend ostream &operator<<(ostream &, String &);
    String(const char *p)
    {
        this->array = new char[strlen(p) + 1];
        strcpy(this->array, p);
    }
    ~String()
    {
        delete this->array;
    }
    char &operator[](int n)
    {
        if (n >= strlen(this->array))
        {
            cout << "Index out of range." << endl;
            return null;
        }
        else
        {
            return *(this->array + n);
        }
    }
    String &operator+(const String &a)
    {
        char *new_array = new char[strlen(this->array) + 1];
        strcpy(new_array, this->array);
        this->array = new char[strlen(new_array) + strlen(a.array) + 1];
        strcpy(this->array, new_array);
        strcat(this->array, a.array);
        return *this;
    }
    string operator+(const char a[])
    {
        char *new_str = new char[this->getLength() + strlen(a) + 1];
        strcpy(new_str, this->getArray());
        strcat(new_str, a);
        string str(new_str);
        return str;
    }
    operator int()
    {
        return this->getLength();
    }
    char *getArray()
    {
        return this->array;
    }
    int getLength()
    {
        return strlen(this->array);
    }
};

ostream &operator<<(ostream &co, String &s)
{

    for (int i = 0; i < strlen(s.getArray()); i++)
    {
        co << *(s.getArray() + i);
    }
    return co;
}

int main()
{
    String string1("mystring"), string2("yourstring"), string3("herstring");
    cout << string1 << endl;
    string1[7] = 'n';
    cout << string1 << endl;
    string1[8] = 'n';
    cout << string1 + string2 + string3 << endl;
    cout << string1 << endl;
    cout << string2 + "ab" << endl;
    cout << string2 << endl;
    cout << string3 + 3 << endl;
    cout << string3 << endl;
    return 0;
}