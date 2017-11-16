// If your define the copy-construction function， you had better to define the
// default construction function.
// Actually, we should use copy constructor function and assignment operator as a
// same unit. if you need one of them, you also need another one.
// If you need to define the destructor, you also need to define the copy
// constructor and operator. this is call the rule of three
//
// short-circuit evaluation if not supported in operator overwrite
// If you want to define the operator as non-member function, add keyword friend
// for it.
//
// If you re-define the operator as non-member function, you must add the word "friend" for it.

const vs mutable

//
// What is the need of mutable?
// Sometimes there is requirement to modify one or more data members of class / struct through const function even though you don’t want the function to update other members of class / struct. This task can be easily performed by using mutable keyword. Consider this example where use of mutable can be useful. Suppose you go to hotel and you give the order to waiter to bring some food dish. After giving order, you suddenly decide to change the order of food. Assume that hotel provides facility to change the ordered food and again take the order of new food within 10 minutes after giving the 1st order. After 10 minutes order can’t be cancelled and old order can’t be replaced by new order. See the following code for details.
