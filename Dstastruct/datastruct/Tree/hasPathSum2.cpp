/*
 *查找和为sum的二叉树的路径，以vector的方式返回
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        int num = 0;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> s;
        vector<int> temp;           //记录一下，必须定义在外边，不然每次循环结束之前的值就丢了
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                num += cur->val;
                temp.push_back(cur->val);
                pre = cur;
                cur = cur->left;
            }
            cur = s.top();
            if(cur->left == nullptr && cur->right == nullptr){
                if(num == sum){
                    result.push_back(temp);
                }
            }
            if(cur->right && cur->right != pre){
                pre = cur;
                cur = cur->right;
            }
            else{
                num -= cur->val;
                if(!temp.empty())
                    temp.pop_back();
                pre = cur;
                s.pop();
                cur = nullptr;
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

