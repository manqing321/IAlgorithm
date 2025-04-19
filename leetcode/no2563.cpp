#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // boundary condtion
        // lower <= upper
        // 1 <= nums.length <= 10^5
        if (nums.size() == 1) {
            return 0;
        }
        int len = nums.size();
        long long res = 0;

        // init
        sort(nums.begin(), nums.end());
        
        // for each num find the range of [lower - num, upper - num]
        // increment the size of this range
        for (int idx = 0; idx < len; idx += 1) {
            
            int num = nums[idx];

            // find range left edge: the first index larger than lower_bound
            int lower_bound = lower - num;
            int left = idx, right = len;
            while (left + 1 != right) {
                int mid = (left + right) >> 1;
                if (nums[mid] < lower_bound) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            int range_begin = right;

            // find the range right edge: the first index larger than upper_bound
            int upper_bound = upper - num;
            left = idx, right = len;
            while (left + 1 != right) {
                int mid = (left + right) >> 1;
                if (nums[mid] <= upper_bound) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            int range_end = right;
            res += range_end - range_begin;
        }
        return res;
    }
};

void test01() {
    auto nums = vector<int>{0,1,7,4,4,5};
    int lower = 3, upper = 6;
    auto expect = 6;
    auto actual = Solution().countFairPairs(nums, lower, upper);
    cout << __func__ <<" expect is " << expect <<", actual is " << actual  << endl;
}
void test02() {
    auto nums = vector<int>{ 1,7,9,2,5};
    int lower = 11, upper = 11;
    auto expect = 1;
    auto actual = Solution().countFairPairs(nums, lower, upper);
    cout << __func__ <<" expect is " << expect <<", actual is " << actual  << endl;
}
int main() {
    test01();
    test02();
}