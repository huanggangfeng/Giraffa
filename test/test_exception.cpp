#include <stdexcept>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
   try {
      std::vector<int> v;
      std::cout << v.max_size() << '\n';
      v.resize(v.max_size() +1);
   } catch (const std::length_error &le)
   {
         std::cout << "length_error:" <<le.what() << '\n';
   }

   return 0;
}
