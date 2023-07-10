/*
输入任意个（含1个）字符串，并将它们拼接在一起，并输出拼接后字符串。
说明及要求：
1、输入任意个字符串，字符串间用空格分隔，每个字符串最长为20（含空字符），比如输入：abx er f，则输出结果为abxerf。
2、不能使用string类或类似的类，但可以使用cstring头文件声明的库函数，如strlen、memset、strcat等。
3、提示：要输入字符串，可以定义长度为20的字符数组s，然后cin>>s。若输入空串，则表达式cin>>s结果为0。拼接后字符串的存放要使用动态数组，因为其长度动态变化。此外要防止内存泄漏、野指针使用。
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char q[20] = {0};
    int i = 0;
    char *s = NULL;
    char *z = NULL;
    s = new char[1]{0};
    while (cin >> q)
    {
        q[19] = 0;
        z = new char[strlen(q) + strlen(s) + 1]{0};
        strcat(z, s);
        strcat(z, q);
        delete[] s;
        s = z;
    }
    cout << s << endl;
    delete[] s;
    return 0;
}
