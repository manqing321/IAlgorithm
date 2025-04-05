#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        auto ans = 0;
        auto len = nums.size();
        for(auto beg = 0, end = 1 << len; beg != end; beg += 1)
        {
            auto not_or_sum = 0;
            auto flag = beg;
            auto idx = 0;
            while(flag){
                if(flag & 1) {
                    not_or_sum ^= nums[idx];
                }
                idx += 1;
                flag >>= 1;
            }
            ans += not_or_sum;
        }
        return ans;
    }
};
int main()
{
    auto nums = vector<int>{5,1,6};
    auto ans = Solution().subsetXORSum(nums);
    cout << ans << endl;
}