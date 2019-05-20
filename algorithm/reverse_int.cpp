#include <iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;


class Solution{
public:
    int reverse(int x){
        if(x == 0)
            return 0;
        string result = to_string(x);
        ::reverse(result.begin(), result.end());
        int answer = atoi(result.c_str());
        if(x < 0){
            answer = -answer;
        }
        if (answer < -2147483648 || answer > 2147483647) {
            return 0;
        }
        return answer;
    }
};
class Solution1{
public:
    int reverse_int(int x){
        if(x == 0)
            return 0;
        string result = to_string(x);
        reverse(result.begin(), result.end());
        int answer = atoi(result.c_str());
        if(x < 0){
            answer = -answer;
        }
        return answer;
    }
};

int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.reverse_int(input) << endl;
    return 0;
}

