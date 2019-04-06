#include <iostream>
#include"BSTree.hpp"

int main()
{
    BSTree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.insert(0);
    bt.insert(2);
    bt.insert(9);
    //std::cout << pRoot->_data << std::endl;
    //std::cout << "test find:";
    //auto pCur = bt.find(5);
    //std::cout << pCur->_data << std::endl;

    std::cout << "test Inorder" << std::endl;
    bt.Inorder();
    std::cout << std::endl;

    std::cout << "test erase" << std::endl;
    bt.Erase(0);
    bt.Inorder();
    std::cout << std::endl;
    return 0;
}

