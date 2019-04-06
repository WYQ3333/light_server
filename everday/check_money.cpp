#include <iostream>
using namespace std;

/* int solution(int input){ */
/*     if(input <= 3){ */
/*         return 1; */
/*     } */
/*     int result = 0; */
/*     if(input%2 == 0){ */
/*         result = 1 + solution(input/2); */
/*     } */
/*     if(input%2 != 0){ */
/*         result = 1 + 2*solution(input/2); */
/*     } */
/*     return result; */
/* } */

long long solution(long long input){
    if(input == 0){
        return 0;
    }
    long long count = 0;
    while(input >= 2){
        if(input%3){
            input = input/3 + 1;
        }
        else{
            input /= 3;
        }
        count++;
    }
    return count;
}
int main()
{
    long long  input;
    while(cin >> input){
        if(input == 0){
            break;
        }
        cout << solution(input) << endl;
    }
    return 0;
}
