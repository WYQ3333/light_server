#pragma once
#include<iostream>

template<class T>
struct AVLTreeNode{
    typedef AVLTreeNode<T> AVLTNode;
    typedef AVLTNode* pAVLTNode;

    AVLTreeNode(const T& weight)
        :_pLeft(nullptr)
        ,_pRight(nullptr)
        ,_pParent(nullptr)
        ,_weight(weight)
        ,_bg(0)
    {}

    pAVLTNode _pLeft;
    pAVLTNode _pRight;
    pAVLTNode _pParent;
    T _weight;       //weight
    int _bg;         //average num

};

template<class T>
class AVLTree{
    typedef AVLTreeNode<T> AVLTNode;
    typedef AVLTNode* pAVLTNode;
public:
    AVLTree()
        :_pRoot(nullptr)
    {}

    ~AVLTree(){
        _AVLTree(_pRoot);
    }

    bool Insert(const T& data){
        if(_pRoot == nullptr){
            _pRoot = new AVLTNode(data);
            return true;
        }
        pAVLTNode pCur = _pRoot;
        pAVLTNode pParent = _pRoot;
        while(pCur){
            pParent = pCur;
            if(data == pCur->_weight){
                return false;
            }
            else if(data < pCur->_weight){
                pCur = pCur->_pLeft;
            }
            else{
                pCur = pCur->_pRight;
            }
        }
        //insert new node
        //left -1,right 1
        pCur = new AVLTNode(data);
        if(data < pParent->_weight){
            pParent->_pLeft = pCur;
        }
        else{
            pParent->_pRight = pCur;
        }
        pCur->_pParent = pParent;

        //check bg if in [-1,0,1];update bg;
        while(pParent){
            if(pCur == pParent->_pLeft){
                pParent->_bg--;
            }
            else{
                pParent->_bg++;
            }

            if(0 == pParent->_bg){
                break;
            }
            else if(1 == pParent->_bg || -1 == pParent->_bg){
                //go up level to update fg
                pCur = pParent;
                pParent = pParent->_pParent;
            }
            else{
                //avltree is not average, need to update
                if(pParent->_bg == 2){
                    if(pCur->_bg == 1){
                        //left_rotate
                        _RotateL(pParent);
                    }
                    else{
                        _RotateRL(pParent);
                    }
                }
                else{
                    if(pCur->_bg == -1){
                        //right_rotate
                        _RotateR(pParent);
                    }
                    else{
                        //first Left_rotate then Right_rotate
                        _RotateLR(pParent);
                    }
                }
            }
        }
    }

    pAVLTNode find(const T& data){
        pAVLTNode pCur = _pRoot;
        while(pCur){
            if(pCur->_weight == data){
                return pCur;
            }
            else if(pCur->_weight > data){
                pCur = pCur->_pLeft;
            }
            else{
                pCur = pCur->_pRight;
            }
        }
        if(pCur == nullptr){
            return nullptr;
        }
    }

    pAVLTNode GetRoot(){
        return _pRoot;
    }

    void Inorder(){
        _Inorder(_pRoot);
    }

    void Inorder_bg(){
        _Inorder_bg(_pRoot);
    }

private:

    void _Inorder_bg(pAVLTNode pRoot){
        if(pRoot == nullptr){
            return;
        }
        _Inorder_bg(pRoot->_pLeft);
        std::cout << pRoot->_bg << " ";
        _Inorder_bg(pRoot->_pRight);
    }

    void _Inorder(pAVLTNode pRoot){
        if(pRoot == nullptr){
            return;
        }
        _Inorder(pRoot->_pLeft);
        std::cout << pRoot->_weight;
        _Inorder(pRoot->_pRight);
    }
    void _RotateLR(pAVLTNode pParent){
        pAVLTNode pSubL = pParent->_pLeft;
        pAVLTNode pSubLR = pSubL->_pRight;
        int bf = pSubLR->_bg;
        _RotateL(pParent->_pLeft);
        _RotateR(pParent);
        if(bf == 1){
            pSubL->_bg = -1;
            pParent->_bg = 0;
        }
        else if(bf == -1){
            pParent->_bg = 1;
            pSubL->_bg = 0;
        }
    }

    void _RotateRL(pAVLTNode pParent){
        pAVLTNode pSubR = pParent->_pRight;
        pAVLTNode pSubRL = pSubR->_pLeft;
        int bf = pSubRL->_bg;
        _RotateR(pParent->_pLeft);
        _RotateL(pParent);

        if(bf == 1){
            pSubR->_bg = 0;
            pParent->_bg = -1;
        }
        else if(bf == -1){
            pParent->_bg = 0;
            pSubR->_bg = 1;
        }
    }

    void _RotateL(pAVLTNode pParent){
        pAVLTNode pSubR = pParent->_pRight;
        pAVLTNode pSubRL = pSubR->_pLeft;
        pParent->_pRight = pSubRL;
        if(pSubRL){
            pSubRL->_pParent = pParent;
        }
        pSubR->_pLeft = pParent;
        pAVLTNode ppParent = pParent->_pParent;
        pSubR->_pParent = ppParent;
        pParent->_pParent = pSubR;
        if(ppParent == nullptr){
            _pRoot = pSubR;
        }
        else{
            if(pParent == ppParent->_pLeft){
                ppParent->_pLeft = pSubR;
            }
            else{
                ppParent->_pRight = pSubR;
            }
        }
        if(pSubRL == nullptr){
            pParent->_bg = -1;
        }
        else{
            pParent->_bg = 0;
        }
        pSubR->_bg = 0;
    }

    void _RotateR(pAVLTNode pParent){
        //pParent->_pLeft is not nullptr
        pAVLTNode pSubL = pParent->_pLeft;
        pAVLTNode pSubLR = pSubL->_pRight;
        pParent->_pLeft = pSubLR;
        if(pSubLR){
            //if pSubLR is not nullptr
            pSubLR->_pParent = pParent;
        }
        pSubL->_pRight = pParent;
        pAVLTNode ppParent = pParent->_pParent;
        pParent->_pParent = pSubL;
        pSubL->_pParent = ppParent;
        if(nullptr == ppParent){
            _pRoot = pSubL;
        }
        else if(pParent == ppParent->_pLeft){
            ppParent->_pLeft = pSubL;
        }
        else{
            ppParent->_pRight = pSubL;
        }
        
        if(pSubLR == nullptr){
            pParent->_bg = 1;
        }
        else{
            pParent->_bg = 0;
        }
        pSubL->_bg = 0;
    }
private:
    void _AVLTree(pAVLTNode pRoot){
        if(pRoot){
            _AVLTree(pRoot->_pLeft);
            _AVLTree(pRoot->_pRight);
            delete pRoot;
            pRoot = nullptr;
        }
    }
    pAVLTNode _pRoot;
};




