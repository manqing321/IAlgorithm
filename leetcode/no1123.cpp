#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* node) {
    auto que = queue<TreeNode*>();
    que.push(node);
    int len = que.size();
    while(len)
    {
        auto ptr = que.front();
        if (ptr->left){
            que.push(ptr->left);
        }
        if (ptr->right){
            que.push(ptr->right);
        }
        cout << ptr->val <<" ";
        que.pop();
        len -= 1;
        if(len == 0) {
            len = que.size();
            cout << endl;
        }
    }
}

class Solution {
public:
    pair<TreeNode*, int> find(TreeNode* node) {
        if(node == nullptr){
            return {node, 0};
        }
        auto left = find(node->left);
        auto right = find(node->right);
        if(left.second > right.second)
        {
            return left;
        }else if (left.second < right.second){
            return right;
        }
        return {node, left.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return find(root).first;
    }
};

int main(){
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t4 = new TreeNode(4, nullptr, t5);
    TreeNode* t3 = new TreeNode(3, nullptr, t6);
    TreeNode* t2 = new TreeNode(2, t3, t4);
    TreeNode* t1 = new TreeNode(1, t2, nullptr);
    print( Solution().lcaDeepestLeaves(t1) );
}
