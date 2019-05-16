#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int arrayPairSum(vector<int>& nums){
        int n = nums.size()/2;
        sort(nums.begin(), nums.end());
        int result = 0;
        for(size_t i = 0; i < nums.size(); i += 2){
            result += nums[i];
        }
        return result;
    }
};
int main()
{
    return 0;
}

