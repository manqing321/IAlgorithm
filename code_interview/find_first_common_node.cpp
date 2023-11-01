#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *find_first_common_node(ListNode *first, ListNode *second)
{
    if (first == nullptr || second == nullptr)
    {
        return nullptr;
    }
    // 计算出两条链表的长度
    int len1 = 0;
    int len2 = 0;
    ListNode *p = first;
    while (p != nullptr)
    {
        ++len1;
        p = p->next;
    }
    p = second;
    while (p != nullptr)
    {
        ++len2;
        p = p->next;
    }
    // 让长链表先走 step
    ListNode *longer = first;
    ListNode *shorter = second;
    int step = len1 - len2;
    if (step < 0)
    {
        longer = second;
        shorter = first;
        step = len2 - len1;
    }
    for (size_t i = 0; i < step; i++)
    {
        if (longer != nullptr)
        {
            longer = longer->next;
        }
    }
    // 最终一起往前走，会在第一个公共节点碰头
    while (longer != nullptr && shorter != nullptr)
    {
        if (longer == shorter)
        {
            return longer;
        }
        else
        {
            longer = longer->next;
            shorter = shorter->next;
        }
    }
    return nullptr;
}

int main()
{
    ListNode l7{7, nullptr};
    ListNode l6{6, &l7};
    ListNode l5{5, &l6};
    ListNode l4{4, &l5};
    ListNode l3{3, &l6};
    ListNode l2{2, &l3};
    ListNode l1{1, &l2};
    auto res = find_first_common_node(&l1, &l4);
    assert(res == &l6);
    std::cout << "finish" << std::endl;
    return 0;
}
