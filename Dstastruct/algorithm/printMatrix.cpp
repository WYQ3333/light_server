#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int row = matrix.size();
        int col = matrix[0].size();
        int row_up = 0, row_down = row, col_left = 0, col_right = col;
        while(row_up < row && row_down > 0 && col_left < col && col_right > 0){
            for(int i = col_left; row_up < row_down && i < col_right; ++i){
                result.push_back(matrix[row_up][i]);
            }
            row_up++;
            for(int i = row_up; col_right > col_left && i < row_down; ++i){
                result.push_back(matrix[i][col_right - 1]);
            }
            col_right--;
            for(int i = col_right -1; row_down > row_up && i >= col_left; --i){
                result.push_back(matrix[row_down - 1][i]);
            }
            row_down--;
            for(int i = row_down - 1; col_left < col_right && i >= row_up; --i){
                result.push_back(matrix[i][col_left]);
            }
            col_left++;
        }
        return result;
    }
};
int main()
{
    return 0;
}

