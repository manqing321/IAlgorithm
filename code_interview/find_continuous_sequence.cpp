#include <iostream>

void print_sequence(int s, int small, int big)
{
    std::cout << s << ":(begin, end) is " << small << ", " << big << ")" << std::endl;
}

void find_continuous_sequence(int s)
{
    if (s < 3)
    {
        return;
    }
    int small = 1;
    int big = 2;
    int mid = (s + 1) >> 1;
    int sum = small + big;
    while (small < mid)
    {
        if (sum == s)
        {
            print_sequence(s, small, big);
        }
        while (sum > s && small < mid)
        {
            sum -= small;
            small++;
            if (sum == s)
            {
                print_sequence(s, small, big);
            }
        }
        big++;
        sum += big;
    }
}

int main()
{
    find_continuous_sequence(3);
    find_continuous_sequence(100);
    find_continuous_sequence(4);
    find_continuous_sequence(15);
    find_continuous_sequence(0);
    std::cout << "finish" << std::endl;
}