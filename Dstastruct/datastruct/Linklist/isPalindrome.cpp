#include <iostream>

/*
 *判断一个链表是否为回文链表，方法是：找链表的中心，将后半部分进行逆置，然后依次判断是否值相等
 */
struct ListNode{
    int val;
    struct ListNode* next;
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //先翻转链表，在逐个进行比较
        if(head == nullptr){
            return true;
        }
        if(head->next == nullptr){
            return true;
        }
        int len = 0;
        ListNode* result = nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            len++;
            cur = cur->next;
        }
        int center = (len + 1)/2;
        int len1 = 1;
        cur = head;
        while(len1 != center){
            cur = cur->next;
            len1++;
        }
        result = cur;
        cur = cur->next;
        result->next = nullptr;
        while(cur){
            if(result->next == nullptr){
                pre = cur;
                cur = cur->next;
                pre->next = nullptr;
                result->next = pre;
                
            }
            else{
                pre = cur;
                cur = cur->next;
                pre->next = result->next;
                result->next = pre;
            }
        }
        pre = head;
        cur = result->next;
        for(int i = 1; i <= (len%2 == 0 ? len1:len1 - 1) && pre != nullptr && cur != nullptr; ++i){
            if(pre->val != cur->val){
                return false;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return true;
    }
};
int main()
{
    return 0;
}

