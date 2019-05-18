#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//解决二叉树的层序遍历，将每一层的结果作为一个数组输出，定义了一个结构体，其中
//有一个level是用来标记二叉树的层数的

typedef struct Tree{
    int _level;
    TreeNode* _pRoot;
    Tree(int level = 0, TreeNode* pRoot = nullptr)
        :_level(level)
        ,_pRoot(pRoot)
        {}
}Tree;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> array;
        Tree t(1,root);
        queue<Tree> q;
        q.push(t);
        while(q.size()){
            vector<int> temp;
            Tree tm = q.front();
            int level = tm._level;
            temp.push_back(tm._pRoot->val);
            q.pop();
            if(tm._pRoot->left){
                Tree cur(tm._level + 1,tm._pRoot->left);
                q.push(cur);
            }
            if(tm._pRoot->right){
                Tree cur(tm._level + 1,tm._pRoot->right);
                q.push(cur);
            }
            while(q.size() && q.front()._level == level){
                Tree s = q.front();
                temp.push_back(q.front()._pRoot->val);
                q.pop();
                if(s._pRoot->left){
                    Tree cur(s._level + 1,s._pRoot->left);
                    q.push(cur);
                }
                if(s._pRoot->right){
                    Tree cur(s._level + 1,s._pRoot->right);
                    q.push(cur);
                }
            }
            array.push_back(temp);
        }
        return array;
    }
};
int main()
{
    return 0;
}

