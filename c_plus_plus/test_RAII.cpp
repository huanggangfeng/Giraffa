// This constant value is used as an argument for operator new and operator new[]
// to indicate that these functions shall not throw an exception on failure, but
// return a null pointer instead.

// By default, when the new operator is used to attempt to allocate memory and
// the handling function is unable to do so, a bad_alloc exception is thrown.
// But when nothrow is used as argument for new, it returns a null pointer instead.

#include <iostream>

using namespace std;

class test_resource
{
public:
    test_resource();
    ~test_resource();
private:
};

test_resource::test_resource()
{

}

int main()
{

    return 0;
}