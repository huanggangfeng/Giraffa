#include <set>
#include <iostream>

int main()
{
    std::set<int> myset;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator, bool> ret;

    for(int i=0; i< 10;i++)
    {
        myset.insert(i);
    }
    // for(int i=0; i< 10;i++)
    // {
    //     myset.insert(i);
    // }
    ret = myset.insert(5);

    std::cout << "set Size:" << myset.size() << '\n';
    std::cout << "ret.first: " << *ret.first << " ret.second :"
              << ret.second << std::endl;
    for(it=myset.begin(); it!=myset.end();++it)
    {
        std::cout<< *it << std::endl;
    }
    std::cout<< *it << '\n';
    return 0;
}
