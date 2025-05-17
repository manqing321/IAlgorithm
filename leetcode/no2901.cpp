#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using std::vector;
using std::string;
using std::for_each;
using std::cout;
using std::unordered_map;
using std::transform;
using std::back_inserter;

class Solution {
public:
    vector<int> max_vec;
    void dfs(int idx, vector<int>& selected, int pre_group, const vector<string>& words, const vector<int>& groups) {
        if (idx == words.size()) {
            if(selected.size() > max_vec.size()){
                max_vec = vector<int>(selected.begin(), selected.end());
            }
            return;
        }
        // not select
        dfs(idx + 1, selected, pre_group, words, groups);

        // select it
        if (selected.size()) {
            const string& pre = words[selected.back()];
            const string& cur = words[idx];
            if (pre.size() != cur.size()) {
                return;
            }            
            int hanming_cnt = 0;
            for (size_t i = 0; i < cur.size(); i++)
            {
                if (cur[i] != pre[i]) {
                    hanming_cnt += 1;
                }
                if (hanming_cnt > 1) {
                    return;
                }
            }
            if (hanming_cnt != 1) {
                return;
            }
            if (pre_group == groups[idx]){
                return;
            }
        }
        selected.push_back(idx);
        dfs(idx + 1, selected, groups[idx], words, groups);
        selected.pop_back();
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto selected = vector<int>();
        dfs(0, selected, 0, words, groups);
        auto ans = vector<string>();
        transform(max_vec.begin(), max_vec.end(), back_inserter(ans), [&](int idx){ return words[idx]; });
        return ans;
    }
};

int main() {
    auto words = vector<string>{ "bab", "dab", "cab" };
    auto groups = vector<int>{ 1, 2, 2 };
    auto ans = Solution().getWordsInLongestSubsequence(words, groups);
    for_each(ans.begin(), ans.end(), [](const string& s) { cout << s << ", "; });
    cout << "\n";
}