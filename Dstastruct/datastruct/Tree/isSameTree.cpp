/*
 *通过先序遍历判断两个树是否相同（树中结点相同，数的结构也相同）
 *
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q != nullptr)
            return false;
        if(p != nullptr && q == nullptr)
            return false;
        stack<TreeNode*> s_p;
        stack<TreeNode*> s_q;
        TreeNode* cur_p = p;
        TreeNode* cur_q = q;
        while((cur_p && cur_q) || (!s_p.empty() && !s_q.empty())){
            if(cur_p == nullptr && cur_q == nullptr){
                cur_p = s_p.top();
                cur_q = s_q.top();
                s_p.pop();
                s_q.pop();
            }
            else if((cur_p == nullptr && cur_q != nullptr) || (cur_p != nullptr && cur_q == nullptr)){
                return false;
            }
            if(cur_p->val != cur_q->val){
                return false;
            }
            if(cur_p->right && cur_q->right){
                s_p.push(cur_p->right);
                s_q.push(cur_q->right);
            }
            else if((!cur_p->right && cur_q->right) || (cur_p->right && !cur_q->right)){
                return false;
            }
            cur_p = cur_p->left;cur_q = cur_q->left;
        }
        if((!cur_p && cur_q) || (cur_p && !cur_q)){
            return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}

