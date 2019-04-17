#include <iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

bool solution(vector<int>& nums){
    if(nums.size() < 3){
        return false;
    }
    int third = INT_MIN;
    stack<int> s;
    for(size_t i = nums.size() - 1; i >= 0 ; --i){
        if(nums[i] < third){
            return true;
        }
        while(!s.empty() && nums[i] > s.top()){
            third = s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> array = {-2, 1, 2, -2, 1, 2};
    //-2 1 2 -2 1 2
    //size() -1..
    //nums[i] = 2;
    //stack : 2
    //third : INT_MIN
    //size() - 2..
    //nums[i] = 1;
    //stack : 2 1
    //third : INT_MIN;
    //size() - 3..
    //nums[i] = -2;
    //stack[i] = 
    //third = 
    cout << solution(array) << endl;
    return 0;
}

