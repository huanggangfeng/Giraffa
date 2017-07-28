// A priority_queue keeps internally a comparing function and a container object as data. The comparing function is a copy of comp and the underlying container depends on the constructor used


#include <queue>
#include <iostream>

int main() {
   std::priority_queue<int> myQueue;
   for (int i = 0; i < 10; i++) {
      myQueue.push(i*10);
   }

   while(!myQueue.empty())
   {
      std::cout << myQueue.top() << ' ';
      myQueue.pop();
   }
   return 0;
}
