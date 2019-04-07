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
            if(pCur->_data == data){
                break;
            }
            else if(data < pCur->_data){
                pParent = pCur;
                pCur = pCur->_pLeft;
            }
            else{
                pParent = pCur;
                pCur = pCur->_pRight;
            }
        }
        if(pCur != nullptr){
            if(pCur->_pLeft == nullptr){
                //only have _pRight;
                if(pCur->_pRight == nullptr){
                    //erase root
                    if(pCur == pParent->_pLeft){
                        pParent->_pLeft = nullptr;
                    }
                    else if(pCur == pParent->_pRight){
                        pParent->_pRight = nullptr;
                    }
                }
                else{
                    if(pCur == pParent->_pLeft){
                        pParent->_pLeft = pCur->_pRight;
                    }
                    else if(pCur == pParent->_pRight){
                        pParent->_pRight = pCur->_pRight;
                    }
                }
                delete pCur;
                pCur = nullptr;

            }
            else if(pCur->_pRight == nullptr){
                //only have _pLeft
                if(pCur == pParent->_pLeft){
                    pParent->_pLeft = pCur->_pLeft;
                }
                else if (pCur == pParent->_pRight){
                    pParent->_pRight = pCur->_pLeft;
                }
                else{
                    pParent = nullptr;
                }
                delete pCur;
                pCur = nullptr;
            }
            else if(pCur->_pLeft && pCur->_pRight){
                //have _pLeft && have _pRight;
                pBSTNode pCurRch = pCur->_pRight;
                pBSTNode pCurRchPar = pCur;
                if(pCurRch->_pLeft == nullptr){
                    pCur->_data = pCurRch->_data;
                    pCur->_pRight = pCurRch->_pRight;
                }
                else{
                    while(pCurRch->_pLeft){
                        pCurRchPar = pCurRch;
                        pCurRch = pCurRch->_pLeft;
                    }
                    pCur->_data = pCurRch->_data;
                    pCurRchPar->_pLeft = nullptr;
                } 
                delete pCurRch;
                pCurRch = nullptr;  
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
        if(pRoot == nullptr){
            return;
        }
        _Inorder(pRoot->_pLeft);
        std::cout << pRoot->_data << " ";
        _Inorder(pRoot->_pRight);
    }

    void Inorder(){
        _Inorder(_pRoot);
    }

private:
    pBSTNode _pRoot;
};
