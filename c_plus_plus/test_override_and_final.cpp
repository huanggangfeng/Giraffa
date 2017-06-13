
#if 0
final
C++11 also adds the ability to prevent inheriting from classes or simply preventing overriding methods in derived classes. This is done with the special identifier final. For example:

// no class can be derived from class A
class A final
{
    virtual void f(int);
};

class B
{
    // no class can override f()
    virtual void f() final; 
};
So, if we do the following, the compiler gives us errors:

class C : public A {};  // Error

class D : public B      // Error
{
    virtual void f();
};
Note that override and final are not language keywords. They are technically identifiers for declarator attributes.

#endif 

test_override_and_final.cpp