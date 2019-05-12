#include<iostream>
using namespace std;
class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur){
            pre = pre->next;
            cur = cur->next;
            if(cur == nullptr){
                return nullptr;
            }
            cur = cur->next;
            if(cur == nullptr){
                return nullptr;
            }
            if(pre == cur){
                break;
            }
        }
        cur = head;
        while(cur != pre){
            cur = cur->next;
            pre = pre->next;
        }
        return pre;
    }
};

int main(){
    return 0;
}
