#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <map>
#include <algorithm>
#include <tuple>
using namespace std;

long long minimum_fuel_cost(vector<vector<int>> &roads, int seats);

int main()
{
    // test 01
    {
        vector<vector<int>> roads{{0, 1}, {0, 2}, {0, 3}};
        int seats = 5;
        int target = 3;
        int actual = minimum_fuel_cost(roads, seats);
        assert(actual == target);
    }
    // test 02
    {
        vector<vector<int>> roads{{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
        int seats = 2;
        int target = 7;
        int actual = minimum_fuel_cost(roads, seats);
        assert(actual == target);
    }
    // test 03
    {
        vector<vector<int>> roads{};
        int seats = 1;
        int target = 0;
        int actual = minimum_fuel_cost(roads, seats);
        assert(actual == target);
    }
    cout << "finish" << endl;
}

struct Solution
{
    int seats;
    map<int, vector<int>> mp;
    set<int> visited;

    vector<int> next_city(int city)
    {
        vector<int> nexts;
        for (auto next : mp[city])
        {
            if (visited.find(next) == visited.end())
            {
                nexts.push_back(next);
            }
        }
        return nexts;
    }

    tuple<int, long long> get_cost(int city)
    {
        visited.insert(city);
        auto nexts = next_city(city);
        if (nexts.empty())
        {
            return {1, 1};
        }
        int passenger = 1;
        long long fuel = 0;
        for (auto next : nexts)
        {
            auto cost = get_cost(next);
            passenger += get<0>(cost);
            fuel += get<1>(cost);
        }
        if (!city)
        {
            return {passenger, fuel};
        }
        return {passenger, fuel + (passenger / seats) + (int)((passenger % seats) != 0)};
    }

    long long minimum_fuel_cost(vector<vector<int>> &roads, int seats)
    {
        if (roads.empty())
        {
            return 0;
        }
        visited.insert(0);
        for (const auto &road : roads)
        {
            mp[road.front()].push_back(road.back());
            mp[road.back()].push_back(road.front());
        }
        this->seats = seats;
        auto res = get_cost(0);
        return get<1>(res);
    }
};

long long minimum_fuel_cost(vector<vector<int>> &roads, int seats)
{
    return Solution().minimum_fuel_cost(roads, seats);
}