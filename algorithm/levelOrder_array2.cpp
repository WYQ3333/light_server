#include <iostream>
#include<vector>

using namespace std;
class Solution {
public:
    // 对于递归来说，如果让一个数组变量为所有递归共用的话，参数必须要有该变量的指针或者引用的形式
    // 当然，也可以使用全局变量
    void dfs(TreeNode* root,int level,vector<vector<int>> &result)
    {
        if (root == NULL)
        {
            return;
        }
        // 为下一层预备
        if (level >= result.size())
        {
            // 这样的操作把一个空vector，加入到二维vertor中
            result.push_back(vector<int> {});
        }
        result[level].push_back(root->val);
        dfs(root->left,level+1,result);
        dfs(root->right,level+1,result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        dfs(root,0,result);
        return result;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

