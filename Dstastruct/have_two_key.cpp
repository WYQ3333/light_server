#include <iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i <= n; ++i){
            while(n%i == 0){
                res += i;
                n /=i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int input;
    while(cin >> input){
        cout << s.minSteps(input) << endl;
    }
    return 0;
}

