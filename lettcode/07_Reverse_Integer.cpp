#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int reserse_int(int x)
{
    std::vector<char> v;

    int temp = x;
    int flag = 1;
    if (x<0);
    {
        flag = -1;
        temp = x * -1;
    }

    while(temp)
    {
        v.push_back(temp%10);
        temp = temp/10;
    }

    int a;
    for(int i: v)
    {
        a = a*10 + i;
    }
    return a * flag;
}

int reserse_int2(int x)
{
    long temp = 0;
    while (x)
    {
        temp = x%10 + temp *10 ;
        x = x/10;
    }

    if (temp > INT_MAX)
        return 0;
    if (temp < INT_MIN)
        return 0;
    return temp;
}

int main()
{
    int v = 122223;
    cout << reserse_int(v) << endl;
    cout << reserse_int2(v) << endl;
}