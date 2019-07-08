#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int threeSumMulti(vector<int>& array, int target){
        if(array.size() == 0)
            return 0;
        int mod_num = pow(10, 9) + 7;
        //用来进行动态规划的数组
        long long count[101] = {0};
        long long sum = 0;
        for(size_t i = 0; i < array.size(); ++i){
            count[array[i]]++;
        }
        for(int i = 0; i <= 100; ++i){
            for(int j = 0; j <= 100; ++j){
                if(count[i] && count[j]){
                    int k = target - i - j;
                    if(k < 0 || k > 100){
                        continue;
                    }
                    if(count[k] == 0){
                        continue;
                    }
                    if(i == j && j == k){
                        sum = (sum + (count[i] * (count[i] - 1) * (count[i] - 2))/6)%mod_num;
                    }
                    else if(i == j && j != k){
                        sum = (sum + count[k]*(count[j]*(count[j] - 1))/2)%mod_num;
                    }
                    else if(i < j && j < k){
                        sum = (sum + count[i]*count[j]*count[k]);
                    }
                }
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> array = {1,1,2,2,3,3,4,4,5,5};
    Solution s;
    cout << s.threeSumMulti(array, 8) << endl;
    return 0;
}

