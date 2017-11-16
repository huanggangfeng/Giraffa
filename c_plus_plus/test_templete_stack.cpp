#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
   public:
      virtual ~Stack () {};
      void push(const T &);
      T top() const;
      void pop();
      bool is_empty() {
         return m_elements.empty();
      }
      int size() const {
         return m_elements.size();
      }
      T operator =(const T value)
      {
         T temp = value;
         return temp;
      }
private:
   std::vector<T> m_elements;
};

template <typename T>
void Stack<T>::push(const T &elem)
{
   m_elements.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
   m_elements.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
   if (m_elements.empty()) {
      throw out_of_range("stack is empty");
   }
   else {
      return m_elements.back();
   }
}

int main(int argc, char const *argv[]) {
   Stack<int> s;
   s.push(10);
   s.push(15);
   int x = s.top();
   s.pop();
   std::cout << "size:" << s.size() << '\n';
   return 0;
}
