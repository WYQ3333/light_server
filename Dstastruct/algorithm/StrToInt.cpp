#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int flag = 1;
        int result = 0;
        for(size_t i = 0; i < str.size(); ++i){
            result *= 10;
            if(i == 0 && str[0] == '-'){
                flag = -1;
                continue;
            }
            else if(i == 0 && str[0] == '+'){
                flag = 1;
                continue;
            }
            else{
                if(str[i] < '0' || str[i] > '9'){
                    return 0;
                }
                result += (str[i] - '0');
            }
        }
        result *= flag;
        return result;
    }
};
int main()
{
    return 0;
}

