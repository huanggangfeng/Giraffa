#include <iostream>
#include <vector>
#include <string>

class Widget {
public:
   Widget () {};
   virtual ~Widget ()
   {
      m_names.clear();
   }

   template<typename T>
   void addName(T&& newName) {
      m_names.push_back(std::forward<T>(newName));
   }

   void print_name()
   {
      for(auto i:m_names)
         std::cout << i << '\n';
   }
private:
   std::vector<std::string> m_names;
};

int main(int argc, char const *argv[]) {
   std::string name("Gangfeng");
   Widget w;
   w.addName(name);
   w.addName(name + "Huang");
   w.print_name();
   return 0;
}
