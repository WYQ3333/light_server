/*
 *判断一个树是否为镜像，通过指定两个指针，一个从左边走，一个从右边走，
 *如果是镜像，则它们的val相等，树的结构也相同
 */

#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    bool ismirror(TreeNode* p, TreeNode* q){
        if(!p && !q){
            //都为NULL
            return true;
        }
        if(!q || !p){
            //有一个为NULL
            return false;
        }
        if(p->val == q->val){
            return ismirror(p->left, q->right) && ismirror(p->right, q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return ismirror(root, root);
    }
};

int main()
{
    return 0;
}

