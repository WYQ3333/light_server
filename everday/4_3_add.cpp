#include <iostream>
using namespace std;


int main()
{
    int input1, input2;
    cin >> input1 >> input2;
    while(input2){
        int temp = input1^input2; //异或的效果相当于不考虑进位两数相加的结果
        int cur = (input1&input2)<<1; //求得经位，不为0一直循环
        input1 = temp;
        input2 = cur;
    }
    cout << input1 << endl;
    return 0;
}

