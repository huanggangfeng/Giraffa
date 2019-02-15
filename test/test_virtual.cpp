#include <memory>
#include <string>
#include <iostream>

using namespace std;

class base {
private:
	std::string buf;
public:
	base () {};
	virtual ~base () {};
  virtual void print_buff()
	{
		std::cout << "hello base" << '\n';
	}
};

class test1 : public base {
private:
	/* data */

public:
	test1 () {};
	virtual ~test1 () {};
	void print_buff() {
		std::cout << "hello test1" << '\n';
	}
};


int main(int argc, char const *argv[]) {
	std::shared_ptr<base> pBase(new test1);
	pBase->print_buff();
	pBase->base::print_buff();
	return 0;
}
