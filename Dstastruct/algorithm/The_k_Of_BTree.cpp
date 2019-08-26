#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data)
        :val(data)
        ,left(nullptr)
        ,right(nullptr)
    {}
};
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr)
            return nullptr;
        if(k <= 0){
            return nullptr;
        }
        stack<TreeNode*> s;
        vector<TreeNode*> array;
        TreeNode* pCur = pRoot;
        while(pCur || !s.empty()){
            while(pCur){
                s.push(pCur);
                pCur = pCur->left;
            }
            pCur = s.top();
            s.pop();
            array.push_back(pCur);
            if(pCur->right){
                pCur = pCur->right;
            }
            else
                pCur = nullptr;
        }
        if(k > array.size())
            return nullptr;
        return array[k - 1];
    }

    void Inorder(TreeNode* pRoot, TreeNode* Result){
        if(pRoot == nullptr)
            return;
        Inorder(pRoot, Result);
        if(count == 0){
            Result = pRoot;
        }
        Inorder(pRoot, Result);
    }

    TreeNode* KthNode2(TreeNode* pRoot, int k){
        if(pRoot == nullptr)
            return nullptr;
        TreeNode* result = nullptr;
        count = k;
        Inorder(pRoot, result);
        return result;
    }

private:
    int count;
};

int main()
{
    return 0;
}

