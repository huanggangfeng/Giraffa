#include <iostream>
#include <new>
using namespace std;

class A
{
public:
	virtual ~A()
	{std::cout << "~A()" << std::endl;}
	void test(){;};
};

class B: public A
{
public:
	~B() {std::cout << "B~()" << std::endl;}
	void test() {std::cout << "test" << std::endl;}
};

int main(int argc, char const *argv[])
{
	A* p = new B;
	p->test();
	delete p;
	return 0;
}