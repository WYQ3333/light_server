#include <iostream>
#include <math.h>
using namespace std;
struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        ListNode* first = headA;
        ListNode* second = headB;
        while(first != second){
            first = first == nullptr? headB : first->next;
            second = second == nullptr ? headA : second->next;
        }
        return first;
    }
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB){
       //先求链表headA的长度，再求headB的长度，求两条链表长度差值，长的链表移动差值位置，
       //再开始比较两个指针，出现相同的则是相交节点。
       //判断两个ListNode是否相等就可以保证后面都相等了，因为保证了后面的next指针都相同 
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        ListNode* cur = headA;
        int lenA = 0;
        int lenB = 0;
        while(cur){
            lenA++;
            cur = cur->next;
        }
        cur = headB;
        while(cur){
            lenB++;
            cur = cur->next;
        }
        int len = lenA > lenB ? lenA-lenB:lenB-lenA;
        cur = lenA > lenB ? headA:headB;
        ListNode* p = lenA > lenB ? headB:headA;
        int count = 0;
        while(count != len){
            count++;
            cur = cur->next;
        }
        while(p && cur){
            if(p == cur){
                return p;
            }
            cur = cur->next;
            p = p->next;
        }
        return nullptr;
    } 
};

int main()
{
    return 0;
}

