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

   // The immplement is similar as the std::unique
   int count = 0;
   for (size_t i = 1; i < myvector.size(); i++) {
      if (myvector[i] == myvector[i-1])
      {
         count++;
      }
      else
      {
         myvector[i-count] = myvector[i];
      }
   }

   myvector.erase(myvector.begin() + count, myvector.end());

   for (auto e : myvector) {
      std::cout << e << ' ';
   }
   std::cout << '\n';
   return 0;
}
