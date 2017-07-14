
#include <set>
#include <iostream>

using namespace std;
typedef std::multiset<int>::iterator It;
int main(int argc, char const *argv[]) {
   multiset<int> mset;
   for (size_t i = 0; i < 10; i++) {
      mset.insert(i);
      mset.insert(i);
   }

   std::cout << "set size:" << mset.size() << '\n';
   auto it = mset.find(5);
   mset.erase(it);
   std::cout << "set size:" << mset.size() << '\n';

   std::pair<It, It> ret = mset.equal_range(6);

   for (auto it2 = ret.first;  it2 != ret.second; it2++) {
      std::cout << " " << *it2 << '\n';
      std::cout << *ret.first <<":" << *ret.second << '\n';
   }
   return 0;
}
