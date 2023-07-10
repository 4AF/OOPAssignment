/*
定义一个函数，参数为三个int类型变量的引用。在函数中交换三个参数的值，使其按升序排序。然后在主函数中输入三个整型数，调用该函数，按升序输出这三个数。


例如：
输入： 3 4 -1
输出： -1 3 4
*/

#include <iostream>
using namespace std;

void sort(int &a, int &b, int &c)
{
	int temp = 0;
	if (a > b)
	{
		temp = b;
		b = a;
		a = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	if (a > b)
	{
		temp = b;
		b = a;
		a = temp;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	sort(a, b, c);
	cout << a << " " << b << " " << c;
	return 0;
}