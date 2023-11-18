#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using std::for_each;
using std::make_pair;
using std::max;
using std::min;
using std::unordered_map;
using std::vector;
int maximum_sum(vector<int> &nums)
{
    unordered_map<int, vector<int>> mp;
    int res = -1;
    for (auto num : nums)
    {
        int temp = num;
        int bit_cnt = 0;
        while (temp)
        {
            bit_cnt += temp % 10;
            temp /= 10;
        }
        mp[bit_cnt].push_back(num);
    }
    for (auto &pair : mp)
    {
        auto& vec = pair.second;
        // std::cout << "key: " << pair.first << " size: " << pair.second.size() << std::endl;
        if (vec.size() > 1)
        {
            int max1 = max(vec[0], vec[1]);
            int max2 = min(vec[0], vec[1]);
            for (int i = 2; i < vec.size(); ++i)
            {
                if (vec[i] > max1)
                {
                    max2 = max1;
                    max1 = vec[i];
                }
                else if (vec[i] > max2)
                {
                    max2 = vec[i];
                }
            }
            std::cout << "key: " << pair.first << ", (max1, max2): (" << max1 << ", " << max2 << ")" << std::endl;
            if (res < max1 + max2)
            {
                res = max1 + max2;
            }
        }
    }
    return res;
}

int main()
{
    // test 01
    {
        vector<int> vec{18, 43, 36, 13, 7};
        int actual = maximum_sum(vec);
        int target = 54;
        assert(actual == target);
    }
    // test 02
    {
        vector<int> vec{243, 205, 369, 253, 72, 484, 300, 161, 188, 69, 309, 96, 226, 308, 252};
        int actual = maximum_sum(vec);
        int target = 495;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}