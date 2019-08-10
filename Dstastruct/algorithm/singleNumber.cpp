#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    //数组中的其他数字均出现两次，只有一个数字出现一次，找出这个数
    int singleNumber1(vector<int>& nums){
        if(nums.empty()){
            return 0;
        }
        int sum = nums[0];
        for(size_t i = 1; i < nums.size(); ++i){
            sum ^= nums[i];
        }
        return sum;
    }

    //数组中的其他数字均出现三次，只有一个数字出现一次，找出这个数
    int singleNumber2(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        int count = 1;
        for(size_t i = 1; i < nums.size(); ++i){
            if(pre == nums[i] && count < 3){
                count++;
                 pre = nums[i];
            }
            else if(pre != nums[i] && count == 3){
                pre = nums[i];
                count = 1;
            }
            else if(pre != nums[i] && count != 3){
                break;
            }
        }
        return pre;
    }

    //模拟三进制法
    int singleNumber2_2(vector<int>& nums) {
        int one =0,two = 0,three;
        for(int num:nums)
        {
            two |= (one & num);
            one ^= num;
            three =(one & two);
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

int main()
{
    vector<int> array = {1,2,3,1,2,3,1,2,3,4};
    Solution s;
    std::cout << s.singleNumber2_2(array) << std::endl;
    return 0;
}
