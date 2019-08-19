#include <iostream>
struct ListNode{
    int val;
    struct ListNode* next;
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        int num = pHead->val;
        ListNode* pCur = pHead->next;
        ListNode* pPre = pHead;
        ListNode* t = nullptr;
        while(pCur){
            if(pCur->val == num && pHead->val == num){
                while(pCur && pCur->val == num){
                    pCur = pCur->next;
                }
                while(pHead != pCur){
                    pHead = pHead->next;
                    delete pPre;
                    pPre = pHead;
                }
                if(pCur == nullptr)
                    return pHead;
                num = pCur->val;
                pCur = pCur->next;
            }
            else if(pCur->val != num){
                num = pCur->val;
                t = pPre;
                pPre = pCur;
                pCur = pCur->next;
            }
            else{
                while(pCur && pCur->val == num){
                    pCur = pCur->next;
                }
                while(t->next != pCur){
                    t->next = pPre->next;
                    delete pPre;
                    pPre = t->next;
                }
                if(pCur == nullptr)
                    return pHead;
                num = pCur->val;
                pCur = pCur->next;
            }
        }
        return pHead;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

