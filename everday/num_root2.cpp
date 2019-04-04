#include <iostream>
#include<string>
using namespace std;

int my_add(string input){
    int result = 0;
    for(size_t i = 0; i < input.size(); ++i){
        result += input[i] - '0';
    }
    return result;
}

int solution(string input){
    int sum = my_add(input);
    while(sum > 9){
        sum = my_add(to_string(sum));
    }
    return sum;
}

int main()
{
    string input;
    while(cin >> input){
        cout << solution(input) << endl;
    }
    return 0;
}

