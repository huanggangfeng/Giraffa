#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
static const int LIST_LENGTH = 10;
int main(int argc, char const *argv[]) {
   std::list<int> mylist1, mylist2;
   for (int i = 0; i < LIST_LENGTH; i++) {
      mylist1.push_back(i * 2);
      mylist2.push_back(i * 2 + 1);
   }

   std::list<int> result(mylist1.size() + mylist2.size(), 0);
   std::merge(mylist1.begin(), mylist1.end(), mylist2.begin(), mylist2.end(),result.begin());

   // std::cout << "size of result:" << result.size() << '\n';
   for (auto element: result)
   {
      std::cout << element << ' ';
   }
   std::cout << '\n';
   return 0;
}
