#include <iostream>

struct ListNode{
    ListNode* next;
    int data;
};

class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(pHead == nullptr){
            return nullptr;
        }
        ListNode* first = pHead->next;
        ListNode* second = pHead;
        if(first == second){
            return first;
        }
        while(second != nullptr){
            while(first != second && first != nullptr){
                first = first->next;
            }
            if(first == second){
                return first;
            }
            else{
                return nullptr;
            }
            second = second->next;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}

