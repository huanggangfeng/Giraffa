#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>


using namespace std;
int winner;
void set_winner(int x)
{
   winner = x;
}
std::once_flag winner_flag;

void wait_1000ms(int id)
{
   for (size_t i = 0; i < 1000; i++) {
      std::this_thread::sleep_for(chrono::milliseconds(1));
   }
   call_once(winner_flag, set_winner, id);
}

const static int thread_number = 10;
int main(int argc, char const *argv[]) {
   std::thread threads[thread_number];
   for (size_t i = 0; i < thread_number; i++) {
      threads[i] = thread(wait_1000ms, i+1);
   }

   for(auto &th: threads)
      th.join();

   std::cout << "Winner thread:" << winner << '\n';
   return 0;
}
