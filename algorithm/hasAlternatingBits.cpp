#include <iostream>
using namespace std;
//判断一个数字是否是0101或者1010循环的
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n == 0 || n == 1)
            return true;
        int pre = -1;
        int cur = 0;
        while(n){
            if(pre == -1){
                pre = n&1;
            }
            else{
                pre = cur;
            }
            n = n >> 1;
            cur = n&1;
            if(n != 0 && cur == pre){
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}

