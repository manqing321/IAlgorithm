#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // 1 <= nums[i] <= 2000
        // 1 <= nums.length <= 1000
        auto ans = 0;
        // count the times of every number
        auto mp = unordered_map<int, size_t>();
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            mp[*iter] = 1;
        }
        auto cnt = mp.size();

        // decrement first or last element then judge if match condition
        mp.clear();
        auto slow = 0;
        auto fast = 0;
        while (slow < nums.size())
        {
            while(fast < nums.size() && mp.size() < cnt){
                mp[nums[fast]] += 1;
                fast += 1;
            }
            if(mp.size() == cnt) {
                // cout << "slow, fast is " << slow <<", " << fast << endl;
                ans += nums.size() - fast + 1;
            }
            mp[nums[slow]] -= 1;
            if (!mp[nums[slow]]){
                mp.erase(nums[slow]);
            }
            slow += 1;
        }
        return ans;
    }
};

void test01() {
    auto nums = vector<int>{ 1,3,1,2,2 };
    auto expect = 4;
    auto actual = Solution().countCompleteSubarrays(nums);
    cout << __func__ <<" expect: " << expect << ", actual: " <<  actual << endl;
}
void test02() {
    auto nums = vector<int>{ 5, 5, 5, 5 };
    auto expect = 10;
    auto actual = Solution().countCompleteSubarrays(nums);
    cout << __func__ <<" expect: " << expect << ", actual: " <<  actual << endl;
}

int main(){
    test01();
    test02();
}