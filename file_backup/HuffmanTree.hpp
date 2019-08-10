#pragma once
#include <vector>
#include <string>
#include <string.h>
#include <queue>

template<class T>
struct HuffmanTreeNode{
    typedef HuffmanTreeNode<T> HFNode;

    //当前节点的权值
    T _weight;
    HFNode* _pLeft;
    HFNode* _pRight;
    HFNode* _pParent;

    HuffmanTreeNode(const T& weight)
        :_weight(weight)
        ,_pLeft(nullptr)
        ,_pRight(nullptr)
        ,_pParent(nullptr)
    {}
};

template<class T>
struct compare{
    //自定义prriority_queue的排序方式，建立小堆
    typedef HuffmanTreeNode<T>* pHFNode;
    bool operator()(const pHFNode& pLeft, const pHFNode& pRight){
        return pLeft->_weight > pRight->_weight;
    }
};

template<class T>
class HuffmanTree
{
public:
    typedef HuffmanTreeNode<T> HFNode;
    typedef HFNode* pHFNode;
private:
    pHFNode _pRoot;
public:
    HuffmanTree() 
        :_pRoot(nullptr)
    {}

    //销毁Huffman树
    void _delete(HuffmanTreeNode<T>* pRoot){
        if(pRoot == nullptr){
            return;
        }

        _delete(pRoot->_pLeft);
        _delete(pRoot->_pRight);

        delete pRoot;
        pRoot = nullptr;
    }

    ~HuffmanTree() {
        _delete(_pRoot);
    }

    void CreateHuffmanTree(const std::vector<T>& v, const T& invalid){
        if(v.empty()){
            //v中为空，说明信息不存在
            return;
        }

        //通过priority_queue建立小堆，对v中的数据进行排序
        std::priority_queue<pHFNode, std::vector<pHFNode>, compare<T>> q;
        //入队
        for(size_t i = 0; i < v.size(); ++i){
            if(v[i] != invalid){
                q.push(new HFNode(v[i]));
            }
        }

        //如果q中个数大于1， 说明Huffman树还没有创建成功
        while(q.size() > 1){
            pHFNode pLeft = q.top();
            q.pop();
            pHFNode pRight = q.top();
            q.pop();

            pHFNode pParent = new HFNode(pLeft->_weight + pRight->_weight);
            pParent->_pLeft = pLeft;
            pParent->_pRight = pRight;
            pLeft->_pParent = pParent;
            pRight->_pParent = pParent;

            q.push(pParent);
        }

        _pRoot = q.top();
    }


    //获取huffman树的根节点
    pHFNode GetRoot(){
        return _pRoot;
    }
};

