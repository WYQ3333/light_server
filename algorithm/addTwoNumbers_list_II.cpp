#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x)
        :val(x)
        ,next(nullptr)
    {}
}
class Solution {
public:
    void reverse_list(ListNode* head){
        if(head == nullptr)
            return;
        ListNode* pre = nullptr;
        ListNode* cur = head->next;
        head->next = nullptr;
        while(cur){
            pre = cur;
            cur = cur->next;
            pre->next = head->next;
            head->next = pre;
            int temp = head->val;
            head->val = pre->val;
            pre->val = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        if(!l1 && nullptr == l2){
            return l1;
        }
        if(l1 == nullptr && !l2){
            return l2;
        }
        reverse_list(l1);
        reverse_list(l2);
        ListNode* p = l1; int p_count = 0;
        ListNode* q = l2; int q_count = 0;
        while(p){
            p_count++;
            p = p->next;
        }
        while(q){
            q_count++;
            q = q->next;
        }
        if(p_count < q_count){
            swap(l1, l2);
        }
        p = l1; q = l2;
        while(q){
            p->val += q->val;
            p = p->next;
            q = q->next;
        }
        q = l1;
        while(q->next){
            if(q->next && q->val > 9){
                q->val -= 10;
                q->next->val += 1;
            }
            q = q->next;
        }
        if(q->next == nullptr&& q->val > 9){
            q->val -= 10;
            ListNode* newNode = new ListNode(1);
            newNode->next = nullptr;
            q->next = newNode;
        }
        reverse_list(l1);
        return l1;
    }
};

class Solution2{
public:
    ListNode* reverse_list(ListNode* head){
        if(list == nullptr)
            return nullptr;
        ListNode* pre = head;
        ListNode* cur = head;
        head = nullptr;
        while(cur){
            pre = cur;
            cur = cur->next;
            pre->next = head;
            head = pre;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        if(!l1 && nullptr == l2){
            return l1;
        }
        if(l1 == nullptr && !l2){
            return l2;
        }
        reverse_list(l1);
        reverse_list(l2);
        ListNode* p = l1; int p_count = 0;
        ListNode* q = l2; int q_count = 0;
        while(p){
            p_count++;
            p = p->next;
        }
        while(q){
            q_count++;
            q = q->next;
        }
        if(p_count < q_count){
            swap(l1, l2);
        }
        p = l1; q = l2;
        while(q){
            p->val += q->val;
            p = p->next;
            q = q->next;
        }
        q = l1;
        while(q->next){
            if(q->next && q->val > 9){
                q->val -= 10;
                q->next->val += 1;
            }
            q = q->next;
        }
        if(q->next == nullptr&& q->val > 9){
            q->val -= 10;
            ListNode* newNode = new ListNode(1);
            newNode->next = nullptr;
            q->next = newNode;
        }
        return l1;
    }
};
int main()
{
    return 0;
}

