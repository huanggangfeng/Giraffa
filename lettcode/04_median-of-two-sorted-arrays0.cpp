#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

std::vector<int> v1;
std::vector<int> v2;

void print_vector()
{
    for (auto i:v1)
        std::cout << " " << i;
    std::cout << '\n';

    for (auto i:v2)
        std::cout << " " << i;
    std::cout << '\n';
}

void get_median()
{
    auto pos1  = v1.begin();
    auto pos2 = v2.begin();
    int half_num = (v1.size() + v2.size()) / 2;
    int steps = 0;
    std::vector<int>::iterator current_it;
    int value1, value2;
    for (size_t i = 0; i <= half_num; i++) {
        if (pos1 == v1.end())
        {
            ++pos2;
        }
        else if (pos2 == v2.end())
        {
            ++pos1;
        }
        else {
            if(*pos1 < *pos2)
                ++pos1;
            else
                ++pos2;
        }

        if ((i+2) == half_num)
            value2 = std::min(*pos1, *pos2);
        if (i == half_num)
            value1 = std::min(*pos1, *pos2);
    }
    std::cout << "value1:" << value1 << '\n';
    std::cout << "value2:" << value2 << '\n';

    std::cout << "pos1:" << std::distance(v1.begin(), pos1) << '\n';
    std::cout << "pos2:" << std::distance(v2.begin(), pos2) << '\n';
    std::cout << "pos1 value:" <<  *pos1 << '\n';
    std::cout << "pos2:" << *pos2 << '\n';
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    v1.assign(5, 1);
    v2.assign(6, 2);

    // for (auto &i : v1)
    //     i = rand() %10;
    // for (auto &i : v2)
    //     i = rand() %10;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    print_vector();
    get_median();
    return 0;
}
