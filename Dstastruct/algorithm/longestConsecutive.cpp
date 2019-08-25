/*
 *通过时间复杂度为o(n)找到无序数组中的最长连续子序列
   通过哈希表实现，如果当前数字num - 1的个数为0， 直接找num+ 1；
   注意：unordered_set迭代器只有++ 或者--操作，没有向指针一样的
   加某个数的操作
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_set<int> my_set(nums.begin(), nums.end());
        int result = 0;
        for(auto it = my_set.begin(); it != my_set.end(); ++it){
            if(my_set.count(*it - 1) == 0){
                int x = *it + 1;
                while(my_set.count(x)){
                    x++;
                }
                result = max(result, x - (*it));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}

