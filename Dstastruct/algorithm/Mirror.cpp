#include <iostream>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
         
        TreeNode *pTmp;
            pTmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
int main()
{
    return 0;
}

