#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
            auto mp = unordered_map<int, int>();
            size_t left = 0;
            size_t ans = 0;
            for (size_t i = 0; i < nums.size(); i++)
            {
                mp[nums[i]] += 1;
                while(mp[nums[i]] > k){
                    mp[nums[left]] -= 1;
                    left += 1;
                }
                if(mp[nums[i]] < k){
                    ans = max(ans, i - left + 1);
                }
            }
            return ans;
        }
    };