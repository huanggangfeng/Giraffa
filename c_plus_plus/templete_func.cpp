#include <iostream>
#include <string>

using namespace std;
template <typename T>
inline T const& Max(T const &a, T const &b) 
{
	return a > b ? a:b;
}

template <typename T>
inline T const& Min(const T &a, const T &b)
{
    return a > b?  b:a;
}

template <typename T>
T test(const T &a, const T&b)
{
  T c = a+b;
  return c;
}

int main(int argc, char const *argv[])
{
	int i = 39, j = 20;
	cout << "Max(i,j): " << Max(i, j) << std::endl;
    cout << "Min(i,j): " << Min(i, j) << std::endl;
    cout << "test(i,j): " << test(i, j) << std::endl;
	double x = 10.5, y = 40.49;
	cout << "Max(x,y): " << Max(x, y) << std::endl;
    cout << "Min(i,j): " << Min(x, y) << std::endl;
    cout << "test(i,j): " << test(x, y) << std::endl;
	return 0;
}