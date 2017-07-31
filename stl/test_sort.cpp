#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void print_vector(const std::vector<int> v)
{
   for (auto i: v)
      std::cout << i << ' ';

   std::cout << '\n';
}

void random_vector(std::vector<int> &v)
{
   print_vector(v);
   random_shuffle(v.begin(), v.end());
}

int main(int argc, char const *argv[]) {
   vector<int> vec;
   vec.assign(10, 5);
   int value = 0;
   for (auto it = vec.begin(); it != vec.end(); it++) {
      *it = value++;
   }
   random_vector(vec);

   // partial_sort
   partial_sort(vec.begin(), vec.begin()+5, vec.end());
   random_vector(vec);

   nth_element(vec.begin(), vec.begin() + 6, vec.end());
   random_vector(vec);

   auto it = is_sorted_until(vec.begin(), vec.end());
   random_vector(vec);
   std::cout << distance(vec.begin(), it) << '\n';


   std::vector<int> vec2(5);
   partial_sort_copy(vec.begin(), vec.end(), vec2.begin(), vec2.end());
   random_vector(vec);
   print_vector(vec2);

   return 0;
}

// 169.254.174.94
