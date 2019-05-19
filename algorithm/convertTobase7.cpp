#include <iostream>
#include<string>

using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        if(num == 0){
            result += '0';
            return result;
        }
        int flag = 0;
        if(num < 0 ){
            flag = 0;
            num = -num;
        }
        else{
            flag = 1;
        }
        while(num){
            result += to_string(num%7);
            num /= 7;
        }
        if(flag == 0){
            result += '-';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    //10进制数转化为7进制数
    return 0;
}

