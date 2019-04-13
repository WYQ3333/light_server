#include <iostream>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = nums.size() - k;
        return nums[index];
    }
};

int main()
{
    return 0;
}

