// Write a function to find the longest common prefix string amongst an array
// of strings.
#include <climits>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
   int min_length = INT_MAX;
   string s;
   for (auto si: strs)
   {
      if(si.size() < min_length)
      {
         min_length = si.size();
         s = si;
      }
   }
   bool isMatch = true;
   for (int i = 0; i < s.size(); i++)
   {
      for (auto si : strs )
      {
         if(si[i] != s[i])
         {
            isMatch = false;
            break;
         }
      }
      if (!isMatch)
         return s.substr(0,i);
   }
   return s;
}

int main(int argc, char const *argv[])
{
   std::vector<string> v = {"gteaetata", "gteaaa", "gtea"};
   std::string longestPrefix = longestCommonPrefix(v);
   std::cout << "longestPrefix:" << longestPrefix << '\n';
   return 0;
}
