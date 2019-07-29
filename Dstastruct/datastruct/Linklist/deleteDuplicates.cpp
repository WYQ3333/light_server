#include <iostream>

struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        int num = head->val;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val == num){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                num = cur->val;
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}

