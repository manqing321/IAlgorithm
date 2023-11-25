#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using std::count_if;
using std::queue;
using std::string;
using std::vector;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *build(vector<string> vec)
{
    if (vec.empty() || vec.front().compare("null") == 0)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(vec.front()));
    auto iter = vec.begin() + 1;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        auto node = que.front();
        que.pop();
        if (iter != vec.end())
        {
            if (iter->compare("null"))
            {
                node->left = new TreeNode(stoi(*iter));
                que.push(node->left);
            }
            iter++;
        }
        if (iter != vec.end())
        {
            if (iter->compare("null"))
            {
                node->right = new TreeNode(stoi(*iter));
                que.push(node->right);
            }
            iter++;
        }
    }
    return root;
}

void dfs(TreeNode *node, vector<int> &vec, int &res)
{
    vec[node->val]++;
    if (node->left == nullptr && node->right == nullptr)
    {
        if (count_if(vec.begin(), vec.end(), [](int num)
                     { return num & 1; }) <= 1)
        {
            res += 1;
        }
        vec[node->val]--;
        return;
    }
    if (node->left != nullptr)
    {
        dfs(node->left, vec, res);
    }
    if (node->right != nullptr)
    {
        dfs(node->right, vec, res);
    }
    vec[node->val]--;
}

int pseudo_palindromic_paths(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    vector<int> vec(10, 0);
    int res = 0;
    dfs(root, vec, res);
    return res;
}

int main()
{
    // test 01
    {
        vector<string> source{"2", "3", "1", "3", "1", "null", "1"};
        TreeNode *root = build(source);
        int actual = pseudo_palindromic_paths(root);
        int target = 2;
        assert(actual == target);
    }
    // test 02
    {
        vector<string> source{"2", "1", "1", "1", "3", "null", "null", "null", "null", "null", "1"};
        TreeNode *root = build(source);
        int actual = pseudo_palindromic_paths(root);
        int target = 1;
        assert(actual == target);
    }
    // test 03
    {
        vector<string> source{"9", "5", "4", "5", "null", "2", "6", "2", "5", "null", "8", "3", "9",
                              "2", "3", "1", "1", "null", "4", "5", "4", "2", "2", "6", "4", "null",
                              "null", "1", "7", "null", "5", "4", "7", "null", "null", "7", "null",
                              "1", "5", "6", "1", "null", "null", "null", "null", "9", "2", "null",
                              "9", "7", "2", "1", "null", "null", "null", "6", "null", "null", "null",
                              "null", "null", "null", "null", "null", "null", "5", "null", "null", "3",
                              "null", "null", "null", "8", "null", "1", "null", "null", "8", "null",
                              "null", "null", "null", "2", "null", "8", "7"};
        TreeNode *root = build(source);
        int actual = pseudo_palindromic_paths(root);
        int target = 1;
        assert(actual == target);
    }
    std::cout << "finish" << std::endl;
}