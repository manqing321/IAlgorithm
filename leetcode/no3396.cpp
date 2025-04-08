#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto st = set<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (st.count(nums[i])) {
                return i / 3 + 1;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};