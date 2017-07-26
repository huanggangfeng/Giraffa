#include <set>
#include <algorithm>
#include <iostream>

std::set<int> vlanPriority;
using namespace std;
static const short kVlanPriorityMask = 0x1FFF;
static const short kVlanPriorityShift = 13;

bool add_vlan(int vlantag)
{
   if(find_if(vlanPriority.begin(), vlanPriority.end(),
      [vlantag](int tag){return (tag == vlantag);}) != vlanPriority.end())
      std::cout << vlantag << " already exist" << '\n';
   else
      vlanPriority.emplace(vlantag);
}

int main() {

   for (int i = 0; i < 6; i++) {
      if (i%2)
         vlanPriority.emplace(i);
   }

   for(auto iset: vlanPriority)
      std::cout << "vlanPriority:" <<iset << '\n';

   short vlanTCI = 0x6002;
   short vlanP = (vlanTCI & ~kVlanPriorityMask) >> kVlanPriorityShift;
   std::cout << "vlan p:" << vlanP << '\n';

   add_vlan(5);
   add_vlan(6);
   add_vlan(7);

   for(auto iset: vlanPriority)
      std::cout << "vlanPriority:" <<iset << '\n';

   return 0;
}
