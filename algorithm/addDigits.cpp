#include <iostream>
using namespace std;

class Solution{
public:
    int addDigits(int num){
        if(num < 10){
            return num;
        }
        int index = num;
        while(index >= 10){
            int cur = 0;
            while(index){
                cur += index % 10;
                index /= 10;
            }
            index = cur;
        }
        return index;
    }
};
int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.addDigits(input) << endl;
    return 0;
}

