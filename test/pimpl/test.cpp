#include <test.h>

class myTest_impl {
public:
   myTest_impl();
   virtual ~myTest_impl() {};
   void private_method()
   {
      cout << "This is the detail of myTest\n";
   }
}

myTest::myTest()
   pimpl(new myTest_impl())
{
}

myTest::public_method()
{
   pimpl->private_method();
}