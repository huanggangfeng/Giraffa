// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Solution: after process, for every positive number x, it's position should be x-1

int firstMissingPositive(vector<int> & nums)
{
   for(int i=0; i<nums.size(); i++){
      if(i+1==nums[i])
         continue;

      int x = nums[i];
      // after swap, the postion i should be i+1
      while (x>=1 && x<=nums.size() && x!=nums[x-1]){
         swap(x, nums[x-1]);
      }
   }

   for(int i=0; i<nums.size(); i++){
      if(i+1!=nums[i])
         return i+1;
   }
   return nums.size()+1;
}

int main(int argc, char const *argv[]) {
   std::vector<int> v;
   srand(time(NULL));
   //v.assign(10, 4);
   v.push_back(2);
   v.push_back(1);
   v.push_back(4);
   // for(auto &i: v)
   // {
   //    i = rand() % 10;
   //    if (i%2 == 0)
   //       i *= -1;
   // }
   int pos = firstMissingPositive(v);
   std::cout << "first post: " << pos << '\n';
   //std::sort(v.begin(), v.end());
   for (auto &i: v)
      std::cout << "i:" << i << '\n';
   return 0;
}
