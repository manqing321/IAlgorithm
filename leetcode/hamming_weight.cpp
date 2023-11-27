#include <iostream>
#include <assert.h>
int hamming_weight(uint32_t n)
{
    int cnt = 0;
    while (n)
    {
        n = (n - 1) & n;
        cnt++;
    }
    return cnt;
}

int main()
{
    // test 01
    {
        int actual = hamming_weight(11);
        int target = 3;
        assert(actual == target);
    }
    // test 02
    {
        int actual = hamming_weight(128);
        int target = 1;
        assert(actual == target);
    }
    // test 03
    {
        int actual = hamming_weight(4294967293);
        int target = 31;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}