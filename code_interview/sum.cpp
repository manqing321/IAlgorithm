#include <iostream>
#include <functional>
#include <vector>
#include <assert.h>
using std::function;
using std::vector;
int func_0(int)
{
    return 0;
}

int sum(int n)
{
    static vector<function<int(int)>> vec{sum, func_0};
    return vec[!!n](n - 1) + n;
}

int main()
{
    // test 1
    {
        int actual = sum(10);
        int target = 55;
        assert(actual == target);
    }

    std::cout <<"finish";
}