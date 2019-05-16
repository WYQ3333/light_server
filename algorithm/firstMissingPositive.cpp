#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0){
            return 1;
        }
        sort(nums.begin(), nums.end());
        long long index = 1;
        if(index > 1){
            return 1;
        }
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
                break;
            }
        }
        return index;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

