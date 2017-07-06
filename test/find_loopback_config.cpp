#include <iostream>

struct stream_config{
   int first_launch;
   int read_interval;
   int second_launch;
   int period;
   stream_config(int n, int a, int b,int c):
      period(n), first_launch(a), read_interval(b), second_launch(c){}
};

stream_config find_result(stream_config init, stream_config fact)
{
   int period = init.period;
   int launch1 = init.first_launch;
   int read_interval = init.read_interval;
   int launch2 = init.second_launch;

   while (launch1 > 0) {
      if (launch1 < fact.first_launch)
         break;
      else
         launch1 -= 5;
   }

   launch1 += 5;

   while (read_interval > 0) {
      if (read_interval < fact.read_interval)
         break;
      else
         read_interval -= 5;
   }
   read_interval += 5;

   while (launch2 > 0) {
      if (launch2 < fact.second_launch)
         break;
      else
         launch2 -= 5;
   }
   launch2 += 5;

   while (period > 0) {
      if (period < fact.period)
         break;
      else
         period -= 5;
   }
   period += 5;

   return stream_config(period, launch1, read_interval, launch2);
}

int main(int argc, char const *argv[]) {
   stream_config fact_result(491, 208 ,243, 462);
   stream_config init_value(600, 250, 300, 550);
   stream_config x = find_result(init_value, fact_result);
   std::cout << "period: " << x.period << '\n';
   std::cout << "first_launch: " << x.first_launch << '\n';
   std::cout << "read_interval: " << x.read_interval << '\n';
   std::cout << "second_launch: " << x.second_launch << '\n';
   return 0;
}
