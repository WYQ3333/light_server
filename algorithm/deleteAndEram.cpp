#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        if(length == 1)
        {
            return nums[0];
        }
        int _max = nums[0];
        for(int i = 0; i < length; i++)
        {
            if(nums[i] > _max)
            {
                _max = nums[i];
            }
        }
        int count[_max + 1] = {0};
        
        for(int i = 0; i < length; i++)
        {
            count[nums[i]]++;
        }
        int dp[_max + 1] = {0};
        dp[1] = count[1] * 1;
        for(int i = 2; i < _max + 1; i++)
        {
            dp[i] = max(dp[i - 1], count[i] * i + dp[i - 2]);
        }
        return dp[_max];
    }
};

class Solution1 {
public:
    int Count_Earn(vector<int> nums,int k){
        int count = 0;
        cout << k << endl;
        for(size_t i = 0; i < nums.size(); ++i){
            cout << nums[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == k - 1){
                nums[i] = 0;
            }
            else if(nums[i] == k + 1){
                nums[i] = 0;
            }
        }
        for(size_t i = 0; i < nums.size(); ++i){
            cout << nums[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < nums.size(); ++i){
            count += nums[i];
        }
        cout << count << endl;
        return count;
    }
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int max_count = 0, pre = 0;
        for(int i = 0; i < nums.size(); ++i){
            int count  = 0;
            if(pre != nums[i]){
                pre = nums[i];
                count = Count_Earn(nums,nums[i]);
            }
            if(count > max_count){
                max_count = count;
            }
        }
        return max_count;
    }
};
int main()
{
    Solution s;
    vector<int> array = {1,1,1,2,4,5,5,5,6};
    cout << s.deleteAndEarn(array) << endl;
    return 0;
}

