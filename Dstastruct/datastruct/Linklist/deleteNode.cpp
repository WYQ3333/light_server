#include <iostream>
/*
 *删除非尾结点
 */
struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr)
            return;
        ListNode* cur = node->next;
        node->val = cur->val;
        node->next = cur->next;
        delete cur;
        cur = nullptr;
    }
};
int main()
{
    return 0;
}

