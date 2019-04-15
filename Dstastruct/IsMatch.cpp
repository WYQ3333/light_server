#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() || p.empty()){
            return false;
        }
        size_t si = 0; 
        size_t sp = 0;
        while(sp < p.size()){
            if(p[sp] == '?'){
                si++;
                sp++;
            }
            else if(p[sp] == '*'){
                if(sp == p.size() - 1){
                    return true;
                }
                char ch = p[sp + 1];
                while(si < s.size()){
                    if(s[si] == ch){
                        break;
                    }
                    si++;
                }
                if(si < s.size()){
                    sp++;
                }
                else{
                    return false;
                }
            }
            else{
                if(p[sp] == s[si]){
                    sp++;
                    si++;
                }
                else{
                    return false;
                }
            }
        }
        if(si != s.size()){
            return false;
        }
        return true;
    }
};

int main()
{
    string input1;
    string input2;
    Solution s;
    while(cin >> input1 >> input2){
        cout << s.isMatch(input1, input2) << endl;
    }
    return 0;
}

