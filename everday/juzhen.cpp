#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

/* string mima(long long num){ */
/*     long long a = 0,b = 1; */
/*     long long count = 1; */
/*     while(count <= num){ */
/*         long long temp = a + b; */
/*         a = b; */
/*         b = temp; */
/*         cout << a << " " << b << endl; */
/*         count++; */
/*     } */
/*     return to_string(b); */
/* } */

/* void solution(long long input, vector<long long> array){ */
/*     for(long long i = 0; i < input; ++i){ */
/*         string temp = mima(array[i]); */
/*         if(temp.size() < 4){ */
/*             reverse(temp.begin(), temp.end()); */
/*             long long temp_size = temp.size(); */
/*             for(long long j = 0; j < 4-temp_size; ++j){ */
/*                 temp += '0'; */
/*             } */
/*             reverse(temp.begin(), temp.end()); */
/*         } */
/*         if(temp.size() > 4){ */
/*             temp = temp.substr(temp.size() - 4); */
/*         } */
/*         cout << temp; */
/*     } */
/*     cout << endl; */
/* } */
int main(){
    long long input;
    int array[10005] = {0,1,2,3,5};
    for(int i = 3; i < 10005; ++i){
        array[i] = array[i-1] + array[i-2];
        if(array[i] >= 10000){
            array[i] %= 10000;
        }
    }
    while(cin >> input){
        long long temp = 0;
        while(temp < input){
            long long a ;
            cin >> a;
            string result = to_string(array[a]);
            int result_size = result.size();
            if(4 > result.size()){
                reverse(result.begin(), result.end());
                for(int j = 0; j < 4 - result_size; ++j){
                    result += '0';
                }
                reverse(result.begin(), result.end());
            }
            if(4 < result.size()){
                result = result.substr(result.size() - 4);
            }
            cout << result;
            temp++;
        }
        cout << endl;
    }
    return 0;
}
