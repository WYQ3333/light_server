#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()){
            return "";
        }
        reverse(str.begin(), str.end());
        size_t j = 0;
        for(size_t i = 0; i < str.size(); ++i){
            if(j < i && str[i] == ' '){
                reverse(str.begin() + j, str.begin() + i);
                j = i + 1;
            }
        }
        if(j != str.size()){
            reverse(str.begin() + j, str.end());
        }
        return str;
    }
};

int main()
{
	Solution s;
    string result = "";
    result = s.ReverseSentence("student. a am I");
    cout << result << endl;
    return 0;
}

