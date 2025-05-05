#include "TreeNode.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void recur(map<pair<int, int>, vector<int>>& mp, const pair<int, int>& p, TreeNode* node) {
        if (!node) {
            return;
        }
        if (mp.find(p) == mp.end()) {
            mp[p] = vector<int>();
        }

        mp[p].push_back(node->val);
        recur(mp, make_pair(p.first + 1, p.second - 1), node->left);
        recur(mp, make_pair(p.first + 1, p.second + 1), node->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        auto mp = map<pair<int, int>, vector<int>>();
        auto ans = vector<vector<int>>();
        recur(mp, make_pair(0, 0), root);
        auto level_map = map<int, vector<int>>();
        for_each(mp.begin(), mp.end(), [&](pair<const pair<int, int>, vector<int>>& p){ 
            sort(p.second.begin(), p.second.end());
            if (level_map.find(p.first.second) == level_map.end()) {
                level_map[p.first.second] = vector<int>();
            }
            for_each(p.second.begin(), p.second.end(), [&](int num){ level_map[p.first.second].emplace_back(num);} );
            
        });
        for_each(level_map.begin(), level_map.end(), [&](const pair<const int, vector<int>>& p){ ans.push_back(p.second); });
        return ans;
    }
};

int main() {
    auto n15 = TreeNode(15);
    auto n7 = TreeNode(7);
    auto n20 = TreeNode(20, &n15, &n7);
    auto n9 = TreeNode(9);
    auto n3 = TreeNode(3, &n9, &n20);
    auto res = Solution().verticalTraversal(&n3);

    for_each(res.begin(), res.end(),[](const vector<int>& vec){ 
        for_each(vec.begin(), vec.end(),[](const int& num){ cout << num <<" "; }); 
        cout << endl;
     });
}