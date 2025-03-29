#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        auto ans = 0;
        auto start = 0;
        auto vec = vector<int>(edges.size(), 0);
        for (size_t i = 0; i < edges.size(); i++)
        {
            if(vec[i]) {
                continue;
            }
            auto pos = i;
            auto increment_flag = start;
            while(pos != -1) {
                increment_flag += 1;
                if(vec[pos]) {
                    if(vec[pos] > start) {
                    ans = max(ans, increment_flag - vec[pos]);
                    }
                    break;
                }
                vec[pos] = increment_flag;
                pos = edges[pos];
            }
        }
        return ans;
    }
};

int main() {
    auto args = vector<int>{3, 3, 4, 2, 3};
    // auto args = vector<int>{2, -1, 3, 1};
    //
    auto sol = Solution();
    auto ans = sol.longestCycle(args);
    cout << ans << endl;
}