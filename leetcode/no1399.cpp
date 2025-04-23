#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        // boundary condition
        // n >= 1 and n <= 10000
        auto mp = unordered_map<int, int>();
        auto max_cnt = 0;
        auto max_group_cnt = 0;
        auto dp = vector<int>{ 0 };
        for (int i = 1; i <= n; i++)
        {
            // caculate the sum of bit
            bool increment = true;
            for (size_t idx = 0; idx < dp.size(); idx += 1) {
                if (increment) {
                    dp[idx] += 1;
                    if (dp[idx] == 10) {
                        dp[idx] = 0;
                        continue;
                    }
                    increment = false;
                    break;
                }
            }
            if (increment) {
                dp.push_back(1);
            }
            int bit_sum = accumulate(dp.begin(), dp.end(), 0, [](int seed, int num){ return seed + num; });
            mp[bit_sum]++;
            if (max_cnt < mp[bit_sum]) {
                max_cnt = mp[bit_sum];
                max_group_cnt = 1;
            } else if (max_cnt == mp[bit_sum]){
                max_group_cnt += 1;
            }
        }

        // T(n) = O(n), S(n) = O(1)
        return max_group_cnt;
    }
};