#include <vector>
#include <map>
#include <numeric>
#include <iostream>
using std::vector;
using std::map;
using std::pair;
using std::max;
using std::cout;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        auto mp = map<int, int>();
        for (int num : nums) {
            mp[num] += num;
        }
        // pre1 pre2 cur
        int pre1 = -1, pre2 = -1, cur = -1;
        int pre1_points = 0, pre2_points = 0, cur_points = 0;
        for (const pair<const int, int>& p : mp) {
            // not take pre2 point
            int not_take_pre2_points = pre1_points + p.second;
            // take pre2
            cur = p.first;
            int take_pre2_point = pre2_points;
            if (cur - pre2 != 1) {
                take_pre2_point += p.second;
            }
            cur_points = max(not_take_pre2_points, take_pre2_point);
            cout << pre1 << ", " << pre2 << ", " << cur << " : " << pre1_points << ", " << pre2_points << ", " << cur_points << "\n";
            pre1 = pre2;
            pre2 = cur;
            pre1_points = pre2_points;
            pre2_points = cur_points;
        }
        return cur_points;
    }
};

int main(){
    auto nums = vector<int>{2,2,3,3,3,4};
    auto ans = Solution().deleteAndEarn(nums);
    cout << ans << '\n';
}