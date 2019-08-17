/*
 *判断一个树是否为另一个树的子结构
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
    bool IsTheSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == nullptr && pRoot2)
            return false;
        if(pRoot2 == nullptr && pRoot1){
            return true;
        }
        if(pRoot1 == nullptr && pRoot2 == nullptr){
            return true;
        }
        if(pRoot1->val != pRoot2->val){
            return false;
        }
        if(IsTheSubtree(pRoot1->left, pRoot2->left)){
            if(IsTheSubtree(pRoot1->right, pRoot2->right))
                return true;
        }
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr){
            return false;
        }
        bool flag = false;
        TreeNode* pCur = pRoot1;
        stack<TreeNode*> s;
        while(pCur || !s.empty()){
            if(pCur == nullptr){
                pCur = s.top();
                s.pop();
            }
            if(pCur->right)
                s.push(pCur->right);
            if(pCur->val == pRoot2->val){
                flag = IsTheSubtree(pCur, pRoot2);
                if(flag == true){
                    break;
                }
            }
            pCur = pCur->left;
        }
        return flag;
    }
};
int main()
{
    return 0;
}

