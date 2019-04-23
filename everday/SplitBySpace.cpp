#include <iostream>
#include<vector>
#include<string>

using namespace std;

void TestFunc(){
    string s;
    vector<string> result;
    getline(cin , s);
    string::iterator left = s.begin();
    while((string::iterator find_space = s.find(left, '')) != s.end()){        
    }
}

int main(){
    TestFunc();
    return 0;
}
