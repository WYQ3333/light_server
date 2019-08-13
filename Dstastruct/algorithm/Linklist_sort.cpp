#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution1 {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
       	vector<int> v;
        for(ListNode* p=head;p;p=p->next){
            v.push_back(p->val);
        }
        sort(v.begin(),v.end());
        int i=0;
        for(ListNode* p=head;p;p=p->next){
            p->val=v[i++];
        }
        return head;
    }
   
};


class Solution_quck_sort {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        sortList(head,NULL);
        return head;
    }
    void sortList(ListNode *head,ListNode *tail){
        if(head==tail)
            return;
        ListNode *mid=partition(head,tail);
        sortList(head,mid);
        sortList(mid->next,tail);
    }
    ListNode* partition(ListNode *node,ListNode *tail){
        ListNode *cur=node;
        ListNode *next=node->next;
        while(next!=tail){
            if(next->val<node->val){
                cur=cur->next;
                swap(cur->val,next->val);
            }
            next=next->next;
        }
        swap(cur->val,node->val);
        return cur;
    }
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       ListNode *fast=head->next,*slow=head;
       while(fast!=NULL&&fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
        ListNode* head2=slow->next;
        slow->next=NULL;
        ListNode *p1=sortList(head);
        ListNode *p2=sortList(head2);
        ListNode *p=merge(p1,p2);
       	return p;
    }
   	ListNode* merge(ListNode* p1,ListNode* p2){
        if(p1==NULL) return p2;
        if(p2==NULL) return p1;
        ListNode* phead;
        if(p1->val<p2->val){
           	phead=p1;
            phead->next=merge(p1->next,p2);
        }
        else{
            phead=p2;
            phead->next=merge(p1,p2->next);
        }
        return phead;
    }
};

int main()
{
    return 0;
}

