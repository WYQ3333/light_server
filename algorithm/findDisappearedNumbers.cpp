#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        if(nums.size() == 0){
            return {};
        }
        vector<int> result;
        sort(nums.begin(), nums.end());
        int index = 1;
        for(size_t i = 0; i < nums.size();){
            if(index == nums[i]){
                index++;
                i++;
            }
            else if(index > nums[i]){
                i++;
                continue;
            }
            else if(index < nums[i]){
                result.push_back(index);
                index++;
            }
        }
        for(size_t i = index; i <= nums.size(); ++i){
            result.push_back(i);
        }
        return result;
    }
    //将所有正数作为数组下标，置对应数组值为负值。
    //那么，仍为正数的位置即为（未出现过）消失的数字。

    vector<int> find_number(vector<int>& nums){
        for(size_t i = 0; i < nums.size(); ++i){
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        vector<int> array;
        for(size_t i = 0; i < nums.size(); ++i){
            if(nums[i] > 0)
                array.push_back(i + 1);
        }
        return array;
    }
};


int main()
{
    Solution s;
    vector<int> array = {1, 2, 3, 3, 4, 6, 7, 8};
    vector<int> result = s.findDisappearedNumbers(array);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << endl;
    }
    return 0;
}

