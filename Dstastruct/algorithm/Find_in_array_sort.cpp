/*
 *二维数组从左向右递增，从上到下递增，进行查找
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool Find(int target, vector<vector<int>> array){
        if(array.empty())
            return false;
        int len = array.size();
        int row = 0;
        int col = array[0].size() - 1;
        while(row < len && col >= 0){
            if(array[row][col] == target){
                return true;
            }
            else if(array[row][col] > target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }

};

int main()
{
    return 0;
}

