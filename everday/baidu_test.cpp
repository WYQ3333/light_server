#include <iostream>
#include<vector>
#include<stdio.h>
#include<errno.h>
using namespace std;

int Solution(size_t n, vector<vector<int>> array){
    int result = 0;
    if(array.size() != n){
        perror("size if false!!!");
        return -1;
    }
    for(size_t i = 1; i < n; ++i){
        int max_l = 0;
        max_l = array[i-1][1] - array[i][0];
        if(max_l > result){
            result = max_l;
        }
    }
    return result;
}

int main()
{
    int result = 0;
    size_t input = 0;
    cin >> input;
    vector<vector<int>> array;
    for(size_t i = 0; i < input; ++i){
        vector<int> temp;
        for(size_t j = 0; j < 2; ++j){
            int cur = 0;
            cin >> cur;
            temp.push_back(cur);
        }
        array.push_back(temp);
    }
    result = Solution(input, array);
    cout << "重叠的最长部分为:";
    cout << result << endl;
    return 0;
}

