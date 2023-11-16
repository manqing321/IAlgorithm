#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using std::max;
using std::vector;
int longest_alternating_subarray(vector<int> &nums, int threshold)
{
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= threshold)
        {
            if (cnt && (nums[i] & 1) ^ (nums[i - 1] & 1))
            {
                cnt++;
                continue;
            }
            res = max(res, cnt);
            cnt = !(nums[i] & 1);
        }
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    return max(res, cnt);
}

int main()
{
    // test 01
    {
        vector<int> vec{3, 2, 5, 4};
        int actual = longest_alternating_subarray(vec, 5);
        int target = 3;
        assert(target == actual);
    }
    std::cout << "finish";
}