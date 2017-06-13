// The purpose of decltype is to provide a standardized version of typeof. Since the result is not identical to the existing compiler extension typeof (and there were probably conflicting versions out there, I'm not sure), the term typeof could not be used. Instead, the previously unused term decltype was chosen. So in C++11, we can now write
// template<typename T, typename S>
// void foo(T lhs, S rhs) {
//   typedef decltype(lhs * rhs) product_type;
//   //...
// }

#include <iostream>

// returns prvalue: plain auto never deduces to a reference
template < typename T > auto foo( T& t ) { return t.value() ; }

// return lvalue: auto& always deduces to a reference
template < typename T > auto& bar( T& t ) { return t.value() ; }

// return prvalue if t.value() is an rvalue
// return lvalue if t.value is an lvalue
// decltype(auto) has decltype semantics (without having to repeat the expression).
template < typename T > decltype(auto) foobar( T& t ) { return t.value() ; }

int main()
{
   struct A { int i = 0 ; int& value() { return i ; } } a;
   struct B { int i = 0 ; int value() { return i ; } } b;

   foo(a) = 20 ; // *** error: expression evaluates to prvalue of type int
   foo(b) ; // fine: expression evaluates to prvalue of type int

   bar(a) = 20 ; // fine: expression evaluates to lvalue of type int
   bar(b) ; // *** error: auto& always deduces to a reference

   foobar(a) = 20 ; // fine: expression evaluates to lvalue of type int
   foobar(b) ; // fine: expression evaluates to prvalue of type int
}