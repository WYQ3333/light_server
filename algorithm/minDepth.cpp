#include <iostream>
using namespace std;

class Solution{
public:

    int countlevel(TreeNode* root){
        if(nullptr == root)
            return 0;
        int left = countlevel(root->left);
        int right = countlevel(root->right);
        if(left == 0){
            return right + 1;
        }
        if(right == 0){
            return left + 1;
        }
        return left < right ? left + 1 : right + 1;
    }

    int minDepth(TreeNode* root){
        if(nullptr == root)
            return 0;
        return countlevel(root);
    }
};

int main()
{
    return 0;
}

