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

//之字形打印二叉树，第一行从左到右打印，第二行从右往左打印
class Solution2 {
public:
    void Print_tree(TreeNode* pRoot, vector<vector<int>>& result, int index){
        if(pRoot == nullptr)
            return;
        if(result.size() <= index){
            vector<int> temp(1,pRoot->val);
            result.push_back(temp);
        }
        else{
            result[index].push_back(pRoot->val);
        }
        Print_tree(pRoot->left, result, index + 1);
        Print_tree(pRoot->right, result, index + 1);
    }
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == nullptr)
            return result;
        Print_tree(pRoot, result, 0);
        for(size_t i = 0; i < result.size(); ++i){
            if(i % 2 != 0){
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}

