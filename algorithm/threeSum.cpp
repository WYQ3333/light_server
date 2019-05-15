#include <iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        if(nums.empty() || nums.size() < 3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int min_num = INT_MAX;
        int sum = 0;
        for(size_t i = 0; i < nums.size(); ++i){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                int a = (temp >= target) ? temp - target : target - temp;
                int c = a < 0 ? -a : a;
                if( c < min_num ){
                    min_num = a;
                    sum = temp;
                    left++;
                }
                else if(a >= min_num){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return sum;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return {};
        
        sort(nums.begin(),nums.end());
        int res=accumulate(nums.begin(),nums.begin()+3,0);
        int mn=abs(target-res);
        for(int i=0;i<nums.size();i++){
            int fix=target-nums[i];
            int l=i+1,r=nums.size()-1;
            //对撞指针
            while(l<r){
                if(nums[l]+nums[r]==fix)
                    return target;
                else {
                    if(abs(nums[l]+nums[r]-fix)<mn){
                        mn=abs(nums[l]+nums[r]-fix);
                        res=nums[l]+nums[r]+nums[i];
                    }
                    if(nums[l]+nums[r]>fix)
                        r--;
                    else if(nums[l]+nums[r]<fix)
                        l++;
                }
            }
        }
        return res;
    }
};
class Solution3{
public:
    int threeSumClosest(vector<int>& nums, int target){
        if(nums.empty() || nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int min_num = INT_MAX;
        int sum = 0;
        for(size_t i = 0; i < nums.size(); ++i){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                int a = (temp >= target) ? (temp - target) : (target - temp);
                if(a <= min_num){
                    min_num = a;
                    sum = temp;
                }
                left++;
                right--;
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> array = {0, 2, 1, -3};
    cout << s.threeSumClosest(array, 1) << endl;
    return 0;
}

