/*
 *求数组中最小的前k个数
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void updata(vector<int>& input,int end){
        if(input.empty()){
            return;
        }
        int index =end/2 - 1;
        for(int i = index; i >= 0; --i){
            int temp = 2*i;
            if(input[temp] > input[temp + 1]){
                temp++;
            }
            if(input[i] > input[temp]){
                swap(input[i], input[temp]);
            }
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.size() < k)
            return result;
        int size = input.size();
        for(int i = 0; i < k; ++i){
            updata(input, size);
            result.push_back(input[0]);
            swap(input[0], input[size - 1]);
            updata(input, size - 1);
            size--;
        }
        return result;
    }
};
int main()
{
    return 0;
}

