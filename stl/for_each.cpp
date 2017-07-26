#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
   std::vector<int> v(10);
   int i = 0;
   for (size_t i = 0; i < v.size(); i++) {
      v[i]  = i;
   }

   for_each(v.begin(), v.end(), [](int &n){std::cout << " " << n;});
   return 0;
}
