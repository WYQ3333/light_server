#include <iostream>
using namespace std;

class Solution{
public:
    int arrangeCoins(int n){
        if(n <= 0){
            return 0;
        }
        int index = 1;
        int result = 1;
        do{
            index <<= result - 1;
            n -= index;
            result++;
        }while(n >= index);
        return result - 1;
    }
};
class Solution1{
public:
    int arrangeCoins(int n){
        if(n <= 0){
            return 0;
        }
        if(n <= 2){
            return 1;
        }
        long long index = 1;
        do{
            n -= index;
            index++;
        }while(n >= index);
        return index - 1;
    }
};
int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.arrangeCoins(input) << endl;
    return 0;
}

