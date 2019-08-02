#include <iostream>
#include <vector>
using std::vector;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data):val(data), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* create(vector<int>& pre, vector<int>& vin, int pleft, int pright, int Ileft, int Iright){
        if(pleft >= pright || Ileft >= Iright)
            return nullptr;
        int head_val = pre[pleft];
        int index = -1;
        for(int i = Ileft; i < Iright; ++i){
            if(vin[i] == head_val){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(head_val);
        root->left = create(pre, vin, pleft+1, pleft + index - Ileft + 1, Ileft, index);
        root->right = create(pre , vin, pleft + index - Ileft + 1, pright, index + 1, Iright);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() != vin.size())
            return nullptr;
        TreeNode* root = create(pre,vin, 0, pre.size(), 0, vin.size());
        return root;
    }
};
int main()
{
    return 0;
}

