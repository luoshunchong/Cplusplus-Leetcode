// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i <= prices.size() - 1; i++)
        {
            if (prices[i] > prices[i - 1])
                sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
};
// @lc code=end

