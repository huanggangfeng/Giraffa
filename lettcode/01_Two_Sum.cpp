#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> v;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            for (std::vector<int>::iterator j = i + 1; i != nums.end(); ++i)
            {
                if (*i + *j == target)
                {
                    v.push_back(std::distance(nums.begin(), i));
                    v.push_back(std::distance(nums.begin(), j));
                    return v;
                }
            }   
        }
    }
};

int main()
{
    Solution test;
    int tmp[] = {1,2,4};
    std::vector<int> test_input(tmp, tmp + 3);
    std::vector<int> ret;

    ret = test.twoSum(test_input, 6);

    for (std::vector<int>::iterator i = ret.begin(); i != ret.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}


