#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        // i < j && j < k
        // (nums[i] - nums[j]) * nums[k]
        // nums[i] 最大，nums[k] 也最大 不用考虑负数

        // 前缀最大值
        auto pre_max_vec = vector<int>(nums.size(), 0);
        int pre_max = nums[0];
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(pre_max <= nums[i]) {
                pre_max = nums[i];
            }
            pre_max_vec[i] = pre_max;
        }
        // for_each(pre_max_vec.begin(), pre_max_vec.end(), [](int num) { cout << num<<" ";}); cout << endl;

        // 后缀最大值
        auto rear_max_vec = vector<int>(nums.size(), 0);
        int rear_max = nums[nums.size() - 1];
        for (int k = nums.size() - 1; k >= 0; k--)
        {
            if(rear_max <= nums[k]) {
                rear_max = nums[k];
            }
            rear_max_vec[k] = rear_max;
        }
        // for_each(rear_max_vec.begin(), rear_max_vec.end(), [](int num) { cout << num<<" ";}); cout << endl;

        for (size_t j = 1; j < nums.size() - 1; j++)
        {
            // 固定 j 
            // 从左边拿最大值
            long long diff = pre_max_vec[j - 1] - nums[j];
            if(diff < 0) {
                continue;
            }
            // 从右边拿最大值
            long long mutil = rear_max_vec[j + 1];
            long long temp_res = diff * mutil;
            if (temp_res > ans) {
                ans = temp_res;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {12, 6, 1, 2, 7};
    long long ans = Solution().maximumTripletValue(nums);
    cout << ans << endl;
}