#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using std::vector;
using std::cout;
using std::accumulate;
using std::count_if;
using std::max;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        size_t cnt1 = 0;
        for (const int& num : nums1) {
            sum1 += num;
            cnt1 += !num;
        }
        long long sum2 = 0;
        size_t cnt2 = 0;
        for (const int& num : nums2) {
            sum2 += num;
            cnt2 += !num;
        }
        long long min1 = sum1 + cnt1;
        long long max1 = cnt1 ? __LONG_LONG_MAX__ : min1;
        long long min2 = sum2 + cnt2;
        long long max2 = cnt2 ? __LONG_LONG_MAX__ : min2;
        
        // if two scope has no union
        if (min1 > max2 || min2 > max1) {
            return -1;
        }
        return max(min1, min2);
        
    }
};
void test01() {
    auto nums1 = vector<int>{3, 2, 0, 1, 0};
    auto nums2 = vector<int>{6, 5, 0};
    auto expect = 12;
    auto actual = Solution().minSum(nums1, nums2);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto nums1 = vector<int>{2, 0, 2, 0};
    auto nums2 = vector<int>{1, 4};
    auto expect = -1;
    auto actual = Solution().minSum(nums1, nums2);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
}