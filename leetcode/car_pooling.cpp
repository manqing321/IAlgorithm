#include <iostream>
#include <vector>
#include <cassert>
using std::vector;

bool car_pooling(vector<vector<int>> &trips, int capacity);

int main()
{
    // test 01
    {
        vector<vector<int>> trips{{2, 1, 5}, {3, 3, 7}};
        int capacity = 4;
        bool target = false;
        bool actual = car_pooling(trips, capacity);
        assert(actual == target);
    }
    // test 02
    {
        vector<vector<int>> trips{{2, 1, 5}, {3, 3, 7}};
        int capacity = 5;
        bool target = true;
        bool actual = car_pooling(trips, capacity);
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}

bool car_pooling(vector<vector<int>> &trips, int capacity)
{
    vector<int> nums(1001, 0);
    for (const auto &vec : trips)
    {
        int passengers_num = vec[0];
        int from = vec[1];
        int to = vec[2];
        nums[from] += passengers_num;
        nums[to] -= passengers_num;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i)
        {
            nums[i] += nums[i - 1];
        }
        if (nums[i] < 0 || nums[i] > capacity)
        {
            return false;
        }
    }
    return true;
}