#include <algorithm>
#include <vector>
#include <iostream>

static const int MAX_CAPABILITY = 30;

int main(int argc, char const *argv[]) {
   std::vector<int> myvector;
   myvector.reserve(MAX_CAPABILITY);
   for (int i = 0; i < MAX_CAPABILITY; i++) {
      myvector.emplace_back(i/2);
   }

   for (auto e : myvector) {
      std::cout << e << ' ';
   }
   std::cout << '\n';

   myvector.erase(std::unique(myvector.begin(), myvector.end(), [](int i, int j){return (i==j);}),
           myvector.end());

   for (auto e : myvector) {
      std::cout << e << ' ';
   }
   std::cout << '\n';
   return 0;
}
