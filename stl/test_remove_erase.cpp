#include <algorithm>
#include <vector>
#include <iostream>

void print_vector(std::vector<int> &v)
{
   for(auto &i: v)
      std::cout << i << ' ';
   std::cout << '\n';
}

int main(int argc, char const *argv[]) {
   std::vector<int> v;
   v.assign(10, 0);
   for (size_t i = 0; i < v.size(); i++)
      v[i] = i;
   std::cout << "Init vector" << '\n';
   print_vector(v);
   auto it = std::remove_if(v.begin(), v.end(),
                           [](int value) {return (value%2 ==0);});
   std::cout << "After remove_if" << '\n';
   print_vector(v);
   v.erase(it, v.end());
   std::cout << "After erase" << '\n';
   print_vector(v);
   return 0;
}
