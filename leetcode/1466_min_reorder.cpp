#include <iostream>
#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int min_reorder(int n, vector<vector<int>> &connections);

int main()
{
    // test 01
    {
        int n = 6;
        vector<vector<int>> connections{{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
        int actual = min_reorder(n, connections);
        int target = 3;
        assert(actual == target);
    }
    // test 02
    {
        int n = 5;
        vector<vector<int>> connections{{1, 0}, {1, 2}, {3, 2}, {3, 4}};
        int actual = min_reorder(n, connections);
        int target = 2;
        assert(actual == target);
    }
    // test 03
    {
        int n = 3;
        vector<vector<int>> connections{{1, 0}, {2, 0}};
        int actual = min_reorder(n, connections);
        int target = 0;
        assert(actual == target);
    }
    cout << "finish" << endl;
}

int min_reorder(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> roads(n);
    unordered_multimap<int, int> mp;
    for (auto con : connections)
    {
        roads[con.front()].push_back(con.back());
        roads[con.back()].push_back(con.front());
        mp.insert(make_pair(con.front(), con.back()));
    }
    int res = 0;
    function<void(int, int)> dfs = [&](int node, int parent)
    {
        for (auto next : roads[node])
        {
            if (next == parent)
            {
                continue;
            }

            auto pair = mp.equal_range(next);
            auto beg = pair.first;
            auto end = pair.second;
            while (beg != end)
            {
                if (beg->second == node)
                {
                    break;
                }
                ++beg;
            }
            if (beg == end)
            {
                ++res;
            }
            dfs(next, node);
        }
    };
    dfs(0, -1);
    return res;
}