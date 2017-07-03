#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
    // use sum of size as a punishment for missing in either list;
    int noshow = l1.size() + l2.size();
    map<string, int> punish;
    for (int i = 0; i < l1.size(); i++)
    {
        punish[l1[i]] = i - noshow;
    }

    for (int j = 0; j < l2.size(); j++)
        punish[l2[j]] += j - noshow;

    map<int, vector<string>> rank;
    for (auto p : punish)
    {
        rank[p.second].push_back(p.first);
    }
    return rank.begin()->second;
}

int main()
{
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
