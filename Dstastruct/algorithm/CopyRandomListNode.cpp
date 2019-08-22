/*
 *复杂链表的复制
 */
#include <iostream>
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        RandomListNode* pCur = pHead;
        while(pCur){
            RandomListNode* temp = new RandomListNode(pCur->label);
            temp->next = pCur->next;
            pCur->next = temp;
            pCur = temp->next;
        }
        pCur = pHead->next;
        RandomListNode* pPre = pHead;
        while(pCur){
            if(pPre->random){
                pCur->random = pPre->random->next;
            }
            pPre = pCur->next;
            if(pPre == nullptr){
                pCur = nullptr;
            }
            else
                pCur = pPre->next;
        }
        pCur = pHead->next;
        pPre = pHead;
        RandomListNode* pNewHead = nullptr;
        RandomListNode* pt = pNewHead;
        while(pCur){
            if(pNewHead == nullptr){
                pNewHead = pCur;
                pt = pNewHead;
                pPre->next = pCur->next;
                pPre = pPre->next;
                if(pPre == nullptr){
                    pCur = nullptr;
                }
                else{
                    pCur->next = nullptr;
                    pCur = pPre->next;
                }
            }
            else{
                pt->next = pCur;
                pt = pt->next;
                pPre->next = pCur->next;
                pPre = pPre->next;
                if(pPre == nullptr){
                    pCur = nullptr;
                }
                else{
                    pCur->next = nullptr;
                    pCur = pPre->next;
                }
            }
        }
        return pNewHead;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

