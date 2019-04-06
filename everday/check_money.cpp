#include <iostream>
using namespace std;

int solution(int input){
    if(input <= 3){
        return 1;
    }
    return 1 + solution(input/2);
}
int main()
{
    int input;
    while(cin >> input){
        if(input == 0){
            break;
        }
        cout << solution(input) << endl;
    }
    return 0;
}
