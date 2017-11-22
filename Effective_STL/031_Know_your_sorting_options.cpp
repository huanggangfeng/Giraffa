#include <algorithm>
#include <vector>
#include <iostream>

static const int count = 20;

void print_myvector(std::vector<int> v)
{
   for (auto e: v)
      std::cout << e << ' ';
   std::cout << '\n';
}

int main(int argc, char const *argv[]) {
   std::vector<int> myvector;
   for (size_t i = 0; i < count; i++) {
      myvector.emplace_back(i);
   }
   std::random_shuffle(myvector.begin(), myvector.end());
   print_myvector(myvector);

   // put the smaller 10 elements at the front of myvector
   partial_sort(myvector.begin(), myvector.begin() +10, myvector.end(), [](int i, int j){return (i<j);});
   print_myvector(myvector);

   std::random_shuffle(myvector.begin(), myvector.end());
   print_myvector(myvector);
   nth_element(myvector.begin(), myvector.begin()+ 3, myvector.end(), [](int i, int j){ return (i<j);});
   print_myvector(myvector);
   return 0;
}
