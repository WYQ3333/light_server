#include <iostream>

//3的n次幂
class Solution {
public:
    bool isPowerOfThree(int n) {
        long long x = 1;
        if(n == 0){
            return false;
        }
        if(n == 1)
            return true;
        while(x < n){
            x *= 3;
            if(x == n){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}

