#pragma once
#include <iostream>
#include <errno.h>

template <typename T>
struct DoubleLinkNode{
    DoubleLinkNode()
        :data(1)
        ,pre(nullptr)
        ,next(nullptr)
    {}

    T data;
    struct DoubleLinkNode* pre;
    struct DoubleLinkNode* next;
};

template <typename T>
class DoubleLinklist
{
public:
    typedef struct DoubleLinkNode<T> DNode;
    typedef struct DoubleLinkNode<T>* pDNode;
public:
    DoubleLinklist()
        :head(nullptr)
    {}

    void DL_init();
    pDNode DL_find(T data);
    pDNode BuyNewNode(T data);
    bool DL_PushBack(T data);
    bool DL_PushFront(T data);
    bool DL_PopBack();
    bool DL_PopFront();
    bool DL_insert(int pos, T data);
    bool DL_erase(T data);

    void DL_Print();
    void DL_rPrint();
    ~DoubleLinklist() {
        if(head != nullptr){
            pDNode cur = head;
            while(cur){
                cur = cur->next;
                head->next = nullptr;
                delete head;
                head = cur;
            }
        }
    }

private:
    pDNode head;
};

template <typename T>
struct DoubleLinkNode<T>* DoubleLinklist<T>::BuyNewNode(T data){
    struct DoubleLinkNode<T>* NewNode = new DoubleLinkNode<T>();
    if(NewNode == nullptr){
        perror("new error!!!");
        return nullptr;
    }
    NewNode->data = data;
    NewNode->pre = nullptr;
    NewNode->next = nullptr;
    return NewNode;
}
template <typename T>
void DoubleLinklist<T>::DL_init(){
    head = BuyNewNode(0);
}
template <typename T>
struct DoubleLinkNode<T>* DoubleLinklist<T>::DL_find(T data){
    struct DoubleLinkNode<T>* cur = head->next;
    if(cur == nullptr){
        perror("DLink is empty!!");
        return nullptr;
    }
    while(cur){
        if(cur->data == data){
            break;
        }
        cur = cur->next;
    }
    return cur;
}
template <typename T>
bool DoubleLinklist<T>::DL_PushBack(T data){
    struct DoubleLinkNode<T>* temp = BuyNewNode(data);
    if(temp == nullptr){
        return false;
    }
    struct DoubleLinkNode<T>* cur = head->next;
    if(cur == nullptr){
        head->next = temp;
        temp->pre = head;
        head->data++;
        return true;
    }
    while(cur->next){
        cur = cur->next;
    }
    cur->next = temp;
    temp->pre = cur;
    head->data++;
    return true;
}
template <typename T>
bool DoubleLinklist<T>::DL_PushFront(T data){
    struct DoubleLinkNode<T>* temp = BuyNewNode(data);
    if(temp == nullptr){
        return false;
    }
    struct DoubleLinkNode<T>* cur = head->next;
    if(cur == nullptr){
        head->next = temp;
        temp->pre = head;
    }
    else{
        temp->next = cur;
        cur->pre = temp;
        head->next = temp;
        temp->pre = head;
    }
    head->data++;
    return true;
}
template <typename T>
bool DoubleLinklist<T>::DL_PopBack(){
    if(head->data == 0){
        perror("DLinklist is empty!!");
        return false;
    }
    struct DoubleLinkNode<T>* cur = head->next;
    struct DoubleLinkNode<T>* pre = nullptr;
    while(cur->next){
        pre = cur;
        cur = cur->next;
    }
    if(pre == nullptr){
        delete cur;
        cur = nullptr;
        head->next = nullptr;
    }
    else{
        pre->next = nullptr;
        cur->pre = nullptr;
        delete cur;
        cur = nullptr;
    }
    head->data--;
    return true;
}

template <typename T>
bool DoubleLinklist<T>::DL_PopFront(){
    struct DoubleLinkNode<T>* cur = head->next;
    if(cur == nullptr){
        perror("DLinklist is empty!!");
        return false;
    }
    if(cur->next == nullptr){
        head->next == nullptr;
        cur->pre = nullptr;
        delete cur;
        cur = nullptr;
    }
    else{
        head->next = cur->next;
        cur->next->pre = head;
        cur->pre = nullptr;
        cur->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    head->data--;
    return true;
}

template <typename T>
bool DoubleLinklist<T>::DL_insert(int pos, T data){
    if(pos > head->data || pos < 0){
        perror("invalid index pos!!!");
        return false;
    }
    int count = 0;
    struct DoubleLinkNode<T>* cur = head->next;
    struct DoubleLinkNode<T>* pre = nullptr;
    struct DoubleLinkNode<T>* temp = BuyNewNode(data);
    if(pos == 0){
        if(head->next == nullptr){
            head->next = temp;
            temp->pre = head;
        }
        else{
            temp->next = cur;
            cur->pre = temp;
            head->next = temp;
            temp->pre = head;
        }
    }
    else{
        while(cur){
            pre = cur;
            cur = cur->next;
            count++;
            if(count == pos - 1){
                break;
            }
        }
        temp->next = cur;
        cur->pre = temp;
        pre->next = temp;
        temp->pre = pre;
    }
    head->data++;
    return true;
}
template <typename T>
bool DoubleLinklist<T>::DL_erase(T data){
    if(head->next == nullptr){
        perror("DLinklist is empty!!");
        return false;
    }
    struct DoubleLinkNode<T>* cur = head->next;
    struct DoubleLinkNode<T>* pre = nullptr;
    if(cur->data == data){
        head->next = cur->next;
        cur->next->pre = head;
        cur->pre = nullptr;
        cur->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    while(cur){
        pre = cur;
        cur = cur->next;
        if(cur->data == data){
            break;
        }
    }
    if(cur == nullptr){
        std::cout << "not find data" << std::endl;
    }
    else{
        pre->next = cur->next;
        cur->next->pre = pre;
        cur->next = nullptr;
        cur->pre = nullptr;
        delete cur;
        cur = nullptr;
    }
    head->data--;
    return true;
}

template <typename T>
void DoubleLinklist<T>::DL_Print(){
    struct DoubleLinkNode<T>* cur = head->next;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "size: " << head->data << std::endl;
    while(cur){
        std::cout << cur->data << "->";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleLinklist<T>::DL_rPrint(){
    struct DoubleLinkNode<T>* cur = head->next;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "size: " << head->data << std::endl;
    while(cur->next){
        cur = cur->next;
    }
    while(cur != head){
        std::cout << cur->data << "->";
        cur = cur->pre;
    }
    std::cout << std::endl;
}
