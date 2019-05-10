#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(),m=num2.size(),p=0;
        vector<int>bits(n+m);
        for(int i=m-1;i>=0;i--){
            p=m-1-i;
            for(int j=n-1;j>=0;--j){
                int res=(num2[i]-'0')*(num1[j]-'0')+bits[p];
                if(res>=10)
                    bits[p+1]+=res/10;
                bits[p]=res%10;
                p++;
            }
        }
        string ans="";
        int terminal=m+n-1;
        while(terminal>=0&&bits[terminal]==0)
            terminal--;
        for(int i=0;i<=terminal;i++)
            ans=char(bits[i]+'0')+ans;
        return ans==""?"0":ans;
    }
};

int main()
{
    Solution s;
    string input1, input2;
    cin >> input1 >> input2;
    cout << s.multiply(input1, input2) << endl;
    return 0;
}

