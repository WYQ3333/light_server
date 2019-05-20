#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        if((str[0] < '0' || str[0] > '9') && str[0] != ' ' && str[0] != '-'){
            return 0;
        }
        string result = "";
        string flag = "";
        for(size_t i = 0; i < str.size(); ){
            if(str[i] == ' '){
                i++;
            }
            if(str[i] >= '0' && str[i] <= '9'){
                result += str[i];
                i++;
            }
            if(result.empty() && ((str[i] < '0' || str[i] > '9') && str[i] != '-') && str[i] != ' '){
                return 0;
            }
            if(result.empty() && str[i] == '-'){
                flag += '-';
                i++;
            }
            if(!result.empty() && (str[i] < '0' || str[i] > '9') && str[i] != ' '){
                break;
            }
        }
        cout <<"result "<< result << endl;
        cout <<"flag " << flag << endl;
        return 0;
    }
};

int main()
{
    Solution s;
    string input;
    cin >> input;
    s.myAtoi(input);
    return 0;
}

