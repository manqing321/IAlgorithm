#include <iostream>
#include <assert.h>

unsigned int find_first_bit(int num)
{
    int first_bit = 0;
    while (!(num & 1) && (first_bit < sizeof(int) * 8))
    {
        num = num >> 1;
        first_bit += 1;
    }
    return first_bit;
}

void find_nums_appear_once(int data[], int len, int *num1, int *num2)
{
    if (data == nullptr || len < 2)
    {
        return;
    }
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        flag ^= data[i];
    }
    // get first 1
    unsigned int index_of_1 = find_first_bit(flag);

    *num1 = *num2 = 0;
    for (size_t i = 0; i < len; i++)
    {
        if ((data[i] >> index_of_1) & 1)
        {
            (*num1) ^= data[i];
        }
        else
        {
            (*num2) ^= data[i];
        }
    }
}

int main()
{
    {
        int num1 = 0, num2 = 0;
        int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
        find_nums_appear_once(arr,sizeof(arr) / sizeof(arr[0]), &num1, &num2);
        std::cout << "(num1, num2) is (" << num1 << ", " << num2 << ")" << std::endl;
        bool is_right = (num1 == 4 && num2 == 6) || (num1 == 6 || num2 == 4);
        assert(is_right);
    }
    std::cout << "finish" << std::endl;
}