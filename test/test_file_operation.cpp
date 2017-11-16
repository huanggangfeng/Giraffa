#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

static const unsigned int max_length = 256;

int main(int argc, char const *argv[]) {
   std::fstream fs;
   fs.open("test_fee.txt", fstream::in | fstream::app);
   char str[max_length];
   std::vector<float> v;
   string value;
   while(fs.getline(str, max_length))
   {
      v.push_back(atof(str));
   }

   for (float i: v)
      std::cout << i << '\n';

   float sum = std::accumulate(v.begin(), v.end(), 0);
   std::cout << "sum:" << sum << '\n';
   fs.close();
   return 0;
}
