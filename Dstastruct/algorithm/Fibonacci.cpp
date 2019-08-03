/*
 *斐波那契数列，实现O(n)的时间复杂度，还可以通过矩阵实现log(n)的时间复杂度
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n < 1){
            return n;
        }
        int a = 1;
        int b = 1;
        for(int i = 3; i <= n; ++i){
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main()
{
    return 0;
}

