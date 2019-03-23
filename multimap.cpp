#include <iostream>
#include<map>

void Test_multimap(){
    std::multimap<std::string, std::string> mu;
    mu.insert(std::pair<std::string, std::string>("李逵","黑旋风"));
    std::cout << mu.count("李逵") << std::endl;
    mu.insert(std::pair<std::string, std::string>("李逵","铁牛"));
    std::cout << mu.count("李逵") << std::endl;
    mu.insert(std::pair<std::string, std::string>("林冲","豹子头"));
    mu.insert(std::pair<std::string, std::string>("宋江","及时雨"));
    mu.insert(std::pair<std::string, std::string>("鲁智深","花和尚"));
    mu.insert(std::pair<std::string, std::string>("吴用","智多星"));

    for(auto it = mu.begin(); it != mu.end(); ++it){
        std::cout << it->first << "-->" ;
        std::cout << it->second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "删除李逵之前" << std::endl;
    std::cout << mu.find("李逵")->first << std::endl;
    std::cout << "-->";
    std::cout << mu.find("李逵")->second << std::endl;

    mu.erase("李逵");
    std::cout << "删除李逵之后" << std::endl;
    std::cout << mu.count("李逵") << std::endl;
    for(auto it = mu.begin(); it != mu.end(); ++it){
        std::cout << it->first << "-->" ;
        std::cout << it->second << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << mu.size() << std::endl;


}

int main()
{
    Test_multimap();
    return 0;
}

