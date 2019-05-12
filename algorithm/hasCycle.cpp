#include <iostream>

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* pre = head;
        ListNode* cur = head;
        int index = 0;
        while(cur){
            index++;
            if(index%2 == 0){
                cur = cur->next;
                pre = pre->next;
            }
            else{
                cur = cur->next;
            }
            if(cur == nullptr){
                return false;
            }
            if(pre >= cur){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head,*slow=head;
        while(fast && slow){
            fast=fast->next;
            if(!fast) return false;
            fast=fast->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

