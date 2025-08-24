#include <iostream>
#include <vector>
using std::vector;
using std::cout;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto cnts = vector<int>();
        auto cnt = 0;
        for(auto num : nums) {
            if (num == 1) {
                cnt++;
            } else {
                cnts.push_back(cnt);
                if (cnt) {
                    cnts.push_back(0);
                }
                cnt = 0;
            }
        }
        if (cnt) {
            cnts.push_back(cnt);
        }
        for (size_t i = 0; i < cnts.size(); i++)
        {
            cout << cnts[i] << " ";
        }
        cout << "\n";
        int ans = cnts[0];
        for (int i = 0; i < cnts.size(); i += 1) {
            auto temp = cnts[i];
            if (i + 1 < cnts.size()) {
                temp += cnts[i + 1];
            }
            if (i + 2 < cnts.size()){
                temp += cnts[i + 2];
            }
            if (temp > ans) {
                ans = temp;
            }
        }
        if (cnts.size() == 1 && ans > 0) {
            return ans - 1;
        }
        return ans;
    }
};

void test01() {
    auto nums = vector<int>{0,1,1,1,0,1,1,0,1};
    auto expect = 5;
    auto actual = Solution().longestSubarray(nums);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}
void test02() {
    auto nums = vector<int>{1,1,0,1};
    auto expect = 3;
    auto actual = Solution().longestSubarray(nums);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}
void test03() {
    auto nums = vector<int>{1,1,1};
    auto expect = 2;
    auto actual = Solution().longestSubarray(nums);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
    test03();
}