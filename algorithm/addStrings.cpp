#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    string addStrings(string num1, string num2){
        if(num1.empty() && num2.empty())
            return "";
        if(num1.empty() && !num2.empty())
            return num2;
        if(num2.empty() && !num1.empty())
            return num1;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(num1.size() < num2.size())
            swap(num1, num2);
        string temp = "";
        int i = 0;
        for( i = 0; i < num2.size(); ++i){
            temp += (num1[i] - '0' + num2[i] - '0') + '0';
        }
        if(i < num1.size())
            temp += num1.substr(i);
        cout << temp << endl;
        for(size_t i = 0; i < temp.size() - 1; ++i){
            if(i < (temp.size() - 1) && temp[i] - '0' > 9){
               temp[i+1] = temp[i+1] + 1;
               temp[i] -= 10;
            }
        }
        if(temp[temp.size() - 1] - '0' > 9){
            temp[temp.size() - 1] -= 10;
            temp += '1';
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main()
{
    Solution s;
    string input1, input2;
    cin >> input1 >> input2;
    cout << s.addStrings(input1, input2) << endl;
    return 0;
}

