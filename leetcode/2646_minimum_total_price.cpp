#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;

int minimum_total_price(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
{
    vector<vector<int>> mp(n);
    for (auto &edge : edges)
    {
        mp[edge.front()].push_back(edge.back());
        mp[edge.back()].push_back(edge.front());
    }

    vector<int> cnt(n);
    for (auto &trip : trips)
    {
        int beg = trip.front();
        int end = trip.back();
        function<bool(int, int)> dfs = [&](int node, int parent) -> bool
        {
            if (node == end)
            {
                ++cnt[node];
                return true;
            }
            for (auto child : mp[node])
            {
                if (child != parent && dfs(child, node))
                {
                    ++cnt[node];
                    return true;
                }
            }
            return false;
        };
        dfs(beg, -1);
    }
    function<pair<int, int>(int, int)> dfs = [&](int node, int parent) -> pair<int, int>
    {
        int not_choose_val = price[node] * cnt[node];
        int choose_val = not_choose_val >> 1;
        for (auto child : mp[node])
        {
            if (child == parent)
            {
                continue;
            }
            auto child_val = dfs(child, node);
            choose_val += child_val.second;
            not_choose_val += min(child_val.first, child_val.second);
        }
        return {choose_val, not_choose_val};
    };
    auto val = dfs(0, -1);
    return min(val.first, val.second);
}

int main()
{
    // test 01
    {
        int n = 4;
        vector<vector<int>> edges{{0, 1}, {1, 2}, {1, 3}};
        vector<int> price{2, 2, 10, 6};
        vector<vector<int>> trips{{0, 3}, {2, 1}, {2, 3}};
        int target = 23;
        int actual = minimum_total_price(n, edges, price, trips);
        assert(actual == target);
    }
    // test 02
    {
        int n = 2;
        vector<vector<int>> edges{{0, 1}};
        vector<int> price{2, 2};
        vector<vector<int>> trips{{0, 0}};
        int target = 1;
        int actual = minimum_total_price(n, edges, price, trips);
        assert(actual == target);
    }
    cout << "finish" << endl;
}