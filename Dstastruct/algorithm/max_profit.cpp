#include <iostream>
#include <vector>
using namespace std;

//每次交易1笔
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_profit = INT_MAX;
        for(size_t i = 0; i < prices.size(); ++i){
            if(prices[i] < min_profit){
                min_profit = prices[i];
            }
            if(prices[i] - min_profit > max_profit){
                max_profit = prices[i] - min_profit;
            }
        }
        return max_profit;
    }
};
//每次可以交易n笔
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int min_num = INT_MAX;
        int max_num = 0;
        if(prices.size() == 0){
            return 0;
        }
        for(size_t i = 0; i < prices.size() - 1; ++i){
            if(prices[i] < min_num){
                min_num = prices[i];
            }
            if(prices[i + 1] - min_num > 0){
                max_num += prices[i + 1] - min_num;
                min_num = INT_MAX;
            }
        }
        return max_num;
    }
};

//每次只能交易2笔
class Solution3 {
public:
    //只能做两次交易
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
        
        //当天可以买卖,求加和的最大值即可
        max_val = 0;
        for(int i=0;i<prices.size();i++){
            if(dp1[i]+dp2[i]>max_val)
                max_val = dp1[i]+dp2[i];
        }
        return max_val;
    }
};

//每次可以交易k笔
class Solution4 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int i, j;
        if(!k || !n)
            return 0;
        //一次交易需两个数，大于一半则说明全交易
        if(k > n/2)
        {
            int sum = 0;
            for(i=1;i<n;i++)
            {
                if(prices[i]-prices[i-1]>0)
                    sum += prices[i]-prices[i-1];
            }
            return sum;
        }
        //小于一半交易
        //3,2,6,5,0,3
        vector<vector<int>> cur(2, vector<int>(k));
        for(i=0;i<k;i++)
            cur[0][i] = INT_MIN; 
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                //cur[0]表示buy，cur[1]表示sell
                //1.第k次buy就是 上一次卖出剩下的钱 - 本次购买需要的钱
                //2.第k次sell就是 第k次买入 + 本次卖出的钱
                if(!j)
                    cur[0][j] = max(cur[0][j], -prices[i]);
                //买入股票带来负收益，减去
                else
                    cur[0][j] = max(cur[0][j], cur[1][j-1]-prices[i]);
                //卖出带来的收益，加入
                cur[1][j] = max(cur[1][j], cur[0][j]+prices[i]);
            }
        }
        return cur[1][k-1];
    }
};

int main()
{
    return 0;
}

