#include <iostream>
#include<vector>
using namespace std;

bool Istriangle(long long a, long long b, long long c){
    if(a < (b + c) && b < (a + c) && c < (a + b)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a, b, c;
    vector<long long> array;
    vector<vector<long long>> result;
    while(cin >> a >> b >> c){
        array.push_back(a);
        array.push_back(b);
        array.push_back(c);
        result.push_back(array);
        array.clear();
    }
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i][0] << " ";
        cout << result[i][1] << " ";
        cout << result[i][2] << " ";
        cout << endl;
    }
    for(size_t i = 0; i < result.size(); ++i){
        if(Istriangle(result[i][0], result[i][1], result[i][2])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
