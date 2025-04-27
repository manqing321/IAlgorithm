#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using std::vector;
using std::cout;
using std::max;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // boundary condition
        // 1 <= nums.length <= 105
        
        int ans = 0;
        int zero_cnt = 0;
        for(int left = 0, right = 0; right < nums.size(); right += 1){
            if (nums[right] == 0) {
                zero_cnt += 1;
            }

            while (zero_cnt > k) {
                if (nums[left] == 0) {
                    zero_cnt -= 1;
                }
                left += 1;
            }

            if (zero_cnt <= k) {
                ans = max(right - left + 1, ans);
            }
        }
        // T(n) = O(n), S(n) = O(1) 
        return ans;
    }
};

void test01() {
    auto nums = vector<int>{ 1,1,1,0,0,0,1,1,1,1,0 };
    auto k = 2;
    auto expect = 6;
    auto actual = Solution().longestOnes(nums, k);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto nums = vector<int>{ 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    auto k = 3;
    auto expect = 10;
    auto actual = Solution().longestOnes(nums, k);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
}