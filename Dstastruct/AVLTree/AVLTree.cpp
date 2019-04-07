#include <iostream>
#include"AVLTree.hpp"


int main()
{
    AVLTree<int> at;
    std::cout << "insert 5 :" << std::endl;
    at.Insert(5);
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(3);
    std::cout << "insert 3 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(7);
    std::cout << "insert 7 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(1);
    std::cout << "insert 1 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(4);
    std::cout << "insert 4 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(6);
    std::cout << "insert 6 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(8);
    std::cout << "insert 8 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(0);
    std::cout << "insert 0 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;

    at.Insert(2);
    std::cout << "insert 2 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;
    
    at.Insert(9);
    std::cout << "insert 9 :" << std::endl;
    at.Inorder();
    std::cout << std::endl;
    std::cout << "bg is :" << std::endl;
    at.Inorder_bg();
    std::cout << std::endl;


    return 0;
}

