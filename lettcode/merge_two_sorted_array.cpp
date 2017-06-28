#include <vector>
#include <iostream>

using namespace std;
std::vector<int> merge_array(vector<int>& nums1, vector<int>& nums2)
{
    std::vector<int> v;
    std::vector<int>::iterator it1, it2, it3;
    it1 = nums1.begin();
    it2 = nums2.begin(); 

    while(it1 != nums1.end() || it2 != nums2.end())
    {
        if (it1 == nums1.end())
        {
            v.insert(v.end(), it2, nums2.end());
            // it2 = nums2.end();
            break;
        }

        if (it2 == nums2.end())
        {
            v.insert(v.end(), it1, nums1.end());
            // it1 = nums1.end();
            break;
        }

        if (*it1 < *it2)
        {
            v.push_back(*it1);
            // cout << *it1<< endl;
            it1 ++;
        }
        else if (*it1 > *it2)
        {
            v.push_back(*it2);
            // cout << *it2<< endl;
            it2 ++;
        }
        else if (*it1 == *it2)
        {
            v.push_back(*it1);
            v.push_back(*it2);
            // cout << *it1 << " " << *it2 << endl;
            it1++;
            it2++;
        }
    }
    return v;
}
int main()
{
    std::vector<int> nums1 = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> nums2 = {2, 4, 6};
    std::vector<int> v = merge_array(nums1, nums2);
    cout << "size of nums1:" << nums1.size() << endl;
    cout << "size of nums2:" << nums2.size() << endl;
    cout << "size of merged:" << v.size() << endl;

    for (int value : v)
    {
        cout << " " <<  value;
        value = 0;
    }
    cout << endl;
    return 0;
}