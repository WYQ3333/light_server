#include <iostream>
#include<math.h>

int solution(int input_num){
    int count = 0;
    for(int i = 2; i < sqrt(input_num); ++i){
        if(input_num%i == 0){
            while(input_num%i == 0){
                input_num /= i;
            }
            count++;
        }
    }
    if(input_num != 1){
        count += 1;
    }
    return count;
}

int main()
{
    int input_num;
    while(std::cin >> input_num){
        std::cout << solution(input_num) << std::endl;
    }
    return 0;
}

