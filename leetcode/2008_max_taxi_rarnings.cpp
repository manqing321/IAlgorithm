#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <functional>
using namespace std;

long long max_taxi_earnings(int n, vector<vector<int>> &rides)
{
    map<int, vector<pair<int, long long>>> mp;
    for (auto ride : rides)
    {
        mp[ride[1]].push_back(make_pair(ride[0], (long long)(ride[1] - ride[0] + ride[2])));
    }
    vector<long long> memo(n + 1, -1);
    function<long long(int)> dfs = [&](int stop) -> long long
    {
        if (stop == 1)
        {
            return 0;
        }
        if (memo[stop] != -1)
        {
            return memo[stop];
        }
        memo[stop] = dfs(stop - 1);
        for (auto ride : mp[stop])
        {
            memo[stop] = max(memo[stop], dfs(ride.first) + ride.second);
        }
        return memo[stop];
    };
    return dfs(n);
}

int main()
{
    // test 01
    {
        int n = 5;
        vector<vector<int>> rides{{2, 5, 4}, {1, 5, 1}};
        long long target = 7;
        long long actual = max_taxi_earnings(n, rides);
        assert(actual == target);
    }
    // test 02
    {
        int n = 20;
        vector<vector<int>> rides{{1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1}};
        long long target = 20;
        long long actual = max_taxi_earnings(n, rides);
        assert(actual == target);
    }
    cout << "finish" << endl;
}