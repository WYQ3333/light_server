#pragma once
#include<iostream>
#include<string>

template<class T>
struct BSTreeNode{
    typedef BSTreeNode<T> BSTNode;
    typedef BSTNode* pBSTNode;

    BSTreeNode(const T& data = T())
        :_pLeft(nullptr)
        ,_pRight(nullptr)
        ,_data(data){}

    pBSTNode _pLeft;
    pBSTNode _pRight;

    T _data;
};

template<class T>
class BSTree{
public:
    typedef BSTreeNode<T> BSTNode;
    typedef BSTNode* pBSTNode;
public:
    BSTree()
        :_pRoot(nullptr)
    {}

    void _destory(pBSTNode pRoot){
        if(pRoot == nullptr){
            return;
        }
        _destory(pRoot->_pLeft);
        _destory(pRoot->_pRight);
        delete pRoot;
        pRoot = nullptr;
    }

    ~BSTree(){
        if(_pRoot)
            _destory(_pRoot);
    }

    bool insert(const T& data){
        if(_pRoot == nullptr){
            _pRoot = new BSTNode(data);
            return true;
        }
        pBSTNode pRoot = _pRoot;
        pBSTNode pParent = nullptr;
        while(pRoot){
            pParent = pRoot;
            if(data < pRoot->_data){
                pRoot = pRoot->_pLeft;
            }
            else if(data > pRoot->_data){
                pRoot = pRoot->_pRight;
            }
            else if(data == pRoot->_data){
                return false;
            }
        }
        pRoot = new BSTNode(data);
        if(data < pParent->_data){
            pParent->_pLeft = pRoot;
        }
        else{
            pParent->_pRight = pRoot;
        }
        return true;
    }

    pBSTNode find(const T& data){
        pBSTNode pCur = _pRoot;
        while(pCur){
            if(pCur->_data > data){
                pCur = pCur->_pLeft;
            }
            if(pCur->_data < data){
                pCur = pCur->_pRight;
            }
            if(pCur->_data == data){
                return pCur;
            }
        }
        return nullptr;
    }

    bool Erase(const T& data){
        pBSTNode pParent = _pRoot;
        pBSTNode pCur = _pRoot;
        while(pCur){
            pParent = pCur;
            if(data < pCur->_data){
                pCur = pCur->_pLeft;
            }
            else if(data > pCur->_data){
                pCur = pCur->_pRight;
            }
            else if(data == pCur->_data){
                break;
            }
        }
        if(pCur != nullptr){
            if(pCur->_pRight == nullptr){
                //only have pLeft;
                if(pCur->_pLeft == nullptr){
                    pParent->_pLeft = nullptr;
                    delete pCur;
                    pCur = nullptr;
                }
                else
                    pParent->_pLeft = pCur->_pLeft;
            }
            if(pCur->_pLeft == nullptr){
                //only have pRight;
                if(pCur->_pRight == nullptr){
                    delete pCur;
                    pCur = nullptr;
                }
                else
                    pParent->_pRight = pCur->_pRight;
            }
            if(pCur->_pLeft && pCur->_pRight){
                pBSTNode pLchild = pCur->_pRight;
                pBSTNode pLchildpar = nullptr;
                while(pLchild->_pLeft){
                    pLchildpar = pLchild;
                    pLchild = pLchild->_pLeft;
                }
                pCur->_data = pLchild->_data;
                pLchildpar->_pLeft == nullptr;
                delete pLchild;
                pLchild = nullptr;
            }
        }
        else{
            return false;
        }
        return true;
    }

    pBSTNode GetRoot(){
        return _pRoot;
    }

    void _Inorder(pBSTNode pRoot){
        if(pRoot){
            _Inorder(pRoot->_pLeft);
            std::cout << pRoot->_data << " ";
            _Inorder(pRoot->_pRight);
        }
    }

    void Inorder(){
        _Inorder(_pRoot);
    }

private:
    pBSTNode _pRoot;
};
