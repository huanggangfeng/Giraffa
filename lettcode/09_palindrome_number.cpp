// palindrome int
#include <iostream>

using namespace std;
bool Is_palindrome(int x)
{
    if(x<0|| (x!=0 && x%10 == 0)) return false;
    int sum=0;
    while(x>sum)
    {
        sum = sum*10 + x%10;
        x = x/10;
    }
    return (x==sum)||(x==sum/10);
}

int main()
{
    int v = 12321;

    bool ret = Is_palindrome(v);
    cout << "It is palindrome: " << ret << endl;
    return 0;
}
