#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;
inline vector<string> get_hour(int bit)
{
    if (bit == 0)
    {
        return vector<string>{"0"};
    }
    if (bit == 1)
    {
        return vector<string>{"1", "2", "4", "8"};
    }
    if (bit == 2)
    {
        return vector<string>{"3", "5", "9", "6", "10"};
    }
    if (bit == 3)
    {
        return vector<string>{"7", "11"};
    }
    return vector<string>();
}

unordered_map<int, vector<string>> mp;
inline vector<string> get_min(int bit)
{
    if (mp.empty())
    {
        for (int i = 0; i < 60; ++i)
        {
            int bit_cnt = 0;
            int num = i;
            while (num)
            {
                num = num & (num - 1);
                bit_cnt++;
            }
            if (i > 9)
            {
                mp[bit_cnt].push_back(to_string(i));
            }
            else
            {
                mp[bit_cnt].push_back("0" + to_string(i));
            }
        }
    }
    return mp[bit];
}

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> res;
    for (int i = 0; i <= turnedOn; ++i)
    {
        auto hours = get_hour(i);
        auto minutes = get_min(turnedOn - i);
        for (auto hour : hours)
        {
            for (auto min : minutes)
            {
                res.push_back(hour + ":" + min);
            }
        }
    }
    return res;
}

bool euqal(const vector<string> &vec1, const vector<string> &vec2);

int main()
{
    // test 01
    {
        vector<string> actual = readBinaryWatch(1);
        vector<string> target{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
        assert(euqal(actual, target));
    }
    // test 02
    {
        vector<string> actual = readBinaryWatch(9);
        vector<string> target{};
        assert(euqal(actual, target));
    }
    std::cout << "finish" << std::endl;
}

bool euqal(const vector<string> &vec1, const vector<string> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        return false;
    }
    unordered_map<string, int> mp;
    for (int i = 0; i < vec1.size(); ++i)
    {
        mp[vec1[i]]++;
    }
    for (int i = 0; i < vec2.size(); ++i)
    {
        mp[vec2[i]]++;
        if (mp[vec2[i]] < 0)
        {
            return false;
        }
    }
    return true;
}