#include <iostream>
#include<vector>
using namespace std;

//一个“快乐数”定义为：对于一个正整数，
//每一次将该数替换为它每个位置上的数字的平方和，
//然后重复这个过程直到这个数变为 1，
//也可能是无限循环但始终变不到 1。
//如果可以变为 1，那么这个数就是快乐数。

class Solution1{
public:
    bool isHappy(int n){
        if(n <= 0){
            return false;
        }
        int index = n;
        while(index){
            int cur = 0;
            while(index){
                int a = index%10;
                cur = cur*cur + a*a;
                index /= 10;
            }
            index = cur;
            if(index == 1){
                return true;
            }
        }
        return false;
    }
};

class Solution2{
public:
    bool isHappy(int n){
        if(n <= 0)
            return false;
        if(n == 1){
            return true;
        }
        vector<int> array;
        int index = n;
        while(index){
            int cur = index;
            if(index == 1){
                return true;
            }
            if(index < 9 && index != 1)
                return false;
            while(cur){
                array.push_back(cur % 10);
                cur /= 10;
            }
            int sum = 0;
            for(size_t i = 0; i < array.size(); ++i){
                sum += array[i] * array[i];
            }
            array.clear();
            index = sum;
        }
        return false;
    }
};
class Solution {
public:
    bool isinarray(vector<int>& array, int n){
        for(size_t i = 0; i < array.size(); ++i){
            if(array[i] == n){
                return true;
            }
        }
        return false;
    }
    bool isHappy(int n) {
        vector<int> array = {4,16,37,58,89,145,42,20};
        int index = n;
        while(index){
            int cur = index;
            if(index == 1){
                return true;
            }
            if(isinarray(array,index)){
                return false;
            }
            vector<int> temp;
            while(cur){
                int a = cur % 10;
                temp.push_back(a);
                cur /= 10;
            }
            int result = 0;
            for(size_t i = 0; i < temp.size(); ++i){
                result += temp[i] * temp[i];
            }
            index = result;
        }
        return false;
    }
};
int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.isHappy(input) << endl;
    return 0;
}

