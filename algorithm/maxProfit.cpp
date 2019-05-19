#include <iostream>
#include<vector>
using namespace std;

class Solution {
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

int main()
{
    return 0;
}

