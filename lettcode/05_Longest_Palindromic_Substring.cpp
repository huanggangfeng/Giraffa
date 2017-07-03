#include <string>
#include <iostream>

using namespace std;
    int longestPalindrome(string s) {
    int len = s.size();
    if (len == 0) return 0;
    if (len == 1) return 1;
    int start = 0, stop = 0, max_len = 0, new_len = 0, new_len2 = 0;
    for(int i=0; i< s.size(); i++)
    {
        int j = 0;
        // 121
        while((i-j)>0 && (i+j) <len)
        {
            cout << "j1:" << j << endl;
            if(s[i-j] == s[i+j])
            {
                j++;
                continue;
            }
            else
                break;
        }

        new_len = 2*(j-1) + 1;
        if (new_len > max_len)
        {
            cout << "max_len:" << new_len << endl;
            max_len = new_len;
            start = i - j;
        }

        // 1221
        j = 0;
        while(i-j >= 0 && i+j <len)
        {
            cout << "j2:" << j << endl;
            if(s[i-j] == s[i+j+1])
            {
                j++;
                continue;
            }
            else
                break;
        }
        new_len2 = 2*j;
        // if (new_len2 > max_len)
        // {
        //     cout << "max_len2:" << new_len2 << endl;
        //     max_len = new_len2;
        //     start = i - (j -1 );
        //     stop = i + j;
        //     cout << "start: " << start << endl;
        // }
        if (new_len2 > max_len)
        {
            max_len = j*2;
            if(new_len2 == 2)
                start = i;
            else
                start = i-j;
        }
    }

        return max_len;
    }

int main()
{
    string s = "bacab";
    int ret = longestPalindrome(s);
    cout << ret << endl;
}


// l
