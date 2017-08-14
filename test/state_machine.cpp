#include <iostream>

enum name : int
{
   kWaitInput = 0,
   kIsOdd = 1,
   kIsEven = 2,
   kStop = 3
};

int state_machine() {
   int state = kWaitInput;
   do {
      int input;
      switch (state) {
         case kWaitInput:
            std::cout << "Input a num:";
            std::cin >> input;
            if (input == -1) {
               state = kStop;
               break;
            }
            if (input % 2 == 0)
               state = kIsEven;
            else
               state = kIsOdd;
            break;
         case kIsOdd:
            std::cout << input << " isOdd" << '\n';
            state = kWaitInput;
            break;
         case kIsEven:
            std::cout << input <<" isEven" << '\n';
            state = kWaitInput;
            break;
         case kStop:
            std::cout << "Stop state machine" << '\n';
            return 1;
      }
   } while(1);

}
int main(int argc, char const *argv[]) {
   int ret = state_machine();
   std::cout << "ret:" << ret << '\n';
   return 0;
}
