#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

#include <memory>

class MyclassImpl;
class Myclass {
public:
   Myclass ();
   virtual ~Myclass ();
   Myclass(const Myclass &rhs);
   Myclass &operator =(Myclass);
   void public_method();

private:
   std::shared_ptr<MyclassImpl> pimpl;
};

#endif
