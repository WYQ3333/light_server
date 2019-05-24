#include <iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
        ,left(nullptr)
        ,right(nullptr)
    {}
};

//N叉树的先序遍历,非递归实现
class Solution3 {
public:
    vector<int> preorder(TreeNode* root) {
        if(nullptr == root)
            return {};
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()){
            if(cur == nullptr&&!s.empty()){
                cur = s.top();
                s.pop();
            }
            result.push_back(cur->val);
            if(!cur->children.empty()){
                for(int i = cur->children.size() - 1; i > 0 ; --i){
                    if(cur->children[i] != nullptr)
                        s.push(cur->children[i]);
                }
                cur = cur->children[0];
            }
            else{
                cur = nullptr;
            }
        }
        return result;
    }
};
//二叉树的前序非递归遍历
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(nullptr == root)
            return {};
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()){
            if(cur == nullptr&&!s.empty()){
                cur = s.top();
                s.pop();
            }
            result.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            cur = cur->left;
        }
        return result;
    }
};
//二叉树的非递归中序遍历，栈实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(nullptr == root)
            return {};
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* cur = root;
        while(nullptr != cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}

