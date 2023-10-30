#include <vector>
#include <iostream>
#include <assert.h>
using std::min;
using std::vector;

inline auto is_reference_above_cnt(vector<int> &citations, int index) -> bool
{
    int reference_time = citations[index];
    int pages_cnt = citations.size() - index;
    return reference_time >= pages_cnt;
}

int h_index(vector<int> &citations)
{
    int beg = 0;
    int end = citations.size() - 1;
    while (beg < end)
    {
        int mid = beg + ((end - beg) >> 1);
        if (is_reference_above_cnt(citations, mid))
        {
            end = mid;
        }
        else
        {
            beg = mid;
        }
        if (beg + 1 == end)
        {
            break;
        }
    }
    int res = 0;
    if (is_reference_above_cnt(citations, beg))
    {
        res = min(citations[beg], (int)(citations.size() - beg));
    }
    else
    {
        res = min(citations[end], (int)(citations.size() - end));
    }
    return res;
}

int main()
{
    vector<int> vec{0, 1, 3, 5, 6};
    assert(h_index(vec) == 3);
    std::cout << "finish" << std::endl;
}