#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int calStringDistance(string s1, string s2){
    if(s1.empty() && s2.empty()){
        return -1;
    }
    if(s1.empty() && !s2.empty()){
        return s2.size();
    }
    if(!s1.empty() && s2.empty()){
        return s1.empty();
    }

    if(s1.size() < s2.size()){
        swap(s1, s2);
    }

    int count = 0;
    for(size_t i = 0; i < s2.size(); ++i){
        if(s1[i] == s2[i]){
            continue;
        }
        else{
            count++;
        }
    }
    count *= 2;
    count += (s1.size() - s2.size());
    return count;
}

int main()
{
    string s1 = "abcdef";
    string s2 = "abcde";
    int result = 0;
    result = calStringDistance(s1, s2);
    cout << result << endl;
    return 0;
}

