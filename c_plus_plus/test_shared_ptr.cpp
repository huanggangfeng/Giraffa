#include <memory>
#include <iostream>

class test_shared_ptr {
private:
   int m_x;

public:
   test_shared_ptr (int x) : m_x(x) {
      std::cout << "constructor of class with:" << m_x << '\n';
   }
   virtual ~test_shared_ptr ()
   {
      std::cout << "destructor of class" << '\n';
   }
   void set_x(int x)
   {
      m_x = x;
   }

   int get_x()
   {
      std::cout << "m_x is:" << m_x << '\n';
      return m_x;
   }
};

int main(int argc, char const *argv[]) {
   std::shared_ptr<test_shared_ptr> pShared(new test_shared_ptr(5));
   pShared->set_x(100);
   int ret = pShared->get_x();
   pShared->get_x();
   return 0;
}
