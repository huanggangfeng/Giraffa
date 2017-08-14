#include <iostream>
#include <map>
#include <utility>
#include <memory>
using namespace std;

class Pizza {
public:
   virtual int getPrice() const = 0;
   virtual ~Pizza () {};
};

class Pizza_A : public Pizza {
public:
   virtual int getPrice() const { return 850; };
   virtual ~Pizza_A () {};
};

class Pizza_B : public Pizza {
public:
   virtual int getPrice() const { return 1050; };
   virtual ~Pizza_B () {};
};

class Pizza_C : public Pizza {
public:
   virtual int getPrice() const { return 1150; };
   virtual ~Pizza_C () {};
};

class PizzaFactory {
public:
   enum PizzaType {
      A,
      B,
      C
   };
   virtual ~PizzaFactory ();
   static shared_ptr<Pizza> createPizza(PizzaType type) {
      switch (type) {
         case A:
         return make_shared<Pizza_A>();
         case B:
         return make_shared<Pizza_B>();
         case C:
         return make_shared<Pizza_C>();
      }
      throw "invalid pizza type.";
   }
};

int getPizzaPrice(PizzaFactory::PizzaType type)
{
   shared_ptr<Pizza> pizza = PizzaFactory::createPizza(type);
   return pizza->getPrice();
}

int main() {
   std::map<PizzaFactory::PizzaType, int> map;
   map.insert(make_pair(PizzaFactory::A, getPizzaPrice(PizzaFactory::A)));
   map.insert(make_pair(PizzaFactory::B, getPizzaPrice(PizzaFactory::B)));
   map.insert(make_pair(PizzaFactory::C, getPizzaPrice(PizzaFactory::C)));

   for (auto &i:map)
      std::cout << "Pizza:" << i.first << " Price: " << i.second << '\n';

   // getPizzaPrice(PizzaFactory::A);
   // getPizzaPrice(PizzaFactory::B);
   // getPizzaPrice(PizzaFactory::C);

   return 0;
}
