#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    //实现字符串加法
    string addstr(string str1, string str2){
        if(str1.empty() && str2.empty())
            return "";
        if(str1.empty() && !str2.empty())
            return str2;
        if(!str1.empty() && str2.empty())
            return str1;
        string result = "";
        if(str1.size() < str2.size()){
            swap(str1, str2);
        }
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        size_t i = 0;
        for(; i < str2.size(); ++i){
            int ch = str1[i] - '0' + str2[i] - '0';
            result += (ch + '0');
        }
        if(i < str1.size())
            result += str1.substr(i);
        //cout << "result " << result << endl;
        for(i = 0; i < result.size(); ++i){
            if((i < result.size() - 1) && result[i] - '0' > 9){
                result[i+1] += 1;
                result[i] -= 10;
            }
        }
        if(result[result.size() - 1] - '0' > 9){
            result[result.size() - 1] -= 10;
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
    //实现字符串乘法
    string multiply(string num1, string num2){
        string result = "";
        if(num1.empty() || num2.empty())
            return result;
        if(num1[0] == '0' || num2[0] == '0'){
            result += '0';
            return result;
        }
        if(num1.size() < num2.size()){
            swap(num1, num2);
        }
        for(int i = num2.size() - 1; i >= 0; --i){
            int temp = 0;
            int index = 0;
            string cur = "";
            int j = 0;
            for(j = num1.size() - 1; j >= 0; --j){
                temp = (num2[i] - '0')*(num1[j] - '0');
                temp += index;
                /* cout << "i " << i << "j " << j << endl; */
                /* cout << "temp " << temp << endl; */
                index = temp/10;
                if(temp > 9){
                    temp %= 10;
                }
                cur += (temp + '0');
            }
            /* index = temp/10;//更新一下进位 */
            //cur += to_string(temp);
            cout << "加进位之前cur " << cur << "index " << index << endl;
            if(index != 0)
                cur += index + '0';
            reverse(cur.begin(), cur.end());
            for(size_t k = 1; k < num2.size() - i; ++k){
                cur += '0';
            }
            cout << "cur " << cur << endl;
            result = addstr(cur, result);
        }
        return result;
    }
};

int main()
{
    Solution s;
    string input1, input2;
    cin >> input1 >> input2;
    /* cout << s.addstr(input1, input2) << endl; */
    cout << s.multiply(input1, input2) << endl;
    return 0;
}

