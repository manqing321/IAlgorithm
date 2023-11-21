#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int min_deletion(vector<int> &nums)
{
    int del = 0;
    bool flag = true;
    for (int i = 0; i < nums.size(); i++)
    {
        if (flag)
        {
            if (i == nums.size() - 1 || nums[i] == nums[i + 1])
            {
                del += 1;
                continue;
            }
        }
        flag = !flag;
    }
    return del;
}

int main()
{
    // test 01
    {
        vector<int> vec{1, 1, 2, 3, 5};
        int actual = min_deletion(vec);
        int target = 1;
        assert(actual == target);
    }
    // test 02
    {
        vector<int> vec{1, 1, 2, 2, 3, 3};
        int actual = min_deletion(vec);
        int target = 2;
        assert(actual == target);
    }
    cout << "finish\n";
}