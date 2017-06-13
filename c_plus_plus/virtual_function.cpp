#include <iostream>
#include <string>
#include <memory>
// #include <class>

using namespace std;
// override final

class A
{
public:
    A() { cout << "create A" << endl;}
    virtual ~A() {cout << "delete A" << endl;}
    virtual void f() { cout << "A()::f()" << endl; };
    
};

class B : public A
{
public:
    B() { cout << "Create B" << endl;}
    virtual ~B() {cout << "delete B" << endl;}
     void f() { cout << "B()::f()" << endl; };
};

class C : public B
{
public:
    C() { cout << "Create C" << endl;}
    virtual ~C() {cout << "delete C" << endl;};
    void f() { cout << "C()::f()" << endl; };
};

int main()
{
    // A *Ap = new A();
    // Ap->f();
    std::unique_ptr<A> Bp(new C());
    Bp->f();
	return 0;
}