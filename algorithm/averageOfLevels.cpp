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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> result;
        Dfs(result, root,0);
        vector<double> answer;
        for(size_t i = 0; i < result.size(); ++i){
            double t = 0;
            for(size_t j = 0; j < result[i].size(); ++j){
                t += result[i][j];
            }
            answer.push_back(t/result[i].size());
        }
        return answer;
    }
};
int main()
{
    return 0;
}

