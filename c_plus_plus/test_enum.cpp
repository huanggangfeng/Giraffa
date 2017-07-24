#include <iostream>

class testEnum {
private:
public:
   testEnum ();
   virtual ~testEnum ();
   enum {
      type_A,
      type_B,
      type_C
   };
};

int main()
 {
    int input1;
    std::cin >> input1;
    if (input1 == testEnum::type_B)
      std::cout << "input1 equal to type_B" << '\n';
    else
      std::cout << "input1 not equal to type_B, input1 is:" << input1
      << " type_A:" << testEnum::type_B << '\n';
    return 0;
}
