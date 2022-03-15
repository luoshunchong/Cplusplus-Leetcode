/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;++i) dp[i][0] = 1;
        for(int j=0;j<n;++j) dp[0][j] = 1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }

    //还可以将该题抽象为一颗二叉树，找到所有路径就是遍历整个二叉树的所有路径
    //但是这样做超时。

    //还有另外一种方法就是数论方法也可以解决
};
// @lc code=end

