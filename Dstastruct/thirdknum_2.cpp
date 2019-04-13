#include <iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long min_n = LLONG_MIN, mid_n =  LLONG_MIN, max_n = LLONG_MIN;
        for(size_t i = 0; i < nums.size(); ++i){
            if(nums[i] > max_n){
                min_n = mid_n;
                mid_n = max_n;
                max_n = nums[i];
            }
            else if(nums[i] != max_n && nums[i] > mid_n){
                min_n = mid_n;
                mid_n = nums[i];
            }
            else if(nums[i] != max_n && nums[i] != mid_n && nums[i] > min_n){
                min_n = nums[i];
            }
        }
        if(min_n == LLONG_MIN){
            return max_n;
        }
        return min_n;
    }

};

int main()
{
    vector<int> array = {1, 2, 2, 5, 3, 5};
    Solution s;
    cout << s.thirdMax(array) << endl;
    return 0;
}

