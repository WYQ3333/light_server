#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    void Print(vector<vector<int>>& array){
        for(size_t i = 0; i < array.size(); ++i){
            for(size_t j = 0; j < array[i].size(); ++j){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
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
        vector<vector<int>> cur(2, vector<int>(k));
        for(i=0;i<k;i++)
            cur[0][i] = INT_MIN; 
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                if(!j)
                    cur[0][j] = max(cur[0][j], -prices[i]);
                else
                    cur[0][j] = max(cur[0][j], cur[1][j-1]-prices[i]);
                cur[1][j] = max(cur[1][j], cur[0][j]+prices[i]);
                Print(cur);
                cout << endl;
                cout << "--------------------------" << endl;
            }
        }
        return cur[1][k-1];
    }
};

class Solution2 {
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
                if(!j)
                    cur[0][j] = max(cur[0][j], -prices[i]);
                //买入股票带来负收益，减去
                else
                    cur[0][j] = max(cur[0][j], cur[1][j-1]-prices[i]);
                //卖出带来正收益，加入
                cur[1][j] = max(cur[1][j], cur[0][j]+prices[i]);
            }
        }
        return cur[1][k-1];
    }
};

int main()
{
    Solution s;
    vector<int> array_num = {2, 4, 1};
    int k = 1;
    cout << s.maxProfit(k, array_num) << endl;
    return 0;
}

