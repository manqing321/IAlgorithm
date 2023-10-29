#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::for_each;
using std::vector;
void print_vec(vector<int> &vec)
{
    for_each(vec.begin(), vec.end(), [](auto i)
             { cout << i << ", "; });
    cout << endl;
}

void merge(vector<int> &vec, vector<int> &cpy, int lbeg, int lend, int rbeg, int rend)
{
    int left = lbeg;
    int right = rend;
    int pos = lbeg;
    while (lbeg <= lend && rbeg <= rend)
    {
        if (vec[lbeg] <= vec[rbeg])
        {
            cpy[pos++] = vec[lbeg++];
        }
        else
        {
            cpy[pos++] = vec[rbeg++];
        }
    }
    while (lbeg <= lend)
    {
        cpy[pos++] = vec[lbeg++];
    }
    while (rbeg <= rend)
    {
        cpy[pos++] = vec[rbeg++];
    }
    while (left <= right)
    {
        vec[left] = cpy[left];
        left++;
    }
}

void merge_sort_core(vector<int> &vec, vector<int> &cpy, int beg, int end)
{
    if (beg == end)
    {
        return;
    }
    int mid = beg + ((end - beg) >> 1);
    // 拆分
    merge_sort_core(vec, cpy, beg, mid);
    merge_sort_core(vec, cpy, mid + 1, end);
    // 合并
    merge(vec, cpy, beg, mid, mid + 1, end);
}

void merge_sort(vector<int> &vec)
{
    vector<int> cpy(vec);
    merge_sort_core(vec, cpy, 0, cpy.size() - 1);
}

int main()
{
    vector<int> vec{1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    cout << "origin vec:";
    print_vec(vec);
    merge_sort(vec);
    cout << "after sort:";
    print_vec(vec);
}