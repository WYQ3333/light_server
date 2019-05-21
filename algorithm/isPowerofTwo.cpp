#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(size_t i = 0; i < 32; ++i){
            if(n == 1 << i){
                return true;
            }
            else if(n > 1 << i){
                continue;
            }
            else{
                break;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.isPowerOfTwo(input) << endl;
    return 0;
}

