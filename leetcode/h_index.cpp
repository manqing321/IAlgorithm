#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int h_index(vector<int> &citations)
{
    if (citations.size() == 0)
    {
        return 0;
    }
    map<int, int> mp;
    for (size_t i = 0; i < citations.size(); i++)
    {
        auto iter = mp.find(citations[i]);
        if (iter == mp.end())
        {
            mp.insert(make_pair(citations[i], 1));
        }
        else
        {
            iter->second += 1;
        }
    }
    // cout << "first fill :";
    // for_each(mp.begin(), mp.end(),
    //          [](pair<const int, int> i)
    //          { cout << "(" << i.first << "," << i.second << "),"; });
    // cout << endl;
    auto rbeg = mp.rbegin();
    int cnt = 0;
    while (rbeg != mp.rend())
    {
        cnt += rbeg->second;
        rbeg->second = cnt;
        rbeg++;
    }
    // cout << "second fill :";
    // for_each(mp.begin(), mp.end(),
    //          [](pair<const int, int> i)
    //          { cout << "(" << i.first << "," << i.second << "),"; });
    // cout << endl;
    int res = 0;
    rbeg = mp.rbegin();
    while (rbeg != mp.rend())
    {
        int temp = min(rbeg->first, rbeg->second);
        if (res < temp)
        {
            res = temp;
        }
        rbeg++;
    }
    // cout << "res is " << res << endl;
    return res;
}

int main()
{
    vector<int> tvec1{3, 0, 6, 1, 5};
    assert(h_index(tvec1) == 3);

    vector<int> vtec2{1, 3, 1};
    assert(h_index(vtec2) == 1);

    vector<int> vtec3{100};
    assert(h_index(vtec3) == 1);

    vector<int> vtec4{11, 15};
    assert(h_index(vtec4) == 2);

    cout << "finish" << endl;
}