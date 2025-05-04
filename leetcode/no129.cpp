#include "TreeNode.h"
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>
#include <numeric>
using std::string;
using std::to_string;
using std::stoi;
using std::max;
using std::cout;
using std::vector;
using std::accumulate;
class Solution {
public:
    vector<string> vec;
    void recursive(TreeNode* node, const string& pre) {
        string s = pre + to_string(node->val);
        if (!node->left && !node->right){
            vec.push_back(s);
        }
        if(node->left) {
            recursive(node->left, s);
        }
        if(node->right) {
            recursive(node->right, s);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        vec = vector<string>();
        recursive(root, "");
        return accumulate(vec.begin(), vec.end(), 0, [](int seed, const string& s){ return seed + stoi(s); });
    }
};

int main() {
    auto t1 = TreeNode(1);
    auto t5 = TreeNode(5);
    auto t9 = TreeNode(9, &t5, &t1);
    auto t0 = TreeNode(0);
    auto t4 = TreeNode(4, &t9, &t0);
    auto expect = 1026;
    auto actual = Solution().sumNumbers(&t4);
    cout << __func__ <<" expect: " << expect <<", actual: " << actual <<"\n";
}