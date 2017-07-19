#include "myclass.h"
#include <iostream>

class MyclassImpl {
public:
   void private_method()
   {
      std::cout << "MyclassImpl private_method is called" << '\n';
   }
   int private_value;

   MyclassImpl()
   {
      std::cout << "MyclassImpl constructor" << '\n';
   };
   ~MyclassImpl() {
      std::cout << "MyclassImpl destructor" << '\n';
   };
};

Myclass::Myclass()
   : pimpl(new MyclassImpl())
{
}

Myclass::~Myclass()
{
   //delete pimpl;
}

void Myclass::public_method()
{
   pimpl->private_method();
   pimpl->private_value = 3;
}
