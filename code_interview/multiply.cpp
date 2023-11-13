#include <iostream>
#include <assert.h>
#include <vector>
using std::vector;
void multiply(const vector<int> &nums, vector<int> &res)
{
    res[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int temp = 1;
    for (int i = res.size() - 2; i >= 0; i--)
    {
        temp *= nums[i + 1];
        res[i] *= temp;
    }
}
int main()
{
    vector<int> vec{1, 3, 5, 7, 9};
    vector<int> actual(5, 0);
    multiply(vec, actual);
    vector<int> target{3 * 5 * 7 * 9, 1 * 5 * 7 * 9, 1 * 3 * 7 * 9, 1 * 3 * 5 * 9, 1 * 3 * 5 * 7};
    assert(actual == target);
    std::cout << "finish\n";
}
