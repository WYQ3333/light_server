#include <iostream>
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int data):val(data), next(nullptr){}
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(pHead == nullptr)
            return nullptr;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast->next && slow){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(fast->next == nullptr || fast == nullptr){
            //此时说明链表中没有环
            return nullptr;
        }
        //链表中有环
        fast = pHead;
        while(fast && slow){
            if(fast == slow){
                return fast;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return nullptr;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

