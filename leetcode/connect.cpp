#include <iostream>
#include <assert.h>
#include <queue>
using std::queue;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void connect_core(queue<Node *> &que1, queue<Node *> &que2)
{
    if (que1.empty())
    {
        return;
    }
    Node *pre_node = nullptr;
    while (!que1.empty())
    {
        Node *node = que1.front();
        que1.pop();
        if (pre_node == nullptr)
        {
            pre_node = node;
        }
        else
        {
            pre_node->next = node;
            pre_node = node;
        }
        if (node->left != nullptr)
        {
            que2.push(node->left);
        }
        if (node->right != nullptr)
        {
            que2.push(node->right);
        }
    }
    connect_core(que2, que1);
}

Node *connect(Node *root)
{
    if (root == nullptr)
    {
        return root;
    }
    queue<Node *> que1;
    queue<Node *> que2;
    que1.push(root);
    connect_core(que1, que2);
    return root;
}

int main()
{
    {
        Node n1(1);
        Node n2(2);
        Node n3(3);
        Node n4(4);
        Node n5(5);
        Node n7(7);
        n1.left = &n2;
        n1.right = &n3;
        n2.left = &n4;
        n2.right = &n5;
        n3.right = &n7;
        connect(&n1);
        assert(n1.next == nullptr);
        assert(n2.next == &n3);
        assert(n3.next == nullptr);
        assert(n4.next == &n5);
        assert(n5.next == &n7);
        assert(n7.next == nullptr);
    }
    std::cout << "finish" << std::endl;
}