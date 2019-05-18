#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        if(board.size() == 0){
            return 0;
        }
        int row = 0;
        int col = 0;
        for(size_t i = 0; i < board.size(); ++i){
            for(size_t j = 0; j < board[i].size(); ++j){
                if(board[i][j] == 'R'){
                    row = i;
                    col = j;
                }
            }
        }
        int result = 0;
        //向上走
        for(int i = row - 1; i >= 0; --i){
            if(board[i][col] == '.'){
                continue;
            }
            else if(board[i][col] == 'p'){
                result++;
                break;
            }
            else if(board[i][col] > 'A'){
                break;
            }
        }
        //向右走
        for(int i = col + 1; i < board[row].size(); ++i){
            if(board[row][i] == '.'){
                continue;
            }
            else if(board[row][i] == 'p'){
                result++;
                break;
            }
            else if(board[row][i] > 'A'){
                break;
            }
        }
        //向下走
        for(int i = row + 1; i < board.size(); ++i){
            if(board[i][col] == '.'){
                continue;
            }
            else if(board[i][col] == 'p'){
                result++;
                break;
            }
            else if(board[i][col] > 'A'){
                break;
            }
        }
        //向左走
        for(int i = col - 1; i >= 0; --i){
            if(board[row][i] == '.'){
                continue;
            }
            else if(board[row][i] == 'p'){
                result++;
                break;
            }
            else if(board[row][i] > 'A'){
                break;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}

