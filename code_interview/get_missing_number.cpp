#include <iostream>
#include <stdlib.h>
#include <assert.h>

int get_first_not_match_val(int *arr, int len, int beg, int end)
{
    if (beg > end)
    {
        return -1;
    }
    int mid = beg + ((end - beg) >> 1);
    int mid_val = arr[mid];
    if (mid_val != mid)
    {
        if (mid == 0 || (mid > 0 && arr[mid - 1] == mid - 1))
        {
            return mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    else
    {
        beg = mid + 1;
    }
    return get_first_not_match_val(arr, len, beg, end);
}

int get_missing_num(int *arr, int len)
{
    if (arr != nullptr && len > 0)
    {
        int first_not_match = get_first_not_match_val(arr, len, 0, len - 1);
        std::cout << "first not match num is " << first_not_match << std::endl;
        return first_not_match;
    }
    return -1;
}

int main()
{
    {
        int arr[] = {0, 1, 2, 3, 5, 6, 7};
        assert(get_missing_num(arr, sizeof(arr) / sizeof(arr[0])) == 4);
    }
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        assert(get_missing_num(arr, sizeof(arr) / sizeof(arr[0])) == 0);
    }
    {
        int arr[] = {0, 1, 2, 3, 4, 5, 7};
        assert(get_missing_num(arr, sizeof(arr) / sizeof(arr[0])) == 6);
    }
    {
        int arr[] = {0, 1, 2, 3, 4, 5, 6};
        assert(get_missing_num(arr, sizeof(arr) / sizeof(arr[0])) == -1);
    }
    std::cout << "finish" << std::endl;
}