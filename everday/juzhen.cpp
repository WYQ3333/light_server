#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

string mima(int num){
    int a = 1,b = 1;
    int count = 1;
    while(count < num){
        int temp = a + b;
        b = a;
        a = temp;
        count++;
    }
    return to_string(a);
}

void solution(int input, vector<int> array){
    for(int i = 0; i < input; ++i){
        string temp = mima(array[i]);
        if(temp.size() < 4){
            reverse(temp.begin(), temp.end());
            int temp_size = temp.size();
            for(int j = 0; j < 4-temp_size; ++j){
                temp += '0';
            }
            reverse(temp.begin(), temp.end());
        }
        cout << temp;
    }
    cout << endl;
}

int main(){
    int input;
    vector<int> array;
    while(cin >> input){
        int temp = 0;
        while(temp < input){
            int a ;
            cin >> a;
            array.push_back(a);
            temp++;
        }
        solution(input, array);
        array.clear();
    }
    
    return 0;
}
