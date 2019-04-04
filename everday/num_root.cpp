#include <iostream>
#include<vector>
using namespace std;

long long my_add(long long num){
    int sum = 0;
    while(num){
        sum += num%10;
        num /= 10;
    }
    return sum;
}

long long solution(long long a){
    if(0 <= a && a <= 9){
        return a;
    }
    long long result = a;
    while(result > 9){
        result = my_add(result);
    }
    return result;
}

int main()
{
    long long input ;
    vector<long long> array;
    while(cin >> input){
        array.push_back(input);
    }
    for(size_t i = 0; i < array.size(); ++i){
        array[i] = solution(array[i]);
    }
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << endl;
    }
    return 0;
}

