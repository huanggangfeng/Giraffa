#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const int &a, const int &b)
{
   return a<b;
}

void print_vector(vector<int> &ivec)
{
   vector<int>::iterator it;
   for (it = ivec.begin();it!=ivec.end();it++)
   {
      cout << *it << " "; 
   }
   cout << endl;
}

int main()
{
   std::vector<int> ivec(3, 99);

   cout << "After init:";
   print_vector(ivec);

   ivec.push_back(55);
   ivec.push_back(66);
   cout << "After push back:";
   print_vector(ivec);

   ivec.insert(ivec.begin(), 33);
   ivec.insert(ivec.begin(), 22);
   ivec.insert(ivec.begin()+1, 44);
   cout << "After Insert:";
   print_vector(ivec);

   ivec.pop_back();
   ivec.pop_back();
   cout << "After pop_back:";
   print_vector(ivec);

   sort(ivec.begin(), ivec.end());
   cout << "After sort:";
   print_vector(ivec);

   reverse(ivec.begin(), ivec.end());
   cout << "After reverse:";
   print_vector(ivec);

   sort(ivec.begin(), ivec.end(),comp);
   cout << "After Sort:";
   print_vector(ivec);

   ivec.erase((ivec.begin()+1), ivec.begin()+2);
   cout << "After erase:";
   print_vector(ivec);

}
