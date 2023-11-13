#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using std::vector;
bool is_continuous(vector<int> &vec)
{
    std::sort(vec.begin(), vec.end());
    int n = std::count_if(vec.begin(), vec.end(), [](int num)
                          { return !num; });
    auto pre = vec.begin() + n;
    auto rear = pre + 1;
    int m = 0;
    while (pre != vec.end() && rear != vec.end())
    {
        if (*pre == *rear)
        {
            return false;
        }
        m += (*rear - *pre - 1);
        rear++;
        pre++;
    }
    return n >= m;
}

int main()
{
    // test1
    {
        vector<int> vec{6, 3, 4, 2, 5};
        bool actual = is_continuous(vec);
        bool target = true;
        assert(actual == target);
    }

    // test2
    {
        vector<int> vec{6, 3, 0, 2, 5};
        bool actual = is_continuous(vec);
        bool target = true;
        assert(actual == target);
    }

    // test3
    {
        vector<int> vec{6, 3, 0, 2, 0};
        bool actual = is_continuous(vec);
        bool target = true;
        assert(actual == target);
    }

    // test4
    {
        vector<int> vec{6, 3, 0, 3, 0};
        bool actual = is_continuous(vec);
        bool target = false;
        assert(actual == target);
    }

    std::cout <<"finish" << std::endl;
}