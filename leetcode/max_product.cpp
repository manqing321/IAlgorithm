#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
using std::make_pair;
using std::multimap;
using std::string;
using std::vector;
int max_product(vector<string> &words)
{
    int max = 0;
    multimap<int, int> size_num_dict;
    for (auto iter = words.begin(); iter != words.end(); iter++)
    {
        int num = 0;
        string &str = *iter;
        for (size_t i = 0; i < str.size(); i++)
        {
            num |= (1 << (str[i] - 'a'));
        }
        for (auto beg = size_num_dict.rbegin(); beg != size_num_dict.rend(); beg++)
        {
            if (!(beg->second & num))
            {
                if (beg->first * str.size() > max)
                {
                    max = beg->first * str.size();
                }
                break;
            }
        }
        size_num_dict.insert(make_pair(str.size(), num));
    }
    return max;
}
