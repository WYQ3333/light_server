#include "Linklist.hpp"

int main()
{
    //Linklist<int> linklist;
    //std::cout << "---------------push_front 1-4--------" << std::endl;
    //linklist.Link_PushFront(1);
    //linklist.Link_PushFront(2);
    //linklist.Link_PushFront(3);
    //linklist.Link_PushFront(4);
    //linklist.Link_Print();
    //linklist.Link_rPrint(linklist.gethead());

    //std::cout << "--------------push_back 5-8---------" << std::endl;
    //linklist.Link_PushBack(5);
    //linklist.Link_PushBack(6);
    //linklist.Link_PushBack(7);
    //linklist.Link_PushBack(8);
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_back----------" << std::endl;
    //linklist.Link_PopBack();
    //linklist.Link_Print();
    //std::cout << "---------------find-------------" << std::endl;
    //struct Linklist_node<int>* cur = linklist.Link_find(2);
    //std::cout << cur->data << std::endl;
    //std::cout << "---------------insert------------" << std::endl;
    //linklist.Link_insert(3, 20);
    //linklist.Link_Print();
    //std::cout << "--------------erase--------------" << std::endl;
    //linklist.Link_erase(20);
    //linklist.Link_Print();

    //ctrl+v shift+i 多行注释 按d建即可取消注释
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    //std::cout << "---------------pop_fron-----------" << std::endl;
    //linklist.Link_PopFront();
    //linklist.Link_Print();
    
    //单链表测试成功
    //struct Linklist_node<int>* result = nullptr;
    //result = linklist.Link_reverse();
    //while(result){
    //    std::cout << result->data << "->";
    //    result = result->next;
    //}
    //std::cout << std::endl;
    
    Linklist<int> l1;
    Linklist<int> l2;
    Linklist<int> l3;

    l1.Link_PushBack(1);
    l1.Link_PushBack(3);
    l1.Link_PushBack(5);
    l1.Link_PushBack(7);
    l1.Link_Print();
    l2.Link_PushBack(2);
    l2.Link_PushBack(4);
    l2.Link_PushBack(6);
    l2.Link_PushBack(8);
    l2.Link_Print();

    struct Linklist_node<int>* result = nullptr;
    result = l3.Link_MergeTwoNode(l1.gethead(), l2.gethead());
    while(result){
        std::cout << result->data << "->";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}

