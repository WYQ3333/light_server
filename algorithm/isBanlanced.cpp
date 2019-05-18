#include <iostream>
using namespace std;

//解法1，求出每个结点的左右子树的高度差，放在TreeNode* pre->val中
//再通过二叉树的非递归先序遍历判断是否存在不平衡的现象
//该方法时间复杂度太高

class Solution1{
public:
    
    int Height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        
        int left = Height(root->left);
        int right = Height(root->right);
        root->val = abs(right - left);
        return left > right ? left + 1 : right + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int result = Height(root);
        stack<TreeNode*> s;
        TreeNode* pRoot = root;
        while(pRoot || s.size()){
            if(pRoot->right)
                s.push(pRoot->right);
            if(pRoot->val > 1){
                return false;
            }
            pRoot = pRoot->left;
            if(pRoot == nullptr && s.size() > 0){
                pRoot= s.top();
                s.pop();
            }
        }
        return true;
    }
};

//方法2；递归实现

class Solution{
public:

    int countlevel(TreeNode* pRoot){
        if(nullptr == pRoot)
            return 0;
        return max(countlevel(pRoot->right), countlevel(pRoot->left)) + 1;
    }

    bool isBalanced(TreeNode* root){
        if(root == nullptr){
            return true;
        }
        else if(abs(countlevel(root->right) - countlevel(root->left)) > 1){
            return false;
        }
        return isBalanced(root->right) && isBalanced(root->left);
    }
};

int main()
{
    return 0;
}

