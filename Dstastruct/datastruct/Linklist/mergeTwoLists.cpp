#include <iostream>

struct ListNode{
    int val;
    struct ListNOde* next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* result = nullptr;
        ListNode* end = nullptr;
        while(first != nullptr && second != nullptr){
            if(first->val < second->val){
                if(result == nullptr){
                    result = first;
                    end = result;
                    first = first->next;
                    end->next == nullptr;
                }
                else{
                    end->next = first;
                    first = first->next;
                    end = end->next;
                    end->next = nullptr;
                }
            }
            else if(first->val > second->val){
                if(result == nullptr){
                    result = second;
                    end = result;
                    second = second->next;
                    end->next == nullptr;
                }
                else{
                    end->next = second;
                    second = second->next;
                    end = end->next;
                    end->next = nullptr;
                }
            }
            else{
                if(result == nullptr){
                    result = first;
                    first = first->next;
                    end = result;
                    end->next = second;
                    second = second->next;
                    end = end->next;
                    end->next = nullptr;
                }
                else{
                    end->next = first;
                    first = first->next;
                    end = end->next;
                    end->next = second;
                    second = second->next;
                    end = end->next;
                    end->next = nullptr;
                }

            }
        }
        if(first != nullptr){
            end->next = first;
        }
        if(second != nullptr){
            end->next = second;
        }
        return result;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

