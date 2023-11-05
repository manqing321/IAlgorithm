#include <iostream>
#include <assert.h>
#include <map>
#include <algorithm>
using std::make_pair;
using std::map;
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

bool is_balanced_core(Node *node, int *depth)
{
    if (node == nullptr)
    {
        *depth = 0;
        return true;
    }
    int left, right;
    if (is_balanced_core(node->left, &left) && is_balanced_core(node->right, &right))
    {
        int diff = left - right;
        if (diff > -2 && diff < 2)
        {
            *depth = 1 + max(left, right);
            return true;
        }
    }
    return false;
}

bool is_balanced(Node *root)
{
    int depth = 0;
    return is_balanced_core(root, &depth);
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

        bool is_balance = is_balanced(&n1);
        assert(is_balance);
    }
    std::cout << "finish" << std::endl;
}
