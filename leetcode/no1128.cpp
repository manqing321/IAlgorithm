#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using std::vector;
using std::for_each;
using std::accumulate;
using std::unordered_map;
using std::min;
using std::max;
using std::pair;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        auto mp = unordered_map<int, int>();
        for_each(dominoes.begin(), dominoes.end(), [&](const vector<int>& pair){ mp[max(pair.front(), pair.back()) * 10 + min(pair.front(), pair.back()) ] += 1; });
        return accumulate(mp.begin(), mp.end(), 0, [](int seed, const pair<const int, int>& pair){ return seed += pair.second * (pair.second - 1); });
    }
};