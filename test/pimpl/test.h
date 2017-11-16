#include <memory>

class myTest_impl;
class myTest {
public:
   myTest();
   virtual ~myTest() {};
   myTest &operator =(myTest);
   void public_method();
private:
   std::unique_ptr<myTest_impl> pimpl;
};


