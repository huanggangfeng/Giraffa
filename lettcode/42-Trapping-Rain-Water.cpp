// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
// In this case, 6 units of rain water (blue section) are being trapped.
// Thanks Marcos for contributing this image!
#include <vector>
#include <iostream>
using namespace std;

int trap(vector<int>& A) {
   int n = A.size();
   int left=0; int right=n-1;
   int res=0;
   int maxleft=0, maxright=0;
   while(left<=right){
       if(A[left]<=A[right]){
           if(A[left]>=maxleft) maxleft=A[left];
           else res+=maxleft-A[left];
           left++;
       }
       else{
           if(A[right]>=maxright) maxright= A[right];
           else res+=maxright-A[right];
           right--;
       }
   }
   return res;
}

int main(int argc, char const *argv[]) {
   std::vector<int> v = {0,1,0,2,0,1,3,2,1,2,1};
   int water_trap = trap(v);
   std::cout << "water_trap is : " << water_trap << '\n';
   return 0;
}
