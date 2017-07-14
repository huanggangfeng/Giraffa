#include <tuple>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
   std::tuple<int, char, string> t(10, 'a', "hjehje");
   std::tuple <int, char, string> p= make_tuple(2, 'c', "teata");

   auto myauto  = std::tuple_cat(t, p);
   int size  = tuple_size<decltype(myauto)>::value;
   std::cout << "size:" << size << '\n';

   std::cout << get<0>(t); // first
   std::cout << ":" << get<1>(t); // second
   std::cout << ":" << get<2>(t) << '\n'; // third

   return 0;
}
