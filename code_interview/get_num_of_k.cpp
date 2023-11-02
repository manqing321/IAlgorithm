#include <iostream>
#include <assert.h>

int get_first_of_k(int *arr, int len, int k, int beg, int end)
{
    if (beg > end)
    {
        return -1;
    }
    int mid = beg + ((end - beg) >> 1);
    int mid_val = arr[mid];
    if (mid_val == k)
    {
        if ((mid > 0 && arr[mid - 1] != k) || mid == 0)
        {
            return mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    else if (mid_val > k)
    {
        end = mid - 1;
    }
    else
    {
        beg = mid + 1;
    }
    return get_first_of_k(arr, len, k, beg, end);
}

int get_last_of_k(int *arr, int len, int k, int beg, int end)
{
    if (beg > end)
    {
        return -1;
    }
    int mid = beg + ((end - beg) >> 1);
    int mid_val = arr[mid];
    if (mid_val == k)
    {
        if (mid == len - 1 || (mid < len - 1 && arr[mid + 1] != k))
        {
            return mid;
        }
        else
        {
            beg = mid + 1;
        }
    }
    else if (mid < k)
    {
        beg = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
    return get_last_of_k(arr, len, k, beg, end);
}

int get_num_of_k(int *arr, int len, int k)
{
    if (arr != nullptr && len > 0)
    {
        int first_k = get_first_of_k(arr, len, k, 0, len - 1);
        int last_k = get_last_of_k(arr, len, k, 0, len - 1);
        if (first_k > -1 && last_k > -1)
        {
            std::cout << "(first, last) is (" << first_k << ", " << last_k << ")\n";
            return last_k - first_k + 1;
        }
    }
    return 0;
}

int main()
{
    {
        int arr[] = {1, 2, 3, 3, 3, 3, 4, 5};
        int k = 3;
        assert(get_num_of_k(arr, sizeof(arr) / sizeof(arr[0]), k) == 4);
    }
    {
        int arr[] = {3, 3, 3, 3, 3, 3, 4, 5};
        int k = 3;
        assert(get_num_of_k(arr, sizeof(arr) / sizeof(arr[0]), k) == 6);
    }
    {
        int arr[] = {1, 2, 3, 3, 3, 3, 3, 3};
        int k = 3;
        assert(get_num_of_k(arr, sizeof(arr) / sizeof(arr[0]), k) == 6);
    }
    {
        int arr[] = {3, 3, 3, 3, 3, 3, 3, 3};
        int k = 3;
        assert(get_num_of_k(arr, sizeof(arr) / sizeof(arr[0]), k) == 8);
    }
    {
        int arr[] = {1, 2, 4, 5, 7, 9};
        int k = 3;
        assert(get_num_of_k(arr, sizeof(arr) / sizeof(arr[0]), k) == 0);
    }
    std::cout << "finish" << std::endl;
}
