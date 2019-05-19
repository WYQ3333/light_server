#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //只能做两次交易
    void Print_array(vector<int>& array){
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i];
        }
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        vector<int> dp1(prices.size(),0),dp2(prices.size(),0);
        
        //从前往后计算从0到i买卖一次的最大值
        int max_val=0, minp=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-minp > max_val)
                max_val = prices[i]-minp;
            if(minp > prices[i])
                minp = prices[i];
            dp1[i] = max_val;
        }
        
        Print_array(dp1);
        cout << endl;
        //从后往前计算从i到最后买卖一次的最大值
        max_val = 0;
        int maxp=prices.back();
        for(int i=prices.size()-2;i>=0;i--){
            if(maxp - prices[i] > max_val)
                max_val = maxp - prices[i];
            if(maxp < prices[i])
                maxp = prices[i];
            dp2[i] = max_val;
        }

        Print_array(dp2);
        cout << endl;
        
        //当天可以买卖,求加和的最大值即可
        max_val = 0;
        for(int i=0;i<prices.size();i++){
            if(dp1[i]+dp2[i]>max_val)
                max_val = dp1[i]+dp2[i];
        }
        return max_val;
    }
};
int main()
{
    Solution s;
    vector<int> array = {3,3,5,0,0,3,1,4};
    cout << s.maxProfit(array) << endl;
    return 0;
}

