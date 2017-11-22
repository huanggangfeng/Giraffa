#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[]) {
   std::vector<int> v;
   for (size_t i = 0; i < 10; i++)
   {
      v.emplace_back(i);
   }

   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));

   for (auto e: v){
      std::cout << e << ' ';
   }
      std::cout << '\n';

   return 0;
}
