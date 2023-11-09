#include <iostream>
#include <assert.h>

bool find_num_with_sum(int arr[], int len, int sum, int *num1, int *num2)
{
    if (arr == nullptr || len < 2)
    {
        return false;
    }
    int pre = 0;
    int rear = len - 1;
    while (pre < rear)
    {
        int sum_temp = arr[pre] + arr[rear];
        if (sum_temp == sum)
        {
            *num1 = arr[pre];
            *num2 = arr[rear];
            return true;
        }
        else if (sum_temp > sum)
        {
            rear -= 1;
        }
        else
        {
            pre += 1;
        }
    }
    return false;
}

int main()
{
    {
        int arr[] = {1, 2, 4, 7, 11, 15};
        int sum = 15;
        int num1 = 0, num2 = 0;
        bool has_found = find_num_with_sum(arr, sizeof(arr) / sizeof(arr[0]), sum, &num1, &num2);
        assert(has_found);
        assert((num1 == 4 && num2 == 11) || (num1 == 11 && num2 == 4));
    }

    std::cout << "finish" << std::endl;
}