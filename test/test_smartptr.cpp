#include <iostream>

class Ref_Count {
private:
	int count;
public:
	void add_ref() {count++;}
	int release() {return --count;}
};

template<class T>
class SmartPtr {
private:
	T *ptr;
	Ref_Count *ref;
	// int ref_count;
public:
	//default construtor
	SmartPtr() {
		ref = new Ref_Count;
		ref->add_ref();
	}
	// construtor
	SmartPtr (T *p = NULL){
		ref = new Ref_Count;
		ref->add_ref();
		ptr  = p;
	}

	// Copy construtor
	SmartPtr(const SmartPtr<T> &sp) :
		ptr(sp.ptr), ref(sp.ref)
	{
			ref->add_ref();
	}

	virtual ~SmartPtr () {
		// ref_count--;
		if (ref->release() == 0) {
				delete(ptr);
				delete(ref);
		}
		std::cout << "delete SmartPtr" << '\n';
	}

	T &operator *() { return *ptr;}
	T *operator ->() {return ptr;}
	SmartPtr<T> & operator = (const SmartPtr<T> &sp) {
		if (this != &sp) {
			if(ref->release() == 0) {
				delete ptr;
				delete ref;
			}
			ptr = sp.ptr;
			ref = sp.ref;
			ref->add_ref();
		}
		return *this;
	}
};

int main(int argc, char const *argv[]) {
	SmartPtr<int> ptr(new int());
	*ptr = 20;
	std::cout << "Value:" << *ptr << '\n';

	// SmartPtr<Test> p_test(new Test(5));
	// std::cout << "Test value:" << p_test->get_value() << '\n';
 	return 0;
}
