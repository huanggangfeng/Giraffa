// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the
// array, and it should return false if every element is distinct.

#include <vector>
#include <set>
#include <iostream>
#include <ctime>

bool containsDuplicate(std::vector<int>& nums)
{
   // std::set<int> mySet(nums.begin(), nums.end());
   // std::cout << "set Size:" << mySet.size() << '\n';
   // std::cout << "vector Size:" << nums.size() << '\n';
   // return (mySet.size() < nums.size());

   return std::set<int>(nums.begin(), nums.end()).size() > nums.size();
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

   if (containsDuplicate(v))
      std::cout << "Contains duplicates" << '\n';
   else
      std::cout << "Do not contains duplicates" << '\n';

   return 0;
}
