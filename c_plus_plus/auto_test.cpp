#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    std::map<std::string, std::vector<int>> map;
    std::vector<int> v;
    for(int i = 0; i < 5; ++i)
    {
        v.push_back(i);
    }
    map["one"] = v;


    for (const auto& test : map)
    {
        std::cout << test.first << std::endl;
        for (auto v: test.second)
        {
            std::cout << v << std::endl;
        }
    }

    for (int &a : v)
    {
        a = a*a;
        std::cout << a << endl;
    }

    for (int a : v)
    {
        std::cout << a << endl;
    }
    return 0;
}
