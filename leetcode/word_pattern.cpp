#include <iostream>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
using std::istringstream;
using std::string;
using std::unordered_map;
using std::unordered_set;
bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> mp;
    unordered_set<string> st;
    istringstream is(s);
    string word;
    size_t idx = 0;
    while (is >> word)
    {
        char c = pattern[idx];
        if (mp.count(c))
        {
            if (mp[c] != word)
            {
                return false;
            }
        }
        else
        {
            if (st.count(word))
            {
                return false;
            }
            mp[c] = word;
            st.insert(word);
        }
        idx++;
    }
    return idx == pattern.size();
}

int main()
{
    // test 01
    {
        int target = true;
        int actual = wordPattern("abba", "dog cat cat dog");
        assert(target == actual);
    }

    // test 02
    {
        int target = false;
        int actual = wordPattern("abba", "dog cat cat fish");
        assert(target == actual);
    }

    // test 03
    {
        int target = false;
        int actual = wordPattern("abba", "dog dog dog dog");
        assert(target == actual);
    }

    std::cout << "finish" << std::endl;
}