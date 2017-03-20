#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> foo = std::make_shared<int> (10);
    std::shared_ptr<int> foo2(new int(20));

    auto bar = std::make_shared<int> (30);

    auto bar2 = std::make_shared<std::pair<int, int>> (40, 50);

    std::cout << "foo: "  << *foo << std::endl;
    std::cout << "foo2: "  <<  *foo2 << std::endl;
    std::cout << "bar: "  << *bar << std::endl;
    std::cout << "bar2: " << bar2->first << " " << bar2->second << std::endl;
    return 0;
}