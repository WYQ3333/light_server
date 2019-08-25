/*
 *找有几个盆友圈，通过并查集查找
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())
            return 0;
        vector<int> array(M.size(), -1);
        for(size_t i = 0; i < M.size(); ++i){
            for(size_t j = i + 1; j < M[i].size(); ++j){
                if(M[i][j] == 1){
                    int index_i = i;
                    int index_j = j;
                    while(array[index_i] >= 0){
                        index_i = array[index_i];
                    }
                    while(array[index_j] >= 0){
                        index_j = array[index_j];
                    }
                    if(index_i == index_j)
                        continue;
                    array[index_i] += array[index_j];
                    array[index_j] = index_i;
                }
            }
        }
        int count = 0;
        for(size_t i = 0; i < array.size(); ++i){
            if(array[i] < 0){
                count++;
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}

