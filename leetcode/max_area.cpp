#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int max_area(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int max_h = max(horizontalCuts[0], h - horizontalCuts.back());
    int max_w = max(verticalCuts[0], w - verticalCuts.back());
    for (size_t i = 0; i < horizontalCuts.size() - 1; i++)
    {
        max_h = max(max_h, horizontalCuts[i + 1] - horizontalCuts[i]);
    }
    for (size_t i = 0; i < verticalCuts.size() - 1; i++)
    {
        max_w = max(max_w, verticalCuts[i + 1] - verticalCuts[i]);
    }
    int max_int = 1000000000 + 7;
    return ((long long)max_w * max_h) % max_int;
}

int main()
{
    {
        vector<int> vec1{1, 2, 4};
        vector<int> vec2{1, 3};
        assert(max_area(5, 4, vec1, vec2) == 4);
    }
    {
        vector<int> vec1{3, 1};
        vector<int> vec2{1};
        assert(max_area(5, 4, vec1, vec2) == 6);
    }
    {
        vector<int> vec1{3};
        vector<int> vec2{3};
        assert(max_area(5, 4, vec1, vec2) == 9);
    }
}