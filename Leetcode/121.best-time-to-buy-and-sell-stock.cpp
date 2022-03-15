/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    // //暴力搜索,超时
    // int maxProfit(vector<int>& prices) {
    //     int res = 0;
    //     for (int i = 0; i < prices.size(); ++i){
    //         for (int j = i + 1; j < prices.size(); ++j){
    //             res = max(res, prices[j] - prices[i]);
    //         }
    //     }
    //     return res;
    // }

    // // 贪心
    // int maxProfit(vector<int>& prices) {
    //     int left = INT_MAX;
    //     int right = 0;
    //     for (int i = 0; i < prices.size(); ++i){
    //         left = min(left, prices[i]);
    //         right = max(right, prices[i] - left);
    //     }
    //     return right;
    // }

    // 动态规划
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int> (2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end

