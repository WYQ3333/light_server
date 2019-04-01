#include <iostream>
#include<stack>
#include<string>
using namespace std;

bool checkIstrue(string s1){
    if(s1.empty()){
        return false;
    }
    stack<char> s;
    s.push(s1[0]);
    for(auto e : s1){
        if(e == '{' || e == '(' || e == '['){
            s.push(e);
        }
        else{
            auto temp = s.top();
            if((temp == '{' && e == '}')||(temp == '(' && e == ')')||(temp == '[' && e == ']')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s1 = "{(([]))}";
    cout << checkIstrue(s1) << endl;
    return 0;
}

