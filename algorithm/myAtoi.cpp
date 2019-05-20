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
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(str[i] == ' ') ++i;
        if(str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
            return 0;
        
        bool neg_flag = false;
        if(str[i] == '-'){
            neg_flag = true;
            ++i;
        }
        else if(str[i] == '+'){
            neg_flag = false;
            ++i;
        }
        
        long long sum = 0;
        bool isFlow = false;
        for(; i < str.size(); i++){
            if(!(str[i] >= '0' && str[i] <= '9')) break;
            
            sum = sum * 10 + (str[i] - '0');
            if(sum > INT_MAX){
                sum = INT_MAX;
                isFlow = true;
                break;
            }
        }
        
        if(neg_flag){
            if(isFlow)
                return INT_MIN;
            
            return -sum;
        }
        
        return sum;
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

