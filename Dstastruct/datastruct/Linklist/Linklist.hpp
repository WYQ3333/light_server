#pragma once
/*
 *这是一个关于带头结点单链表的实现
 */
#include <iostream>
#include <errno.h>
#include <vector>

template <typename T>
struct Linklist_node{
    Linklist_node()
        :data(0)
        ,next(nullptr)
    {}
    T data;
    struct Linklist_node* next;
};

template <typename T>
class Linklist
{
public:
    typedef struct Linklist_node<T> Link_node;
    typedef struct Linklist_node<T>* pLink_node;
public:
    Linklist()
    {}
    bool Link_PushBack(T data);
    bool Link_PopBack();
    bool Link_PushFront(T data);
    bool Link_PopFront();
    pLink_node Link_find(T data);
    pLink_node BuyNewNode(T data);
    bool Link_insert(int pos, T data);
    bool Link_erase(T data);
    pLink_node gethead();

    void Link_Print();

    //链表面试题
    //reverse Linklist
    pLink_node Link_reverse();
    //单链表的第k个结点
    pLink_node Link_K_data(int k);
    //从尾到头打印单链表
    void Link_rPrint(pLink_node first);
    //合并两个有序链表
    pLink_node Link_MergeTwoNode(pLink_node first, pLink_node second);
    //判断带环链表的入口点
    //链表头到环入口点的距离为a
    //慢指针走过的距离为s，则快指针走过的距离为2s
    //设链表总长度为L，环长为r 环入口点到相遇点的距离为x
    //s + n*r = 2*s(n表示快指针在环中走过的圈数)
    //s = x + a L = a + r
    //s = n*r         s = (n - 1)*r + r     x + a = (n - 1)*r + L - a    
    //a = (n-1)*r + (L - x - a)==>相遇点到入口的距离等于
    //链表头到入口的距离



    ~Linklist() {
        if(head.data != 0){
            pLink_node cur = head.next;
            pLink_node pre = cur;
            while(cur){
                pre = cur;
                cur = cur->next;
                delete pre;
                pre = nullptr;
            }
        }
    }
private:
    Link_node head;
};


template <typename T>
struct Linklist_node<T>* Linklist<T>::BuyNewNode(T data){
    struct Linklist_node<T>* NewNode = new Linklist_node<T>();
    if(NewNode == nullptr){
        perror("new node error!!");
        return nullptr;
    }
    NewNode->data = data;
    NewNode->next = nullptr;
    return NewNode;
}

template <typename T>
bool Linklist<T>::Link_PushBack(T data){
    struct Linklist_node<T>* temp = BuyNewNode(data);
    if(temp == nullptr){
        return false;
    }
    if(head.next == nullptr){
        head.next = temp;
        return true;
    }
    struct Linklist_node<T>* cur = head.next;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = temp;
    head.data++;
    return true;
}

template <typename T>
bool Linklist<T>::Link_PopBack(){
    if(head.next == nullptr){
        perror("Linklist is empty!!");
        return false;
    }
    struct Linklist_node<T>* cur = head.next;
    struct Linklist_node<T>* pre = nullptr;
    while(cur->next){
        pre = cur;
        cur = cur->next;
    }
    if(pre == nullptr){
        delete cur;
        cur = nullptr;
        head.next = nullptr;
    }
    else{
        pre->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    head.data--;
    return true;
}

template <typename T>
bool Linklist<T>::Link_PushFront(T data){
    struct Linklist_node<T>* temp = BuyNewNode(data);
    if(temp == nullptr){
        return false;
    }
    temp->next = head.next;
    head.next = temp;
    head.data++;
    return true;
}

template <typename T>
bool Linklist<T>::Link_PopFront(){
    if(head.next == nullptr){
        perror("linklist is empty!!");
        return false;
    }
    struct Linklist_node<T>* cur = head.next;
    head.next = cur->next;
    delete cur;
    cur = nullptr;
    head.data--;
    return true;
}

template <typename T>
struct Linklist_node<T>* Linklist<T>::Link_find(T data){
    if(head.data == 0){
        perror("Linklist is empty!!");
        return nullptr;
    }
    struct Linklist_node<T>* cur = head.next;
    while(cur){
        if(cur->data == data){
            break;
        }
        cur = cur->next;
    }
    return cur;
}
template <typename T>
bool Linklist<T>::Link_insert(int pos, T data){
    struct Linklist_node<T>* temp = BuyNewNode(data);
    if(pos > head.data || pos < 0){
        perror("invalid position!!");
        return false;
    }
    int count = 0;
    struct Linklist_node<T>* cur = head.next;
    struct Linklist_node<T>* pre = nullptr;
    while(cur){
        pre = cur;
        cur = cur->next;
        count++;
        if(count == pos - 1){
            break;
        }
    }
    if(pre == nullptr && pos == 0){
        head.next = temp;
    }
    else{
        temp->next = cur;
        pre->next = temp;
    }
    head.data++;
    return true;
}
template <typename T>
bool Linklist<T>::Link_erase(T data){
    if(head.next == nullptr){
        std::cout << "linklist is empty!!" << std::endl;
        return false;
    }
    struct Linklist_node<T>* pre = nullptr;
    struct Linklist_node<T>* cur = head.next;
    if(cur->data == data){
        head.next = nullptr;
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
    pre->next = cur->next;
    delete cur;
    cur = nullptr;
    head.data--;
    return true;
}

template <typename T>
void Linklist<T>::Link_Print(){
    struct Linklist_node<T>* cur = head.next;
    std::cout << "linklist size: " << head.data << std::endl;
    std::cout << "linklist value is: ";
    while(cur){
        std::cout << cur->data << "->";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
struct Linklist_node<T>* Linklist<T>::Link_reverse(){
    if(head.next == nullptr){
        perror("linklist is empty!!!");
        return nullptr;
    }
    struct Linklist_node<T>* result = nullptr;
    struct Linklist_node<T>* cur = head.next;
    struct Linklist_node<T>* pre = cur;
    while(cur){
        pre = cur;
        cur = cur->next;
        if(result == nullptr){
            result = pre;
            result->next = nullptr;
        }
        else{
            pre->next = result;
            result = pre;
        }
    }
    return result;
}

//链表的第k个结点
template <typename T>
struct Linklist_node<T>* Linklist<T>::Link_K_data(int k){
    if(head.data == 0){
        perror("linklist is empty!!");
        return nullptr;
    }
    if(head.data < k){
        std::cout << "invalid k" << std::endl;
        return nullptr;
    }
    struct Linklist_node<T>* first = head.next;
    struct Linklist_node<T>* second = head.next;
    int count = 0;
    while(count != k){
        count++;
        second = second->next;
    }
    while(second->next){
        first = first->next;
        second = second->next;
    }
    return first;
}

template <typename T>
void Linklist<T>::Link_rPrint(struct Linklist_node<T>* first){
    //用数组实现
    std::vector<T> array;
    struct Linklist_node<T>* cur = first;
    if(cur == nullptr){
        perror("linklist is empty!!");
        return;
    }
    while(cur){
        array.push_back(cur->data);
        cur = cur->next;
    }

    for(int i = array.size() - 1; i >= 0; --i ){
        std::cout << array[i] << "->";
    }
    std::cout << std::endl;
}

template <typename T>
struct Linklist_node<T>* Linklist<T>::gethead(){
    return head.next;
}

template <typename T>
struct Linklist_node<T>* Linklist<T>::Link_MergeTwoNode(struct Linklist_node<T>* first, struct Linklist_node<T>* second){
    if(first == nullptr){
        return second;
    }
    if(second == nullptr){
        return first;
    }

    struct Linklist_node<T>* result;
    struct Linklist_node<T>* cur;
    if(first->data < second->data){
        result = first;
        first = first->next;
        result->next = nullptr;
        cur = result;
    }
    else if(first->data > second->data){
        result = second;
        second = second->next;
        result->next = nullptr;
        cur = result;
    }
    else{
        result= first;
        first = first->next;
        result->next = nullptr;
        cur = result;
        cur->next = second;
        cur = cur->next;
        second = second->next;
        cur->next = nullptr;
    }
    while(first != nullptr && second != nullptr){
        struct Linklist_node<T>* f = first;
        struct Linklist_node<T>* s = second;
        if(f->data < s->data){
            first = first->next;
            f->next = nullptr;
            cur->next = f;
            cur = cur->next;
        }
        else if(f->data > s->data){
            second = second->next;
            s->next = nullptr;
            cur->next = s;
            cur = cur->next;
        }
        else{
            second = second->next;
            first = first->next;
            f->next = nullptr;
            s->next = nullptr;
            cur->next = f;
            cur = cur->next;
            cur->next = s;
            cur = cur->next;
        }
    }

    if(first != nullptr){
        cur->next = first;
    }

    if(second != nullptr){
        cur->next = second;
    }
    return result;
}
