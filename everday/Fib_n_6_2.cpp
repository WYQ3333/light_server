#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;

string str_add(string str1, string str2){
    vector<string> result;
    if(str1.size() < str2.size()){
        swap(str1, str2);
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for(size_t i = 0; i < str2.size(); ++i){
        string temp = to_string((str1[i] - '0') + (str2[i] - '0'));
        result.push_back(temp);
    }
    for(size_t i = str2.size(); i < str1.size(); ++i){
        string temp = to_string(str1[i] - '0');
        result.push_back(temp);
    }
    int a = 0;
    for(size_t i = 0; i < result.size(); ++i){
        result[i] = to_string(atoi(result[i].c_str()) + a);
        if(atoi(result[i].c_str()) > 9){
            int b = atoi(result[i].c_str())%10;
            result[i] = to_string(b);
            a = 1;
        }
        else{
            a = 0;
        }
    }
    string answer = "";
    for(size_t i = 0; i < result.size(); ++i){
        answer += result[i];
    }
    if(a != 0){
        answer += to_string(a);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

string solution(string input){
    string result = "";
    string a = "1";
    string b = "2";
    for(int i = 1; i < atoi(input.c_str()); ++i){
        string temp = str_add(a, b);
        a = b;
        b = temp;
    }
    if(a.size() > 6){
        result = a.substr(b.size() - 6, 6);
    }
    else{
        result = a;
    }
    return result;
}

int main()
{
    string input;
    while(cin >> input){
        cout << solution(input) << endl;
    }
    return 0;
}

