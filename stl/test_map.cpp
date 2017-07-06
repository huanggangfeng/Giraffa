#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
   std::map<char, int> mymap;
   // mymap.resize(10);
   std::map<char, int>::key_compare my_comp = mymap.key_comp();

   mymap.emplace('a', 100);
   mymap.emplace('b', 200);
   mymap.emplace('c', 300);
   auto ret = mymap.emplace_hint(mymap.begin(), 'd', 500);

   // key_comp returns the same as operator<.
   bool ret_b =  my_comp(mymap.begin()->first, mymap.rbegin()->first);
   if (ret_b)
      std::cout << "first is less" << '\n';
   else
      std::cout << "c" << '\n';

   for (auto x: mymap)
      std::cout << x.first << ":" << x.second << '\n';

   auto it = mymap.find('b');
   std::cout << it->first << ":" << it->second << '\n';

   mymap.erase(it);

   // Find a key is not exist
   auto ret_it = mymap.equal_range('d');

   // output value is 0
   std::cout << "pair_it first: " << ret_it.first->first << ":" << ret_it.first->second << '\n';
   std::cout << "pair_it second: "<< ret_it.second->first << ":" << ret_it.second->second << '\n';
   return 0;
}
