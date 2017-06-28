#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    std::vector<int> dict(256,-1);
    int max_len = 0; start = -1;
    for (int i = 0; i < s.length(); ++i)
    {
        if(dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        max_len = max(max_len, i-start);
    }
}
int main()
{

}