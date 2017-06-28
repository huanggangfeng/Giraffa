#include <string>
#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string str)
{
    int sign = 1; int i = 0;
    long num = 0;
  
    while(str[i] == ' ')
        i++;

    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i] == '-');
        i++; 
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = num*10  + (str[i] - '0');
        if(num * sign >= INT_MAX) return INT_MAX;
        if(num * sign <= INT_MIN) return INT_MIN;  
        i++;

    }
    return num * sign;
}

// int myAtoi2(string str) {
//     long result = 0;
//     int indicator = 1;
//     for(int i = 0; i<str.size();)
//     {
//         i = str.find_first_not_of(' ');
//         if(str[i] == '-' || str[i] == '+')
//             indicator = (str[i++] == '-')? -1 : 1;
//         while('0'<= str[i] && str[i] <= '9') 
//         {
//             result = result*10 + (str[i++]-'0');
//             if(result*indicator >= INT_MAX) return INT_MAX;
//             if(result*indicator <= INT_MIN) return INT_MIN;                
//         }
//         return result*indicator;
//     }
// }

int main(int argc, char const *argv[])
{
    string test = "2147483648";
    int ret = myAtoi(test);
    cout << UINT_MAX << "Function 1:" << ret << endl;
    return 0;
}