// Template Partial Specialization In C++

#include <iostream>
#include <cstring>

using namespace std;
// template <typename T>
// struct is_pointer : std::false_type{};
//
// template <typename T>
// struct is_pointer<T*> : std::true_type{};
//
//
// int main(int argc, char const *argv[]) {
//    // bool is_pointer<int *>;
//
//    return 0;
// }

template <class T, int size>
class StaticArray {
private:
   T m_array[size];

public:
   T* getArray()
   {
      return m_array;
   }
   T& operator[](int index)
   {
      return m_array[index];
   }
};

template <typename T, int size>
void print(StaticArray<T, size> & array)
{
   for (size_t i = 0; i < size; i++) {
      std::cout << array[i] << ' ';
   }
   std::cout << '\n';
}

int main(int argc, char const *argv[]) {
   StaticArray<char, 14>  char14;
   // strcpy_s(char14.getArray(), 14, "Hello, Wrold!");
   strcpy(char14.getArray(), "Hello, Wrold!");
   print(char14);

   StaticArray<int, 10> int10;
   for (size_t i = 0; i < 10; i++) {
      int10[i] = i;
   }

   for (size_t i = 0; i < 10; i++) {
      std::cout << int10[i] << '\n';
   }
   return 0;
}
