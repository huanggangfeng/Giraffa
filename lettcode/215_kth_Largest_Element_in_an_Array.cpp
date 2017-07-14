// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.
//
// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.
//
// Note:
// You may assume k is always valid, 1 ? k ? array's length.
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>

//  naive solution
int findKthLargest(std::vector<int> &nums, int k)
{
   std::vector<int> temp(nums);
   std::sort(temp.begin(), temp.end());
   return temp[temp.size() - k];
}

//
int findKthLargest_1(std::vector<int>& nums, int k) {
   std::multiset<int> mset;
   int n = nums.size();
   for (int i = 0; i < n; i++) {
      mset.insert(nums[i]);
      if (mset.size() > k)
      mset.erase(mset.begin());
   }
   return *mset.begin();
}

int main(int argc, char const *argv[]) {
   std::vector<int> v;
   v.assign(10, 5);
   srand(time(NULL));
   for (auto &i: v)
   {
      i = rand() %50;
      std::cout << "i: " << i << '\n';
   }
   int k = findKthLargest_1(v, v.size());
   std::cout << "kth largest number is: " << k << '\n';
   return 0;
}
