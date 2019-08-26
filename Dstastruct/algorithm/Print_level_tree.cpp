#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
public:
    void Print_tree(vector<vector<int>>& result, TreeNode* pRoot, int index){
        if(pRoot == nullptr)
            return;
        if(result.size() <= index){
            vector<int> temp(1,pRoot->val);
            result.push_back(temp);
        }
        else{
            result[index].push_back(pRoot->val);
        }
        Print_tree(result, pRoot->left, index + 1);
        Print_tree(result, pRoot->right, index + 1);
    }
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == nullptr)
            return result;
        Print_tree(result, pRoot, 0);
        return result;
    }
    
};
int main()
{
    return 0;
}

