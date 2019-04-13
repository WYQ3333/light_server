#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
    vector<int> array = {1,1,1,1,1,2,3,4,5};
    Solution s;
    cout << s.findKthLargest(array, 2) << endl;
    return 0;
}

