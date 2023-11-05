#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using std::for_each;
using std::map;
using std::string;
using std::vector;
vector<string> find_repeated_dna_sequences(string s)
{
    map<char, int> char_int_dict = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    map<int, char> int_char_dict = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};
    int num = 0;
    map<int, int> mp;
    for (size_t i = 0; i < s.size(); i++)
    {
        num = ((num << 2) & ((1 << 20) - 1)) | char_int_dict[s[i]];
        if (i >= 9)
        {
            mp[num] += 1;
        }
    }
    vector<string> res;
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (iter->second > 1)
        {
            int num = iter->first;
            string s(10, '0');
            for (int i = 9; i >= 0; i--)
            {
                s[i] = int_char_dict[num & 3];
                num = num >> 2;
            }
            res.push_back(s);
        }
    }
    return res;
}

int main()
{
    {
        string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        auto res = find_repeated_dna_sequences(s);
        for_each(res.begin(), res.end(), [](string &s)
                 { std::cout << s << ", "; });
        std::cout << std::endl;
    }
    {
        string s = "GAGAGAGAGAGA";
        auto res = find_repeated_dna_sequences(s);
        for_each(res.begin(), res.end(), [](string &s)
                 { std::cout << s << ", "; });
        std::cout << std::endl;
    }
    {
        string s = "ACGTAAAAAACGTAAAAAA";
        auto res = find_repeated_dna_sequences(s);
        for_each(res.begin(), res.end(), [](string &s)
                 { std::cout << s << ", "; });
        std::cout << std::endl;
    }
}