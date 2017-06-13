#include <map>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    std::map<string, int> mymap;

    mymap.insert(std::pair<string,int>("tete", 1));
    mymap.insert(std::pair<string,int>("hhhe", 2));

    std::map<std::string, int>::iterator it = mymap.begin();
    for (; it != mymap.end(); ++it)
    {
        std::cout << it->first << '\t'<< it->second << '\n';        
    }

    return 0;
}

