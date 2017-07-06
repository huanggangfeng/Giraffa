#include <deque>
#include <iostream>

int main(int argc, char const *argv[]) {
   std::deque<int> my_deque(100);
   // for_each(my_deque.begin(), my_deque.end(), )
   my_deque.erase(my_deque.begin()+5,my_deque.begin()+10);

   std::deque<int>::iterator it = my_deque.begin();
   for(;it != my_deque.end(); it++)
      std::cout << " " << *it;
   std::cout << "over" << '\n';
   return 0;
}
