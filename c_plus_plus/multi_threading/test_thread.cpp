#include <thread>
#include <iostream>

using namespace std;

void foo(/* arguments */) {
   std::cout << "This is foo" << '\n';
}

void bar(int x) {
   std::cout << "This is bar" << '\n';
}

int main(int argc, char const *argv[]) {

   std::thread first(foo);
   std::thread second(bar, 0);

   first.join();
   second.join();
   return 0;
}
