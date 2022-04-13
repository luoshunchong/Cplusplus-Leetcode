// @algorithm @lc id=100327 lang=cpp 
// @title li-wu-de-zui-da-jie-zhi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[1,3,1],[1,5,1],[4,2,1]])=12
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //动态规划
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 1; i <= grid.size(); ++i) {
            for (int j = 1; j <= grid[0].size(); ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};