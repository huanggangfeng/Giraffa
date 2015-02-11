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

   srand(time(NULL));
   for (it = a.begin(); it!=a.end();it++)
      *it = rand()%100;
   
   sort(a.begin(), a.end());
   
   for (it = a.begin(); it!=a.end();it++)
      cout << *it << " ";
   cout << endl;
}
