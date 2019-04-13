#include <iostream>
#include<vector>
#include<queue>
using namespace std;
#define  INF 10000

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return matrix;
        int col = matrix[0].size();

        queue<pair<int, int> > myQueue;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                    myQueue.push(pair<int, int>(i, j));
                else
                    matrix[i][j] = INF;
            }
        }

        while (!myQueue.empty())
        {
            pair<int, int> rec = myQueue.front();
            myQueue.pop();

            if (rec.first-1 >= 0 && matrix[rec.first-1][rec.second] > matrix[rec.first][rec.second]+1)
            {
                matrix[rec.first-1][rec.second] = matrix[rec.first][rec.second]+1;
                myQueue.push(pair<int, int>(rec.first-1, rec.second));
            }

            if (rec.second-1 >= 0 && matrix[rec.first][rec.second-1] > matrix[rec.first][rec.second]+1)
            {
                matrix[rec.first][rec.second-1] = matrix[rec.first][rec.second]+1;
                myQueue.push(pair<int, int>(rec.first, rec.second-1));
            }

            if (rec.first+1 < row && matrix[rec.first+1][rec.second] > matrix[rec.first][rec.second]+1)
            {
                matrix[rec.first+1][rec.second] = matrix[rec.first][rec.second]+1;
                myQueue.push(pair<int, int>(rec.first+1, rec.second));
            }

            if (rec.second+1 < col && matrix[rec.first][rec.second+1] > matrix[rec.first][rec.second]+1)
            {
                matrix[rec.first][rec.second+1] = matrix[rec.first][rec.second]+1;
                myQueue.push(pair<int, int>(rec.first, rec.second+1));
            }
            cout << rec.first << " " << rec.second << endl;
            cout << "########################################" << endl;
            Print(matrix);
            cout << "--------------------------------------" << endl;
        }
        return matrix;
        
    }

    void Print(vector<vector<int>> array){
        for(size_t i = 0; i < array.size(); ++i){
            for(size_t j = 0; j < array.size(); ++j){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Solution2{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0){
            return matrix;
        }
        int col = matrix[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0){
                    q.push(make_pair(i,j));
                }
                else{
                    matrix[i][j] = INF;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> rec = q.front();
            q.pop();

            if(rec.first - 1 >=0 && matrix[rec.first - 1][rec.second] > matrix[rec.first][rec.second] + 1){
                matrix[rec.first - 1][rec.second] = matrix[rec.first][rec.second] + 1;
                q.push(make_pair(rec.first-1, rec.second));
            }
            if(rec.second - 1 >=0 && matrix[rec.first][rec.second - 1] > matrix[rec.first][rec.second] + 1){
                matrix[rec.first][rec.second - 1] = matrix[rec.first][rec.second] + 1;
                q.push(make_pair(rec.first, rec.second - 1));
            }
            if(rec.first + 1 < row && matrix[rec.first + 1][rec.second] > matrix[rec.first][rec.second] + 1){
                matrix[rec.first + 1][rec.second] = matrix[rec.first][rec.second] + 1;
                q.push(make_pair(rec.first+1, rec.second));
            }
            if(rec.second + 1 < col && matrix[rec.first][rec.second + 1] > matrix[rec.first][rec.second] + 1){
                matrix[rec.first][rec.second + 1] = matrix[rec.first][rec.second] + 1;
                q.push(make_pair(rec.first, rec.second + 1));
            }
        }
        return matrix;
    }
};
int main()
{
    vector<vector<int>> array{
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    Solution2 s;
    vector<vector<int>> result;
    result = s.updateMatrix(array);
    for(size_t i = 0; i < result.size(); ++i){
        for(size_t j = 0; j < result.size(); ++j){
            cout << result[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}

