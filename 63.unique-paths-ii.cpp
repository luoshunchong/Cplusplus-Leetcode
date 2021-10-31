/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    /*
    在初始化dp数组的时候，当遇到障碍物的时候，障碍物及以后的位置都不初始化了
    在遍历的时候，当遇到障碍物的时候，就跳过。
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m&&obstacleGrid[i][0]==0;++i) dp[i][0]=1;
        for(int j=0;j<n&&obstacleGrid[0][j]==0;++j) dp[0][j]=1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

