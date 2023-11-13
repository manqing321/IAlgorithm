#include <iostream>
#include <assert.h>

int g_m = 3;
int last_remain(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return (last_remain(n - 1) + g_m) % n;
}
int main()
{
    int actual = last_remain(5);
    int target = 3;
    assert(actual == target);
    std::cout << "finish" << std::endl;
}