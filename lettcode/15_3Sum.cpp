// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note: The solution set must not contain duplicate triplets.
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
void three_sum(std::vector<int> v)
{
   std::vector<int> tmp = v;
   std::sort(tmp.begin(), tmp.end());
   // unique(tmp.begin(), tmp.end());
   // for (auto i: tmp)
   //    std::cout << "i*" << i << '\n';

   tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
   for (auto i: tmp)
      std::cout << "i:" << i << '\n';
}

int main(int argc, char const *argv[]) {
   std::vector<int> v = {1,2,3,4,5,2,1,5,6};
   three_sum(v);
   return 0;
}
