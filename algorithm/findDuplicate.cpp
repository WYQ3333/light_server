#include <iostream>
#include<algorithm>
using namespace std;
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = 0;
        for(size_t i = 1;i < nums.size(); ++i){
            if(nums[i-1] == nums[i]){
                a = nums[i];
            }
        }
        return a;
    }
};

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        if(nums.size() <= 2){
            return nums[0];
        }
        int last = nums[0];
        int fast = nums[nums[0]];
        while(fast != last){
            last = nums[last];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(fast != last){
            last = nums[last];
            fast = nums[fast];
        }
        return fast;
    }
};
int main()
{
    return 0;
}

