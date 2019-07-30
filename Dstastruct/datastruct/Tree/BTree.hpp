#pragma once
#include <iostream>
#include <string>
#include <errno.h>
#include <stack>
#include <queue>

struct BTreeNode{
    char val;
    struct BTreeNode* left;
    struct BTreeNode* right;
    BTreeNode(char data):val(data), left(nullptr), right(nullptr){}
};

class BTree
{
public:
    BTree() :root(nullptr){}
    BTreeNode* BuyNewNode(char data);                        //申请新的结点
    BTreeNode* CreateBTree(std::string Preorder, std::string Inorder); //创建二叉树
    int Height(BTreeNode* root);                            //求二叉树的高度
    BTreeNode* GetRoot();                                   //获取二叉树的根节点

    //树的遍历，递归版
    void Preorder_r(BTreeNode* p);                                        //前序遍历
    void Inorder_r(BTreeNode* p);                                         //中序遍历
    void Postorder_r(BTreeNode* p);                                       //后序遍历


    //树的遍历，非递归版
    void Preorder();                                        //前序遍历
    void Inorder();                                         //中序遍历
    void Postorder();                                       //后序遍历

    //树的层序遍历
    void Levelorder();                                      //层序遍历
    void _delete_root(BTreeNode* root);
    ~BTree();

private:
    BTreeNode* root;
};

BTreeNode* BTree::BuyNewNode(char data){
    BTreeNode* NewNode = new BTreeNode(data);
    if(NewNode == nullptr){
        perror("new NewNode error!!!");
        return nullptr;
    }
    return NewNode;
}

BTreeNode* BTree::CreateBTree(std::string Preorder, std::string Inorder){
    if(Preorder.size() != Inorder.size()){
        return nullptr;
    }
    if(Preorder.size() == 0){
        return nullptr;
    }
    BTreeNode* result = BuyNewNode(Preorder[0]);
    int index = Inorder.find(Preorder[0]);
    std::string left_str_ino = Inorder.substr(0, index);      //左子树的中序遍历
    std::string left_str_pre = Preorder.substr(1, left_str_ino.size()); //左子树的前序遍历
    result->left = CreateBTree(left_str_pre, left_str_ino);
    std::string right_str_ino = Inorder.substr(index + 1);  //右子树的中序遍历
    std::string right_str_pre = Preorder.substr(left_str_pre.size() + 1);   //右子树的前序遍历
    result->right = CreateBTree(right_str_pre, right_str_ino);
    root = result;
    return result;
}

int BTree::Height(BTreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int len_left = Height(root->left);
    int len_right = Height(root->right);
    return len_left > len_right ? len_left + 1: len_right + 1;
}

BTreeNode* BTree::GetRoot(){
    return root;
}



void BTree::Preorder_r(BTreeNode* p){
    if(p != nullptr){
        std::cout << p->val << " ";
        Preorder_r(p->left);
        Preorder_r(p->right);
    }
}
void BTree::Inorder_r(BTreeNode* p){
    if(p != nullptr){
        Inorder_r(p->left);
        std::cout << p->val << " ";
        Inorder_r(p->right);
    }
}
void BTree::Postorder_r(BTreeNode* p){
    if(p != nullptr){
        Postorder_r(p->left);
        Postorder_r(p->right);
        std::cout << p->val << " ";
    }
}
    //树的遍历，非递归版
void BTree::Preorder(){
    std::stack<BTreeNode*> s;
    if(root == nullptr){
        return;
    }
    BTreeNode* cur = root;
    while(cur || !s.empty()){
        if(cur == nullptr){
            cur = s.top();
            s.pop();
        }
        std::cout << cur->val << " ";
        if(cur->right){
            s.push(cur->right);
        }
        cur = cur->left;
    }
}
//非递归的中序遍历
void BTree::Inorder(){
    std::stack<BTreeNode*> s;
    if(root == nullptr){
        return;
    }
    BTreeNode* cur = root;
    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        std::cout << cur->val << " ";
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = nullptr;
        }
    }
}

//非递归后序遍历
void BTree::Postorder(){
    if(root == nullptr){
        return;
    }
    BTreeNode* cur = root;
    BTreeNode* pre = nullptr;     //表记cur之前走过的结点
    std::stack<BTreeNode*> s;
    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            pre = cur;
            cur = cur->left;
        }
        cur = s.top();
        if(cur->right && cur->right != pre){
            pre = cur;
            cur = cur->right;
        }
        else{
            std::cout << cur->val << " ";
            pre = cur;
            cur = nullptr;
            s.pop();
        }
    }
}
//树的层序遍历
void BTree::Levelorder(){
    if(root == nullptr){
        return;
    }
    std::queue<BTreeNode*> q;
    BTreeNode* cur = root;
    while(cur || !q.empty()){
        if(cur){
            std::cout << cur->val << " ";
            if(cur->right){
                q.push(cur->right);
            }
            cur = cur->left;
        }
        else{
            cur = q.front();
            q.pop();
        }
    }
}

void BTree::_delete_root(BTreeNode* root){
    if(root == nullptr){
        return;
    }
    _delete_root(root->left);
    _delete_root(root->right);
    delete root;
    root = nullptr;
}

BTree::~BTree() {
    //后序遍历销毁二叉树
    if(root != nullptr){
        _delete_root(root);
    }
}


