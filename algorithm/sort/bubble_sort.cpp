#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
   vector<int> a(10);
   vector<int>::iterator it;
   int temp;

   srand(time(NULL));
   for (it = a.begin(); it!=a.end();it++)
      *it = rand()%100;
   
//   sort(a.begin(), a.end());
   for (int i = 0; i < a.size(); ++i)
   {  
      for (int j = 0; j < a.size() - i - 1; ++j)
      {
         if (a[j] > a[j+1])
         {
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
         }
      }
   }   

   for (it = a.begin(); it!=a.end();it++)
      cout << *it << " ";
   cout << endl;
}
