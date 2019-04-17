#include <iostream>
#include<queue>
#include<vector>
using namespace std;


bool solution(vector<int>& array){
    for(size_t i = 0; i < array.size(); ++i){
        for(size_t j = i + 1; j < array.size(); ++j){
            for(size_t k = j + 1; k < array.size(); ++k){
                if(array[i] < array[j] && array[i] < array[k] && array[j] > array[k]){
                    return true;
                }
            }
        }
    }
    return false;
}

int findqtop(vector<int>& nums, int index){
    int result = -1; 
    for(size_t i = 0; i < nums.size(); ++i){
        if(nums[i] == index){
            result = i;
        }
    }
    return result;
}

bool find132(vector<int>& nums){
    if(nums.size() < 3){
        return false;
    }
    priority_queue<int, vector<int>> q;
    for(size_t i = 0; i < nums.size(); ++i){
        q.push(nums[i]);
    }
    while(!q.empty()){
        int index = q.top();
        int indexi = 0;
        indexi = findqtop(nums, index);
        if(indexi == (nums.size() - 1)){
            return false;
        }
        int min_x = nums[0];
        for(size_t i = 0; i < indexi; ++i){
            if(nums[i] < min_x){
                min_x = nums[i];
            }
        }
        int max_x = nums[nums.size() -1];
        for(size_t i = nums.size() - 1; i > indexi; --i){
            if(nums[i] > max_x){
                max_x = nums[i];
            }
        }

        if(min_x < max_x && min_x < index && index > max_x){
            return true;
        }
        q.pop();
    }
    return false;
}

int main()
{
    vector<int> array;
    int input;
    cin >> input;
    for(int i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    cout << find132(array) << endl;
    return 0;
}

