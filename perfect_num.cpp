#include <iostream>

bool Isperfect_num(long long num){
    long long sum = 0;
    for(long long i = 1; i < num; ++i){
        if(num%i == 0){
            sum += i;
        }
    }
    if(sum == num){
        std::cout << num << " " << std::endl;
        return true;
    }
    else{
        return false;
    }
}

long long count(long long n){
    long long count = 0;
    for(long long i = 1; i < n; ++i){
        if(Isperfect_num(i)){
            count++;
        }
    }
    return count;
}


int main()
{
    long long input;
    std::cin >> input ;
    if(input == 0){
        std::cout << 0 << std::endl;
    }
    input = count(input);
    std::cout << input << std::endl;
    return 0;
}

