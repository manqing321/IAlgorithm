#include <iostream>
#include <assert.h>
#include <stdlib.h>
int get_num_same_as_index_core(const int *numbers, const int length, int beg, int end)
{
    if (beg > end)
    {
        return -1;
    }
    int mid = beg + ((end - beg) >> 1);
    int val = numbers[mid];
    if (mid == val)
    {
        return mid;
    }
    else if (mid < val)
    {
        end = mid - 1;
    }
    else
    {
        beg = mid + 1;
    }
    return get_num_same_as_index_core(numbers, length, beg, end);
}

int get_num_same_as_index(const int *numbers, const int length)
{
    if (numbers == nullptr || length < 0)
    {
        throw "invalid input.";
    }
    return get_num_same_as_index_core(numbers, length, 0, length - 1);
}

int main()
{
    {
        int arr[] = {-3, -1, 1, 3, 5};
        int res = get_num_same_as_index(arr, sizeof(arr) / sizeof(arr[0]));
        assert(res == 3);
    }
    std::cout << "finish" << std::endl;
}