#include <iostream>
#include <stack>
using std::stack;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
class Solution {
public:
    int Height(TreeNode* pRoot){
        if(pRoot == nullptr)
            return 0;
        int left = Height(pRoot->left);
        int right = Height(pRoot->right);
        return left > right ? left + 1 : right + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        TreeNode* pCur = pRoot;
        stack<TreeNode*> s;
        while(pCur || !s.empty()){
            int left = 0;
            int right = 0;
            if(pCur == nullptr){
                pCur = s.top();
                s.pop();
            }
            if(pCur->left){
                left = Height(pCur->left);
            }
            if(pCur->right){
                right = Height(pCur->right);
                s.push(pCur->right);
            }
            if(left - right >=2 || right - left >= 2){
                return false;
            }
            pCur = pCur->left;
        }
        return true;
    }
};
int main()
{
    return 0;
}

