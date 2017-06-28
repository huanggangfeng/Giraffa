#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
    int noshow = l1.size() + l2.size();  // use sum of size as a punishment for missing in either list;
    map<string, int> punish;
    for (int i = 0; i < l1.size(); i++)
    {
        punish[l1[i]] = i - noshow; // unpunish 1 * noshow for showing up at least in l1
        std::cout << l1[i] << " "<<i- noshow << std::endl;
    }

    std::cout << "........................." << std::endl;
    for (int j = 0; j < l2.size(); j++)
    {
        punish[l2[j]] += j - noshow;// unpunish 1 * noshow for showing up at least in l2
        std::cout << l2[j] << " "<<j- noshow << std::endl;
    }
    std::cout << "........................." << std::endl;
    for (auto p: punish)
        std::cout << p.second << " "<< p.first << std::endl;
    std::cout << "........................." << std::endl;
    map<int, vector<string>> rank;
    std::cout << "p.second" << " "<< "p.first" << std::endl;
    for (auto p : punish)
    {
        std::cout << p.second << " "<< p.first << std::endl;
        rank[p.second].push_back(p.first);
    }

    return rank.begin()->second;
}


int main()
{
    // std::map<string, int> mymap;

    // mymap.insert(std::pair<string,int>("tete", 1));
    // mymap.insert(std::pair<string,int>("hhhe", 2));

    // std::map<std::string, int>::iterator it = mymap.begin();
    // for (; it != mymap.end(); ++it)
    // {
    //     std::cout << it->first << '\t'<< it->second << '\n';        
    // }

    std::vector<string> v1 = {"hhhhh", "zgangfeng", "test"};
    std::vector<string> v2 = {"tsn", "zgangfeng", "test"};
    std::vector<string> v = findRestaurant(v1, v2);
    std::cout << v.size() << endl;
    for (auto vi: v)
    {
        std::cout << vi << std::endl;
    }
    return 0;
}



