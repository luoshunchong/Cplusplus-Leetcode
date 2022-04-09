// @algorithm @lc id=64 lang=cpp 
// @title minimum-path-sum


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[1,3,1],[1,5,1],[4,2,1]])=7
// @test([[1,2,3],[4,5,6]])=12
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        //初始化
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int j = 1; j < grid.size(); ++j) dp[j][0] = dp[j - 1][0] + grid[j][0];

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};