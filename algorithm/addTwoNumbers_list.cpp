#include <iostream>
#include<vector>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x)
        :val(x)
        ,next(nullptr)
    {}
}ListNode;

class Solution {
public:
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

class Solution_error{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if(l1 == nullptr && l2 != nullptr){
            return l1;
        }
        if(l1 != nullptr && l2 == nullptr){
            return l1;
        }
        ListNode* p = l1;
        int pcount = 0;
        ListNode* q = l2;
        int qcount = 0;
        while(p != nullptr){
            pcount++;
        }
        while(q != nullptr){
            qcount++;
        }
        if(pcount < qcount){
            ListNode* temp = p;
            p = q;
            q = temp;
        }
        ListNode* result = p;
        int i = 0; 
        while(q){
            i++;
            p->val = p->val + q->val;
            p = p->next;
        }
        while(p->next){
            if(p->val > 9){
                p->next->val += 1;
                p->val -= 10;
            }
        }
        if(p->val > 9){
            ListNode* newlist = new ListNode(1);
            p->val -= 10;
            p->next = nexlist;
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

