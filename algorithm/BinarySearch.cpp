#include <iostream>
#include<vector>
using namespace std;
//二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        if(nums[nums.size() - 1] < target)
            return -1;
        if(nums[0] > target)
            return -1;
        int mid = 0;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}

