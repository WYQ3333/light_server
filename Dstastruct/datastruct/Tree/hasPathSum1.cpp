/*
 *判断二叉树的一条路劲上的值的总和是否等于给定的sum值，如果等于，返回true，否则返回false
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> s;
        int num = 0;
        while(cur || !s.empty()){
            while(cur){
                pre = cur;
                s.push(cur);
                num += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if(cur->left == nullptr && cur->right == nullptr){
                if(sum == num){
                    return true;
                }
            }
            if(cur->right && cur->right != pre){
                pre = cur;
                cur = cur->right;
            }
            else{
                num -= cur->val;
                pre = cur;
                s.pop();
                cur = nullptr;
            }
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

