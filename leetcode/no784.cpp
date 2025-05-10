#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>
using std::vector;
using std::string;
using std::for_each;
using std::cout;
using std::transform;
using std::accumulate;
using std::isdigit;
class Solution {
public:
    void dfs(vector<string>& ans, string& chs, int idx){
        if (idx == chs.size()) {
            ans.push_back(chs);
            return;
        }
        
        // skip idx
        dfs(ans, chs, idx + 1);

        if (isdigit(chs[idx])) {
            return;
        }
        chs[idx] ^= 32;
        dfs(ans, chs, idx + 1);
        chs[idx] ^= 32;
    }

    vector<string> letterCasePermutation(string s) {
        auto ans = vector<string>();
        dfs(ans, s, 0);
        return ans;
    }
};

int main() {
    string s = "a1b2";
    auto actual = Solution().letterCasePermutation(s);
    for_each(actual.begin(), actual.end(), [](const string& str){ cout << str << ","; });
    cout << "\n";
}