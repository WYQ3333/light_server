#include <iostream>
#include <stack>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        stack<TreeNode*> s;
        TreeNode* pPre = nullptr;
        TreeNode* pCur = pRootOfTree;
        TreeNode* pHead = nullptr;
        while(pCur || !s.empty()){
            while(pCur){
                s.push(pCur);
                pCur = pCur->left;
            }
            pCur = s.top();
            s.pop();
            if(pHead == nullptr){
                pHead = pCur;
            }
            if(pPre){
                pPre->right = pCur;
                pCur->left = pPre;
            }
            if(pCur->right){
                pPre = pCur;
                pCur = pCur->right;
            }
            else{
                if(!s.empty())
                    pCur->right = s.top();
                pPre = pCur;
                pCur = nullptr;
            }
            
        }
        return pHead;
    }
};
int main()
{
    return 0;
}

