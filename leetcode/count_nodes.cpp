#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
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

inline int left_depth(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + left_depth(node->left);
}
inline int right_depth(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + right_depth(node->right);
}
int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = left_depth(root);
    int right = right_depth(root);
    if (left == right)
    {
        return (1 << left) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    // test 01
    {
        vector<string> source{"1", "2", "3", "4", "5", "6"};
        auto head = build(source);
        int actual = countNodes(head);
        int target = 6;
        assert(target == actual);
    }

    std::cout << "finish" << std::endl;
}