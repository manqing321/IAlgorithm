#include <iostream>
#include <vector>
#include <assert.h>
using std::vector;
int max_diff(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        return 0;
    }
    int min = vec[0];
    int res = vec[1] - vec[0];
    for (size_t i = 2; i < vec.size(); i++)
    {
        if (vec[i - 1] < min)
        {
            min = vec[i - 1];
        }
        if (vec[i] - min > res)
        {
            res = vec[i] - min;
        }
    }
    return res;
}

int main()
{
    // test 1
    {
        vector<int> vec{9, 11, 8, 5, 7, 12, 16, 14};
        int actual = max_diff(vec);
        int target = 11;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}