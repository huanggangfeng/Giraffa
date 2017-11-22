#include <vector>
#include <iostream>
#include <algorithm>

static const int count = 20;

int main(int argc, char const *argv[]) {
   std::vector<int> myvector;
   for (size_t i = 0; i < count; i++) {
      myvector.emplace_back(i%5);
   }

   for (auto e : myvector)
      std::cout << e << ' ';
   std::cout << '\n';

//    int removeElement(vector<int>& nums, int val) {
//     int cnt = 0;
//     for(int i = 0 ; i < nums.size() ; ++i) {
//         if(nums[i] == val)
//             cnt++;
//         else
//             nums[i-cnt] = nums[i];
//     }
//     return nums.size()-cnt;
// }
   myvector.erase(std::remove(myvector.begin(),myvector.end(), 3), myvector.end());
   for (auto e : myvector)
      std::cout << e << ' ';
   std::cout << '\n';
   return 0;
}
