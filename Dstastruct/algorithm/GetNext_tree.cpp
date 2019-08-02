/*
 *给一个节点，获取树的下一个节点
 */

#include <iostream>

struct TreeLinkNode{
    int val;
    struct TreeLinkNode* next;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    TreeLinkNode(int data):val(data), next(nullptr),left(nullptr),right(nullptr)
    {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(nullptr == pNode)
            return nullptr;
        TreeLinkNode* cur = nullptr;
        if(pNode->right){
            //找右子树的最左结点
            TreeLinkNode* temp = pNode->right;
            while(temp->left){
                temp = temp->left;
            }
            cur = temp;
        }
        else if(pNode->next){
            //找父节点,如果PNode是左子树，则返回其父节点，如果是右子树，需向上一直找父节点
            TreeLinkNode* pParent = pNode->next;
            TreeLinkNode* temp = pNode;
            while(pParent != nullptr && temp == pParent->right){
                temp = pParent;
                pParent = pParent->next;
            }
            cur = pParent;
        }
        return cur;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

