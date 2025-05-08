#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
using std::vector;
using std::string;
using std::for_each;
using std::cout;
using std::set;
using std::copy;
class Solution {
public:
    bool is_palindrome(const string& s, int idx, int len) {
        size_t left = idx, right = idx + len - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(vector<vector<string>>& ans, vector<int>& vec, const string& s, int idx) {
        if (idx == s.size() - 1) {
            int beg = 0;
            int i = 0;
            vec.push_back(s.size() - 1);
            for (; i < vec.size(); i++) {
                int end = vec[i] + 1;
                if (!is_palindrome(s, beg, end - beg)) {
                    break;
                }
                beg = end;
            }
            if (i == vec.size()) {
                beg = 0;
                auto s_vec = vector<string>();
                for (size_t i = 0; i < vec.size(); i++)
                {
                    int end = vec[i] + 1;
                    s_vec.push_back(s.substr(beg, end - beg));
                    beg = end;
                }
                ans.push_back(s_vec);
            }
            vec.pop_back();
            return;
        }
        // not take
        dfs(ans, vec, s, idx + 1);

        // take it
        vec.push_back(idx);
        dfs(ans, vec, s, idx + 1);
        vec.pop_back();
    }
    vector<vector<string>> partition(string s) {
        // 选择是否拆分
        int n = s.size() - 1;
        auto vec = vector<int>();
        auto ans = vector<vector<string>>();
        dfs(ans, vec, s, 0);
        return ans;
    }
};

int main() {
    auto s = "aab";
    auto actual = Solution().partition(s);
    for_each(actual.begin(),  actual.end(), [](const vector<string>& vec) {
        for_each(vec.begin(),  vec.end(), [](const string& s) { 
            cout << s << ", ";
        });
        cout << "\n";
    });
}