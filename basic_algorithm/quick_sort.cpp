#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::for_each;
using std::vector;
inline auto swap(vector<int> &vec, size_t first, size_t second)
{
    int temp = vec[first];
    vec[first] = vec[second];
    vec[second] = temp;
}

inline size_t partional(vector<int> &vec, size_t beg, size_t end)
{
    // 随机选取一个下标
    int mid = beg + ((end - beg) >> 1);
    int val = vec[mid];
    swap(vec, mid, end);
    
    // 左右两边对半分
    int small = beg - 1;
    for (size_t i = beg; i < end; i++)
    {
        if (vec[i] < val)
        {
            small++;
            if (small != i)
            {
                swap(vec, small, i);
            }
        }
    }
    small++;
    swap(vec, small, end);
    return small;
}

inline auto quick_sort_core(vector<int> &vec, int beg, int end)
{
    if (beg == end)
    {
        return;
    }
    int index = partional(vec, beg, end);
    if (index > beg)
    {
        quick_sort_core(vec, beg, index - 1);
    }
    if (index < end)
    {
        quick_sort_core(vec, index + 1, end);
    }
}

inline auto quick_sort(vector<int> &vec)
{
    quick_sort_core(vec, 0, vec.size() - 1);
}

int main()
{
    vector<int> vec{1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    cout << "origin:  \t";
    auto print_func = [](int &num)
    { cout << num << ", "; };
    for_each(vec.begin(), vec.end(), print_func);
    cout << endl;

    quick_sort(vec);

    cout << "after sort:\t";
    for_each(vec.begin(), vec.end(), print_func);
    cout << endl;
}