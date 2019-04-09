#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = nums[0];
        int max2 = nums[0];
        for(size_t i = 1; i < nums.size(); ++i){
            if(max1 > 0){
                max1 += nums[i];
            }
            else{
                max1 = nums[i];
            }
            
            if(max1 > max2){
                max2 = max1;
            }
        }
        return max2;
    }
};

int main(){
    Solution s;
    vector<int> array = {-1, -2, -1, -3};
    cout << s.maxSubArray(array) << endl;
    return 0;
}
