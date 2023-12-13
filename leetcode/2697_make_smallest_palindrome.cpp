#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string make_smallest_palindrome(string s)
{
    int beg = 0;
    int end = s.size() - 1;
    while (beg < end)
    {
        if (s[beg] != s[end])
        {
            char c = min(s[beg], s[end]);
            s[beg] = c;
            s[end] = c;
        }
        beg++;
        end--;
    }
    return s;
}

int main()
{
    // test 01
    {
        string s = "egcfe";
        string actual = make_smallest_palindrome(s);
        string target = "efcfe";
        assert(actual == target);
    }
    // test 02
    {
        string s = "abcd";
        string actual = make_smallest_palindrome(s);
        string target = "abba";
        assert(actual == target);
    }
    // test 01
    {
        string s = "seven";
        string actual = make_smallest_palindrome(s);
        string target = "neven";
        assert(actual == target);
    }
    cout << "finish" << endl;
}