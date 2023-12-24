#include <iostream>
#include <cassert>
#include <functional>
using namespace std;

long long minimum_perimeter(long long neededApples)
{
    using llong = long long;
    llong beg = 0;
    llong end = 200000;
    function<llong(llong)> get_apples = [](llong side) -> llong
    {
        return 2 * side * (side + 1) * (2 * side + 1);
    };
    function<llong(llong)> get_sides = [](llong side) -> llong
    {
        return 8 * side;
    };
    while (beg < end)
    {
        auto mid = beg + ((end - beg) >> 1);
        auto apples = get_apples(mid);
        if (apples == neededApples)
        {
            return get_sides(mid);
        }
        if (apples > neededApples)
        {
            auto pre = get_apples(mid - 1);
            if (pre == neededApples)
            {
                return get_sides(mid - 1);
            }
            else if (pre < neededApples)
            {
                return get_sides(mid);
            }
            end = mid - 1;
        }
        else
        {
            auto rear = get_apples(mid + 1);
            if (rear >= neededApples)
            {
                return get_sides(mid + 1);
            }
            beg = mid + 1;
        }
    }
    return get_sides(end);
}

int main()
{
    // test 01
    {
        long long actual = minimum_perimeter(1);
        long long target = 8;
        assert(actual == target);
    }
    // test 02
    {
        long long actual = minimum_perimeter(13);
        long long target = 16;
        assert(actual == target);
    }
    // test 03
    {
        long long actual = minimum_perimeter(1000000000);
        long long target = 5040;
        assert(actual == target);
    }
    cout << "finish" << endl;
}