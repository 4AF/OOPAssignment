/*
先创建一个数组，数组长度由键盘输入确定，数组类型为指向int的指针。
然后动态创建一组int类型变量，使得数组每个元素指向一个变量，并通过键盘输入每个变量的值。
最后输出这些变量的和。
例如：
输入 3 7 3 -1 //第1个数为数组大小
输出 9
提示：创建数组时需要先定义指向指针的指针变量；
注意：谢绝使用静态数组，并且遵守防止使用野指针的有关措施。
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int **p = new int *[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = new int;
        cin >> *p[i];
        sum += *p[i];
    }

    cout << sum << endl;
    for (int i = 0; i < n; i++)
        delete p[i];
    delete[] p;
    return 0;
}