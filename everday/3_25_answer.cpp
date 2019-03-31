#include <iostream>
#include<vector>
#include<string>
using namespace std;

string Find_max_commen_str(string& s1, string& s2){
    if(s1.empty() || s2.empty()){
        return "";
    }
    if(s1.size() > s2.size()){
        swap(s1, s2);
    }
    int len1 = s1.size(), len2 = s2.size();
    int i, j, start = 0, max = 0;
    vector<vector<int>> array(len1+1, vector<int>(len2+1, 0));
    for(i = 1; i < len1; ++i){
        for(j = 1; j < len2; ++j){
            if(s1[i-1] == s2[j-1]){
                array[i][j] = array[i-1][j-1] +1;
            }
            if(array[i][j] > max){
                max = array[i][j];
                start = i - max;
            }
        }
    }
    string result = s1.substr(start, max);
    return result;
}

int main()
{
    string s1 = "hello world";
    string s2 = "hello ";
    string result = "";
    result = Find_max_commen_str(s1, s2);
    cout << result << endl;
    return 0;
}

