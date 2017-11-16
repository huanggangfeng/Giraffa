// Pointers to functions and pointers to member functions are not subject to
//const_cast const_cast is safe only if you're casting a variable that was
// originally non-const, the original variable was in fact const, then using
// const_cast will result in undefined behavior.


//dynamic_cast 主要用于执行“安全的向下转型（safe downcasting）”，也就是说，要确定一个对象
// 是否是一个继承体系中的一个特定类型。
// 它是唯一不能用旧风格语法执行的强制转型，也是唯一可能有重大运行时代价的强制转型。

//static_cast 可以被用于强制隐型转换（例如，non-const 对象转型为 const 对象，int 转型为 double，等等），
// 它还可以用于很多这样的转换的反向转换（例如，void* 指针转型为有类型指针，基类指针转型为派生类指针），
// 但是它不能将一个 const 对象转型为 non-const 对象（只有 const_cast 能做到），它最接近于C-style的转换。

// const_cast 一般用于强制消除对象的常量性。它是唯一能做到这一点的 C++ 风格的强制转型。

// reinterpret_cast 是特意用于底层的强制转型，导致实现依赖（implementation-dependent）（就是说，不可移植）的结果，例如，将一个指针转型为一个整数。
// 这样的强制转型在底层代码以外应该极为罕见。

// static_cast performs implicit conversions, the reverses of implicit standard conversions, and (possibly unsafe) base to derived conversions.
// reinterpret_cast converts one pointer to another without changing the address, or converts between pointers and their numerical (integer) values.
// const_cast only changes cv-qualification; all other casts cannot cast away constness.
// dynamic_cast casts up and down class hierarchies only, always checking that the conversion requested is valid.


#include<iostream>

using namespace std;

class A {
public:
   A () {std::cout << "Create A" << '\n';}
   virtual ~A () {std::cout << "Destroy A" << '\n';}
};

class B : public A {
private:
   /* data */

public:
   B ()  {std::cout << "Create B" << '\n';}
   virtual ~B () {std::cout << "Destroy B" << '\n';}
};


int main()
{
    int i = 3;
    const int& cref_i = i;
    const_cast<int&>(cref_i) = 4;
    // Result is 5
    cout << "i: " << i << endl;

    const int j = 5;
    const int & cref_j = j;
    const_cast<int &>(cref_j) = 10;
    // The result is 5
    cout << "j: " << j << endl;

    int *pj = const_cast<int *>(&j);
    *pj = 4;
    // The result is 5
    cout << "j: " << j << endl;

    B testb;
    A testa;
    A *a=&testb;
    B *bp = dynamic_cast<B*> (a);
    A *ap = dynamic_cast<A*> (&testb);
    return 0;
}
