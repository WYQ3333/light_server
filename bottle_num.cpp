#include <iostream>
#include<stdio.h>
#include<vector>

int Bottle_num(int bott_num){
    if(bott_num <= 1){
        return bott_num;
    }
    int empty_bot = bott_num;
    int result = 0;
    while(true){
        if(empty_bot <= 1){
            break;
        }
        if(empty_bot == 2){
            result++;
            break;
        }
        int temp = empty_bot/3;
        empty_bot %= 3;
        result += temp;
        empty_bot += temp;
    }
    return result;
}

int main()
{
    int input;
    int n = 0;
    std::vector<int> array;
    while(n <= 10){
        std::cin >> input;
        if(input == 0){
            break;
        }
        array.push_back(input);
        n++;
    }
    for(size_t i = 0; i < array.size(); ++i){
        std::cout << Bottle_num(array[i]) << std::endl;
    }
    return 0;
}

