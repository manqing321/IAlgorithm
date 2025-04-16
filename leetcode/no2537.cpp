#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        auto mp = map<int, size_t>();
        auto slow = 0;
        auto fast = 0;
        long long good_arr_cnt = 0;
        while(slow < nums.size()) {
            bool is_good = good_arr_cnt >= k;
            if(!is_good) {
                while(fast < nums.size()) {            
                    auto iter = mp.find(nums[fast]);
                    if(iter == mp.end()) {
                        mp.insert(make_pair(nums[fast], 1));
                    } else {
                        good_arr_cnt += iter->second;
                        iter->second += 1;
                    }

                    fast += 1;
                    if(good_arr_cnt >= k) {
                        cout << "slow, fast is " << slow <<", " << fast <<": increment " << nums.size() - fast + 1 << endl;
                        ans += nums.size() - fast + 1;
                        break;
                    }
                }
            }
            else {
                cout << "slow, fast is " << slow <<", " << fast <<": increment " << nums.size() - fast + 1 << endl;
                ans += nums.size() - fast + 1; 
            }
            mp[nums[slow]] -= 1;
            if(mp[nums[slow]] == 0) {
                mp.erase(mp.find(nums[slow]));
            } else {
                good_arr_cnt -= mp[nums[slow]];
            }
            slow += 1;
        }
        return ans;
    }
};

void test01() {
    auto nums = vector<int>{ 1, 1, 1, 1, 1 };
    int k = 10;
    auto expect = 1;
    auto actual = Solution().countGood(nums, k);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << endl;
}

void test02() {
    auto nums = vector<int>{ 3, 1, 4, 3, 2, 2, 4 };
    int k = 2;
    auto expect = 4;
    auto actual = Solution().countGood(nums, k);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << endl;
}
void test03(){
    auto nums = vector<int>{ 2, 3, 1, 3, 2, 3, 3, 3, 1, 1, 3, 2, 2, 2 };
    int k = 18;
    auto expect = 9;
    auto actual = Solution().countGood(nums, k);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << endl;
}

int main() {
    test01();
    test02();
    test03();
}