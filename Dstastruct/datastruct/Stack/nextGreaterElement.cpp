#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 *这是一个在另一个数组中查找比它大的一个数字
 *
 */
class Solution1{
public:
    int BinaryFind(vector<int>& nums, int left, int right, int k){
        //[left, right)
        if(right <= left){
            return -1;
        }
        int result = -1;
        int mid = (right - left)/2 + left;
        if(nums[mid] == k){
            result = nums[mid];
            return result;
        }
        else if(nums[mid] < k){
            result = BinaryFind(nums, mid + 1, right, k);
        }
        else{
            result = BinaryFind(nums, left, mid, k);
        }
        return result;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        vector<int> rt;
        for(size_t i = 0; i < nums1.size(); ++i){
            int temp = BinaryFind(nums2, 0, nums2.size(), nums1[i] + 1);
            rt.push_back(temp);
        }
        return rt;
    }
};

/*
 *给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
 *nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
 */
class Solution2 {
public:
    int find_index(vector<int>& nums2, int k){
        int index = -1;
        for(size_t i = 0; i < nums2.size(); ++i){
            if(nums2[i] == k){
                index = i;
            }
        }
        for(size_t i = index; i < nums2.size(); ++i){
            if(nums2[i] > k){
                return nums2[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rt;
        for(size_t i = 0; i < nums1.size(); ++i){
            rt.push_back(find_index(nums2, nums1[i]));
        }
        return rt;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        for(size_t i=0;i<nums1.size();++i){
            int n = nums1[i];
            bool flag = false;
            for(size_t j=0;j<nums2.size();++j){
                if(flag&&nums2[j]>n){
                    res[i] = nums2[j];
                    break;
                }
                if(nums2[j]==n&&!flag)flag = true;
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}

