#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> array;
        array.resize(m);
        for(int i = 0; i < m; ++i){
            array[i].resize(n);
        }
        if(m == 1 || n == 1){
            return 1;
        }
        array[0][0] = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j != 0){
                    array[i][j] =  1;
                }
                else if(j == 0&& i != 0){
                    array[i][j] = 1;
                }
                else if(i != 0 && j != 0){
                    array[i][j] = array[i-1][j] + array[i][j-1];
                }
            }
        }
        return array[m-1][n-1];
    }
};
int main()
{
    Solution s;
    cout << s.uniquePaths(7,3) << endl;
    return 0;
}

