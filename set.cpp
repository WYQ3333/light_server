#include <iostream>
#include<set>

void Test_Set(){
    int array[] = { 0, 3, 1, 4, 2, 7, 5, 9, 6, 8 };
    std::set<int> s(array, array + sizeof(array)/sizeof(array[0]));
    std::cout << s.size() << std::endl;
    for(auto it = s.begin(); it != s.end(); ++it){
        std::cout << *it ;
    }

    std::cout << std::endl;
    s.insert(11);
    s.insert(10);
    s.insert(12);
    std::cout << s.size() << std::endl;
    for(auto it = s.begin(); it != s.end(); ++it){
        std::cout << *it ;
    }
    std::cout << std::endl;
    s.erase(5);
    s.erase(8);
    std::cout << s.size() << std::endl;
    for(auto it = s.begin(); it != s.end(); ++it){
        std::cout << *it ;
    }
    std::cout << std::endl;
}

int main()
{
    Test_Set();
    return 0;
}

