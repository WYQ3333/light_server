#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    typedef long long int_l;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int_l m = obstacleGrid.size();
        int_l n = obstacleGrid[0].size();
        vector<vector<int_l>> array;
        array.resize(m);
        for(int i = 0; i < m; ++i){
            array[i].resize(n);
        }
        array[0][0] = 1;
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        
        if(m == 1 && n != 1){
            for(int i = 0; i < n; ++i){
                if(obstacleGrid[0][i] == 1){
                    return 0;
                }
            }
            return 1;
        }
        if(n == 1 && m != 1){
            for(int i = 0; i < m; ++i){
                if(obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j != 0 ){
                    if(obstacleGrid[i][j-1] != 1){
                        array[i][j] =  array[i][j-1] == 0 ? 0 : 1;
                    }
                    else{
                        array[i][j] = 0;
                    }
                }
                else if(j == 0&& i != 0){
                    if(obstacleGrid[i-1][j] != 1){
                        array[i][j] = array[i-1][j] == 0 ? 0 : 1;
                    }
                    else{
                        array[i][j] = 0;
                    }
                }
                else if(i != 0 && j != 0){
                    if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)
                        array[i][j] = 0;
                    else if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] == 1)
                        array[i][j] = array[i-1][j] ;
                    else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] != 1)
                        array[i][j] = array[i][j-1];
                    else{
                        array[i][j] = array[i-1][j] + array[i][j-1];
                    }
                }
            }
        }
        return array[m-1][n-1];
    }
};


int main()
{
    Solution s;
    vector<vector<int>> array = {{0,0},{0,1}};
    cout << s.uniquePathsWithObstacles(array) << endl;
    return 0;
}

