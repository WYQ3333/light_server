#include "DoubleLinklist.hpp"

int main()
{
    DoubleLinklist<int> DL;
    DL.DL_init();
    DL.DL_Print();
    //尾插成功
    //DL.DL_PushBack(1);
    //DL.DL_PushBack(2);
    //DL.DL_PushBack(3);
    //DL.DL_PushBack(4);
    DL.DL_PushFront(1);
    DL.DL_PushFront(2);
    DL.DL_PushFront(3);
    DL.DL_PushFront(4);
    //DL.DL_Print();
    //DL.DL_rPrint();
    //DL.DL_PopBack();
    //DL.DL_Print();
    //DL.DL_PopFront();
    //DL.DL_Print();
    //DL.DL_insert(2, 20);
    //DL.DL_Print();
    //DL.DL_erase(20);
    //DL.DL_Print();
    DL.DL_PopFront();
    DL.DL_Print();
    DL.DL_rPrint();
    std::cout << "=========================" << std::endl;

    DL.DL_PopFront();
    DL.DL_Print();
    DL.DL_rPrint();
    std::cout << "=========================" << std::endl;

    DL.DL_PopFront();
    DL.DL_Print();
    DL.DL_rPrint();
    std::cout << "=========================" << std::endl;

    DL.DL_PopFront();
    DL.DL_Print();
    DL.DL_rPrint();
    std::cout << "=========================" << std::endl;

    DL.DL_PopFront();
    DL.DL_Print();
    DL.DL_rPrint();
    std::cout << "=========================" << std::endl;
    return 0;
}

