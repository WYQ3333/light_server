#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        stack<char> st;
        size_t index = 0;
        while(index < s.size()){
            if(s[index] == '(' || s[index] == '[' || s[index] == '{'){
                st.push(s[index]);
                index++;
            }
            else if(st.empty() && (s[index] == ']' || s[index] == ')' || s[index] == '}')){
                return false;
            }
            else{
                if(!st.empty() && ( 
                                   (st.top() == '(' && s[index] == ')') || 
                                   (st.top() == '[' && s[index] == ']') || 
                                   (st.top() == '{' && s[index] == '}')))
                {
                    while(!st.empty() && index < s.size() &&
                          ((st.top() == '(' && s[index] == ')') || 
                          (st.top() == '[' && s[index] == ']') || 
                          (st.top() == '{' && s[index] == '}')) 
                          ){
                        st.pop();
                        index++;
                    }
                }
                else if(!st.empty()){
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string input;
    cout << "请输入 ";
    cin >> input;
    cout << s.isValid(input) << endl;
    return 0;
}

