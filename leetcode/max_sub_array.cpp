#include <iostream>
#include <vector>
#include <assert.h>
using std::vector;
int max_sub_array(vector<int> &nums)
{
    int sum = 0;
    int res = nums[0];
    for (auto &num : nums)
    {
        sum += num;
        if (res < sum)
        {
            res = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return res;
}

int main()
{
    // test 01
    {
        vector<int> source = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int actual = max_sub_array(source);
        int target = 6;
        assert(actual == target);
    }
    std::cout << "finish\n";
}