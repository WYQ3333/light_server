#include <iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    int count_bit(int num){
        int count = 0;
        while(num){
            count++;
            num = num&(num - 1);
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i = 0; i <= num ; ++i){
            result.push_back(count_bit(i));
        }
        return result;
    }
};

class Solution3{
public:
    int count_bit(int num){
        int count = 0;
        while(num){
            count++;
            num = num&(num - 1);
        }
        return count;
    }
    vector<int> countBits(int num){
        vector<int> result;
        int flag = 0;
        for(int i = 0; i <= num; ++i){
            if(result.size()%4 == 0){
                result.push_back(count_bit(i));
                flag = 0;
            }
            else{
                if(flag == 0){
                    result.push_back(result.back() + 1);
                    flag = 1;
                }
                else{
                    result.push_back(result.back());
                    flag = 0;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; ++ i) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};
int main()
{
    return 0;
}

