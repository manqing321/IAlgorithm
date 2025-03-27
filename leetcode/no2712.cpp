#include <iostream>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    long long minimumCost(const string& s, char ch) {
        long long cost = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if(s[i] == ch) {
                size_t j = i;
                while(j < s.size() && s[j] == ch) {
                    j += 1;
                }
                long long left_cost = j + i;
                long long right_cost = (s.size() - j) + (s.size() - i);
                cost += min(left_cost, right_cost);
                i = j - 1;
            }
        }
        return cost;
    }

    long long minimumCost(string s) {         
        return min(minimumCost(s, '1'), minimumCost(s, '0'));
    }
};

int main() {
    string s = "010101";
    auto sol = Solution();
    auto ans = sol.minimumCost(s);
    cout << ans << endl;
}