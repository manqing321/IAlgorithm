#include <iostream>
#include <assert.h>

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val = 0, Node *left = nullptr, Node *right = nullptr)
        : val(val), left(left), right(right) {}
};

Node *kth_node_core(Node *node, unsigned int &k)
{
    Node *target = nullptr;
    if (node->left != nullptr)
    {
        target = kth_node_core(node->left, k);
    }
    if (target == nullptr)
    {
        if (k == 1)
        {
            target = node;
        }
        k -= 1;
    }
    if (target == nullptr && node->right != nullptr)
    {
        target = kth_node_core(node->right, k);
    }
    return target;
}

int kth_node(Node *root, unsigned int k)
{
    if (root == nullptr || k < 1)
    {
        throw "invalid input";
    }

    Node *res = kth_node_core(root, k);
    if (res != nullptr)
    {
        return res->val;
    }
    throw "not found";
}

int main()
{
    {
        Node n2(2);
        Node n4(4);
        Node n3(3, &n2, &n4);

        Node n8(8);
        Node n6(6);
        Node n7(7, &n6, &n8);

        Node n5(5, &n3, &n7);
        int res = kth_node(&n5, 3);
        std::cout << "res is " << res << std::endl;
        assert(res == 4);
    }
    std::cout << "finish" << std::endl;
}