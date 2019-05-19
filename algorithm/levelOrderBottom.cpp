#include <iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void Dfs(vector<vector<int>>& result, TreeNode* root,int k){
        if(root == nullptr)
            return;
        if(result.size() <= k){
            result.push_back(vector<int> {});
        }
        result[k].push_back(root->val);
        if(root->left)
            Dfs(result,root->left,k+1);
        if(root->right)
            Dfs(result,root->right,k+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> result;
        Dfs(result, root,0);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    return 0;
}

