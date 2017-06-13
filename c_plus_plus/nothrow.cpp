// This constant value is used as an argument for operator new and operator new[]
// to indicate that these functions shall not throw an exception on failure, but
// return a null pointer instead.

// By default, when the new operator is used to attempt to allocate memory and
// the handling function is unable to do so, a bad_alloc exception is thrown.
// But when nothrow is used as argument for new, it returns a null pointer instead.



// noexcept operator (since C++11)
// C++  C++ language  Exceptions 
// The noexcept operator performs a compile-time check that returns true if an expression is declared to not throw any exceptions.
// It can be used within a function template's noexcept specifier to declare that the function will throw exceptions for some types but not others.


#include <iostream>
#include <utility>
#include <vector>
 
void may_throw();
void no_throw() noexcept;
auto lmay_throw = []{};
auto lno_throw = []() noexcept {};
class T{
public:
  ~T(){} // dtor prevents move ctor
         // copy ctor is noexcept
};
class U{
public:
  ~U(){} // dtor prevents move ctor
         // copy ctor is noexcept(false)
  std::vector<int> v;
};
class V{
public:
  std::vector<int> v;
};
 
int main()
{
 T t;
 U u;
 V v;
 
 std::cout << std::boolalpha
           << "Is may_throw() noexcept? " << noexcept(may_throw()) << '\n'
           << "Is no_throw() noexcept? " << noexcept(no_throw()) << '\n'
           << "Is lmay_throw() noexcept? " << noexcept(lmay_throw()) << '\n'
           << "Is lno_throw() noexcept? " << noexcept(lno_throw()) << '\n'
           << "Is ~T() noexcept? " << noexcept(std::declval<T>().~T()) << '\n'
           // note: the following tests also require that ~T() is noexcept because
           // the expression within noexcept constructs and destroys a temporary
           << "Is T(rvalue T) noexcept? " << noexcept(T(std::declval<T>())) << '\n'
           << "Is T(lvalue T) noexcept? " << noexcept(T(t)) << '\n'
           << "Is U(rvalue U) noexcept? " << noexcept(U(std::declval<U>())) << '\n'
           << "Is U(lvalue U) noexcept? " << noexcept(U(u)) << '\n'  
           << "Is V(rvalue V) noexcept? " << noexcept(V(std::declval<V>())) << '\n'
           << "Is V(lvalue V) noexcept? " << noexcept(V(v)) << '\n';  
}
