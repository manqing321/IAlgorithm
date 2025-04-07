#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0, [](int sec, int num){ return sec + num;});
        if (sum & 1) {
            return false;
        }
        int half = sum >> 1;
        auto max_ptr = max_element(nums.begin(), nums.end());
        if (*max_ptr > half) {
            return false;
        }
        auto dp = vector<int>(half + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num > half) {
                return false;
            }
            if(num == half) {
                return true;
            }
            for (int j = dp.size() - 1; j >= num; j--) {
                if (j > num) {
                    dp[j] = dp[j] || dp[j - num];
                } else {
                    dp[j] = true;
                }
            }
        }
        return dp.back();
    }
};

int main(){
    auto nums = vector<int>{ 100, 100, 99, 97 };
    auto ans = Solution().canPartition(nums);
    cout <<"ans: " << ans << endl;
}