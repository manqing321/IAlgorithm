#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
using namespace std;

template <typename T>
bool is_equal(const vector<T> &lhs, const vector<T> &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    auto liter = lhs.cbegin();
    auto riter = rhs.cbegin();
    while (liter != lhs.cend() && riter != rhs.cend())
    {
        if (*liter != *riter)
        {
            return false;
        }
        liter++;
        riter++;
    }
    return true;
}

vector<int> next_greater_element(vector<int> &nums1, vector<int> &nums2)
{
    // map val to index
    map<int, int> mp;
    for (int i = 0; i < nums2.size(); ++i)
    {
        mp[nums2[i]] = i;
    }

    // set next data by monotonic stack
    vector<int> next_data(nums2.size(), -1);
    stack<int> stk;
    for (int i = nums2.size() - 1; i >= 0; --i)
    {
        while (!stk.empty() && stk.top() < nums2[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            next_data[i] = stk.top();
        }
        stk.push(nums2[i]);
    }

    // build result
    vector<int> res;
    for (int i = 0; i < nums1.size(); ++i)
    {
        res.push_back(next_data[mp[nums1[i]]]);
    }
    return res;
}

int main()
{
    // test01
    {
        vector<int> nums1{4, 1, 2};
        vector<int> nums2{1, 3, 4, 2};
        vector<int> actual = next_greater_element(nums1, nums2);
        vector<int> target{-1, 3, -1};
        assert(is_equal(actual, target));
    }
    // test02
    {
        vector<int> nums1{2, 4};
        vector<int> nums2{1, 2, 3, 4};
        vector<int> actual = next_greater_element(nums1, nums2);
        vector<int> target{3, -1};
        assert(is_equal(actual, target));
    }
    cout << "finish" << endl;
}