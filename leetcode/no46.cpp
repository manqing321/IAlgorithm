#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::for_each;
using std::all_of;

class Solution {
public:
    void dfs(vector<vector<int>>& ans, const vector<int>& nums, vector<int>& path, vector<bool>& selected) {
        if (all_of(selected.begin(), selected.end(), [](bool b){ return b; })) {
            ans.push_back(path);
            return;
        }
        for (size_t idx = 0; idx < nums.size(); idx++) {
            if (!selected[idx]) {
                // select it
                selected[idx] = true;
                path.push_back(nums[idx]);
                dfs(ans, nums, path, selected);
                path.pop_back();
                selected[idx] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        auto selected = vector<bool>(nums.size(), false);
        auto ans = vector<vector<int>>();
        auto path = vector<int>();
        dfs(ans, nums, path, selected);
        return ans;
    }
};

int main() {
    auto nums = vector<int>{1, 2, 3};
    auto actual = Solution().permute(nums);
    for_each(actual.begin(), actual.end(), [](const vector<int>& vec){
        for_each(vec.begin(), vec.end(), [](const int num){ 
            cout << num << ", ";
        });
        cout << '\n';
    });
}