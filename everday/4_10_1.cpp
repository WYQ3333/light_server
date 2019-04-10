#include<iostream>
using namespace std;

bool IssuShu(int m){
    if(m == 1){
        return false;
    }
    for(int i = 2; i < m; ++i){
        if(m%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int yearf, monthf, daysf;
    int yeart, montht, dayst;
    while(cin >> yearf >> monthf >> daysf >> yeart >> montht >> dayst){
        int result = 0;
        if(IssuShu(monthf)){
            result += dayst - daysf + 1;
        }
        else{
            result += (dayst - daysf + 1)*2;
        }
        cout << result << endl;
    }
    return 0;
}
