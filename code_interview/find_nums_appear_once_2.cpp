#include <iostream>
#include <assert.h>

int find_nums_appear_once(int arr[], int len)
{
    int bit[32] = {0};
    for (int i = 0; i < len; i++)
    {
        int bit_mask = 1;
        for (int j = 31; j >= 0; j--)
        {
            if (arr[i] & bit_mask)
            {
                bit[j] += 1;
            }
            bit_mask = bit_mask << 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        res = res << 1;
        res += bit[i] % 3;
    }
    return res;
}

int main()
{
    {
        int arr[] = {1, 3, 5, 1, 3, 4, 5, 5, 3, 1};
        assert(find_nums_appear_once(arr, sizeof(arr) / sizeof(arr[0])) == 4);
    }
    std::cout << "finish" << std::endl;
}