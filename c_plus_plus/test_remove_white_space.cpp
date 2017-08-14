#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string replaceInString(string str, string tofind, string toreplace)
{
   size_t position = 0;
   for (position = str.find(tofind); position != string::npos; position = str.find(tofind,position) )
   {
      str.replace(position, 1, toreplace);
   }
   return(str);
}

string removeWhiteSpace(string s)
{
   return replaceInString(replaceInString(replaceInString(replaceInString(s, " ", ""), "\t", ""), "\n", ""), "\r", "");
}

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
   stringstream ss(s);
   string item;
   while (getline(ss, item, delim))
   {
      elems.push_back(item);
   }
   return elems;
}

int main(int argc, char const *argv[]) {
   string input = "tghawetkha  htgewalta     hgeag feahga";
   string ret = removeWhiteSpace(input);
   std::cout << ret << '\n';

   std::vector<string> vStr;
   char delim = ' ';
   vStr = split(input, delim, vStr);

   for (auto it = ret.begin(); it != ret.end(); it++) {
      std::cout << *it << ' ';
   }
   return 0;
}
