// This constant value is used as an argument for operator new and operator new[]
// to indicate that these functions shall not throw an exception on failure, but
// return a null pointer instead.

// By default, when the new operator is used to attempt to allocate memory and
// the handling function is unable to do so, a bad_alloc exception is thrown.
// But when nothrow is used as argument for new, it returns a null pointer instead.

#include <iostream>

using namespace std;

class test_RAII {
private:
   int *res;
   int m_size;

public:
   test_RAII (int n)
   : m_size(n)
   {
      res = new int[n];
      for(int i = 0; i < n; ++i)
         res[i] = i;
   }

   virtual ~test_RAII ()
   {
      std::cout << "delete res is called" << '\n';
      delete [] res;
   }

   int operator [](int n)
   {
      if (n < 0 || n >= m_size)
         return 0;
      else
         return res[n];
   }
};

int main(int argc, char const *argv[]) {
   test_RAII test(5);
   int ret = test[4];
   std::cout << "ret is: " << ret << '\n';
   return 0;
}
