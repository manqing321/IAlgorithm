#include <iostream>
#include <assert.h>
#include <vector>
#include <deque>
using std::cout;
using std::deque;
using std::endl;
using std::vector;
vector<int> max_in_window(const vector<int> &nums, unsigned int k)
{
    vector<int> res;
    if (k >= 1 && nums.size() >= k)
    {
        deque<int> index;
        for (int i = 0; i < k; i++)
        {
            while (!index.empty() && nums[i] >= nums[index.back()])
            {
                index.pop_back();
            }
            index.push_back(i);
        }
        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[index.front()]);
            while (!index.empty() && nums[i] >= nums[index.back()])
            {
                index.pop_back();
            }
            if (!index.empty() && index.front() <= i - k)
            {
                index.pop_front();
            }
            index.push_back(i);
        }
        res.push_back(nums[index.front()]);
    }
    return res;
}

int main()
{
    vector<int> num{2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> actual = max_in_window(num, 3);
    vector<int> target = {4, 4, 6, 6, 6, 5};
    assert(actual == target);

    cout << "finish" << endl;
}