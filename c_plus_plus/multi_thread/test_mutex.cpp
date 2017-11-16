#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
void print_block(int n, char c)
{
    mtx.lock();
   for (size_t i = 0; i < n; i++) {
      std::cout << c << " ";
   }
   std::cout << '\n';
   mtx.unlock();
}


std::mutex mtx;
void print_block(int n, char c)
{
    mtx.lock();
   for (size_t i = 0; i < n; i++) {
      std::cout << c << " ";
   }
   std::cout << '\n';
   mtx.unlock();
}

int main(int argc, char const *argv[]) {
   std::thread th1 (print_block, 50, '*');
   std::thread th2 (print_block, 50, '#');
   th1.join();
   th2.join();
   return 0;
}
