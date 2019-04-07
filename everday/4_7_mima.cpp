#include <iostream>
#include<string>
#include<vector>

void solution(const std::vector<char> array, std::string& str_input){
    for(size_t i = 0; i < str_input.size(); ++i){
        if(str_input[i] >= 'A' && str_input[i] <= 'Z'){
            int index = 0;
            index = str_input[i] - 5;
            if(index < 'A'){
                index = 'Z' - ('A' - index) + 1;
            }
            str_input[i] = array[index];
        }
    }
}

int main()
{
    std::vector<char> array;
    array.resize(256);
    for(size_t i = 0; i < array.size(); ++i){
        array[i] = i;
    }
    std::string str_input;
    while(getline(std::cin, str_input)){
        solution(array, str_input);
        std::cout << str_input << std::endl;
    }
    return 0;
}

