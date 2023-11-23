#include <iostream>
#include <string>
#include <assert.h>
#include <map>
#include <unordered_map>
using namespace std;

string entity_parser(string text)
{
    int size = text.size();
    string res;
    unordered_map<string, char> mp{
        {"quot"s, '"'},
        {"apos"s, '\''},
        {"amp"s, '&'},
        {"gt"s, '>'},
        {"lt"s, '<'},
        {"frasl"s, '/'}};
    for (size_t i = 0; i < size; i++)
    {
        bool have_found = false;
        if (text[i] == '&')
        {
            for (size_t j = 3; j < 7; j++)
            {
                if (i + j < size && text[i + j] == ';')
                {
                    string s = text.substr(i + 1, j - 1);
                    auto iter = mp.find(s);
                    if (iter != mp.end())
                    {
                        have_found = true;
                        res += iter->second;
                        i += j;
                        break;
                    }
                }
            }
        }
        if (!have_found)
        {
            res += text[i];
        }
    }
    return res;
}

int main()
{
    // test 01
    {
        string args{"&amp; is an HTML entity but &ambassador; is not."};
        string target = "& is an HTML entity but &ambassador; is not.";
        string actual = entity_parser(args);
        assert(actual.compare(target) == 0);
    }
    // test 02
    {
        string args{"and I quote: &quot;...&quot;"};
        string target = "and I quote: \"...\"";
        string actual = entity_parser(args);
        assert(actual.compare(target) == 0);
    }
    // test 03
    {
        string args{"Stay home! Practice on Leetcode :)"};
        string target = "Stay home! Practice on Leetcode :)";
        string actual = entity_parser(args);
        assert(actual.compare(target) == 0);
    }
    // test 04
    {
        string args{"x &gt; y &amp;&amp; x &lt; y is always false"};
        string target = "x > y && x < y is always false";
        string actual = entity_parser(args);
        assert(actual.compare(target) == 0);
    }
    // test 05
    {
        string args{"leetcode.com&frasl;problemset&frasl;all"};
        string target = "leetcode.com/problemset/all";
        string actual = entity_parser(args);
        assert(actual.compare(target) == 0);
    }
    cout << "finish" << endl;
}