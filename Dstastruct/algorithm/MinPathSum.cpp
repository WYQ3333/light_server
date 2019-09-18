#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	int MinPathSum(vector<vector<int>>& grid){
		if (grid.empty())
			return 0;
		vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), 0));
		vector<pair<int, int>> Path;
		dp[0][0] = grid[0][0];
		for (size_t i = 1; i < grid.size();  ++i){
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (size_t j = 1; j < grid.size(); ++j){
			dp[j][0] = dp[j - 1][0] + grid[j][0];
		}
		for (size_t i = 1; i < grid.size(); ++i){
			for (size_t j = 1; j < grid[i].size(); ++j){
				dp[i][j] = dp[i - 1][j]>dp[i][j - 1] ? dp[i][j - 1] + grid[i][j] : dp[i - 1][j] + grid[i][j];
			}
		}
		int row = dp.size() - 1, col = dp.size() - 1;
		while (row > 0 && col > 0){
			Path.push_back(make_pair(row, col));
			if (dp[row - 1][col] < dp[row][col - 1]){
				row--;
			}
			else{
				col--;
			}
		}
		while (col > 0){
			Path.push_back(make_pair(row, col));
			col--;
		}
		while (row > 0){
			Path.push_back(make_pair(row, col));
			row--;
		}
		Path.push_back(make_pair(0, 0));
		reverse(Path.begin(), Path.end());
		for (size_t i = 0; i < Path.size(); ++i){
			cout << Path[i].first << " " << Path[i].second << endl;
		}
		return dp[grid.size() - 1][grid.size() - 1];
	}
};

#include <iostream>
using namespace std;

//
//int numberOfPaths(int m, int n)
//{
//	if (m == 1 || n == 1)
//		return 1;
//
//	return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
//}

int main()
{
	vector<vector<int>> array = {
		{ 1, 3, 1 },
		{ 1, 5, 1 },
		{ 4, 2, 1 },
	};
	Solution s;
	cout << s.MinPathSum(array) << endl;
	system("pause");
	return 0;
}

