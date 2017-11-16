#include <iostream>
#include <cstdint>
#include <netinet/in.h>

static int count= 0;


void enable_vlan()
{
   if (count)
   {
      ++count;
      std::cout << "enable_vlan++" << count << '\n';
      return;
   }

   count = 1;
   std::cout << "enable_vlan at first time:" << count << '\n';
}

void disable_vlan(/* arguments */) {
   if (count > 1)
   {
      --count;
      std::cout << "disable_vlan--:" << count << '\n';
      return;
   }

   count = 0;
   std::cout << "disable_vlan at last:" << count << '\n';
}


static const uint16_t kVlanPriorityMask = 0x1FFF;
int main()
{
   enable_vlan(); //1
   enable_vlan(); //2
   disable_vlan();// 1
   enable_vlan(); //2
   enable_vlan(); //3


   disable_vlan();// 2
   disable_vlan();// 1
   disable_vlan();// 0
   uint16_t vlanTCI = 0x6002;
   uint16_t pcp = (vlanTCI &  ~kVlanPriorityMask) >> 13;
   std::cout << "pcp:" << std::hex << pcp << '\n';
   return 0;
}
