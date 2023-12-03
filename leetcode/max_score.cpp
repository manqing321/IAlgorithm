#include <iostream>
#include <cassert>
#include <vector>
using std::vector;

int max_score(vector<int> &card_points, int k);

int main()
{
    // test01
    {
        vector<int> vec{1, 2, 3, 4, 5, 6, 1};
        int k = 3;
        int actual = max_score(vec, k);
        int target = 12;
        assert(actual == target);
    }
    // test02
    {
        vector<int> vec{2, 2, 2};
        int k = 2;
        int actual = max_score(vec, k);
        int target = 4;
        assert(actual == target);
    }
    // test03
    {
        vector<int> vec{9, 7, 7, 9, 7, 7, 9};
        int k = 7;
        int actual = max_score(vec, k);
        int target = 55;
        assert(actual == target);
    }
    // test04
    {
        vector<int> vec{1, 1000, 1};
        int k = 1;
        int actual = max_score(vec, k);
        int target = 1;
        assert(actual == target);
    }
    // test05
    {
        vector<int> vec{1, 79, 80, 1, 1, 1, 200, 1};
        int k = 3;
        int actual = max_score(vec, k);
        int target = 202;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}

int max_score(vector<int> &card_points, int k)
{
    vector<int> &sums = card_points;
    for (int i = 0; i < sums.size(); ++i)
    {
        if (i)
        {
            sums[i] += sums[i - 1];
        }
    }
    if (sums.size() == k)
    {
        return sums.back();
    }
    int remainder = sums.size() - k;
    int min = sums[remainder - 1];
    for (int i = 1; i + remainder - 1 < sums.size(); i++)
    {
        int left = i - 1;
        int right = i + remainder - 1;
        int diff = sums[right] - sums[left];
        if (diff < min)
        {
            min = diff;
        }
    }
    return sums.back() - min;
}
