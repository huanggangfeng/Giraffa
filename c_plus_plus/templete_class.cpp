#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;
template <class T>
class Stack
{
	public:
	void push(T const &);
	void pop();
	T top() const;
	bool empty() const
	{
		return elems.empty();
	}

	private:
		std::vector<T> elems;
};

template <class T>
void Stack<T>::push(T const & elem)
{
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw out_of_range("stack is empty");
	}
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw out_of_range("stack is empty");
	}
	return elems.back();
}


int main(int argc, char const *argv[])
{
	try
	{
		Stack<int> intStack;
		Stack<string> stringStack;

		for (int i = 0; i < 10; ++i)
		{
			intStack.push(100*i);
		}

		stringStack.push("hello");
		stringStack.push("world");
		cout << intStack.top() << endl;
		intStack.pop();
		cout << stringStack.top() << endl;
		intStack.pop();
		intStack.pop();
		intStack.pop();
		cout << intStack.top() << endl;
	} catch(exception const &ex)
	{
		cerr << "Exception :" << ex.what() << std::endl;
	}

	return 0;
}
