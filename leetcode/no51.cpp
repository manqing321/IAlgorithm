#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using std::vector;
using std::string;
using std::unordered_set;
using std::for_each;
using std::cout;

class Solution {
public:
    void dfs(vector<vector<string>>& ans, 
        unordered_set<int>& col_st,
        unordered_set<int>& row_minus_col_st,
        unordered_set<int>& row_add_col_st,
        int row,
        const int len,
        vector<string>& path) {
            if (row == len) {
                ans.emplace_back(path);
                return;
            }
            for (size_t col = 0; col < len; col++) {
                if (col_st.count(col)) {
                    continue;
                }
                if (row_add_col_st.count(row + col)) {
                    continue;
                }
                if (row_minus_col_st.count(row - col)) {
                    continue;
                }
                string s(len, '.');
                s[col] = 'Q';
                path[row] = s;
                col_st.insert(col);
                row_add_col_st.insert(row + col);
                row_minus_col_st.insert(row - col);
                dfs(ans, col_st, row_minus_col_st, row_add_col_st, row + 1, len, path);
                col_st.erase(col);
                row_add_col_st.erase(row + col);
                row_minus_col_st.erase(row - col);
            }

    }
    vector<vector<string>> solveNQueens(int n) {
        auto col_st = unordered_set<int>();
        auto row_add_col_st = unordered_set<int>();
        auto row_minus_col_st = unordered_set<int>();
        auto ans = vector<vector<string>>();
        auto path = vector<string>(n, string());
        dfs(ans, col_st, row_minus_col_st, row_add_col_st, 0, n, path);
        return ans;
    }
};

int main() {
    int n = 4;
    auto ans = Solution().solveNQueens(n);
    for (const auto& vec: ans) {
        for (const string& s: vec) {
            cout << s << '\n';
        }
        cout << '\n';
    }
}