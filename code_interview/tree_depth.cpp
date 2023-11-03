#include <iostream>
#include <assert.h>
using std::max;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val = 0, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right)
    {
    }
};

int tree_depth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(tree_depth(root->left), tree_depth(root->right)) + 1;
}

int main()
{
    {
        Node n6(6);
        Node n3(3, nullptr, &n6);
        Node n7(7);
        Node n4(4);
        Node n5(5, &n7, nullptr);
        Node n2(2, &n4, &n5);
        Node n1(1, &n2, &n3);

        int depth = tree_depth(&n1);
        assert(depth == 4);
    }
    std::cout << "finish" << std::endl;
}