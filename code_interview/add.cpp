#include <iostream>
#include <assert.h>
int add(int num1, int num2)
{
    int sum = num1 ^ num2;
    int carry = num1 & num2;
    if (carry)
    {
        return add(sum, carry << 1);
    }
    else
    {
        return sum;
    }
}
int main()
{
    // test 01
    {
        int num1 = 100;
        int num2 = 100;
        int actual = add(num1, num2);
        int target = 200;
        assert(actual == target);
    }
    // test 02
    {
        int num1 = 100;
        int num2 = -100;
        int actual = add(num1, num2);
        int target = 0;
        assert(actual == target);
    }
    // test 03
    {
        int num1 = -200;
        int num2 = -100;
        int actual = add(num1, num2);
        int target = -300;
        assert(actual == target);
    }
    std::cout << "finish\n";
}