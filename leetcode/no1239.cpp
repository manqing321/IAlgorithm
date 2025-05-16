#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

class Solution {
public:
    int dfs(array<bool, 26>& reconds, array<bool, 26>& chars, int idx, const vector<string>& source) {
        if (idx == source.size()) {
            return count_if(reconds.begin(), reconds.end(), [](bool b){ return b; });
        }
        // donnot take it
        int res = dfs(reconds, chars, idx + 1, source);

        // take it
        auto str = source[idx];
        auto i = 0;

        chars.fill(false);
        for (char c : str) {
            i = c - 'a';
            if (chars[i] || reconds[i]) {
                return res;
            }
            chars[i] = true;
        }
        for_each(str.begin(), str.end(), [&](char c){ reconds[c - 'a'] = true; });
        int take_res = dfs(reconds, chars, idx + 1, source);
        for_each(str.begin(), str.end(), [&](char c){ reconds[c - 'a'] = false; });
        return max(res, take_res);
    }

    int maxLength(vector<string>& arr) {
        auto chars = array<bool, 26>();
        auto reconds = array<bool, 26>();
        return dfs(reconds, chars, 0, arr);
    }
};

int main() {
    auto arr = vector<string>{ "un","iq","ue" };
    auto expect = 4;
    auto actual = Solution().maxLength(arr);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}