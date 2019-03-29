#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<errno.h>

template<class T>
struct BTreeNode{
    BTreeNode(T data)
        :_pLeft(nullptr)
        ,_pRight(nullptr)
        ,_data(data){}

    BTreeNode<T>* _pLeft;
    BTreeNode<T>* _pRight;
    T _data;
};

template<class T>
class BTree
{
public:
    BTree() 
        :_pRoot(nullptr)
    {}

    BTreeNode<T>* CreateBTree_string(std::string Pre, std::string Ino){
        if(Pre.empty()&&Ino.empty()){
            return nullptr;
        }
        BTreeNode<T>* pRoot = new BTreeNode<T>(Pre[0]);
        if(pRoot == nullptr){
            perror("new failure!! ");
            return nullptr;
        }
        std::string str_left_Ino = Ino.substr(0, Ino.find(Pre[0]));
        std::string str_left_Pre = Pre.substr(1, str_left_Ino.size());
        if(!str_left_Pre.empty() && !str_left_Pre.empty()&& str_left_Pre.size() == str_left_Ino.size()){
            pRoot->_pLeft = CreateBTree_string(str_left_Pre, str_left_Ino);
        }
        std::string str_right_Ino = Ino.substr(Ino.find(Pre[0])+1);
        std::string str_right_Pre = Pre.substr(str_left_Pre.size()+1,str_right_Ino.size());
        if(!str_right_Pre.empty() && !str_right_Ino.empty() && str_right_Pre.size() == str_right_Ino.size()){
            pRoot->_pRight = CreateBTree_string(str_right_Pre, str_right_Ino);
        }
        return pRoot;
    }
    void CreateBTree(std::string& Pre, std::string& Ino){
        if(Pre.size()!=Ino.size()){
            perror("BTree pre not equal Ino: !!!");
            return;
        }
        _pRoot = CreateBTree_string(Pre, Ino);
    }

    void CreateBTree(std::vector<T> Pre, std::vector<T> Ino){
        if(Pre.size()!= Ino.size()){
            perror("BTree pre not equal Ino: !!!");
            return;
        }
    }

    void _destoryBT(BTreeNode<T>* pRoot){
        if(pRoot == nullptr){
            return;
        } 
        _destoryBT(pRoot->_pLeft);
        _destoryBT(pRoot->_pRight);
        delete pRoot;
        pRoot = nullptr;
    }
    ~BTree()
    {
        if(_pRoot != nullptr){
            _destoryBT(_pRoot);
        }
    }
public:
    void PrePrint(){
        BTreeNode<T>* pCur = _pRoot;
        Pre_print(pCur);
        std::cout << std::endl;
    }

    void Inoprint(){
        BTreeNode<T>* pCur = _pRoot;
        Ino_print(pCur);
        std::cout << std::endl;
    }
    void Backprint(){
        BTreeNode<T>* pCur = _pRoot;
        Back_print(pCur);
        std::cout << std::endl;
    }
private:
    void Pre_print(BTreeNode<T>* pRoot){
        if(pRoot == nullptr){
            return;
        }
        std::cout << pRoot->_data;
        Pre_print(pRoot->_pLeft);
        Pre_print(pRoot->_pRight);
    }

    void Ino_print(BTreeNode<T>* pRoot){
        if(pRoot == nullptr){
            return;
        }
        Ino_print(pRoot->_pLeft);
        std::cout << pRoot->_data;
        Ino_print(pRoot->_pRight);
    }
    
    void Back_print(BTreeNode<T>* pRoot){
        if(pRoot == nullptr){
            return;
        }
        Back_print(pRoot->_pLeft);
        Back_print(pRoot->_pRight);
        std::cout << pRoot->_data;
    }
private:
    BTreeNode<T>* _pRoot;
};

