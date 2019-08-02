/*
 *从尾到头打印单链表
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

class Solution{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> result;
        if(head == nullptr)
            return result;
        ListNode* cur = head;
        while(cur){
            result.push_back(cur->val);
            cur = cur->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> printListFromTailToHead2(ListNode* head){
        vector<int> result;
        if(nullptr == head)
            return result;
        stack<int> s;
        ListNode* cur = head;
        while(cur){
            s.push(cur->val);
            cur = cur->next;
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }

    //递归实现
    void print_num(ListNode* head, vector<int>& result){
        if(head == nullptr)
            return;
        print_num(head->next, result);
        result.push_back(head->val);
    }
    vector<int> printListFromTailToHead3(ListNode* head){
        vector<int> result;
        if(nullptr == head)
            return result;
        print_num(head, result);
        return result;
    }
};

int main()
{
    return 0;
}

