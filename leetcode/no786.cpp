#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        auto mp = unordered_map<int, int>();
        for (const int& num : answers) {
            if (mp[num + 1] == num + 1) {
                mp[num + 1] = 0;
                ans += num + 1;
            }
            mp[num + 1] += 1;
        }
        for (const auto& p : mp) {
            ans += p.first;
        }
        return ans;
    }
};
