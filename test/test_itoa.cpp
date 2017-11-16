#include <iostream>     // std::cout
#include <numeric>      // std::iota
#include <vector>
#include <algorithm>

int main () {
   int numbers[10];

   std::vector<int> v(10, 5);
   std::iota(v.begin(), (v.begin()+10), 100);
   random_shuffle(std::begin(v), std::end(v));
   for (int& it: v)
   {
      std::cout << ' ' << it;
   }
   std::cout << '\n';

   std::iota (numbers,numbers+10,100);

   for (int& i:numbers)
   {
      std::cout << ' ' << i;
   }
   std::cout << '\n';

   return 0;
}
