#include <thread>
#include <iostream>
#include <unistd.h>

const static int count = 10;

void foo(/* arguments */) {
   for (size_t i = 0; i < count; i++) {
      sleep(1);
      std::cout << "foo: " << i << '\n';
   }
}

void bar(int x) {
   for (size_t i = 0; i < count; i++) {
      std::cout << "bar:" << i << '\n';
      sleep(1);
   }
}

int main(int argc, char const *argv[]) {
   std::thread first(foo);
   std::thread second(bar, 1);

   first.join();
   second.join();
   return 0;
}
