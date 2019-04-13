#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(s.size() < 3){
            return *(s.rbegin());
        }
        int result = 0;
        auto it = s.rbegin();
        for(int i = 0; i < 3; ++i){
            result = *it;
            ++it;
        }
        return result;
    }
};

int main()
{
    vector<int> array = {1,6,7,8,9,1,5,4,2, 2, 3};
    //vector<int> array = {1, 2, 2, 3};
    Solution s;
    cout << s.thirdMax(array) << endl;
    return 0;
}

