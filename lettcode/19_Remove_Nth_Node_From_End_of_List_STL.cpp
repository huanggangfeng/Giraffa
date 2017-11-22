#include <list>
#include <iostream>

using namespace std;
static const int LIST_LENGTH = 10;


int main()
{
   std::list<int> mylist;
   for (int i=0 ; i< LIST_LENGTH; ++i)
   {
      mylist.push_back(i);
   }

   for (auto it = mylist.begin(); it != mylist.end(); ++it) {
      std::cout << *it << ' ';
   }
   std::cout << '\n';
   auto it2 = mylist.begin();
   std::advance(it2, (LIST_LENGTH - 2 ));
   it2 = mylist.erase(it2);

   for (auto it = mylist.begin(); it != mylist.end(); ++it) {
      std::cout << *it << ' ';
   }
   std::cout << '\n';
}
