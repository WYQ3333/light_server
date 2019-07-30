/*
 *求二叉树的所有左叶子节点的和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sum = 0;
        TreeNode* pre = nullptr;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                pre = cur;
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(!s.empty())
                pre = s.top();
            else
                pre = cur;
            if(pre->left == cur && cur->left == nullptr && cur->right == nullptr){
                sum += cur->val;
            }
            if(cur->right){
                pre = cur;
                cur = cur->right;
            }
            else{
                cur = nullptr;
            }
        }
        return sum;
    }
};
int main()
{
    return 0;
}

