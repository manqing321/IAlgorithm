#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

int inverse_pairs(int *data, int len);
int inverse_pairs_core(int *data, int *copy, int beg, int end);

int inverse_pairs(int *data, int len)
{
    if (data == nullptr || len < 0)
    {
        return 0;
    }
    int *copy = new int[len];
    for (size_t i = 0; i < len; i++)
    {
        copy[i] = data[i];
    }
    int count = inverse_pairs_core(data, copy, 0, len - 1);
    delete[] copy;
    return count;
}

int inverse_pairs_core(int *data, int *copy, int beg, int end)
{
    if (beg == end)
    {
        copy[beg] == data[beg];
        return 0;
    }
    int len = (end - beg) / 2;
    int left = inverse_pairs_core(copy, data, beg, beg + len);
    int right = inverse_pairs_core(copy, data, beg + len + 1, end);

    // i 初始化为前半段最后一个数字的下标
    int i = beg + len;
    // j 初始化为后半段最后一个数字的下标
    int j = end;
    int index_copy = end;
    int count = 0;
    while (i >= beg && j >= beg + len + 1)
    {
        if (data[i] > data[j])
        {
            copy[index_copy--] = data[i--];
            count += j - beg - len;
        }
        else
        {
            copy[index_copy--] = data[j--];
        }
    }
    for (; i >= beg; --i)
    {
        copy[index_copy--] = data[i];
    }
    for (; j >= beg + len + 1; --j)
    {
        copy[index_copy--] = data[j];
    }
    return left + right + count;
}

int main()
{
    int arr[] = {7, 5, 6, 4};
    cout << inverse_pairs(arr, 4) << endl;
    cout << "finish" << endl;
}
