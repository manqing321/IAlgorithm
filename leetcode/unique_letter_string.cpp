#include <iostream>
#include <assert.h>
#include <string>
using std::string;
int unique_letter_string(string s)
{
    int res = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        char arr[26]{0};
        arr[s[i] - 'A'] = 1;
        int num = 1;
        int dup_cnt = 0;
        for (int j = 1; i + j < s.size() && dup_cnt < 26; j++)
        {
            if (arr[s[i + j] - 'A'] == 0)
            {
                arr[s[i + j] - 'A'] = 1;
                num += 1;
            }
            else if (arr[s[i + j] - 'A'] == 1)
            {
                arr[s[i + j] - 'A'] = 2;
                num -= 1;
                dup_cnt += 1;
            }
            res += num;
        }
    }
    return res;
}

int main()
{
    // test 01
    {
        int actual = unique_letter_string("ABC");
        int target = 10;
        assert(actual == target);
    }
    // test 02
    {
        int actual = unique_letter_string("ABA");
        int target = 8;
        assert(actual == target);
    }
    // test 03
    {
        int actual = unique_letter_string("LEETCODE");
        int target = 92;
        assert(actual == target);
    }
    // test 04
    {
        int actual = unique_letter_string("BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAABBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        int target = 84046;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}