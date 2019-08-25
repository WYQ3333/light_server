#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* pCur = head->next;
        ListNode* pPre = head;
        while(pCur){
            if(pCur->val >= pPre->val){
                pPre = pCur;
                pCur = pCur->next;
            }
            else{
                ListNode* pPretemp = nullptr;
                ListNode* temp = head;
                while(temp->val < pCur->val){
                    pPretemp = temp;
                    temp = temp->next;
                }
                if(pPretemp == nullptr){
                    //头插
                    pPre->next = pCur->next;
                    pCur->next = head;
                    head = pCur;
                    pCur = pPre->next;
                }
                else{
                    pPre->next = pCur->next;
                    pPretemp->next = pCur;
                    pCur->next = temp;
                    pCur = pPre->next;
                }
            }
        }
        return head;
    }
    ListNode* insertionSortList2(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        vector<int> array;
        ListNode* pCur = head;
        while(pCur){
            array.push_back(pCur->val);
            pCur = pCur->next;
        }
        sort(array.begin(), array.end());
        pCur = head;
        int index = 0;
        while(pCur){
            pCur->val = array[index++];
            pCur = pCur->next;
        }
        return head;
    }
};
int main()
{
    return 0;
}

